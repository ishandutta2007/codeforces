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

    boolean check(int len, int cnt, int period) {
        int high = len / cnt;
        int low = len / (cnt + 1);
        if (len % (cnt + 1) != 0)
            low++;
        int d = low;
        if (d % period != 0)
            d = d - d % period + period;
        return d >= low && d <= high;
    }

    StringBuilder calc(char[] s, int cnt) {
        int n = s.length;
        int k = 0;
        int[] p = new int[n];
        StringBuilder res = new StringBuilder(n);
        if (cnt == 1)
            res.append('1');
        else
            res.append('0');
        for (int i = 1; i < n; i++) {
            while (k > 0 && s[i] != s[k])
                k = p[k - 1];
            if (s[i] == s[k])
                k++;
            p[i] = k;
            boolean ok = check(i + 1, cnt, i - p[i] + 1);
            if (ok)
                res.append('1');
            else
                res.append('0');
        }
        return res;
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        char[] s = in.next().toCharArray();
        StringBuilder sb = calc(s, k);
        out.println(sb.toString());
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

    public int nextInt() {
        return Integer.parseInt(next());
    }

}