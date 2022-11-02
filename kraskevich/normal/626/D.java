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

    final int N = 10 * 1000 + 10;

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = in.nextInt();
        double[] w1 = new double[N];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (a[i] > a[j])
                    w1[a[i] - a[j]]++;
        double[] w2 = new double[N];
        for (int d1 = 1; d1 <= 5000; d1++)
            for (int d2 = 1; d2 <= 5000; d2++)
                w2[d1 + d2] += w1[d1] * w1[d2];
        double res = 0;
        for (int diff = 1; diff < N; diff++) {
            for (int d = diff + 1; d < N; d++)
                res += w2[diff] * w1[d];
        }
        double N = (long) n;
        double denom = N * N * N * (N - 1) * (N - 1) * (N - 1) / 8D;
        out.printf("%.10f%n", res / denom);
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