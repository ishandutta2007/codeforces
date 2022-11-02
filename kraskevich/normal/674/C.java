import java.util.Arrays;
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

    final double INF = 1e50;

    double[] frac;
    double[] sum;
    double[] W;
    double[] dp;
    
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        int[] t = new int[n];
        for (int i = 0; i < n; i++)
            t[i] = in.nextInt();
        W = new double[n + 1];
        sum = new double[n + 1];
        frac = new double[n + 1];
        for (int i = 0; i < n; i++) {
            W[i + 1] = W[i] + 1.0 / t[i];
            sum[i + 1] = sum[i] + t[i];
            frac[i + 1] = frac[i] + sum[i + 1] / t[i];
        }
        dp = new double[n + 1];
        Arrays.fill(dp, INF);
        dp[0] = 0;
        for (int i = 0; i < k; i++)
            dp = makeStep();
        out.printf("%.10f%n", dp[n]);
    }

    double[] makeStep() {
        int n = W.length - 1;
        double[] newDP  = new double[n + 1];
        Arrays.fill(newDP, INF);
        newDP[0] = 0;
        LineStack stack = new LineStack();
        for (int i = 0; i < n; i++) {
            stack.addLine(new Line(-sum[i], dp[i] - frac[i] + sum[i] * W[i]));
            newDP[i + 1] = stack.getBest(W[i + 1]) + frac[i + 1];
        }
        return newDP;
    }

    class Line {
        double K;
        double B;

        Line(double K, double B) {
            this.K = K;
            this.B = B;
        }

        double intersectionX(Line other) {
            return (other.B - B) / (K - other.K);
        }
    }

    class LineStack {

        ArrayList<Line> lines = new ArrayList<>();
        int first = 0;

        void addLine(Line newLine) {
            while (lines.size() >= 2) {
                Line p = lines.get(lines.size() - 1);
                Line pp = lines.get(lines.size() - 2);
                if (p.intersectionX(newLine) <= pp.intersectionX(newLine))
                    lines.remove(lines.size() - 1);
                else
                    break;
            }
            lines.add(newLine);
        }

        double getBest(double curX) {
            while (first < lines.size() - 1) {
                Line f = lines.get(first);
                Line ff = lines.get(first + 1);
                if (ff.K * curX + ff.B <= f.K * curX + f.B)
                    first++;
                else
                    break;
            }
            Line f = lines.get(first);
            return f.K * curX + f.B;
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