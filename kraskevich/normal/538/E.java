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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {

    final int INF = 1_000_000;
    ArrayList<Integer>[] g;
    int[] dpBig;
    int[] dpSmall;
    int leaves;

    void dfs(int v, int h) {
        if (g[v].size() == 0) {
            leaves++;
            dpBig[v] = 1;
            dpSmall[v] = 1;
            return;
        }
        int totBig = 0;
        int minBig = INF;
        int totSmall = 0;
        int minSmall = INF;
        for (int to : g[v]) {
            dfs(to, h + 1);
            totBig += dpBig[to];
            minBig = Math.min(minBig, dpBig[to]);
            totSmall += dpSmall[to];
            minSmall = Math.min(minSmall, dpSmall[to]);
        }
        if (h % 2 == 0) {
            dpBig[v] = minBig;
            dpSmall[v] = totSmall;
        } else {
            dpSmall[v] = minSmall;
            dpBig[v] = totBig;
        }
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        g = new ArrayList[n];
        for (int i = 0; i < n; i++)
            g[i] = new ArrayList<>();
        dpBig = new int[n];
        dpSmall = new int[n];
        for (int i = 0; i < n - 1; i++) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            g[a].add(b);
        }
        dfs(0, 0);
        out.println(leaves - dpBig[0] + 1);
        out.println(dpSmall[0]);
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