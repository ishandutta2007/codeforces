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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public long c2(int x) {
            return 1L * x * (x - 1) / 2;
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), q = in.nextInt();
            int[] arr = in.readIntArray(n);
            for (int i = 0; i < n; i++) arr[i]--;
            TaskC.Query[] qs = new TaskC.Query[q];
            for (int i = 0; i < q; i++) {
                qs[i] = new TaskC.Query(in.nextInt() - 1, in.nextInt() - 1, in.nextInt() - 1, in.nextInt() - 1, i);
            }

            long[] res = new long[q];
            for (int i = 0; i < q; i++) {
                res[i] = c2(n) - c2(qs[i].l) - c2(qs[i].d) - c2(n - 1 - qs[i].r) - c2(n - 1 - qs[i].u);
            }

            TaskC.Q2[] ff = new TaskC.Q2[2 * q];
            TaskC.Q2[] bb = new TaskC.Q2[2 * q];
            for (int i = 0; i < q; i++) {
                ff[2 * i + 0] = new TaskC.Q2(qs[i].l - 1, qs[i].d - 1, true, i);
                ff[2 * i + 1] = new TaskC.Q2(qs[i].l - 1, qs[i].u, false, i);

                bb[2 * i + 0] = new TaskC.Q2(qs[i].r + 1, qs[i].d - 1, true, i);
                bb[2 * i + 1] = new TaskC.Q2(qs[i].r + 1, qs[i].u, false, i);
            }
            Arrays.sort(ff, Comparator.comparingInt(x -> x.pos));
            Arrays.sort(bb, Comparator.comparingInt(x -> -x.pos));

            BIT b = new BIT(n + 10);
            int ptr = 0;
            for (int i = 0; i < 2 * q; i++) {
                while (ptr <= ff[i].pos) {
                    b.update(arr[ptr], +1);
                    ptr++;
                }

                int x = b.query(ff[i].thresh);
                if (!ff[i].less) x = ptr - x;
                res[ff[i].idx] += c2(x);
            }

            b = new BIT(n + 10);
            ptr = n - 1;
            for (int i = 0; i < 2 * q; i++) {
                while (ptr >= bb[i].pos) {
                    b.update(arr[ptr], +1);
                    ptr--;
                }

                int x = b.query(bb[i].thresh);
                if (!bb[i].less) x = (n - 1 - ptr) - x;
                res[bb[i].idx] += c2(x);
            }

            out.println(res);
        }

        static class Query {
            public int l;
            public int d;
            public int r;
            public int u;
            public int idx;

            public Query(int l, int d, int r, int u, int idx) {
                this.l = l;
                this.d = d;
                this.r = r;
                this.u = u;
                this.idx = idx;
            }

        }

        static class Q2 {
            public int pos;
            public int thresh;
            public boolean less;
            public int idx;

            public Q2(int pos, int thresh, boolean less, int idx) {
                this.pos = pos;
                this.thresh = thresh;
                this.less = less;
                this.idx = idx;
            }

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

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void print(long[] array) {
            for (int i = 0; i < array.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(array[i]);
            }
        }

        public void println(long[] array) {
            print(array);
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }

    static class BIT {
        private int[] tree;
        private int N;

        public BIT(int N) {
            this.N = N;
            this.tree = new int[N + 3];
        }

        public int query(int K) {
            K += 2;
            int sum = 0;
            for (int i = K; i > 0; i -= (i & -i))
                sum += tree[i];
            return sum;
        }

        public void update(int K, int val) {
            K += 2;
            for (int i = K; i < tree.length; i += (i & -i))
                tree[i] += val;
        }

    }
}