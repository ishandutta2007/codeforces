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
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        String s = in.next();
        int n = s.length();
        int mx = 0;
        for (int i = 0; i < n; i++)
            mx = Math.max(mx, s.charAt(i) - '0');
        String[] ans = new String[mx];
        for (int i = 0; i < mx; i++)
            ans[i] = "";
        for (int pos = 0; pos < n; pos++) {
            for (int j = 0; j < s.charAt(pos) - '0'; j++)
                ans[j] += '1';
            for (int j = s.charAt(pos) - '0'; j < mx; j++)
                ans[j] += '0';
        }
        out.println(mx);
        for (int i = 0; i < mx; i++) {
            while (ans[i].charAt(0) == '0')
                ans[i] = ans[i].substring(1);
            out.print(ans[i] + " ");
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
                // ignore
            }
            if (line == null)
                return null;
            tokenizer = new StringTokenizer(line);
        }
        return tokenizer.nextToken();
    }

}