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
import java.util.Comparator;
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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        public int mod = 1000000007;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), q = in.nextInt();
            int[] arr = in.readIntArray(n);
            TaskF.Query[] qs = new TaskF.Query[q];
            for (int i = 0; i < q; i++) {
                qs[i] = new TaskF.Query(in.nextInt() - 1, in.nextInt(), i);
            }
            Arrays.sort(qs, Comparator.comparingInt(x -> x.l));
            int cptr = 0;
            Basis b = new Basis();
            int[] p2 = Utils.genPower(2, n + 1010, mod);
            int[] ans = new int[q];
            for (int it = 0; it < q; it++) {
                int jt = it;
                while (jt < q && qs[jt].l == qs[it].l) jt++;
                while (cptr <= qs[it].l) {
                    b.add(arr[cptr++]);
                }

                for (int k = it; k < jt; k++) {
                    if (b.test(qs[k].x)) {
                        ans[qs[k].idx] = p2[qs[it].l - b.size + 1];
                    }
                }

                it = jt - 1;
            }
            out.println(ans);
        }

        static class Query {
            public int l;
            public int x;
            public int idx;

            public Query(int l, int x, int idx) {
                this.l = l;
                this.x = x;
                this.idx = idx;
            }

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

        public void print(int[] array) {
            for (int i = 0; i < array.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(array[i]);
            }
        }

        public void println(int[] array) {
            print(array);
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

    static class Utils {
        public static int[] genPower(int base, int len, int mod) {
            int[] ret = new int[len];
            ret[0] = 1;
            for (int i = 1; i < len; i++) ret[i] = (int) (1L * ret[i - 1] * base % mod);
            return ret;
        }

    }

    static class Basis {
        public int size;
        public long[] basis;

        public Basis() {
            basis = new long[100];
            size = 0;
        }

        public boolean add(long x) {
            for (int i = size - 1; i >= 0; i--) {
                x = Math.min(x, x ^ basis[i]);
            }
            if (x == 0) return false;
            basis[size++] = x;
            for (int i = size - 2; i >= 0; i--) {
                if (basis[i] > basis[i + 1]) {
                    long t = basis[i + 1];
                    basis[i + 1] = basis[i];
                    basis[i] = t;
                }
            }
            return true;
        }

        public boolean test(long x) {
            for (int i = size - 1; i >= 0; i--) {
                x = Math.min(x, x ^ basis[i]);
            }
            return x == 0;
        }

    }
}