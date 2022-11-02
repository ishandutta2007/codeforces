import java.util.Arrays;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {

    int res = Integer.MAX_VALUE;
    int resV = -1;
    int resU = -1;
    ArrayList<Integer>[] edges;
    int[] from;
    int[] to;
    int[] len;
    int[] parId;
    int[] tin;
    int timer;
    int[] dp;
    boolean[] was;
    int st;
    int term;

    void dfs(int v, int p, int deleted) {
        parId[v] = p;
        was[v] = true;
        tin[v] = timer++;
        dp[v] = tin[v];
        for (int id : edges[v]) {
            if (id == deleted)
                continue;
            int t = from[id] == v ? to[id] : from[id];
            if (t == v)
                continue;
            if (!was[t]) {
                dfs(t, id, deleted);
                dp[v] = Math.min(dp[v], dp[t]);
            } else if (id != p) {
                dp[v] = Math.min(dp[v], tin[t]);
            }
        }
    }

    int getOther(int v, int id) {
        return from[id] == v ? to[id] : from[id];
    }

    int getEdge() {
        int resId = -1;
        for (int v = term; v != st; v = getOther(v, parId[v]))
            if (dp[v] == tin[v] && (resId == -1 || len[resId] > len[parId[v]]))
                resId = parId[v];
        return resId;
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        st = in.nextInt() - 1;
        term = in.nextInt() - 1;
        parId = new int[n];
        was = new boolean[n];
        edges = new ArrayList[n];
        from = new int[m];
        to = new int[m];
        len = new int[m];
        dp = new int[n];
        tin = new int[n];
        for (int i = 0; i < n; i++)
            edges[i] = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            from[i] = in.nextInt() - 1;
            to[i] = in.nextInt() - 1;
            len[i] = in.nextInt();
            edges[from[i]].add(i);
            edges[to[i]].add(i);
        }
        dfs(st, -1, -1);
        if (!was[term]) {
            out.println(0);
            out.println(0);
            return;
        }
        int edge = getEdge();
        if (edge != -1) {
            res = len[edge];
            resV = edge;
        }
        ArrayList<Integer> toDelete = new ArrayList<>();
        for (int v = term; v != st; v = getOther(v, parId[v]))
            toDelete.add(parId[v]);
        for (int deleted : toDelete) {
            Arrays.fill(was, false);
            dfs(st, -1, deleted);
            edge = getEdge();
            if (edge != -1 && len[edge] + len[deleted] < res) {
                res = len[edge] + len[deleted];
                resV = edge;
                resU = deleted;
            }
        }
        if (res == Integer.MAX_VALUE) {
            out.println(-1);
            return;
        }
        out.println(res);
        int c = 1;
        if (resU != -1)
            c++;
        out.println(c);
        resU++;
        resV++;
        out.print(resV + " ");
        if (resU != 0)
            out.print(resU);
        out.println();
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