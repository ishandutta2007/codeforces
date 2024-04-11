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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    int n;
    String[] g;
    boolean[] was;
    ArrayList<Integer> cur;

    void dfs(int v) {
        was[v] = true;
        cur.add(v);
        for (int to = 0; to < g.length; to++)
            if (!was[to] && g[v].charAt(to) == '1')
                dfs(to);
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        n = in.nextInt();
        int[] p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = in.nextInt();
            p[i]--;
        }
        g = new String[n];
        for (int i = 0; i < n; i++)
            g[i] = in.next();
        was = new boolean[n];
        int[] res = new int[n];
        for (int i = 0; i < n; i++)
            if (!was[i]) {
                cur = new ArrayList<>();
                dfs(i);
                ArrayList<Integer> t = new ArrayList<>();
                for (int j = 0; j < cur.size(); j++)
                    t.add(p[cur.get(j)]);
                Collections.sort(cur);
                Collections.sort(t);
                /*for (int elem : cur)
                    System.err.print(elem + " ");
                System.err.println();
                for (int elem : t)
                    System.err.print(elem + " ");
                System.err.println();*/
                for (int j = 0; j < cur.size(); j++)
                    res[cur.get(j)] = t.get(j);
            }
        for (int v : res)
            out.print((v + 1) + " ");
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