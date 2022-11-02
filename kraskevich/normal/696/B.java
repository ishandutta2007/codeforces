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
    int[] size;
    double[] res;

    void dfs1(int v) {
        size[v] = 1;
        for (int to : g[v]) {
            dfs1(to);
            size[v] += size[to];
        }
    }

    void dfs2(int v, double curT) {
        res[v] = curT;
        for (int to : g[v])
            dfs2(to, curT + 0.5 * (size[v] - size[to] - 1) + 1.0);
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        g = new ArrayList[n];
        for (int i = 0; i < n; i++)
            g[i] = new ArrayList<>();
        size = new int[n];
        res = new double[n];
        for (int i = 1; i < n; i++) {
            int p = in.nextInt() - 1;
            g[p].add(i);
        }
        dfs1(0);
        dfs2(0, 1.0);
        for (int i = 0; i < n; i++)
            out.printf("%.10f ", res[i]);
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