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
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), k = in.nextInt();
            TaskF.Card[] c = new TaskF.Card[n];
            for (int i = 0; i < n; i++) {
                c[i] = new TaskF.Card(in.nextInt(), in.nextInt(), in.nextInt());
            }

            boolean[] prime = new boolean[200010];
            Arrays.fill(prime, true);
            prime[0] = false;
            prime[1] = false;
            for (int i = 2; i < prime.length; i++) {
                if (prime[i]) {
                    for (int j = i + i; j < prime.length; j += i) {
                        prime[j] = false;
                    }
                }
            }
            int lo = 1, hi = n + 1;
            while (lo < hi) {
                int mid = (lo + hi) / 2;

                int bestpow = 0;
                // include 1
                {
                    int nnodes = n + 2;
                    List<MaxFlowDinic.Edge>[] gg = LUtils.genArrayList(nnodes);
                    int best1 = 0;
                    int sump = 0;
                    for (int i = 0; i < n; i++) {
                        if (c[i].l > mid) continue;
                        if (c[i].c == 1) {
                            best1 = Math.max(best1, c[i].p);
                            continue;
                        }
                        if (prime[c[i].c + 1]) {
                            continue;
                        }

                        sump += c[i].p;
                        if (c[i].c % 2 == 1) MaxFlowDinic.addEdge(gg, nnodes - 1, i, c[i].p);
                        else MaxFlowDinic.addEdge(gg, i, nnodes - 2, c[i].p);
                    }
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                            if (c[i].c == 1 || c[j].c == 1) continue;
                            if (c[i].c % 2 == 1 && c[j].c % 2 == 0 && prime[c[i].c + c[j].c]) {
                                MaxFlowDinic.addEdge(gg, i, j, 1 << 29);
                            }
                        }
                    }
                    bestpow = Math.max(bestpow, best1 + sump - MaxFlowDinic.maxFlow(gg, nnodes - 1, nnodes - 2));
                }


                // don't include 1
                {
                    int nnodes = n + 2;
                    List<MaxFlowDinic.Edge>[] gg = LUtils.genArrayList(nnodes);
                    int sump = 0;
                    for (int i = 0; i < n; i++) {
                        if (c[i].l > mid) continue;
                        if (c[i].c == 1) {
                            continue;
                        }

                        sump += c[i].p;
                        if (c[i].c % 2 == 1) MaxFlowDinic.addEdge(gg, nnodes - 1, i, c[i].p);
                        else MaxFlowDinic.addEdge(gg, i, nnodes - 2, c[i].p);
                    }
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                            if (c[i].c == 1 || c[j].c == 1) continue;
                            if (c[i].c % 2 == 1 && c[j].c % 2 == 0 && prime[c[i].c + c[j].c]) {
                                MaxFlowDinic.addEdge(gg, i, j, 1 << 29);
                            }
                        }
                    }
                    bestpow = Math.max(bestpow, sump - MaxFlowDinic.maxFlow(gg, nnodes - 1, nnodes - 2));
                }

                if (bestpow < k) lo = mid + 1;
                else {
                    hi = mid;
                }
            }
            out.println(lo > n ? -1 : lo);
        }

        static class Card {
            public int p;
            public int c;
            public int l;

            public Card(int p, int c, int l) {
                this.p = p;
                this.c = c;
                this.l = l;
            }

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

    static class LUtils {
        public static <E> List<E>[] genArrayList(int size) {
            return Stream.generate(ArrayList::new).limit(size).toArray(List[]::new);
        }

    }
}