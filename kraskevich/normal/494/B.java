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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    final long MOD = 1_000_000_007;

    int[] getZ(String s) {
        int[] z = new int[s.length()];
        int l = 0;
        int r = 0;
        for (int i = 1; i < s.length(); i++) {
            if (i <= r)
                z[i] = Math.min(r - i + 1, z[i - l]);
            while (i + z[i] < s.length() && s.charAt(i + z[i]) == s.charAt(z[i]))
                z[i]++;
            if (i + z[i] - 1 > r) {
                r = i + z[i] - 1;
                l = i;
            }
        }
        return z;
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        String s = in.next();
        String t = in.next();
        int n = s.length();
        int m = t.length();
        long[] f = new long[n];
        long[] add = new long[n];
        int[] z = getZ(t + "#" + s);
        long curr = 0;
        long sumF = 0;
        long sumP = 0;
        for (int i = 0; i < s.length(); i++) {
            sumP = (sumP + 1) % MOD;
            sumF = (sumF + (i == 0 ? 0 : f[i - 1])) % MOD;
            long prev = (sumP + sumF) % MOD;
            if (z[i + m + 1] == m) {
                sumF = 0;
                sumP = 0;
                add[i + m - 1] = (add[i + m - 1] + prev) % MOD;
            }
            curr = (curr + add[i]) % MOD;
            f[i] = (curr + (i == 0 ? 0 : f[i - 1])) % MOD;
        }
        out.println(f[n - 1]);
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