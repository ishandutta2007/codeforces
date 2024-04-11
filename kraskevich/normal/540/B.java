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
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        int p = in.nextInt();
        int x = in.nextInt();
        int y = in.nextInt();
        int[] a = new int[n];
        int median = 0;
        for (int i = 0; i < k; i++) {
            a[i] = in.nextInt();
            if (a[i] >= y)
                median++;
        }
        int want = n / 2 + 1;
        if (want - median > n - k) {
            out.println(-1);
            return;
        }
        for (int i = k; i < k + want - median; i++)
            a[i] = y;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0)
                a[i] = 1;
            sum += a[i];
        }
        if (sum > x) {
            out.println(-1);
            return;
        }
        for (int i = k; i < n; i++)
            out.print(a[i] + " ");
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