import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
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
        ArrayList<Integer>[] g;
        int n, m;
        boolean[][] have;
        int[] x;
        int[] y;
        boolean[] used;
        int stop;
        

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
                n = in.nextInt();
                g = new ArrayList[n];
                for (int i = 0; i < n; i++)
                        g[i] = new ArrayList<>();
                have = new boolean[n][n];
                m = in.nextInt();
                for (int i = 0; i < m; i++) {
                        int a = in.nextInt();
                        int b = in.nextInt();
                        --a;
                        --b;
                        g[a].add(b);
                        have[a][b] = true;
                }
                int res = Integer.MAX_VALUE;
                for (int center = 0; center < n; center++)
                        res = Math.min(res, solve(center));
                out.print(res);
        }

        int solve(int v) {
                stop = v;
                int withV = 0;
                int add = 0;
                for (int i = 0; i < n; i++)
                        if (i != v)
                                if (have[v][i])
                                        withV++;
                                else
                                        add++;
                for (int i = 0; i < n; i++)
                        if (i != v)
                                if (have[i][v])
                                        withV++;
                                else
                                        add++;
                if (have[v][v])
                        withV++;
                else
                        add++;
                x = new int[n];
                y = new int[n];
                used = new boolean[n];
                Arrays.fill(x, -1);
                Arrays.fill(y, -1);
                int matched = 0;
                for (int i = 0; i < n; i++)
                        if (i != v && x[i] == -1) {
                                Arrays.fill(used, false);
                                if (dfs(i))
                                        matched++;
                        }
                add += n - 1 - matched;
                add += m - withV - matched;
                return add;
        }
        
        boolean dfs(int v) {
                if (used[v])
                        return false;
                used[v] = true;
                for (int to : g[v])
                        if (to != stop && y[to] == -1) {
                                x[v] = to;
                                y[to] = v;
                                return true;
                        }
                for (int to : g[v])
                        if (to != stop && dfs(y[to])) {
                                x[v] = to;
                                y[to] = v;
                                return true;
                        }
                return false;
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