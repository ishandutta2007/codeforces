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

    final int LIMIT = 10000;

    long gcd(long a, long b, long[] xy) {
        if (a == 0) {
            xy[0] = 0;
            xy[1] = 1;
            return b;
        }
        long[] xy0 = new long[2];
        long g = gcd(b % a, a, xy0);
        xy[0] = xy0[1] - (b / a) * xy0[0];
        xy[1] = xy0[0];
        return g;
    }

    long[] findSol(long A, long B, long C) {
        long[] xy = new long[3];
        long g = gcd(A, B, xy);
        if (C % g != 0)
            return null;
        xy[2] = g;
        xy[0] *= C / g;
        xy[1] *= C / g;
        return xy;
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        long c = in.nextLong();
        long hr = in.nextLong();
        long hb = in.nextLong();
        long cr = in.nextLong();
        long cb = in.nextLong();
        if (cr >= cb) {
            long t = hr;
            hr = hb;
            hb = t;
            t = cr;
            cr = cb;
            cb = t;
        }
        long res = 0;
        if (cb >= LIMIT) {
            for (long cntB = 0; cntB <= c / cb; cntB++) {
                long cntR = (c - cb * cntB) / cr;
                res = Math.max(res, cntR * hr + cntB * hb);
            }
        } else {
            for (int rep = 0; rep < 2; rep++) {
                long t = hr;
                hr = hb;
                hb = t;
                t = cr;
                cr = cb;
                cb = t;
                for (int mod = 0; mod < cb; mod++) {
                    long C = c - mod;
                    if (C <= 0)
                        continue;
                    long A = cr;
                    long B = cb;
                    long[] xy = findSol(A, B, C);
                    if (xy == null)
                        continue;
                    long x = xy[0];
                    long y = xy[1];
                    long g = xy[2];
                    if (x * A + y * B != C)
                        throw new AssertionError();
                    //System.err.println(x + " " + y + " " + C);
                    //System.err.println(A +  " " + B);
                    long stepX = B / g;
                    //System.err.println(stepX);
                    if (x >= 0) {
                        long maxStep = x / stepX;
                        long nx = x - maxStep * stepX;
                        long ny = (C - A * nx) / B;
                        if (nx >= 0 && ny >= 0) {
                            res = Math.max(res, nx * hr + ny * hb);
                        }
                    } else {
                        long minStep = Math.abs(x) / stepX;
                        long nx = x;
                        nx += minStep * stepX;
                        if (nx < 0)
                            nx += stepX;
                        long ny = (C - A * nx) / B;
                        if (nx >= 0 && ny >= 0) {
                            res = Math.max(res, nx * hr + ny * hb);
                        }
                    }
                }
            }
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

    public long nextLong() {
        return Long.parseLong(next());
    }

}