import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStreamReader;

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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        private Edge[] firstEdge;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n, m;
            n = in.nextInt();
            m = in.nextInt();

            firstEdge = new Edge[n];

            int[] degree = new int[n];

            for (int i = 0; i < m; ++i) {
                int u = in.nextInt() - 1;
                int v = in.nextInt() - 1;

                if (u < v) {
                    int t = u;
                    u = v;
                    v = t;
                }

                new Edge(u, v);
                ++degree[u];
                ++degree[v];
            }

            int[] dist = new int[n];

            long answer = 0;
            for (int i = 0; i < n; ++i) {
                dist[i] = 1;
                for (Edge e = firstEdge[i]; e != null; e = e.next) {
                    dist[i] = Math.max(dist[i], dist[e.to] + 1);
                }

                answer = Math.max(answer, dist[i] * (long) degree[i]);
            }

            out.println(answer);
        }

        class Edge {
            int to;
            Edge next;

            Edge(int from, int to) {
                this.to = to;
                this.next = firstEdge[from];
                firstEdge[from] = this;
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