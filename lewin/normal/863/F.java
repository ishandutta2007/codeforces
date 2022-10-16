import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.PriorityQueue;
import java.util.AbstractQueue;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.AbstractCollection;
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
            int n = in.nextInt(), q = in.nextInt();
            int nnodes = 2 * n + 2;
            List<MinCostFlow.Edge>[] graph = LUtils.genArrayList(nnodes);
            int[] up = new int[n], down = new int[n];
            Arrays.fill(up, n - 1);
            for (int i = 0; i < q; i++) {
                int type = in.nextInt();
                int l = in.nextInt() - 1, r = in.nextInt() - 1, v = in.nextInt() - 1;
                for (int j = l; j <= r; j++) {
                    if (type == 1) {
                        down[j] = Math.max(down[j], v);
                    } else {
                        up[j] = Math.min(up[j], v);
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                MinCostFlow.addEdge(graph, nnodes - 1, i, 1, 0);
                for (int j = down[i]; j <= up[i]; j++) {
                    MinCostFlow.addEdge(graph, i, j + n, 1, 0);
                }
            }

            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    MinCostFlow.addEdge(graph, j + n, nnodes - 2, 1, 2 * k + 1);
                }
            }

            int[] r = MinCostFlow.minCostFlow(graph, nnodes - 1, nnodes - 2, n);
            out.println(r[0] == n ? r[1] : -1);
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

        public void close() {
            writer.close();
        }

        public void println(int i) {
            writer.println(i);
        }

    }

    static class MinCostFlow {
        public static void addEdge(List<MinCostFlow.Edge>[] graph, int s, int t, int cap, int cost) {
            graph[s].add(new MinCostFlow.Edge(t, cap, cost, graph[t].size()));
            graph[t].add(new MinCostFlow.Edge(s, 0, -cost, graph[s].size() - 1));
        }

        public static int[] minCostFlow(List<MinCostFlow.Edge>[] graph, int s, int t, int maxf) {
            int n = graph.length;
            int[] prio = new int[n];
            int[] curflow = new int[n];
            int[] prevedge = new int[n];
            int[] prevnode = new int[n];
            int[] pot = new int[n];

            //bellmanFord(graph, s, pot); // bellmanFord invocation can be skipped if edges costs are non-negative
            int flow = 0;
            int flowCost = 0;
            while (flow < maxf) {
                PriorityQueue<Long> q = new PriorityQueue<>();
                q.add((long) s);
                Arrays.fill(prio, Integer.MAX_VALUE);
                prio[s] = 0;
                boolean[] finished = new boolean[n];
                curflow[s] = Integer.MAX_VALUE;
                while (!finished[t] && !q.isEmpty()) {
                    long cur = q.remove();
                    int u = (int) (cur & 0xFFFF_FFFFL);
                    int priou = (int) (cur >>> 32);
                    if (priou != prio[u])
                        continue;
                    finished[u] = true;
                    for (int i = 0; i < graph[u].size(); i++) {
                        MinCostFlow.Edge e = graph[u].get(i);
                        if (e.f >= e.cap)
                            continue;
                        int v = e.to;
                        int nprio = prio[u] + e.cost + pot[u] - pot[v];
                        if (prio[v] > nprio) {
                            prio[v] = nprio;
                            q.add(((long) nprio << 32) + v);
                            prevnode[v] = u;
                            prevedge[v] = i;
                            curflow[v] = Math.min(curflow[u], e.cap - e.f);
                        }
                    }
                }
                if (prio[t] == Integer.MAX_VALUE)
                    break;
                for (int i = 0; i < n; i++)
                    if (finished[i])
                        pot[i] += prio[i] - prio[t];
                int df = Math.min(curflow[t], maxf - flow);
                flow += df;
                for (int v = t; v != s; v = prevnode[v]) {
                    MinCostFlow.Edge e = graph[prevnode[v]].get(prevedge[v]);
                    e.f += df;
                    graph[v].get(e.rev).f -= df;
                    flowCost += df * e.cost;
                }
            }
            return new int[]{flow, flowCost};
        }

        public static class Edge {
            public int to;
            public int f;
            public int cap;
            public int cost;
            public int rev;

            Edge(int to, int cap, int cost, int rev) {
                this.to = to;
                this.cap = cap;
                this.cost = cost;
                this.rev = rev;
            }

        }

    }
}