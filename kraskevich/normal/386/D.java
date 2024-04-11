import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
        final int INF = 1_000_000_000;
        int[][][] dist;
        State[][][] par;
        PrintWriter out;

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
                this.out = out;
                int n = in.nextInt();
                String[] colors = new String[n];
                int a, b, c;
                a = in.nextInt();
                b = in.nextInt();
                c = in.nextInt();
                a--;
                b--;
                c--;
                for (int i = 0; i < n; i++)
                        colors[i] = in.nextToken();
                dist = new int[n][n][n];
                for (int i = 0; i < n; i++)
                        for (int j = 0; j < n; j++)
                                for (int k = 0; k < n; k++)
                                        dist[i][j][k] = INF;
                par = new State[n][n][n];
                dist[a][b][c] = dist[a][c][b] = 0;
                dist[b][a][c] = dist[b][c][a] = 0;
                dist[c][a][b] = dist[c][b][a] = 0;
                State[] q = new State[n * n * n];
                int head = 0;
                int tail = 0;
                q[tail++] = new State(a, b, c);
                q[tail++] = new State(a, c, b);
                q[tail++] = new State(b, a, c);
                q[tail++] = new State(b, c, a);
                q[tail++] = new State(c, a, b);
                q[tail++] = new State(c, b, a);
                while (head < tail) {
                        State v = q[head++];
                        for (int k = 0; k < n; k++) {
                                if (k == v.a || k == v.b || k == v.c)
                                        continue;
                                if (colors[v.a].charAt(v.b) != colors[v.c].charAt(k))
                                        continue;
                                int to_a = v.a;
                                int to_b = v.b;
                                int to_c = k;
                                if (dist[to_a][to_b][to_c] > dist[v.a][v.b][v.c] + 1) {
                                        q[tail++] = new State(to_a, to_b, to_c);
                                        q[tail++] = new State(to_a, to_c, to_b);
                                        q[tail++] = new State(to_b, to_a, to_c);
                                        q[tail++] = new State(to_b, to_c, to_a);
                                        q[tail++] = new State(to_c, to_a, to_b);
                                        q[tail++] = new State(to_c, to_b, to_a);
                                        int d = dist[v.a][v.b][v.c] + 1;
                                        dist[to_a][to_b][to_c] = dist[to_a][to_c][to_b] = d;
                                        dist[to_b][to_a][to_c] = dist[to_b][to_c][to_a] = d;
                                        dist[to_c][to_a][to_b] = dist[to_c][to_b][to_a] = d;
                                        par[to_a][to_b][to_c] = new State(v.a, v.b, v.c);
                                        par[to_a][to_c][to_b] = new State(v.a, v.c, v.b);
                                        par[to_b][to_a][to_c] = new State(v.b, v.a, v.c);
                                        par[to_b][to_c][to_a] = new State(v.b, v.c, v.a);
                                        par[to_c][to_a][to_b] = new State(v.c, v.a, v.b);
                                        par[to_c][to_b][to_a] = new State(v.c, v.b, v.a);
                                }
                        }
                }
                if (dist[0][1][2] == INF) {
                        out.println(-1);
                        return;
                }
                out.println(dist[0][1][2]);
                rec(0, 1, 2);
        }

        void rec(int a, int b, int c) {
                if (dist[a][b][c] == 0)
                        return;
                rec(par[a][b][c].a, par[a][b][c].b, par[a][b][c].c);
                if (a != par[a][b][c].a)
                        out.println((par[a][b][c].a + 1) + " " + (a + 1));
                if (b != par[a][b][c].b)
                        out.println((par[a][b][c].b + 1) + " " + (b + 1));
                if (c != par[a][b][c].c)
                        out.println((par[a][b][c].c + 1) + " " + (c + 1));
        }

        class State  {
                int a, b, c;

                State(int a, int b, int c) {
                        this.a = a;
                        this.b = b;
                        this.c = c;
                }
        }
}

class FastScanner {
        BufferedReader reader;
        StringTokenizer tokenizer;

        public FastScanner(InputStream inputStream)  {
                reader = new BufferedReader(new InputStreamReader(inputStream));
        }

        public String nextToken() {
                while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                        String line;
                        try {
                                line = reader.readLine();
                        } catch (IOException e) {
                                return null;
                        }
                        tokenizer = new StringTokenizer(line);
                }
                return tokenizer.nextToken();
        }

        public int nextInt() {
                return Integer.parseInt(nextToken());
        }

        }