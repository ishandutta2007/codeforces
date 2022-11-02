import java.util.ArrayList;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.List;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Collections;
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

    boolean[] was;
    int[] p;
    ArrayList<Integer> cur;
    ArrayList<Integer> pos;
    ArrayList<Integer>[] g;

    void dfs(int v) {
        was[v] = true;
        pos.add(v);
        cur.add(p[v]);
        for (int to : g[v])
            if (!was[to])
                dfs(to);
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        p = new int[n];
        g = new ArrayList[n];
        for (int i = 0; i < n; i++)
            g[i] = new ArrayList<>();
        for (int i = 0; i < n; i++)
            p[i] = in.nextInt();
        for (int i = 0; i < m; i++) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            g[a].add(b);
            g[b].add(a);
        }
        was = new boolean[n];
        int[] ans = new int[n];
        for (int i = 0; i < n; i++)
            if (!was[i]) {
                cur = new ArrayList<>();
                pos = new ArrayList<>();
                dfs(i);
                Collections.sort(cur);
                Collections.reverse(cur);
                Collections.sort(pos);
                for (int j = 0; j < pos.size(); j++)
                    ans[pos.get(j)] = cur.get(j);
            }
        for (int v : ans)
            out.print(v + " ");
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