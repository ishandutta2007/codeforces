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
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author lewin
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        GChipGame solver = new GChipGame();
        solver.solve(1, in, out);
        out.close();
    }

    static class GChipGame {
        int n;
        int m;
        int[] rr;

        boolean can(int sum, int x) {
            int sm = x, big = sum - x;
            int havebig = 0, havesmall = 0;
            for (int i = 0; i < n; i++) {
                if (rr[i] >= sm) havesmall++;
                if (rr[i] >= big) havebig++;
            }
            if (havesmall > havebig) return true;
            if (n > 1 && rr[n - 2] >= 2 * sm) return true;
            if (rr[n - 1] >= 2 * sm && havebig % 2 == 0) return true;
            return false;
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            m = in.nextInt();
            long[] v = new long[n];
            for (int i = 0; i < n; i++) {
                v[i] = in.nextLong();
            }
            rr = new int[n];
            long small = 0, first = 0, second = 0;
            for (int sum = 2; sum <= m + m; sum++) {
                for (int i = 0; i < n; i++) {
                    rr[i] = (int) (v[i] % sum);
                }
                AUtils.sort(rr);
                int lo = Math.max(1, sum - m), hi = (sum - 1) / 2;

                if (lo <= hi && can(sum, lo)) {
                    while (lo < hi) {
                        int mid = (lo + hi + 1) / 2;
                        if (can(sum, mid)) lo = mid;
                        else hi = mid - 1;
                    }
                    small += lo - Math.max(1, sum - m) + 1;
                    lo++;
                }
                if (lo <= (sum - 1) / 2) {
                    int r = sum - lo;
                    int c = 0;
                    for (int i = 0; i < n; i++) {
                        if (rr[i] >= r) {
                            c++;
                        }
                    }
                    if (c % 2 == 1) {
                        first += 2 * ((sum - 1) / 2 - lo + 1);
                    } else {
                        second += 2 * ((sum - 1) / 2 - lo + 1);
                    }
                }
                if (sum % 2 == 0) {
                    int c = 0;
                    for (int i = 0; i < n; i++) {
                        if (rr[i] >= sum / 2) {
                            c++;
                        }
                    }
                    if (c % 2 == 1) {
                        first++;
                    } else {
                        second++;
                    }
                }
            }
            out.println(small + " " + small + " " + first + " " + second);
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

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void println(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1 << 16];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
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

        public long nextLong() {
            int c;
            for (c = this.read(); isSpaceChar(c); c = this.read()) {
                ;
            }

            byte sgn = 1;
            if (c == 45) {
                sgn = -1;
                c = this.read();
            }

            long res = 0L;

            while (c >= 48 && c <= 57) {
                res *= 10L;
                res += (long) (c - 48);
                c = this.read();
                if (isSpaceChar(c)) {
                    return res * (long) sgn;
                }
            }

            throw new InputMismatchException();
        }

        public static boolean isSpaceChar(int c) {
            return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;
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
}