import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
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
        ArrayList<Integer>[] g;
        boolean[] was;
        int[] color;
        int tot = 0;

        void dfs(int v) {
                color[v] = tot;
                was[v] = true;
                for (int to : g[v])
                        if (!was[to])
                                dfs(to);
        }

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
                int n = in.nextInt();
                int m = in.nextInt();
                int k = in.nextInt();
                int[] c = new int[k];
                for (int i = 0; i < k; i++)
                        c[i] = in.nextInt();
                int[] type = new int[n];
                int[] first = new int[k];
                int sum = 0;
                for (int i = 0; i < k; i++) {
                        for (int j = sum; j < sum + c[i]; j++)
                                type[j] = i;
                        first[i] = sum;
                        sum += c[i];
                }
                int[][] dist = new int[k][k];
                for (int i = 0; i < k; i++)
                        for (int j = 0; j < k; j++)
                                dist[i][j] = i == j ? 0 : INF;
                was = new boolean[n];
                tot = 0;
                color = new int[n];
                g = new ArrayList[n];
                for (int i = 0; i < n; i++)
                        g[i] = new ArrayList<>();
                for (int i = 0; i < m; i++) {
                        int u, v, cost;
                        u = in.nextInt();
                        v = in.nextInt();
                        cost = in.nextInt();
                        u--;
                        v--;
                        dist[type[u]][type[v]] = Math.min(
                                dist[type[u]][type[v]],
                                cost
                        );
                        dist[type[v]][type[u]] = Math.min(
                                dist[type[v]][type[u]],
                                cost
                        );
                        if (cost == 0) {
                                g[u].add(v);
                                g[v].add(u);
                        }
                }
                for (int i = 0; i < n; i++)
                        if (!was[i]) {
                                dfs(i);
                                tot++;
                        }
                for (int i = 0; i < n; i++)
                        if (color[i] != color[first[type[i]]]) {
                                out.print("No");
                                return;
                        }
                for (int mid = 0; mid < k; mid++)
                        for (int i = 0; i < k; i++)
                                for (int j = 0; j < k; j++)
                                        if (dist[i][j] > dist[i][mid] + dist[mid][j])
                                                dist[i][j] = dist[i][mid] + dist[mid][j];
                out.println("Yes");
                for (int i = 0; i < k; i++) {
                        for (int j = 0; j < k; j++) {
                                if (dist[i][j] == INF)
                                        dist[i][j] = -1;
                                out.print(dist[i][j] + " ");
                        }
                        out.println();
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