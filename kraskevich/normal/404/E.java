import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
                char[] s = in.nextToken().toCharArray();
                int n  = s.length;
                if (s[n - 1] == 'L') {
                        for (int i = 0; i < n; i++)
                                if (s[i] == 'L')
                                        s[i] = 'R';
                                else
                                        s[i] = 'L';
                }
                int max = 0;
                int cur = 0;
                for (int i = 0; i < n; i++) {
                        if (s[i] == 'L')
                                cur--;
                        else
                                cur++;
                        if (i != n - 1)
                                max = Math.max(max, cur);
                }
                //out.println(cur + " " + max);
                //out.println(s);
                if (cur > max) {
                        out.println(1);
                        return;
                }
                int l = 1;
                int r = n;
                while (l < r) {
                        int m = (l + r + 1) / 2;
                        if (good(s, m))
                                l = m;
                        else
                                r = m - 1;
                }
                //out.println(good(s, 1));
                if (!good(s, l)) {
                        out.println(0);
                        return;
                }
                out.println(l);
        }

        boolean good(char[] s, int edge) {
                int max = 0;
                int cur = 0;
                for (int i = 0; i < s.length; i++) {
                        if (s[i] == 'L')
                                cur--;
                        else
                                cur++;
                        if (cur <= -edge)
                                cur = -edge + 1;
                        if (i != s.length - 1)
                                max = Math.max(max, cur);
                }
                return max < cur;
        }
}

class FastScanner {
        BufferedReader reader;
        StringTokenizer tokenizer;

        public FastScanner(InputStream inputStream)  {
                reader = new BufferedReader(new InputStreamReader(inputStream));
        }

        public String nextToken() {
                while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                        String line;
                        try {
                                line = reader.readLine();
                        } catch (IOException e) {
                                return null;
                        }
                        tokenizer = new StringTokenizer(line);
                }
                return tokenizer.nextToken();
        }

        }