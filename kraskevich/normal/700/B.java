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

    ArrayList<Integer>[] g;
    long[] size;
    boolean[] was;
    boolean[] has;
    long res;
    int k;
    
    void dfs(int v) {
        was[v] = true;
        size[v] = has[v] ? 1 : 0;
        ArrayList<Integer> kids = new ArrayList<>();
        for (int to : g[v])
            if (!was[to]) {
                dfs(to);
                size[v] += size[to];
                kids.add(to);
            }
        for (int to : kids) {
            long low = k - size[to];
            long high = size[to];
            res += Math.min(low, high);
        }
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        k = in.nextInt();
        g = new ArrayList[n];
        for (int i = 0; i < n; i++)
            g[i] = new ArrayList<>();
        size = new long[n];
        has = new boolean[n];
        was = new boolean[n];
        k *= 2;
        for (int i = 0; i < k; i++) {
            int v = in.nextInt() - 1;
            has[v] = true;
        }
        for (int i = 0; i < n - 1; i++) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            g[a].add(b);
            g[b].add(a);
        }
        dfs(0);
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