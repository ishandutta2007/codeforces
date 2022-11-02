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

    final long MOD = 1_000_000_000 + 7;

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        char[] p = in.next().toCharArray();
        int[] pos = new int[m];
        boolean[] have = new boolean[n];
        for (int i = 0; i < m; i++) {
            pos[i] = in.nextInt();
            pos[i]--;
            have[pos[i]] = true;
        }
        char[] s = new char[n];
        int last = 0;
        for (int i = 0; i < m; i++) {
            int st = pos[i];
            for (int j = Math.max(last, st); j < st + p.length; j++)
                s[j] = p[j - st];
            last = st + p.length;
        }
        int k = 0;
        long res = 1;
        String str = new String(p) + "#" + new String(s);
        int[] pref = new int[str.length()];
        for (int i = 1; i < str.length(); i++) {
            while (k > 0 && str.charAt(i) != str.charAt(k))
                k = pref[k - 1];
            if (str.charAt(i) == str.charAt(k))
                k++;
            pref[i] = k;
        }
        for (int i = 0; i < m; i++) {
            int st = pos[i];
            if (pref[p.length + 1 + st + p.length - 1] != p.length)
                res = 0;
        }
        for (int i = 0; i < n; i++)
            if (s[i] == 0)
                res = res * 26 % MOD;
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

    public int nextInt() {
        return Integer.parseInt(next());
    }

}