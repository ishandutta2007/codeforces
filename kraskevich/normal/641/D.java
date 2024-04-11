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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {

    double solve(double A, double B, double C) {
        double D = Math.max(0.0, B * B - 4 * A * C);
        return  (-B + Math.sqrt(D)) / (2 * A);
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        double[] min = new double[n];
        double[] max = new double[n];
        for (int i = 0; i < n; i++)
            max[i] = in.nextDouble();
        for (int i = 0; i < n; i++)
            min[i] = in.nextDouble();
        double s1 = 0;
        double s2 = 0;
        double[] ans1 = new double[n];
        double[] ans2 = new double[n];
        for (int i = 0; i < n; i++) {
            double x1 = solve(1, -(s2 - s1 + min[i] + max[i]), -s1 * (min[i] + max[i]) + max[i]);
            double x2 = min[i] + max[i] - x1;
            s1 += x1;
            s2 += x2;
            ans1[i] = x1;
            ans2[i] = x2;
        }
        for (int i = 0; i < ans1.length; i++)
            out.printf("%.10f ", Math.max(0.0, ans1[i]));
        out.println();
        for (int i = 0; i < ans2.length; i++)
            out.printf("%.10f ", Math.max(0.0, ans2[i]));
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

    public double nextDouble() {
        return Double.parseDouble(next());
    }

}