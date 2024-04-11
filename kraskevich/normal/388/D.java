import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
        long k;
        final long MOD = 1_000_000_007;
        long[][][] dp = new long[31][31][2];

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
                k = in.nextInt();
                for (int i = 0; i < 31; i++)
                        for (int j = 0; j < 31; j++)
                                Arrays.fill(dp[i][j], -1);
                out.println(getDp(30, 0, 0));
        }

        long getDp(int pos, int have, int less) {
                if (pos < 0)
                        return 1;
                if (dp[pos][have][less] != -1)
                        return dp[pos][have][less];
                long res = 0;
                if (less == 1) {
                        res += getDp(pos - 1, have, 1) * ways0(have);
                        res += getDp(pos - 1, have, 1) * ways1(have);
                        res += getDp(pos - 1, have + 1, 1);
                        res %= MOD;
                } else if (getBit(pos) == 1) {
                        res += getDp(pos - 1, have, 1) * ways0(have);
                        res += getDp(pos - 1, have, 0) * ways1(have);
                        res += getDp(pos - 1, have + 1, 0);
                        res %= MOD;
                } else {
                        res += getDp(pos - 1, have, 0) * ways0(have);
                        res %= MOD;
                }
                return dp[pos][have][less] = res;
        }

        long ways1(int have) {
                if (have == 0) 
                        return 0;
                return (1L << (have - 1)) % MOD;
        }
        
        
        long ways0(int have) {
                if (have == 0)
                        return 1;
                return (1L << (have - 1)) % MOD;        
        }

        int getBit(int pos) {
                return (k & (1L << pos)) == 0 ? 0 : 1;
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

        }