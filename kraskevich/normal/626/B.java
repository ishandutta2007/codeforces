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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {

    boolean[][][] was;

    void dfs(int a, int b, int c) {
        if (was[a][b][c])
            return;
        was[a][b][c] = true;
        if (a > 1)
            dfs(a - 1, b, c);
        if (b > 1)
            dfs(a, b - 1, c);
        if (c > 1)
            dfs(a, b, c - 1);
        if (a > 0 && b > 0)
            dfs(a - 1, b - 1, c + 1);
        if (a > 0 && c > 0)
            dfs(a - 1, b + 1, c - 1);
        if (b > 0 && c > 0)
            dfs(a + 1, b - 1, c - 1);
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        String s = in.next();
        int b = 0;
        int g = 0;
        int r = 0;
        for (int i = 0; i < n; i++) {
            switch (s.charAt(i)) {
                case 'B': b++; break;
                case 'G': g++; break;
                case 'R': r++; break;
            }
        }
        was = new boolean[n + 1][n + 1][n + 1];
        dfs(b, g, r);
        if (was[1][0][0])
            out.print('B');
        if (was[0][1][0])
            out.print('G');
        if (was[0][0][1])
            out.print('R');
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