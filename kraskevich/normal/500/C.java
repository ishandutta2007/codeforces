import java.util.Arrays;
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
        int m = in.nextInt();
        int[] w = new int[n];
        for (int i = 0; i < n; i++)
            w[i] = in.nextInt();
        int[] b = new int[m];
        for (int i = 0; i < m; i++)
            b[i] = in.nextInt();
        int[] pos = new int[n];
        Arrays.fill(pos, -1);
        int lastPos = 0;
        for (int i = 0; i < m; i++) {
            b[i]--;
            if (pos[b[i]] == -1)
                pos[b[i]] = lastPos++;
        }
        long res = 0;
        for (int i = 0; i < n; i++)
            if (pos[i] == -1)
                pos[i] = lastPos++;
        for (int i = 0; i < m; i++) {
            int p = pos[b[i]];
            for (int j = 0; j < n; j++)
                if (pos[j] < p) {
                    pos[j]++;
                    res += w[j];
                }
            pos[b[i]] = 0;
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