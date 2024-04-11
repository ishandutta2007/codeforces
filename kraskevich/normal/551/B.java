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
        char[] a = in.next().toCharArray();
        char[] b = in.next().toCharArray();
        char[] c = in.next().toCharArray();
        long[] cntA = new long[26];
        for (int i = 0; i < a.length; i++)
            cntA[a[i] - 'a']++;
        long[] cntB = new long[26];
        for (int i = 0; i < b.length; i++)
            cntB[b[i] - 'a']++;
        long[] cntC = new long[26];
        for (int i = 0; i < c.length; i++)
            cntC[c[i] - 'a']++;
        int best = 0;
        for (int k = 0; k <= a.length; k++) {
            long[] cur = cntA.clone();
            int add = a.length;
            boolean ok = true;
            for (int ch = 0; ch < 26; ch++) {
                cur[ch] -= cntB[ch] * k;
                if (cur[ch] < 0)
                    ok = false;
                if (cntC[ch] > 0)
                    add = Math.min(add, (int) (cur[ch] / cntC[ch]));
            }
            if (ok)
                best = Math.max(best, k + add);
        }
        for (int k = 0; k <= a.length; k++) {
            long[] cur = cntA.clone();
            int add = a.length;
            boolean ok = true;
            for (int ch = 0; ch < 26; ch++) {
                cur[ch] -= cntB[ch] * k;
                if (cur[ch] < 0)
                    ok = false;
                if (cntC[ch] > 0)
                    add = Math.min(add, (int) (cur[ch] / cntC[ch]));
            }
            if (ok && add + k == best) {
                String B = new String(b);
                String C = new String(c);
                for (int ch = 0; ch < 26; ch++)
                    cur[ch] -= add * cntC[ch];
                for (int i = 0; i < k; i++)
                    out.print(B);
                for (int i = 0; i < add; i++)
                    out.print(C);
                for (int ch = 0; ch < 26; ch++)
                    for (int rep = 0; rep < cur[ch]; rep++)
                        out.print((char) (ch + 'a'));
                return;
            }
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
                }
            if (line == null)
                return null;
            tokenizer = new StringTokenizer(line);
        }
        return tokenizer.nextToken();
    }

}