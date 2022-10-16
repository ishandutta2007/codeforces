import java.util.*;
import java.io.*;

public class E157 {
	public static final int mod = 1000000007;
	private static BufferedReader in;
	private static PrintWriter out;
	
	private static long [][] dp;
	private static int N;

	public static void main(String[] args) throws IOException {
		in = new BufferedReader(new InputStreamReader (System.in));
		out = new PrintWriter(System.out, true);
		
		int T = Integer.parseInt (in.readLine ());
		
		dp = new long [2601][101];
		for (int i = 0; i <= 2600; i++)
			Arrays.fill (dp [i], -1);
		while (T-- > 0) {
			char [] c = in.readLine().toCharArray();
			N = c.length;
			
			int sumall = 0;
			for (char s : c)
				sumall += s - 'a';
			out.println (dfs (sumall, N) - 1);
		}
		
		out.close();
		System.exit(0);
	}
	
	private static long dfs (int cursum, int left) {
		if (left == 0) return cursum == 0 ? 1 : 0;
		if (dp [cursum][left] != -1) return dp [cursum][left];
		long ans = 0;
		for (int i = 0; i < Math.min (26, cursum + 1); i++)
			ans = (ans + dfs (cursum - i, left - 1)) % mod;
		return dp [cursum][left] = ans;
	}
}