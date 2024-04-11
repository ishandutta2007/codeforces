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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        String s = in.next();
        int n = s.length();
        for (int i = 0; i < n; i++)
            if (s.charAt(i) == '0') {
                out.println("YES");
                out.println("0");
                return;
            }
        for (int fst = 0; fst < n; fst++) {
            boolean[][] dp = new boolean[n + 1][8];
            int[][] par = new int[n + 1][8];
            boolean[][] take = new boolean[n + 1][8];
            dp[fst][(s.charAt(fst) - '0') % 8] = true;
            take[fst][(s.charAt(fst) - '0') % 8] = true;
            for (int i = fst + 1; i < n; i++)
                for (int mod = 0; mod < 8; mod++) {
                    int newMod = (s.charAt(i) - '0' + mod * 10) % 8;
                    if (dp[i - 1][mod]) {
                        dp[i][newMod] = true;
                        par[i][newMod] = mod;
                        take[i][newMod] = true;
                        dp[i][mod] = true;
                        par[i][mod] = mod;
                        take[i][mod] = false;
                    }
                }
            if (!dp[n - 1][0])
                continue;
            String res = "";
            int mod = 0;
            for (int pos = n - 1; pos >= fst; pos--) {
                if (take[pos][mod])
                    res = s.charAt(pos) + res;
                mod = par[pos][mod];
            }
            out.println("YES");
            out.println(res);
            return;
        }
        out.println("NO");
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

}