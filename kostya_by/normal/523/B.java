import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author kostya_by
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int t = in.nextInt();
        double c = in.nextDouble();
        long[] a = new long[n + 1];
        for (int i = 1; i <= n; i++) {
            a[i] = a[i - 1] + in.nextInt();
        }
        int m = in.nextInt();
        int[] p = new int[m + 1];
        for (int i = 1; i <= m; i++) {
            p[i] = in.nextInt();
        }

        double approx = 0.0;
        int ptr = 0;
        for (int i = 1; i <= n; i++ ) {
            approx = (approx + (a[i] - a[i - 1]) * 1.0 / t) / c;
            if (ptr < m && p[ptr + 1] == i) {
                ptr += 1;
                double real = (a[i] - a[i - t]) * 1.0 / t;
                double error = Math.abs(approx - real) / real;
                out.println(String.format("%.6f %.6f %.6f", real, approx, error));
            }
        }
    }
}

class InputReader {
    private final BufferedReader reader;
    private StringTokenizer tokenizer;

    public InputReader(InputStream in) {
        reader = new BufferedReader(new InputStreamReader(in));
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(readLine());
        }
        return tokenizer.nextToken();
    }

    public String readLine() {
        String line;
        try {
            line = reader.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        return line;
    }
}