import java.util.ArrayList;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.StringTokenizer;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Igor Kraskevich
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
    int n;
    ArrayList<Integer>[] g;
    ArrayList<Integer>[] w;
    int[] cost;
    int[] from;
    int[] to;
    int[] par;
    int[] size;
    boolean[] was;
    double res = 0.0;

    long cnk(long n, long k) {
        if (k > n)
            return 0;
        if (k == 0)
            return 1;
        if (k == 1)
            return n;
        if (k == 2)
            return n * (n - 1) / 2;
        if (k == 3)
            return n * (n - 1) * (n - 2) / 3;
        return 0;
    }

    void dfs(int v, int p) {
        was[v] = true;
        par[v] = p;
        size[v] = 1;
        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v].get(i);
            if (!was[to]) {
                dfs(to, v);
                size[v] += size[to];
                int up = size[to];
                int down = n - up;
                long all = cnk(n, 3);
                long good = cnk(up, 2) * cnk(down, 1) + cnk(down, 2) * cnk(up, 1);
                res += good * 2.0 / all * 1.0 * w[v].get(i);
            }
        }
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        n = in.nextInt();
        from = new int[n - 1];
        to = new int[n - 1];
        was = new boolean[n];
        par = new int[n];
        size = new int[n];
        cost = new int[n - 1];
        g = new ArrayList[n];
        w = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            w[i] = new ArrayList<>();
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i < n - 1; i++) {
            from[i] = in.nextInt();
            to[i] = in.nextInt();
            cost[i] = in.nextInt();
            from[i]--;
            to[i]--;
            g[from[i]].add(to[i]);
            g[to[i]].add(from[i]);
            w[from[i]].add(cost[i]);
            w[to[i]].add(cost[i]);
        }
        dfs(0, 0);
        int q = in.nextInt();
        for (int i = 0; i < q; i++) {
            int v = in.nextInt();
            v--;
            int len = in.nextInt();
            int delta = cost[v] - len;
            int a = from[v];
            int b = to[v];
            if (par[a] == b) {
                int t = a;
                a = b;
                b = t;
            }
            cost[v] = len;
            long all = cnk(n, 3);
            int up = size[b];
            int down = n - size[b];
            long good = cnk(up, 2) * cnk(down, 1) + cnk(down, 2) * cnk(up, 1);
            res -= good * 2.0 / all * 1.0 * delta;
            out.printf("%.10f\n", 2 * res);
        }
    }
}

class FastScanner {
    private StringTokenizer tokenizer;
    private BufferedReader reader;

    public FastScanner(InputStream inputStream) {
        reader = new BufferedReader(new InputStreamReader(inputStream));
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            String line = null;
            try {
                line = reader.readLine();
            } catch (IOException e) {
                // ignore
            }
            if (line == null)
                return null;
            tokenizer = new StringTokenizer(line);
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

}