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
        HBreadboardCapacity solver = new HBreadboardCapacity();
        solver.solve(1, in, out);
        out.close();
    }

    static class HBreadboardCapacity {
        int n;
        int m;
        public static int INF = 1 << 20;
        String col = "RB";
        String dir = "LRUD";
        SegmentTreeX[] rt;
        HBreadboardCapacity.ST2[] cts;
        int[][] ss;

        int get() {
            int[] r = {n, m};
            int ans = INF;
            for (int i = 0; i < 2; i++) {
                HBreadboardCapacity.State x = rt[i].query(0, rt[i].n - 1);
                for (int j = 0; j < 2; j++) {
                    for (int k = 0; k < 2; k++) {
                        int t1 = j == 0 ? ss[i][0] : (r[1 - i] - ss[i][0]);
                        int t2 = k == 0 ? ss[i][1] : (r[1 - i] - ss[i][1]);
                        ans = Math.min(ans, x.a[x.flip * 4 + j * 2 + k] + t1 + t2);
                    }
                }
            }
            return ans;
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            m = in.nextInt();
            int q = in.nextInt();
            int[][] g = new int[4][];
            for (int i = 0; i < 4; i++) {
                char[] x = in.next().toCharArray();
                g[i] = new int[x.length];
                for (int k = 0; k < x.length; k++) {
                    g[i][k] = col.indexOf(x[k]);
                }
            }
            cts = new HBreadboardCapacity.ST2[4];
            ss = new int[2][2];
            for (int i = 0; i < 4; i++) {
                cts[i] = new HBreadboardCapacity.ST2(g[i]);
                ss[1 - i / 2][i % 2] = cts[i].query(0, cts[i].n - 1);
            }
            rt = new SegmentTreeX[2];
            rt[0] = new SegmentTreeX(n, m, g[0], g[1]);
            rt[1] = new SegmentTreeX(m, n, g[2], g[3]);
            out.println(get());
            while (q-- > 0) {
                int id = dir.indexOf(in.next().charAt(0));
                int l = in.nextInt() - 1, r = in.nextInt() - 1;
                if (l > r) {
                    int t = l;
                    l = r;
                    r = t;
                }
                cts[id].modify(l, r, 1);
                rt[id / 2].modify(l, r, (id % 2) + 1);
                ss[1 - id / 2][id % 2] = cts[id].query(0, cts[id].n - 1);
                out.println(get());
            }
        }

        static class State {
            public int[] a;
            public int flip;

            public State() {
                a = new int[16];
                this.flip = 0;
            }

        }

        static class ST2 extends SegmentTree<Integer, Integer> {
            public int[] arr;

            public ST2(int[] arr) {
                super(arr.length);
                this.arr = arr;
                this.reset();
            }

            public Integer getNeutralDelta() {
                return 0;
            }

            public Integer getNeutralValue() {
                return 0;
            }

            public Integer getInitValue(int position) {
                return arr[position];
            }

            public Integer joinValueWithDelta(Integer value, Integer delta, int segmentLength) {
                if (delta == 0) return value;
                if (delta == 1) return segmentLength - value;
                return null;
            }

            public Integer joinDeltas(Integer delta1, Integer delta2) {
                return delta1 ^ delta2;
            }

            public Integer joinValues(Integer value1, Integer value2) {
                return value1 + value2;
            }

        }

        public class SegmentTreeX {
            public int n;
            public int m;
            HBreadboardCapacity.State[] value;
            int[] top;
            int[] bottom;

            public SegmentTreeX(int n, int m, int[] top, int[] bottom) {
                this.n = n;
                this.m = m;
                this.top = top;
                this.bottom = bottom;
                value = new HBreadboardCapacity.State[4 * n];
                init(0, 0, n - 1);
            }

            public HBreadboardCapacity.State getInitValue(int position) {
                HBreadboardCapacity.State ret = new HBreadboardCapacity.State();
                AUtils.deepFill(ret.a, INF);
                for (int j = 0; j < 4; j++) {
                    int val = (((j & 1) == 1) ? (1 - top[position]) : (top[position])) + (((j & 2) == 2) ? (1 - bottom[position]) : (bottom[position]));
                    ret.a[j * 4] = val;
                    ret.a[j * 4 + 3] = 2 - val;
                }
                return ret;
            }

            public HBreadboardCapacity.State joinValues(HBreadboardCapacity.State value1, HBreadboardCapacity.State value2) {
                HBreadboardCapacity.State ret = new HBreadboardCapacity.State();
                AUtils.deepFill(ret.a, INF);
                for (int q = 0; q < 4; q++) {
                    ret.a[q * 4 + 0 * 2 + 0] = Math.min(ret.a[q * 4 + 0 * 2 + 0], value1.a[(q ^ value1.flip) * 4 + 0 * 2 + 0] + value2.a[(q ^ value2.flip) * 4 + 0 * 2 + 0]);
                    ret.a[q * 4 + 0 * 2 + 0] = Math.min(ret.a[q * 4 + 0 * 2 + 0], value1.a[(q ^ value1.flip) * 4 + 0 * 2 + 0] + value2.a[(q ^ value2.flip) * 4 + (0 ^ 1) * 2 + 0] + this.m);
                    ret.a[q * 4 + 0 * 2 + 0] = Math.min(ret.a[q * 4 + 0 * 2 + 0], value1.a[(q ^ value1.flip) * 4 + 0 * 2 + 1] + value2.a[(q ^ value2.flip) * 4 + 1 * 2 + 0]);
                    ret.a[q * 4 + 0 * 2 + 0] = Math.min(ret.a[q * 4 + 0 * 2 + 0], value1.a[(q ^ value1.flip) * 4 + 0 * 2 + 1] + value2.a[(q ^ value2.flip) * 4 + (1 ^ 1) * 2 + 0] + this.m);
                    ret.a[q * 4 + 0 * 2 + 1] = Math.min(ret.a[q * 4 + 0 * 2 + 1], value1.a[(q ^ value1.flip) * 4 + 0 * 2 + 0] + value2.a[(q ^ value2.flip) * 4 + 0 * 2 + 1]);
                    ret.a[q * 4 + 0 * 2 + 1] = Math.min(ret.a[q * 4 + 0 * 2 + 1], value1.a[(q ^ value1.flip) * 4 + 0 * 2 + 0] + value2.a[(q ^ value2.flip) * 4 + (0 ^ 1) * 2 + 1] + this.m);
                    ret.a[q * 4 + 0 * 2 + 1] = Math.min(ret.a[q * 4 + 0 * 2 + 1], value1.a[(q ^ value1.flip) * 4 + 0 * 2 + 1] + value2.a[(q ^ value2.flip) * 4 + 1 * 2 + 1]);
                    ret.a[q * 4 + 0 * 2 + 1] = Math.min(ret.a[q * 4 + 0 * 2 + 1], value1.a[(q ^ value1.flip) * 4 + 0 * 2 + 1] + value2.a[(q ^ value2.flip) * 4 + (1 ^ 1) * 2 + 1] + this.m);

                    ret.a[q * 4 + 1 * 2 + 0] = Math.min(ret.a[q * 4 + 1 * 2 + 0], value1.a[(q ^ value1.flip) * 4 + 1 * 2 + 0] + value2.a[(q ^ value2.flip) * 4 + 0 * 2 + 0]);
                    ret.a[q * 4 + 1 * 2 + 0] = Math.min(ret.a[q * 4 + 1 * 2 + 0], value1.a[(q ^ value1.flip) * 4 + 1 * 2 + 0] + value2.a[(q ^ value2.flip) * 4 + (0 ^ 1) * 2 + 0] + this.m);
                    ret.a[q * 4 + 1 * 2 + 0] = Math.min(ret.a[q * 4 + 1 * 2 + 0], value1.a[(q ^ value1.flip) * 4 + 1 * 2 + 1] + value2.a[(q ^ value2.flip) * 4 + 1 * 2 + 0]);
                    ret.a[q * 4 + 1 * 2 + 0] = Math.min(ret.a[q * 4 + 1 * 2 + 0], value1.a[(q ^ value1.flip) * 4 + 1 * 2 + 1] + value2.a[(q ^ value2.flip) * 4 + (1 ^ 1) * 2 + 0] + this.m);
                    ret.a[q * 4 + 1 * 2 + 1] = Math.min(ret.a[q * 4 + 1 * 2 + 1], value1.a[(q ^ value1.flip) * 4 + 1 * 2 + 0] + value2.a[(q ^ value2.flip) * 4 + 0 * 2 + 1]);
                    ret.a[q * 4 + 1 * 2 + 1] = Math.min(ret.a[q * 4 + 1 * 2 + 1], value1.a[(q ^ value1.flip) * 4 + 1 * 2 + 0] + value2.a[(q ^ value2.flip) * 4 + (0 ^ 1) * 2 + 1] + this.m);
                    ret.a[q * 4 + 1 * 2 + 1] = Math.min(ret.a[q * 4 + 1 * 2 + 1], value1.a[(q ^ value1.flip) * 4 + 1 * 2 + 1] + value2.a[(q ^ value2.flip) * 4 + 1 * 2 + 1]);
                    ret.a[q * 4 + 1 * 2 + 1] = Math.min(ret.a[q * 4 + 1 * 2 + 1], value1.a[(q ^ value1.flip) * 4 + 1 * 2 + 1] + value2.a[(q ^ value2.flip) * 4 + (1 ^ 1) * 2 + 1] + this.m);
                }
                ret.flip = 0;
                return ret;
            }

            public void init(int root, int left, int right) {
                if (left == right) {
                    value[root] = getInitValue(left);
                } else {
                    int mid = (left + right) >> 1;
                    init(2 * root + 1, left, mid);
                    init(2 * root + 2, mid + 1, right);
                    value[root] = joinValues(value[2 * root + 1], value[2 * root + 2]);
                }
            }

            void pushDelta(int root, int left, int right) {
                if (value[root].flip != 0) {
                    value[2 * root + 1].flip ^= value[root].flip;
                    value[2 * root + 2].flip ^= value[root].flip;
                    value[root] = joinValues(value[2 * root + 1], value[2 * root + 2]);
                }
            }

            public HBreadboardCapacity.State query(int from, int to) {
                return query(from, to, 0, 0, n - 1);
            }

            HBreadboardCapacity.State query(int from, int to, int root, int left, int right) {
                if (from == left && to == right)
                    return value[root];
                pushDelta(root, left, right);
                int mid = (left + right) >> 1;
                if (from <= mid && to > mid)
                    return joinValues(
                            query(from, mid, root * 2 + 1, left, mid),
                            query(mid + 1, to, root * 2 + 2, mid + 1, right));
                else if (from <= mid)
                    return query(from, mid, root * 2 + 1, left, mid);
                else if (to > mid)
                    return query(mid + 1, to, root * 2 + 2, mid + 1, right);
                else
                    throw new RuntimeException("Incorrect query from " + from + " to " + to);
            }

            public void modify(int from, int to, int delta) {
                modify(from, to, delta, 0, 0, n - 1);
            }

            void modify(int from, int to, int delta, int root, int left, int right) {
                if (from == left && to == right) {
                    this.value[root].flip ^= delta;
                    return;
                }
                pushDelta(root, left, right);
                int mid = (left + right) >> 1;
                if (from <= mid)
                    modify(from, Math.min(to, mid), delta, 2 * root + 1, left, mid);
                if (to > mid)
                    modify(Math.max(from, mid + 1), to, delta, 2 * root + 2, mid + 1, right);
                value[root] = joinValues(value[2 * root + 1], value[2 * root + 2]);
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

    static class AUtils {
        public static void deepFill(int[] x, int val) {
            Arrays.fill(x, val);
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

        public void println(int i) {
            writer.println(i);
        }

    }

    static abstract class SegmentTree<E, T> {
        public int n;
        protected E[] value;
        protected T[] delta;

        public abstract T getNeutralDelta();

        public abstract E getNeutralValue();

        public abstract E getInitValue(int position);

        public abstract E joinValueWithDelta(E value, T delta, int segmentLength);

        public abstract T joinDeltas(T delta1, T delta2);

        public abstract E joinValues(E value1, E value2);

        public SegmentTree(int n) {
            this.n = n;
            value = (E[]) new Object[2 * n];
            delta = (T[]) new Object[2 * n];
//        this.reset();
        }

        public void reset() {
            for (int i = 0; i < n; i++) {
                value[i + n] = getInitValue(i);
            }
            for (int i = 2 * n - 1; i > 1; i -= 2) {
                value[i >> 1] = joinValues(value[i], value[i ^ 1]);
            }
            for (int i = 0; i < 2 * n; i++)
                delta[i] = getNeutralDelta();
        }

        protected void pushDelta(int i) {
            int d = 0;
            for (; (i >> d) > 0; d++) {
            }
            for (d -= 2; d >= 0; d--) {
                int x = i >> d;
                value[x >> 1] = joinNodeValueWithDelta(x >> 1, 1 << (d + 1));
                delta[x] = joinDeltas(delta[x], delta[x >> 1]);
                delta[x ^ 1] = joinDeltas(delta[x ^ 1], delta[x >> 1]);
                delta[x >> 1] = getNeutralDelta();
            }
        }

        protected E joinNodeValueWithDelta(int i, int len) {
            return joinValueWithDelta(value[i], delta[i], len);
        }

        public E query(int from, int to) {
            from += value.length >> 1;
            to += value.length >> 1;
            pushDelta(from);
            pushDelta(to);
            E res = getNeutralValue();
            boolean found = false;
            for (int len = 1; from <= to; from = (from + 1) >> 1, to = (to - 1) >> 1, len <<= 1) {
                if ((from & 1) != 0) {
                    res = found ? joinValues(res, joinNodeValueWithDelta(from, len)) : joinNodeValueWithDelta(from, len);
                    found = true;
                }
                if ((to & 1) == 0) {
                    res = found ? joinValues(res, joinNodeValueWithDelta(to, len)) : joinNodeValueWithDelta(to, len);
                    found = true;
                }
            }
            if (!found) throw new RuntimeException();
            return res;
        }

        public void modify(int from, int to, T delta) {
            from += value.length >> 1;
            to += value.length >> 1;
            pushDelta(from);
            pushDelta(to);
            int a = from;
            int b = to;
            for (; from <= to; from = (from + 1) >> 1, to = (to - 1) >> 1) {
                if ((from & 1) != 0) {
                    this.delta[from] = joinDeltas(this.delta[from], delta);
                }
                if ((to & 1) == 0) {
                    this.delta[to] = joinDeltas(this.delta[to], delta);
                }
            }
            for (int i = a, len = 1; i > 1; i >>= 1, len <<= 1) {
                if (i % 2 == 1) i ^= 1;
                value[i >> 1] = joinValues(joinNodeValueWithDelta(i, len), joinNodeValueWithDelta(i ^ 1, len));
            }
            for (int i = b, len = 1; i > 1; i >>= 1, len <<= 1) {
                if (i % 2 == 1) i ^= 1;
                value[i >> 1] = joinValues(joinNodeValueWithDelta(i, len), joinNodeValueWithDelta(i ^ 1, len));
            }
        }

    }
}