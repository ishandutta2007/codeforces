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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {

    int getPow(int base, int n) {
        int res = 1;
        for (int i = 0; i < n; i++)
            res *= base;
        return res;
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        int cur = k;
        ArrayList<Integer> factors = new ArrayList<>();
        ArrayList<Integer> degs = new ArrayList<>();
        for (int i = 2; i * i <= k; i++) {
            if (cur % i == 0) {
                int deg = 0;
                while (cur % i == 0) {
                    cur /= i;
                    deg++;
                }
                factors.add(i);
                degs.add(deg);
            }
        }
        if (cur > 1) {
            factors.add(cur);
            degs.add(1);
        }
        for (int i = 0; i < n; i++) {
            int c = in.nextInt();
            for (int j = 0; j < factors.size(); j++) {
                if (c % getPow(factors.get(j), degs.get(j)) == 0)
                    degs.set(j, 0);
            }
        }
        for (int d : degs) {
            if (d > 0) {
                out.println("No");
                return;
            }
        }
        out.println("Yes");
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