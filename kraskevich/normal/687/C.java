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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        boolean[][] old = new boolean[k + 1][k + 1];
        boolean[][] now = new boolean[k + 1][k + 1];
        old[0][0] = now[0][0] = true;
        for (int i = 0; i < n; i++) {
            int c = in.nextInt();
            for (int s = 0; s <= k; s++)
                for (int r = 0; r <= k; r++) {
                    if (s + c <= k)
                        now[s + c][r] |= old[s][r];
                    if (r + c <= k)
                        now[s][r + c] |= old[s][r];
                }
            for (int s = 0; s <= k; s++)
                System.arraycopy(now[s], 0, old[s], 0, k + 1);
        }
        ArrayList<Integer> ans = new ArrayList<>();
        for (int i = 0; i <= k; i++)
            if (old[i][k - i])
                ans.add(i);
        out.println(ans.size());
        for (int v : ans)
            out.print(v + " ");
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