import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.util.LinkedList;
import java.util.ArrayList;
import java.io.InputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Comparator;
import java.util.StringTokenizer;
import java.util.Arrays;
import java.util.Queue;

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
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();

            int length = 0;
            final char[][] greetings = new char[n][];
            for (int i = 0; i < n; ++i) {
                greetings[i] = in.next().toCharArray();
                length += greetings[i].length;
            }

            int lastNode = 2;
            int[] ca = new int[length + 2];
            int[] cb = new int[length + 2];

            int[] which = new int[length + 2];
            Arrays.fill(which, -1);

            for (int i = 0; i < n; ++i) {
                int current = 1;
                for (char c : greetings[i]) {
                    int[] ch = (c == 'a' ? ca : cb);
                    if (ch[current] == 0) {
                        ch[current] = lastNode++;
                    }
                    current = ch[current];
                }
                which[current] = i;
            }

            int[] suffix = new int[lastNode];
            {
                suffix[1] = 0;
                ca[0] = cb[0] = 1;
                int[] queue = new int[length + 2];
                int front = 0, rear = 0;
                queue[rear++] = 1;
                while (front < rear) {
                    int current = queue[front++];
                    for (int i = 0; i < 2; ++i) {
                        int[] ch = i == 0 ? ca : cb;
                        if (ch[current] == 0) {
                            ch[current] = ch[suffix[current]];
                        } else {
                            suffix[ch[current]] = ch[suffix[current]];
                            if (which[ch[current]] == -1) {
                                which[ch[current]] = which[suffix[ch[current]]];
                            }
                            queue[rear++] = ch[current];
                        }
                    }
                }
            }

            boolean[][] rel = new boolean[n][n];
            for (int i = 0; i < n; ++i) {
                int current = 1;
                for (int j = 0; j < greetings[i].length; ++j) {
                    int[] ch = greetings[i][j] == 'a' ? ca : cb;
                    current = ch[current];
                    if (j + 1 == greetings[i].length) {
                        current = suffix[current];
                    }
                    if (which[current] != -1) {
                        // All greetings are different.
                        rel[which[current]][i] = true;
                    }
                }
            }

            Bitset[] relSet = new Bitset[n];
            for (int i = 0; i < n; ++i) {
                relSet[i] = new Bitset(n);
                relSet[i].set(i, 1);
            }

            Integer[] orders = new Integer[n];
            for (int i = 0; i < n; ++i) {
                orders[i] = i;
            }

            Arrays.sort(orders, new Comparator<Integer>() {

                public int compare(Integer o1, Integer o2) {
                    return greetings[o1].length - greetings[o2].length;
                }
            });

            for (int i = n - 1; i >= 0; --i) {
                for (int j = 0; j < n; ++j) {
                    if (i != j && rel[i][j]) {
                        relSet[i] = relSet[i].or(relSet[j]);
                    }
                }
            }

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    rel[i][j] = relSet[i].get(j) == 1;
                }
            }
//
//        MaxFlow flow = new MaxFlow(2 * n + 2, 2 * n, 2 * n + 1);
//        for (int i = 0; i < n; ++i) {
//            flow.insert(2 * n, i, 1);
//            flow.insert(i + n, 2 * n + 1, 1);
//            for (int j = 0; j < n; ++j) {
//                if (i != j && rel[i][j]) {
//                    flow.insert(i, j + n, 1);
//                }
//            }
//        }

            DinicGraph flow = new DinicGraph(2 * n + 2);
            for (int i = 0; i < n; ++i) {
                flow.addEdge(2 * n, i, 1);
                flow.addEdge(i + n, 2 * n + 1, 1);
                for (int j = 0; j < n; ++j) {
                    if (i != j && rel[i][j]) {
                        flow.addEdge(i, j + n, 1);
                    }
                }
            }

            int answer = n - (int) flow.getMaxFlow(2 * n, 2 * n + 1);
            out.println(answer);

            boolean[] vis = bfs(flow, 2 * n, 1);

            int[] plan = new int[answer];
            answer = 0;
            for (int i = 0; i < n; ++i) {
                if (vis[i] && !vis[i + n]) {
                    plan[answer++] = i;
                }
            }

            if (answer != plan.length) {
                throw new RuntimeException();
            }
            for (int i = 0; i < answer; ++i) {
                if (i > 0) out.print(" ");
                out.print(plan[i] + 1);
            }
            out.println();
        }

        boolean[] bfs(DinicGraph flow, int s, int c) {
            boolean[] vis = new boolean[flow.edges.length];
            Queue<Integer> queue = new LinkedList<Integer>();
            vis[s] = true;
            queue.add(s);
            while (!queue.isEmpty()) {
                int current = queue.poll();
                for (DinicGraph.Edge e : flow.edges[current]) {
                    if (e.cap > e.flow && !vis[e.to]) {
                        vis[e.to] = true;
                        queue.add(e.to);
                    }
                }
            }
            return vis;
        }

        static class DinicGraph {
            public ArrayList<Edge>[] edges;
            int[] cur;
            int[] q;
            public int[] d;
            int n;

            public DinicGraph(int n) {
                edges = new ArrayList[n];
                this.n = n;
                for (int i = 0; i < edges.length; i++) {
                    edges[i] = new ArrayList<Edge>();
                }
                q = new int[n];
                d = new int[n];
                cur = new int[n];
            }

            public Edge addEdge(int from, int to, int cap) {
                Edge e1 = new Edge(from, to, 0, cap);
                Edge e2 = new Edge(to, from, 0, 0);
                e1.rev = e2;
                e2.rev = e1;
                edges[from].add(e1);
                edges[to].add(e2);
                return e1;
            }

            boolean bfs(int source, int target) {
                int head = 0;
                int tail = 1;
                Arrays.fill(d, Integer.MAX_VALUE);
                d[source] = 0;
                q[0] = source;
                while (head < tail) {
                    int x = q[head++];
                    for (int i = 0; i < edges[x].size(); i++) {
                        Edge e = edges[x].get(i);
                        if (e.cap - e.flow > 0 && d[e.to] == Integer.MAX_VALUE) {
                            d[e.to] = d[x] + 1;
                            q[tail++] = e.to;
                            if (e.to == target) {
                                return true;
                            }
                        }
                    }
                }
                return false;
            }

            public int dfs(int x, int target, int cMin) {
                if (x == target) {
                    return cMin;
                }
                for (int i = cur[x]; i < edges[x].size(); cur[x] = ++i) {
                    Edge e = edges[x].get(i);
                    if (d[e.to] != d[x] + 1 || e.cap - e.flow == 0) {
                        continue;
                    }
                    int add = dfs(e.to, target, Math.min(cMin, e.cap - e.flow));
                    if (add == 0) {
                        continue;
                    }
                    e.flow += add;
                    e.rev.flow -= add;
                    return add;
                }
                return 0;
            }

            public long getMaxFlow(int source, int target) {
                long flow = 0;
                while (bfs(source, target)) {
                    Arrays.fill(cur, 0);
                    while (true) {
                        int add = dfs(source, target, Integer.MAX_VALUE);
                        if (add == 0) {
                            break;
                        }
                        flow += add;
                    }
                }
                return flow;
            }

            public static class Edge {
                public int from;
                public int to;
                public int flow;
                public int cap;
                public Edge rev;

                public Edge(int from, int to, int flow, int cap) {
                    super();
                    this.from = from;
                    this.to = to;
                    this.flow = flow;
                    this.cap = cap;
                }

            }

        }

        static class Bitset {
            int len;
            int vlen;
            int[] bit;

            Bitset(int bits) {
                len = bits;
                vlen = (bits + 31) >> 5;
                bit = new int[vlen];
            }

            public void set(int x, int y) {
                if (((bit[x >> 5] >>> (x & 31)) & 1) != y) {
                    bit[x >> 5] ^= 1 << (x & 31);
                }
            }

            public int get(int x) {
                return (bit[x >> 5] >>> (x & 31)) & 1;
            }

            public Bitset or(Bitset o) {

                Bitset ret = new Bitset(len);
                for (int i = 0; i < vlen; ++i) {
                    ret.bit[i] = bit[i] | o.bit[i];
                }

                return ret;
            }

        }

    }

    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (Exception e) {
                    throw new UnknownError();
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}