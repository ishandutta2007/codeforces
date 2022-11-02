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

    double v1;
    double v2;
    int cnt;
    double s;

    boolean can(double t) {
        double busDist = (s * v2 - t * v1 * v2) / (v2 - v1);
        double busX = busDist;
        double curTime = busDist / v2;
        for (int i = 1; i < cnt; i++) {
            double curX = curTime * v1;
            double extraTime = (busX - curX) / (v1 + v2);
            curTime += extraTime;
            curX = curTime * v1;
            curTime += busDist / v2;
            busX = curX + busDist;
        }
        return busX <= s;
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int l = in.nextInt();
        int v1 = in.nextInt();
        int v2 = in.nextInt();
        int k = in.nextInt();
        this.s = l;
        this.v1 = v1;
        this.v2 = v2;
        this.cnt = n / k;
        if (n % k != 0)
            this.cnt++;
        double L = 0.0;
        double R = s / v1;
        for (int i = 0; i < 100; i++) {
            double mid = (L + R) / 2;
            if (can(mid))
                R = mid;
            else
                L = mid;
        }
        out.printf("%.10f", R);
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