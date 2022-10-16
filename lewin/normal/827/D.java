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
import java.util.concurrent.atomic.AtomicInteger;
import java.io.Writer;
import java.util.function.BiConsumer;
import java.io.OutputStreamWriter;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public int[] ans;
        int len;
        int[][] up;
        int[][] w;
        int[] tin;
        int[] tout;
        int[] depth2;
        int time;
        List<Integer>[] tree;
        boolean valuesOnVertices;
        TaskD.SegmentTree segmentTree;
        int[] parent;
        int[] heavy;
        int[] depth;
        int[] pathRoot;
        int[] pos;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            TaskD.Edge[] e = new TaskD.Edge[m];
            for (int i = 0; i < m; i++) {
                e[i] = new TaskD.Edge(in.nextInt() - 1, in.nextInt() - 1, in.nextInt(), i);
            }
            Arrays.sort(e, Comparator.comparingInt(x -> x.weight));
            int[] p = DisjointSets.createSets(n);
            ans = new int[m];
            List<TaskD.E2>[] tree = LUtils.genArrayList(n);
            List<TaskD.E2>[] aa = LUtils.genArrayList(n);
            boolean[] used = new boolean[m];
            List<Integer>[] trr = LUtils.genArrayList(n);
            for (int i = 0; i < m; i++) {
                if (DisjointSets.unite(p, e[i].from, e[i].to)) {
                    tree[e[i].from].add(new TaskD.E2(e[i].to, e[i].weight));
                    tree[e[i].to].add(new TaskD.E2(e[i].from, e[i].weight));
                    aa[e[i].from].add(new TaskD.E2(e[i].to, e[i].idx));
                    aa[e[i].to].add(new TaskD.E2(e[i].from, e[i].idx));
                    trr[e[i].from].add(e[i].to);
                    trr[e[i].to].add(e[i].from);
                    used[e[i].idx] = true;
                }
            }
            init(tree, 0);
            init2(trr, false);
            for (int i = 0; i < m; i++) {
                if (!used[e[i].idx]) {
                    used[e[i].idx] = true;
                    ans[e[i].idx] = weight(e[i].from, e[i].to) - 1;
                    modify(e[i].from, e[i].to, e[i].weight - 1);
                }
            }
            for (int i = 0; i < n; i++) {
                for (TaskD.E2 j : aa[i]) {
                    int d = query(i, j.to);
                    ans[j.weight] = d >= 1 << 30 ? -1 : d;
                }
            }
            out.println(ans);
        }

        public void init(List<TaskD.E2>[] tree, int root) {
            int n = tree.length;
            len = 1;
            while ((1 << len) <= n) ++len;
            up = new int[len][n];
            tin = new int[n];
            tout = new int[n];
            depth2 = new int[n];
            w = new int[len][n];
            dfs(tree, root, root);
        }

        void dfs(List<TaskD.E2>[] tree, int u, int p) {
            tin[u] = time++;
            up[0][u] = p;
            for (int i = 1; i < len; i++) {
                up[i][u] = up[i - 1][up[i - 1][u]];
                w[i][u] = Math.max(w[i][u], Math.max(w[i - 1][u], w[i - 1][up[i - 1][u]]));
            }
            for (TaskD.E2 v : tree[u])
                if (v.to != p) {
                    w[0][v.to] = v.weight;
                    depth2[v.to] = depth2[u] + 1;
                    dfs(tree, v.to, u);
                }
            tout[u] = time++;
        }

        int weight(int a, int b) {
            if (depth2[a] < depth2[b]) {
                a ^= b;
                b ^= a;
                a ^= b;
            }

            int ret = 0;

            int diff = depth2[a] - depth2[b];
            for (int i = 0; (1 << i) <= diff; i++)
                if ((diff & (1 << i)) != 0) {
                    ret = Math.max(ret, w[i][a]);
                    a = up[i][a];
                }

            if (a == b)
                return ret;

            int log = 0;
            while (1 << (log + 1) <= depth2[a])
                log++;

            // another binary search
            for (int i = log; i >= 0; i--)
                if (up[i][a] != up[i][b]) {
                    ret = Math.max(ret, w[i][a]);
                    ret = Math.max(ret, w[i][b]);
                    a = up[i][a];
                    b = up[i][b];
                }
            ret = Math.max(ret, w[0][a]);
            ret = Math.max(ret, w[0][b]);
            return ret;
        }

        public void init2(List<Integer>[] tree, boolean valuesOnVertices) {
            this.tree = tree;
            this.valuesOnVertices = valuesOnVertices;
            int n = tree.length;
            segmentTree = new TaskD.SegmentTree(n);

            parent = new int[n];
            heavy = new int[n];
            depth = new int[n];
            pathRoot = new int[n];
            pos = new int[n];

            Arrays.fill(heavy, -1);
            parent[0] = -1;
            depth[0] = 0;
            dfs(0);
            for (int u = 0, p = 0; u < n; u++) {
                if (parent[u] == -1 || heavy[parent[u]] != u) {
                    for (int v = u; v != -1; v = heavy[v]) {
                        pathRoot[v] = u;
                        pos[v] = p++;
                    }
                }
            }
        }

        int getNeutralValue() {
            return 1 << 30;
        }

        int dfs(int u) {
            int size = 1;
            int maxSubtree = 0;
            for (int v : tree[u]) {
                if (v != parent[u]) {
                    parent[v] = u;
                    depth[v] = depth[u] + 1;
                    int subtree = dfs(v);
                    if (maxSubtree < subtree) {
                        maxSubtree = subtree;
                        heavy[u] = v;
                    }
                    size += subtree;
                }
            }
            return size;
        }

        public int query(int u, int v) {
            AtomicInteger res = new AtomicInteger(getNeutralValue()); // just mutable integer
            processPath(u, v, (a, b) -> res.set(segmentTree.queryOperation(res.get(), segmentTree.query(a, b))));
            return res.get();
        }

        public void modify(int u, int v, int delta) {
            processPath(u, v, (a, b) -> segmentTree.modify(a, b, delta));
        }

        void processPath(int u, int v, BiConsumer<Integer, Integer> op) {
            for (; pathRoot[u] != pathRoot[v]; v = parent[pathRoot[v]]) {
                if (depth[pathRoot[u]] > depth[pathRoot[v]]) {
                    int t = u;
                    u = v;
                    v = t;
                }
                op.accept(pos[pathRoot[v]], pos[v]);
            }
            if (!valuesOnVertices && u == v) return;
            op.accept(Math.min(pos[u], pos[v]) + (valuesOnVertices ? 0 : 1), Math.max(pos[u], pos[v]));
        }

        static class Edge {
            public int from;
            public int to;
            public int weight;
            public int idx;

            public Edge(int from, int to, int weight, int idx) {
                this.from = from;
                this.to = to;
                this.weight = weight;
                this.idx = idx;
            }

        }

        static class E2 {
            public int to;
            public int weight;

            public E2(int to, int weight) {
                this.to = to;
                this.weight = weight;
            }

        }

        static class SegmentTree {
            int[] value;
            int[] delta;

            public SegmentTree(int n) {
                value = new int[2 * n];
                for (int i = 0; i < n; i++) {
                    value[i + n] = getInitValue();
                }
                for (int i = 2 * n - 1; i > 1; i -= 2) {
                    value[i >> 1] = queryOperation(value[i], value[i ^ 1]);
                }
                delta = new int[2 * n];
                Arrays.fill(delta, getNeutralDelta());
            }

            int modifyOperation(int x, int y) {
                return Math.min(x, y);
            }

            int queryOperation(int leftValue, int rightValue) {
                return Math.min(leftValue, rightValue);
            }

            int deltaEffectOnSegment(int delta, int segmentLength) {
                if (delta == getNeutralDelta()) return getNeutralDelta();
                // Here you must write a fast equivalent of following slow code:
                // int result = delta;
                // for (int i = 1; i < segmentLength; i++) result = queryOperation(result, delta);
                // return result;
                return delta;
            }

            int getNeutralDelta() {
                return 1 << 30;
            }

            int getInitValue() {
                return 1 << 30;
            }

            int joinValueWithDelta(int value, int delta) {
                if (delta == getNeutralDelta()) return value;
                return modifyOperation(value, delta);
            }

            int joinDeltas(int delta1, int delta2) {
                if (delta1 == getNeutralDelta()) return delta2;
                if (delta2 == getNeutralDelta()) return delta1;
                return modifyOperation(delta1, delta2);
            }

            void pushDelta(int i) {
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

            int joinNodeValueWithDelta(int i, int len) {
                return joinValueWithDelta(value[i], deltaEffectOnSegment(delta[i], len));
            }

            public int query(int from, int to) {
                from += value.length >> 1;
                to += value.length >> 1;
                pushDelta(from);
                pushDelta(to);
                int res = 0;
                boolean found = false;
                for (int len = 1; from <= to; from = (from + 1) >> 1, to = (to - 1) >> 1, len <<= 1) {
                    if ((from & 1) != 0) {
                        res = found ? queryOperation(res, joinNodeValueWithDelta(from, len)) : joinNodeValueWithDelta(from, len);
                        found = true;
                    }
                    if ((to & 1) == 0) {
                        res = found ? queryOperation(res, joinNodeValueWithDelta(to, len)) : joinNodeValueWithDelta(to, len);
                        found = true;
                    }
                }
                if (!found) throw new RuntimeException();
                return res;
            }

            public void modify(int from, int to, int delta) {
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
                    value[i >> 1] = queryOperation(joinNodeValueWithDelta(i, len), joinNodeValueWithDelta(i ^ 1, len));
                }
                for (int i = b, len = 1; i > 1; i >>= 1, len <<= 1) {
                    value[i >> 1] = queryOperation(joinNodeValueWithDelta(i, len), joinNodeValueWithDelta(i ^ 1, len));
                }
            }

        }

    }

    static class LUtils {
        public static <E> List<E>[] genArrayList(int size) {
            return Stream.generate(ArrayList::new).limit(size).toArray(List[]::new);
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

    static class DisjointSets {
        public static int[] createSets(int size) {
            int[] p = new int[size];
            for (int i = 0; i < size; i++)
                p[i] = i;
            return p;
        }

        public static int root(int[] p, int x) {
            return x == p[x] ? x : (p[x] = root(p, p[x]));
        }

        public static boolean unite(int[] p, int a, int b) {
            a = root(p, a);
            b = root(p, b);
            if (a != b) {
                if (Math.random() < 0.5)
                    p[a] = b;
                else
                    p[b] = a;
                return true;
            }
            return false;
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