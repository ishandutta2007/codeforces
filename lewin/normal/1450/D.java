import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
        DRatingCompression solver = new DRatingCompression();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class DRatingCompression {
        public boolean isPermutation(int[] x) {
            int[] brr = Arrays.copyOf(x, x.length);
            AUtils.sort(brr);
            for (int i = 0; i < x.length; i++) {
                if (brr[i] != i + 1) {
                    return false;
                }
            }
            return true;
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int[] arr = in.readIntArray(n);
            char[] ret = new char[n];
            Arrays.fill(ret, '0');
            ret[0] = isPermutation(arr) ? '1' : '0';
            int[] narr = new int[n - 1];
            for (int i = 0; i < n - 1; i++) {
                narr[i] = Math.min(arr[i], arr[i + 1]);
            }

            int lo = 0, hi = n;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                int[] t = new int[n - mid];
                MinQueue mq = new MinQueue(n);
                for (int i = 0; i < mid; i++) {
                    mq.add(narr[i], i);
                }
                for (int i = 0; i < n - mid; i++) {
                    t[i] = (int) mq.getMin(i);
                    if (i + mid < n - 1) mq.add(narr[i + mid], i + mid);
                }
                if (isPermutation(t)) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
            for (int j = lo; j < n; j++) {
                ret[j] = '1';
            }
            out.println(new String(ret));
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

    static class AUtils {
        public static void sort(int[] arr) {
            shuffle(arr);
            Arrays.sort(arr);
        }

        public static void shuffle(int[] arr) {
            for (int i = 1; i < arr.length; i++) {
                int j = (int) (Math.random() * (i + 1));
                if (i != j) {
                    int t = arr[i];
                    arr[i] = arr[j];
                    arr[j] = t;
                }
            }
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

        public int[] readIntArray(int tokens) {
            int[] ret = new int[tokens];
            for (int i = 0; i < tokens; i++) {
                ret[i] = nextInt();
            }
            return ret;
        }

        public int read() {
            if (this.numChars == -1) {
                throw new UnknownError();
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

        public String next() {
            int c;
            while (isSpaceChar(c = this.read())) {
                ;
            }

            StringBuilder result = new StringBuilder();
            result.appendCodePoint(c);

            while (!isSpaceChar(c = this.read())) {
                result.appendCodePoint(c);
            }

            return result.toString();
        }

        public static boolean isSpaceChar(int c) {
            return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;
        }

    }

    static class MinQueue {
        public long[] value;
        public int front;
        public int back;
        public int[] index;

        public MinQueue(int N) {
            value = new long[N];
            index = new int[N];
            front = back = 0;
        }

        public void add(long val, int idx) {
            while (front < back && value[back - 1] >= val) back--;
            value[back] = val;
            index[back++] = idx;
        }

        public long getMin(int idx) {
            while (front < back && index[front] < idx) front++;
            return front == back ? 1L << 60 : value[front];
        }

    }
}