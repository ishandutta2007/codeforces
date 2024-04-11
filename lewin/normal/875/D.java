import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.TreeSet;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public TreeSet<Integer>[] pos;
        public int[] brr;
        public int[] a;
        public int[] id;
        public int[] pp;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int[] arr = in.readIntArray(n);
            a = new int[n + 1];
            for (int i = 1; i <= n; i++) a[i] = arr[i - 1];

            brr = Arrays.copyOf(a, n + 1);
            AUtils.sort(brr);
            id = new int[n + 1];
            for (int i = 0; i <= n; i++) id[i] = Arrays.binarySearch(brr, a[i]);
            pos = new TreeSet[n + 1];
            for (int i = 0; i <= n; i++) {
                pos[i] = new TreeSet<>();
                pos[i].add(0);
            }
            pp = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                pos[id[i]].add(i);
                pp[i] = pos[id[i]].size();
            }
            for (int i = 0; i <= n; i++) {
                pos[i].add(n + 1);
            }

            out.println(solve(1, n));
        }

        public long solve(int from, int to) {
            if (from == to) {
                return 0;
            }
            int mid = (from + to) / 2;
            long ans = solve(from, mid) + solve(mid + 1, to);

            int f1 = mid;
            int c1 = 0;
            while (f1 >= from) {
                int t1 = f1;
                c1 |= a[f1--];
                while (f1 >= from && (c1 & a[f1]) == a[f1]) {
                    f1--;
                }

                int f2 = mid + 1;
                int c2 = 0;
                while (f2 <= to) {
                    int t2 = f2;
                    c2 |= a[f2++];
                    while (f2 <= to && (c2 & a[f2]) == a[f2]) {
                        f2++;
                    }


                    int cc = c1 | c2;
                    int j = Arrays.binarySearch(brr, cc);
                    if (j < 0) {
                        ans += 1L * (t1 - f1) * (f2 - t2);
                    } else {
                        int a1 = Math.max(pos[j].floor(mid), f1);
                        int a2 = Math.min(pos[j].ceiling(mid + 1), f2);
                        ans += 1L * Math.max(0, t1 - a1) * Math.max(0, a2 - t2);
                    }
                }
            }
            return ans;
        }

    }

    static class AUtils {
        public static void sort(int[] arr) {
            for (int i = 1; i < arr.length; i++) {
                int j = (int) (Math.random() * (i + 1));
                if (i != j) {
                    int t = arr[i];
                    arr[i] = arr[j];
                    arr[j] = t;
                }
            }
            Arrays.sort(arr);
        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void close() {
            writer.close();
        }

        public void println(long i) {
            writer.println(i);
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int[] readIntArray(int tokens) {
            int[] ret = new int[tokens];
            for (int i = 0; i < tokens; i++) {
                ret[i] = nextInt();
            }
            return ret;
        }

        public int read() {
            if (this.numChars == -1) {
                throw new InputMismatchException();
            } else {
                if (this.curChar >= this.numChars) {
                    this.curChar = 0;

                    try {
                        this.numChars = this.stream.read(this.buf);
                    } catch (IOException var2) {
                        throw new InputMismatchException();
                    }

                    if (this.numChars <= 0) {
                        return -1;
                    }
                }

                return this.buf[this.curChar++];
            }
        }

        public int nextInt() {
            int c;
            for (c = this.read(); isSpaceChar(c); c = this.read()) {
                ;
            }

            byte sgn = 1;
            if (c == 45) {
                sgn = -1;
                c = this.read();
            }

            int res = 0;

            while (c >= 48 && c <= 57) {
                res *= 10;
                res += c - 48;
                c = this.read();
                if (isSpaceChar(c)) {
                    return res * sgn;
                }
            }

            throw new InputMismatchException();
        }

        public static boolean isSpaceChar(int c) {
            return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;
        }

    }
}