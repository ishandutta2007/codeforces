import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Stream;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Comparator;
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
        GShiftingDominoes solver = new GShiftingDominoes();
        solver.solve(1, in, out);
        out.close();
    }

    static class GShiftingDominoes {
        int[] start;
        int[] end;
        int time;
        List<Integer>[] graph;

        void dfs(int node) {
            start[node] = time++;
            for (int next : graph[node]) {
                dfs(next);
            }
            end[node] = time - 1;
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            char[][] grid = new char[n][m];
            for (int i = 0; i < n; i++) {
                grid[i] = in.next().toCharArray();
            }
            int[][] id = new int[n][m];
            AUtils.deepFill(id, -1);
            int idx = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (id[i][j] != -1) continue;
                    id[i][j] = idx;
                    if (grid[i][j] == 'U') id[i + 1][j] = idx;
                    if (grid[i][j] == 'L') id[i][j + 1] = idx;
                    idx++;
                }
            }

            int nnodes = 2 * idx;
            graph = LUtils.genArrayList(nnodes);
            boolean[] vis = new boolean[idx];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (vis[id[i][j]]) continue;
                    int parity = (i + j) % 2;

                    vis[id[i][j]] = true;
                    if (grid[i][j] == 'U') {
                        if (i > 0) graph[id[i - 1][j] * 2 + 1 - parity].add(id[i][j] * 2 + 1 - parity);
                        if (i + 2 < n) graph[id[i + 2][j] * 2 + parity].add(id[i][j] * 2 + parity);
                    }
                    if (grid[i][j] == 'L') {
                        if (j > 0) graph[id[i][j - 1] * 2 + 1 - parity].add(id[i][j] * 2 + 1 - parity);
                        if (j + 2 < m) graph[id[i][j + 2] * 2 + parity].add(id[i][j] * 2 + parity);
                    }
                }
            }
            int[] indeg = new int[nnodes];
            for (int i = 0; i < nnodes; i++) {
                for (int j : graph[i]) {
                    indeg[j]++;
                }
            }
            start = new int[nnodes];
            end = new int[nnodes];
            time = 0;
            for (int i = 0; i < nnodes; i++) {
                if (indeg[i] == 0) {
                    dfs(i);
                }
            }
            GShiftingDominoes.Interval[] its = new GShiftingDominoes.Interval[nnodes];
            for (int i = 0; i < idx; i++) {
                int a = 2 * i + 0, b = 2 * i + 1;
                its[2 * i + 0] = new GShiftingDominoes.Interval(start[b], start[a], end[a], +1);
                its[2 * i + 1] = new GShiftingDominoes.Interval(end[b] + 1, start[a], end[a], -1);
            }

            GShiftingDominoes.ST root = new GShiftingDominoes.ST(time);
            Arrays.sort(its, Comparator.comparingInt(a -> a.time));
            long ans = 0;
            int lasttime = 0;
            int ptr = 0;
            while (ptr < its.length) {
                int x = ptr;

                Pair<Integer, Integer> c = root.query(0, time - 1);
                int count = time - (c.u == 0 ? c.v : 0);
                ans += 1L * (its[ptr].time - lasttime) * count;
                lasttime = its[ptr].time;

                while (x < its.length && its[x].time == its[ptr].time) {
                    root.modify(its[x].start, its[x].end, its[x].type);
                    x++;
                }

                ptr = x;
            }
            out.println(ans);
        }

        static class ST extends SegmentTree<Pair<Integer, Integer>, Integer> {
            public ST(int n) {
                super(n);
            }

            public Integer getNeutralDelta() {
                return 0;
            }

            public Pair<Integer, Integer> getNeutralValue() {
                return new Pair<>(1 << 20, 0);
            }

            public Pair<Integer, Integer> getInitValue(int position) {
                return new Pair<>(0, 1);
            }

            public Pair<Integer, Integer> joinValueWithDelta(Pair<Integer, Integer> value, Integer delta, int segmentLength) {
                return new Pair<>(value.u + delta, value.v);
            }

            public Integer joinDeltas(Integer delta1, Integer delta2) {
                return delta1 + delta2;
            }

            public Pair<Integer, Integer> joinValues(Pair<Integer, Integer> value1, Pair<Integer, Integer> value2) {
                int mn = Math.min(value1.u, value2.u);
                int ct = (value1.u == mn ? value1.v : 0) + (value2.u == mn ? value2.v : 0);
                return new Pair<>(mn, ct);
            }

        }

        static class Interval {
            public int start;
            public int end;
            public int time;
            public int type;

            public Interval(int time, int start, int end, int type) {
                this.time = time;
                this.start = start;
                this.end = end;
                this.type = type;
            }

            public String toString() {
                return "Interval{" +
                        "start=" + start +
                        ", end=" + end +
                        ", time=" + time +
                        ", type=" + type +
                        '}';
            }

        }

    }

    static class Pair<U extends Comparable<U>, V extends Comparable<V>> implements Comparable<Pair<U, V>> {
        public final U u;
        public final V v;

        public Pair(U u, V v) {
            this.u = u;
            this.v = v;
        }

        public int hashCode() {
            return (u == null ? 0 : u.hashCode() * 31) + (v == null ? 0 : v.hashCode());
        }

        public boolean equals(Object o) {
            if (this == o)
                return true;
            if (o == null || getClass() != o.getClass())
                return false;
            Pair<U, V> p = (Pair<U, V>) o;
            return (u == null ? p.u == null : u.equals(p.u)) && (v == null ? p.v == null : v.equals(p.v));
        }

        public int compareTo(Pair<U, V> b) {
            int cmpU = u.compareTo(b.u);
            return cmpU != 0 ? cmpU : v.compareTo(b.v);
        }

        public String toString() {
            return String.format("[Pair = (%s, %s)", u.toString(), v.toString());
        }

    }

    static class LUtils {
        public static <E> List<E>[] genArrayList(int size) {
            return Stream.generate(ArrayList::new).limit(size).toArray(List[]::new);
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
        public static void deepFill(int[][] x, int val) {
            for (int[] y : x) deepFill(y, val);
        }

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

        public void println(long i) {
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
            this.reset();
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