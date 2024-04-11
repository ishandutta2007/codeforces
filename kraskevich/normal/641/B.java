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

    int n;
    int m;
    int[][] a;

    void shiftRow(int r) {
        int t = a[r][m - 1];
        for (int i = m - 1; i > 0; i--)
            a[r][i] = a[r][i - 1];
        a[r][0] = t;
    }

    void shiftCol(int c) {
        int t = a[n - 1][c];
        for (int i = n - 1; i > 0; i--)
            a[i][c] = a[i - 1][c];
        a[0][c] = t;
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        n = in.nextInt();
        m = in.nextInt();
        a = new int[n][m];
        int q = in.nextInt();
        int[] tq = new int[q];
        int[] rq = new int[q];
        int[] cq = new int[q];
        int[] xq = new int[q];
        for (int i = 0; i < q; i++) {
            tq[i] = in.nextInt();
            if (tq[i] == 1)
                rq[i] = in.nextInt();
            else if (tq[i] == 2)
                cq[i] = in.nextInt();
            else {
                rq[i] = in.nextInt();
                cq[i] = in.nextInt();
                xq[i] = in.nextInt();
            }
        }
        for (int i = q - 1; i >= 0; i--) {
            int t = tq[i];
            if (t == 1) {
                int r = rq[i];
                shiftRow(r - 1);
            } else if (t == 2) {
                int c = cq[i];
                shiftCol(c - 1);
            } else {
                int r = rq[i];
                int c = cq[i];
                int x = xq[i];
                r--;
                c--;
                a[r][c] = x;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                out.print(a[i][j] + " ");
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