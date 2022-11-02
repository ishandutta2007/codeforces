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

    boolean isBlack(boolean[][] a, int i, int j) {
        if (i < 0 || i >= a.length)
            return false;
        if (j < 0 || j >= a[0].length)
            return false;
        return a[i][j];
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        boolean[][] was = new boolean[n][m];
        int k = in.nextInt();
        int res = 0;
        for (int t = 0; t < k; t++) {
            int x = in.nextInt();
            int y = in.nextInt();
            x--;
            y--;
            was[x][y] = true;
            boolean bad = false;
            for (int i = x - 2; i <= x + 2; i++)
                for (int j = y - 2; j <= y + 2; j++)
                    if (isBlack(was, i, j) && isBlack(was, i + 1, j)
                            && isBlack(was, i, j + 1) && isBlack(was, i + 1, j + 1))
                        bad = true;
            if (bad) {
                res = t + 1;
                break;
            }
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