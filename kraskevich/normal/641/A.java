import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.StringTokenizer;
import java.io.InputStream;
import java.io.InputStreamReader;

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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {

    int n;
    char[] dir;
    int[] len;
    boolean[] was;
    boolean outside;

    void dfs(int v) {
        if (was[v])
            return;
        was[v] = true;
        int d = dir[v] == '>' ? 1 : -1;
        int to = v + len[v] * d;
        if (to < 0 || to >= n) {
            outside = true;
            return;
        }
        dfs(to);
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        n = in.nextInt();
        dir = in.next().toCharArray();
        len = new int[n];
        for (int i = 0; i < n; i++)
            len[i] = in.nextInt();
        was = new boolean[n];
        dfs(0);
        if (outside)
            out.println("FINITE");
        else
            out.println("INFINITE");
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