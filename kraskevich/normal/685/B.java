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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {

    final int LOG = 20;
    ArrayList<Integer>[] g;
    int[] sizes;
    int[][] go;
    int n;

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        n = in.nextInt();
        int q = in.nextInt();
        sizes = new int[n];
        go = new int[n][LOG];
        g = new ArrayList[n];
        for (int i = 0; i < n; i++)
            g[i] = new ArrayList<>();
        for (int i = 1; i < n; i++) {
            int par = in.nextInt() - 1;
            g[par].add(i);
        }
        dfs(0);
        for (int i = 0; i < q; i++) {
            int v = in.nextInt() - 1;
            out.println(getLowest(v) + 1);
        }
    }

    void dfs(int v) {
        sizes[v] = 1;
        int maxKid = -1;
        for (int to : g[v]) {
            dfs(to);
            if (maxKid == -1 || sizes[maxKid] < sizes[to])
                maxKid = to;
            sizes[v] += sizes[to];
        }
        if (maxKid == -1)
            maxKid = v;
        go[v][0] = maxKid;
        for (int h = 1; h < LOG; h++)
            go[v][h] = go[go[v][h - 1]][h - 1];
    }
    
    int getLowest(int v) {
        int cur = v;
        int all = sizes[v];
        for (int h = LOG - 1; h >= 0; h--) {
            int next = go[cur][h];
            int rest = all - sizes[next];
            if (rest * 2 <= all)
                cur = next;
        }
        return cur;
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