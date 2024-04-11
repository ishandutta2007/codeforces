import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
                long n = in.nextLong();
                int m = in.nextInt();
                int[] mods = new int[18];
                mods[0] = 1;
                for (int i = 1; i < mods.length; i++)
                        mods[i] = mods[i - 1] * 10 % m;
                String val = Long.toString(n);
                int cnt = val.length();
                int[] digits = new int[cnt];
                for (int i = 0; i < cnt; i++)
                        digits[i] = val.charAt(i) - '0';
                long[][] dp = new long[1 << cnt][m];
                dp[0][0] = 1;
                for (int mask = 0; mask < (1 << cnt) - 1; mask++) {
                        int pos = Integer.bitCount(mask);
                        for (int curMod = 0; curMod < m; curMod++) {
                                if (dp[mask][curMod] == 0)
                                        continue;
                                for (int newPos = 0; newPos < cnt; newPos++) {
                                        if ((mask & (1 << newPos)) != 0)
                                                continue;
                                        if (digits[pos] == 0 && newPos == cnt - 1)
                                                continue;
                                        dp[mask | (1 << newPos)][(curMod + mods[newPos] * digits[pos]) % m] += 
                                                dp[mask][curMod];
                                }
                        }
                }
                long[] fact = new long[20];
                fact[0] = 1;
                for (int i = 1; i < 20; i++)
                        fact[i] = fact[i - 1] * i;
                int[] count = new int[10];
                for (int d : digits)
                        count[d]++;
                long res = dp[(1 << cnt) - 1][0];
                for (int d = 0; d < 10; d++)
                        res /= fact[count[d]];
                out.print(res);
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

        public int nextInt() {
                return Integer.parseInt(nextToken());
        }

        public long nextLong() {
                return Long.parseLong(nextToken());
        }

        }