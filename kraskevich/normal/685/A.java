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

    int n;
    int m;
    int[] digits;
    boolean[] was;
    int lenN;
    int lenM;
    int tot;

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        n = in.nextInt();
        m = in.nextInt();
        lenN = getDigits(n - 1);
        lenM = getDigits(m - 1);
        digits = new int[lenN + lenM];
        was = new boolean[7];
        go(0);
        out.println(tot);
    }

    void go(int pos) {
        if (pos == lenN + lenM) {
            int hours = evaluate(digits, 0, lenN);
            int minutes = evaluate(digits, lenN, lenM + lenN);
            if (hours < n && minutes < m) {
                tot++;
            }
            return;
        }
        for (int d = 0; d < 7; d++) {
            if (!was[d]) {
                digits[pos] = d;
                was[d] = true;
                go(pos + 1);
                was[d] = false;
            }
        }
    }

    int getDigits(int n) {
        int res = 0;
        while (n > 0) {
            n /= 7;
            res++;
        }
        if (res == 0)
            res++;
        return res;
    }

    int evaluate(int[] a, int l, int r) {
        int res = 0;
        for (int i = l; i < r; i++) {
            res = res * 7 + a[i];
        }
        return res;
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