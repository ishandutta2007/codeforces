import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
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
        public static int[] arr;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), q = in.nextInt();
            arr = in.readIntArray(n);
            TaskF.SegmentTree root = new TaskF.SegmentTree(n);
            for (int i = 0; i < q; i++) {
                int type = in.nextInt();
                if (type == 1) {
                    int from = in.nextInt() - 1, to = in.nextInt() - 1, a = in.nextInt(), b = in.nextInt();
                    root.modify(from, to, a, b);
                } else {
                    int from = in.nextInt() - 1, to = in.nextInt() - 1;
                    out.println(root.query(from, to));
                }
            }
        }

        static class SegmentTree {
            int n;
            long[][] value;
            int[][] delta;

            public SegmentTree(int n) {
                this.n = n;
                value = new long[4 * n][10];
                delta = new int[4 * n][10];
                init(0, 0, n - 1);
            }

            long[] combine(long[] a, int[] b) {
                long[] ret = new long[10];
                for (int i = 0; i < 10; i++) {
                    ret[b[i]] += a[i];
                }
                return ret;
            }

            int[] combined(int[] a, int[] b) {
                int[] c = new int[10];
                for (int i = 0; i < 10; i++) {
                    c[i] = b[a[i]];
                }
                return c;
            }

            void pushDelta(int root, int left, int right) {
                value[root] = combine(value[root], delta[root]);
                delta[2 * root + 1] = combined(delta[2 * root + 1], delta[root]);
                delta[2 * root + 2] = combined(delta[2 * root + 2], delta[root]);
                for (int i = 0; i < 10; i++) {
                    delta[root][i] = i;
                }
            }

            void init(int root, int left, int right) {
                for (int digit = 0; digit < 10; digit++) {
                    delta[root][digit] = digit;
                }
                if (left == right) {
                    int cpow = 1;
                    while (arr[left] > 0) {
                        int d = arr[left] % 10;
                        value[root][d] += cpow;
                        cpow *= 10;
                        arr[left] /= 10;
                    }
                } else {
                    int mid = (left + right) >> 1;
                    init(2 * root + 1, left, mid);
                    init(2 * root + 2, mid + 1, right);
                    value[root] = MatrixOperations.vector_add(value[2 * root + 1], value[2 * root + 2]);
                }
            }

            public long query(int from, int to) {
                long[] x = query(from, to, 0, 0, n - 1);
                long ret = 0;
                for (int j = 0; j < 10; j++) {
                    ret += x[j] * j;
                }
                return ret;
            }

            long[] query(int from, int to, int root, int left, int right) {
                if (from == left && to == right)
                    return combine(value[root], delta[root]);
                pushDelta(root, left, right);
                int mid = (left + right) >> 1;
                if (from <= mid && to > mid)
                    return MatrixOperations.vector_add(
                            query(from, Math.min(to, mid), root * 2 + 1, left, mid),
                            query(Math.max(from, mid + 1), to, root * 2 + 2, mid + 1, right));
                else if (from <= mid)
                    return query(from, Math.min(to, mid), root * 2 + 1, left, mid);
                else if (to > mid)
                    return query(Math.max(from, mid + 1), to, root * 2 + 2, mid + 1, right);
                else
                    throw new RuntimeException("Incorrect query from " + from + " to " + to);
            }

            public void modify(int from, int to, int a, int b) {
                if (a == b) return;
                int[] delta = new int[10];
                for (int i = 0; i < 10; i++) {
                    delta[i] = i == a ? b : i;
                }
                modify(from, to, delta, 0, 0, n - 1);
            }

            void modify(int from, int to, int[] delta, int root, int left, int right) {
                if (from == left && to == right) {
                    this.delta[root] = combined(this.delta[root], delta);
                    return;
                }
                pushDelta(root, left, right);
                int mid = (left + right) >> 1;
                if (from <= mid)
                    modify(from, Math.min(to, mid), delta, 2 * root + 1, left, mid);
                if (to > mid)
                    modify(Math.max(from, mid + 1), to, delta, 2 * root + 2, mid + 1, right);
                value[root] = MatrixOperations.vector_add(
                        combine(value[2 * root + 1], this.delta[2 * root + 1]),
                        combine(value[2 * root + 2], this.delta[2 * root + 2]));
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

    static class MatrixOperations {
        public static long[] vector_add(long[] A, long[] B) {
            long[] C = new long[A.length];
            for (int i = 0; i < A.length; i++)
                C[i] = A[i] + B[i];
            return C;
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
}