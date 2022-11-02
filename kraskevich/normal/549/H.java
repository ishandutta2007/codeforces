import java.util.ArrayList;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.List;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Collections;
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
		TaskH solver = new TaskH();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskH {
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        long a = in.nextLong();
        long b = in.nextLong();
        long c = in.nextLong();
        long d = in.nextLong();
        long det = a * d - b * c;
        if (det == 0) {
            out.println(0);
            return;
        }
        double low = 0;
        double high = 1e18;
        for (int rep = 0; rep < 200; rep++) {
            double mid = (low + high) / 2;
            if (check(a, b, c, d, mid))
                high = mid;
            else
                low = mid;
        }
        out.printf("%.10f", high);
    }

    boolean check(double a, double b, double c, double d, double x) {
        ArrayList<Double> xs = new ArrayList<>();
        ArrayList<Double> ys = new ArrayList<>();
        xs.add((a - x) * (d - x));
        xs.add((a - x) * (d + x));
        xs.add((a + x) * (d - x));
        xs.add((a + x) * (d + x));
        ys.add((b - x) * (c - x));
        ys.add((b - x) * (c + x));
        ys.add((b + x) * (c - x));
        ys.add((b + x) * (c + x));
        Collections.sort(xs);
        Collections.sort(ys);
        double L1 = xs.get(0);
        double R1 = xs.get(3);
        double L2 = ys.get(0);
        double R2 = ys.get(3);
        return Math.min(R1, R2) >= Math.max(L1, L2);
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

    public long nextLong() {
        return Long.parseLong(next());
    }

}