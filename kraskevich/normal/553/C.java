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

    final long MOD = 1_000_000_000 + 7;

    ArrayList<Integer>[] g;
    ArrayList<Integer> badA = new ArrayList<>();
    ArrayList<Integer> badB = new ArrayList<>();
    boolean[] was;
    int[] compId;
    int curComp;
    ArrayList<Integer>[] gr;
    int[] color;
    boolean ok = true;

    void dfs(int v) {
        was[v] = true;
        compId[v] = curComp;
        for (int to : g[v])
            if (!was[to])
                dfs(to);
    }

    void dfsColor(int v, int col) {
        color[v] = col;
        for (int to : gr[v]) {
            if (color[to] != 0 && color[to] != other(col))
                ok = false;
            if (color[to] == 0)
                dfsColor(to, other(col));
        }
    }

    int other(int c) {
        if (c == 1)
            return 2;
        return 1;
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        g = new ArrayList[n];
        for (int i = 0; i < n; i++)
            g[i] = new ArrayList<>();
        was = new boolean[n];
        compId = new int[n];
        int m = in.nextInt();
        for (int i = 0; i < m; i++) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            int c = in.nextInt();
            if (c == 1) {
                g[a].add(b);
                g[b].add(a);
            } else {
                badA.add(a);
                badB.add(b);
            }
        }
        for (int i = 0; i < n; i++) {
            if (!was[i]) {
                dfs(i);
                curComp++;
            }
        }
        gr = new ArrayList[curComp];
        for (int i = 0; i < curComp; i++)
            gr[i] = new ArrayList<>();
        color = new int[curComp];
        long res = 1;
        for (int i = 0; i < badA.size(); i++) {
            int a = badA.get(i);
            int b = badB.get(i);
            a = compId[a];
            b = compId[b];
            gr[a].add(b);
            gr[b].add(a);
        }
        for (int i = 0; i < curComp; i++)
            if (color[i] == 0) {
                dfsColor(i, 1);
                if (i != 0)
                    res = (res * 2) % MOD;
                if (!ok)
                    res = 0;
            }
        out.println(res);
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