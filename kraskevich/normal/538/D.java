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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        char[][] c = new char[n][];
        for (int i = 0; i < n; i++)
            c[i] = in.next().toCharArray();
        boolean[][] good = new boolean[2 * n + 1][2 * n + 1];
        boolean[][] covered = new boolean[n][n];
        for (int dx = -n; dx <= n; dx++) {
            for (int dy = -n; dy <= n; dy++)
                if (dx != 0 || dy != 0)
                    good[dx + n][dy + n] = true;
        }
        for (int x = 0; x < n; x++)
            for (int y = 0; y < n; y++)
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < n; j++)
                        if (c[i][j] == '.' && c[x][y] == 'o')
                            good[i - x + n][j - y + n] = false;
        for (int x = 0; x < n; x++)
            for (int y = 0; y < n; y++)
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < n; j++)
                        if (c[x][y] == 'o' && good[i - x + n][j - y + n])
                            covered[i][j] = true;
        //out.println(Arrays.deepToString(good));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (c[i][j] == 'x' && !covered[i][j]) {
                    out.println("NO");
                    return;
                }
        out.println("YES");
        for (int i = 1; i < 2 * n; i++) {
            for (int j = 1; j < 2 * n; j++) {
                if (i == n && j == n)
                    out.print("o");
                else
                    out.print(good[i][j] ? 'x' : '.');
            }
            out.println();
        }
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