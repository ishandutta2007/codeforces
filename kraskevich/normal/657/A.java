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
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int d = in.nextInt();
        int h = in.nextInt();
        if (d < h || d > 2 * h) {
            out.println(-1);
            return;
        }
        if (h == 1) {
            if (n != 2 && d == 1 || n == 2 && d == 2) {
                out.println(-1);
                return;
            }
            for (int i = 2; i <= n; i++)
                out.println(i + " " + 1);
            return;
        }
        if (n < d + 1) {
            out.println(-1);
            return;
        }
        for (int i = 2; i <= h + 1; i++)
            out.println((i - 1) + " " + i);
        int v = 1;
        for (int i = h + 2; i <= d + 1; i++) {
            out.println(v + " " + i);
            v = i;
        }
        for (int i = d + 2; i <= n; i++)
            out.println(2 + " " + i);
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