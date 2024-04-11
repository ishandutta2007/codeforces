import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.AbstractQueue;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.AbstractCollection;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
        PrintWriter out = new PrintWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public static int n;
        public static int a;
        public static int b;
        public static double[] p;
        public static double[] u;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            a = in.nextInt();
            b = in.nextInt();
            double sumall = 0;
            p = new double[n];
            for (int i = 0; i < n; i++) sumall += p[i] = in.nextDouble();
            u = new double[n];
            for (int j = 0; j < n; j++) sumall += u[j] = in.nextDouble();

            double ans = solve();
            out.printf("%.10f\n", ans);
        }

        public static double solve() {
            int N = 2 + n + 2;
            List<TaskE.Edge>[] graph = new List[N];
            for (int i = 0; i < N; i++) graph[i] = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                addEdge(graph, 0, 2 + i, 1, 1 - p[i]);
                addEdge(graph, 1, 2 + i, 1, 1 - u[i]);
                addEdge(graph, 2 + i, N - 2, 1, 0);
                addEdge(graph, 2 + i, N - 2, 1, p[i] * u[i]);
            }
            addEdge(graph, N - 1, 0, a, 0);
            addEdge(graph, N - 1, 1, b, 0);
            return a + b - minCostFlow(graph, N - 1, N - 2, a + b)[1];
        }

        public static void addEdge(List<TaskE.Edge>[] graph, int s, int t, int cap, double cost) {
            graph[s].add(new TaskE.Edge(t, cap, cost, graph[t].size()));
            graph[t].add(new TaskE.Edge(s, 0, -cost, graph[s].size() - 1));
        }

        public static double[] minCostFlow(List<TaskE.Edge>[] graph, int s, int t, int maxf) {
            int n = graph.length;
            double[] prio = new double[n];
            int[] curflow = new int[n];
            int[] prevedge = new int[n];
            int[] prevnode = new int[n];
            double[] pot = new double[n];

            int flow = 0;
            double flowCost = 0;
            while (flow < maxf) {
                PriorityQueue<Pair<Double, Integer>> q = new PriorityQueue<>();
                q.add(new Pair<>(0.0, s));
                Arrays.fill(prio, Integer.MAX_VALUE);
                prio[s] = 0;
                boolean[] finished = new boolean[n];
                curflow[s] = Integer.MAX_VALUE;
                while (!finished[t] && !q.isEmpty()) {
                    Pair<Double, Integer> c = q.remove();
                    int u = c.v;
                    double priou = c.u;
                    if (priou != prio[u])
                        continue;
                    finished[u] = true;
                    for (int i = 0; i < graph[u].size(); i++) {
                        TaskE.Edge e = graph[u].get(i);
                        if (e.f >= e.cap)
                            continue;
                        int v = e.to;
                        double nprio = prio[u] + e.cost + pot[u] - pot[v];
                        if (prio[v] > nprio + 1e-12) {
                            prio[v] = nprio;
                            q.add(new Pair<>(nprio, v));
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
                    TaskE.Edge e = graph[prevnode[v]].get(prevedge[v]);
                    e.f += df;
                    graph[v].get(e.rev).f -= df;
                    flowCost += df * e.cost;
                }
            }
            return new double[]{flow, flowCost};
        }

        static class Edge {
            int to;
            int f;
            int cap;
            int rev;
            double cost;

            Edge(int to, int cap, double cost, int rev) {
                this.to = to;
                this.cap = cap;
                this.cost = cost;
                this.rev = rev;
            }

        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public int nextInt() {
            return Integer.parseInt(next());
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

    }
}