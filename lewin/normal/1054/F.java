import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.Set;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.stream.Stream;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Collections;
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
        FElectricScheme solver = new FElectricScheme();
        solver.solve(1, in, out);
        out.close();
    }

    static class FElectricScheme {
        boolean between(int test, int lo, int high) {
            return test > lo && test < high;
        }

        boolean intersect(FElectricScheme.SegmentVer x, FElectricScheme.SegmentHor y) {
            return between(x.x, y.x1, y.x2) && between(y.y, x.y1, x.y2);
        }

        void add(HashMap<Integer, List<Integer>> mp, int key, int value) {
            List<Integer> r = mp.get(key);
            if (r == null) mp.put(key, r = new ArrayList<>());
            r.add(value);
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            HashMap<Integer, List<Integer>> xmp = new HashMap<>();
            HashMap<Integer, List<Integer>> ymp = new HashMap<>();
            for (int i = 0; i < n; i++) {
                int px = in.nextInt(), py = in.nextInt();
                add(xmp, px, py);
                add(ymp, py, px);
            }
            List<FElectricScheme.SegmentVer> sx = new ArrayList<>();
            List<FElectricScheme.SegmentHor> sy = new ArrayList<>();
            xmp.forEach((k, v) -> {
                Collections.sort(v);
                for (int i = 1; i < v.size(); i++) {
                    sx.add(new FElectricScheme.SegmentVer(k, v.get(i - 1), v.get(i)));
                }
            });
            ymp.forEach((k, v) -> {
                Collections.sort(v);
                for (int i = 1; i < v.size(); i++) {
                    sy.add(new FElectricScheme.SegmentHor(k, v.get(i - 1), v.get(i)));
                }
            });
            int nnodes = sx.size() + sy.size() + 2;
            List<MaxFlowDinic.Edge>[] gg = LUtils.genArrayList(nnodes);
            for (int i = 0; i < sx.size(); i++) {
                for (int j = 0; j < sy.size(); j++) {
                    if (intersect(sx.get(i), sy.get(j))) {
                        MaxFlowDinic.addEdge(gg, i, j + sx.size(), 1);
                    }
                }
            }
            for (int i = 0; i < sx.size(); i++) MaxFlowDinic.addEdge(gg, nnodes - 1, i, 1);
            for (int j = 0; j < sy.size(); j++) MaxFlowDinic.addEdge(gg, j + sx.size(), nnodes - 2, 1);
            Set<Integer> ss = MaxFlowDinic.minCut(gg, nnodes - 1, nnodes - 2);
            boolean[] vxc = new boolean[sx.size()];
            boolean[] vyc = new boolean[sy.size()];
            for (int i = 0; i < sx.size(); i++) vxc[i] = ss.contains(i);
            for (int i = 0; i < sy.size(); i++) vyc[i] = !ss.contains(i + sx.size());
            List<FElectricScheme.SegmentVer> ax = new ArrayList<>();
            List<FElectricScheme.SegmentHor> ay = new ArrayList<>();
            int[] ptr = new int[1];
            xmp.forEach((k, v) -> {
                int start = v.get(0);
                for (int i = 1; i < v.size(); i++) {
                    if (!vxc[ptr[0]]) {
                        ax.add(new FElectricScheme.SegmentVer(k, start, sx.get(ptr[0]).y1));
                        start = sx.get(ptr[0]).y2;
                    }
                    ptr[0]++;
                }
                ax.add(new FElectricScheme.SegmentVer(k, start, v.get(v.size() - 1)));
            });
            ptr[0] = 0;
            ymp.forEach((k, v) -> {
                int start = v.get(0);
                for (int i = 1; i < v.size(); i++) {
                    if (!vyc[ptr[0]]) {
                        ay.add(new FElectricScheme.SegmentHor(k, start, sy.get(ptr[0]).x1));
                        start = sy.get(ptr[0]).x2;
                    }
                    ptr[0]++;
                }
                ay.add(new FElectricScheme.SegmentHor(k, start, v.get(v.size() - 1)));
            });


            out.println(ay.size());
            for (FElectricScheme.SegmentHor s : ay) {
                out.println(s.x1 + " " + s.y + " " + s.x2 + " " + s.y);
            }
            out.println(ax.size());
            for (FElectricScheme.SegmentVer s : ax) {
                out.println(s.x + " " + s.y1 + " " + s.x + " " + s.y2);
            }

        }

        static class SegmentHor {
            public int y;
            public int x1;
            public int x2;

            public SegmentHor(int y, int x1, int x2) {
                this.y = y;
                this.x1 = x1;
                this.x2 = x2;
            }

        }

        static class SegmentVer {
            public int x;
            public int y1;
            public int y2;

            public SegmentVer(int x, int y1, int y2) {
                this.x = x;
                this.y1 = y1;
                this.y2 = y2;
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

        public void println(int i) {
            writer.println(i);
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

        public static boolean isSpaceChar(int c) {
            return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;
        }

    }

    static class MaxFlowDinic {
        public static void addEdge(List<MaxFlowDinic.Edge>[] graph, int s, int t, int cap) {
            graph[s].add(new MaxFlowDinic.Edge(t, graph[t].size(), cap));
            graph[t].add(new MaxFlowDinic.Edge(s, graph[s].size() - 1, 0));
        }

        static boolean dinicBfs(List<MaxFlowDinic.Edge>[] graph, int src, int dest, int[] dist) {
            Arrays.fill(dist, -1);
            dist[src] = 0;
            int[] Q = new int[graph.length];
            int sizeQ = 0;
            Q[sizeQ++] = src;
            for (int i = 0; i < sizeQ; i++) {
                int u = Q[i];
                for (MaxFlowDinic.Edge e : graph[u]) {
                    if (dist[e.t] < 0 && e.f < e.cap) {
                        dist[e.t] = dist[u] + 1;
                        Q[sizeQ++] = e.t;
                    }
                }
            }
            return dist[dest] >= 0;
        }

        static int dinicDfs(List<MaxFlowDinic.Edge>[] graph, int[] ptr, int[] dist, int dest, int u, int f) {
            if (u == dest)
                return f;
            for (; ptr[u] < graph[u].size(); ++ptr[u]) {
                MaxFlowDinic.Edge e = graph[u].get(ptr[u]);
                if (dist[e.t] == dist[u] + 1 && e.f < e.cap) {
                    int df = dinicDfs(graph, ptr, dist, dest, e.t, Math.min(f, e.cap - e.f));
                    if (df > 0) {
                        e.f += df;
                        graph[e.t].get(e.rev).f -= df;
                        return df;
                    }
                }
            }
            return 0;
        }

        public static int maxFlow(List<MaxFlowDinic.Edge>[] graph, int src, int dest) {
            int flow = 0;
            int[] dist = new int[graph.length];
            while (dinicBfs(graph, src, dest, dist)) {
                int[] ptr = new int[graph.length];
                while (true) {
                    int df = dinicDfs(graph, ptr, dist, dest, src, Integer.MAX_VALUE);
                    if (df == 0)
                        break;
                    flow += df;
                }
            }
            return flow;
        }

        public static Set<Integer> minCut(List<MaxFlowDinic.Edge>[] graph, int src, int dest) {
            maxFlow(graph, src, dest);
            Set<Integer> ret = new HashSet<>();
            int n = graph.length;
            int[] queue = new int[n];
            int front = 0, back = 0;
            queue[back++] = src;
            ret.add(src);
            while (front < back) {
                int node = queue[front++];
                for (MaxFlowDinic.Edge e : graph[node]) {
                    if (!ret.contains(e.t) && e.f < e.cap) {
                        ret.add(e.t);
                        queue[back++] = e.t;
                    }
                }
            }
            return ret;
        }

        public static class Edge {
            public int t;
            public int rev;
            public int cap;
            public int f;
            public int idx;

            public Edge(int t, int rev, int cap) {
                this.t = t;
                this.rev = rev;
                this.cap = cap;
            }

            public Edge(int t, int rev, int cap, int idx) {
                this.t = t;
                this.rev = rev;
                this.cap = cap;
                this.idx = idx;
            }

        }

    }
}