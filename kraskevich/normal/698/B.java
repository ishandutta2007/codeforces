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
    int color[];
    boolean[] bad;

    void dfs(int v) {
        color[v] = 1;
        for (int to : g[v]) {
            if (color[to] == 1)
                bad[v] = true;
            else if (color[to] == 0)
                dfs(to);
        }
        color[v] = 2;
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        g = new ArrayList[n];
        bad = new boolean[n];
        for (int i = 0; i < n; i++)
            g[i] = new ArrayList<>();
        int[] p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = in.nextInt() - 1;
            g[i].add(p[i]);
        }
        color = new int[n];
        for (int i = 0; i < n; i++)
            if (color[i] == 0)
                dfs(i);
        int root = -1;
        for (int i = 0; i < n; i++)
            if (p[i] == i) {
                root = i;
                break;
            }
        if (root == -1) {
            for (int i = 0; i < n; i++)
                if (bad[i]) {
                    root = i;
                    break;
                }
        }
        if (root == -1)
            throw new AssertionError();
        int[] ans = new int[n];
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (bad[i]) {
                ans[i] = root;
                if (ans[i] != p[i])
                    cnt++;
            } else {
                ans[i] = p[i];
            }
        out.println(cnt);
        for (int i = 0; i < n; i++)
            out.print(ans[i] + 1 + " ");
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