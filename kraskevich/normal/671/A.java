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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int ax = in.nextInt();
        int ay = in.nextInt();
        int bx = in.nextInt();
        int by = in.nextInt();
        int tx = in.nextInt();
        int ty = in.nextInt();
        int n = in.nextInt();
        double[] distT = new double[n];
        double[] distA = new double[n];
        double[] distB = new double[n];
        double total = 0;
        TwoMin minA = new TwoMin();
        TwoMin minB = new TwoMin();
        for (int i = 0; i < n; i++) {
            int x = in.nextInt();
            int y = in.nextInt();
            distT[i] = dist(x, y, tx, ty);
            distA[i] = dist(x, y, ax, ay);
            distB[i] = dist(x, y, bx, by);
            minA.add(new Pair(-distT[i] + distA[i], i));
            minB.add(new Pair(-distT[i] + distB[i], i));
            total += 2 * distT[i];
        }
        double res = Math.min(total + minA.first.val, total + minB.first.val);
        if (n >= 2) {
            if (minA.first.index == minB.first.index) {
                res = Math.min(res, total + minA.first.val + minB.second.val);
                res = Math.min(res, total + minA.second.val + minB.first.val);
            } else {
                res = Math.min(res, total + minA.first.val + minB.first.val);
            }
        }
        out.printf("%.10f%n", res);
    }

    class Pair {
        double val;
        int index;

        Pair(double val, int index) {
            this.val = val;
            this.index = index;
        }
    }

    class TwoMin {
        Pair first;
        Pair second;

        void add(Pair newVal) {
            if (first == null) {
                first = newVal;
            } else if (first.val >= newVal.val) {
                second = first;
                first = newVal;
            } else if (second == null || second.val > newVal.val) {
                second = newVal;
            }
        }
    }

    double dist(long x1, long y1, long x2, long y2) {
        long dx = x1 - x2;
        long dy = y1 - y2;
        return Math.sqrt(dx * dx + dy * dy);
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