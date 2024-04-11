import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;


public class Main 
{
	static int mod = (int)1e9 + 7;
	static int INF = (int)1e9;
	
	Scanner in;
	PrintWriter out;
	
	int n;
	String str;
	int[][] eq_dp;
	
	public static void main(String[] args) 
	{
		new Main().run();
	}
	
	public void run()
	{
		in = new Scanner(System.in);
		out = new PrintWriter(System.out);
		solve();
		out.flush();
	}
	
	public void solve()
	{
		str = in.next();
		n = str.length();
		
		int[][] dp = new int[n][n];
		int[][] flag = new int[n][n];
		eq_dp = new int[n][n];
		
		//part0
		
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = 0; j < n; j++)
			{
				if (str.charAt(i) != str.charAt(j))
				{
					eq_dp[i][j] = 0;
					continue;
				}
				
				int cur_val = 1;
				if (j + 1 < n && i + 1 < n)
					cur_val += eq_dp[i + 1][j + 1];
				
				eq_dp[i][j] = cur_val;
			}
		}
		
		//part1
		
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				dp[i][j] = 0;
				flag[i][j] = 0;
			}
		}
		
		for (int i = 0; i < n; i++)
			dp[0][i] = 1;
		
		for (int i = 0; i < n; i++)
		{
			int cur_sum = 0;
			for (int j = i; j < n; j++)
			{
				cur_sum = add(cur_sum, flag[i][j]);
				dp[i][j] = add(dp[i][j], cur_sum);
				int cur_val = dp[i][j];
				
				if (j == n - 1 || str.charAt(j + 1) == '0')
					continue;
				
				int cur_len = j - i + 1;
				int k = j + cur_len;

				if (k >= n)
					continue;
				
				if (gr(i, j, j + 1, k))
					k++;
				
				if (k < n)
					flag[j + 1][k] = add(flag[j + 1][k], cur_val);
			}
		}
		
		int ans1 = 0;
		for (int i = 0; i < n; i++)
			ans1 = add(ans1, dp[i][n - 1]);
		
		//part2
		
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				dp[i][j] = INF;
				flag[i][j] = INF;
			}
		}
		
		for (int i = 0; i < n; i++)
			dp[0][i] = 1;
		
		for (int i = 0; i < n; i++)
		{
			int cur_min = INF;
			for (int j = i; j < n; j++)
			{
				cur_min = Math.min(cur_min, flag[i][j]);
				dp[i][j] = Math.min(dp[i][j], cur_min);
				int cur_val = dp[i][j];
				
				if (j == n - 1 || str.charAt(j + 1) == '0')
					continue;
				
				int cur_len = j - i + 1;
				int k = j + cur_len;

				if (k >= n)
					continue;
				
				if (gr(i, j, j + 1, k))
					k++;
				
				if (k < n)
					flag[j + 1][k] = Math.min(flag[j + 1][k], cur_val + 1);
			}
		}
		
		BigInteger ans2 = BigInteger.ZERO;
		BigInteger suf = BigInteger.ZERO;
		BigInteger pow2 = BigInteger.ONE;
		for (int i = n - 1; i >= 0; i--)
		{
			int cur_sign = (int)(str.charAt(i) - '0');
			suf = suf.add(BigInteger.valueOf(cur_sign).multiply(pow2));
			pow2 = pow2.multiply(BigInteger.valueOf(2));
			BigInteger cur_ans = suf.add(BigInteger.valueOf(dp[i][n - 1]));
			if (dp[i][n - 1] != INF && (ans2.equals(BigInteger.ZERO) || ans2.compareTo(cur_ans) > 0))
				ans2 = cur_ans;
		}
		
		out.println(ans1);
		ans2 = ans2.mod(BigInteger.valueOf(mod));
		out.println(ans2.toString());
	}
	
	int add(int a, int b)
	{
		int res = a + b;
		if (res >= mod)
			res -= mod;
		return res;
	}
	
	boolean gr(int a, int b, int c, int d)
	{		
		int len = b - a + 1;
		int dp_val = eq_dp[a][c];

		if (dp_val >= len)
			return false;
		
		char c1 = str.charAt(a + dp_val);
		char c2 = str.charAt(c + dp_val);
		return c1 > c2;
	}
	
	boolean slow_less(int a, int b, int c, int d)
	{
		return str.substring(a, b + 1).compareTo(str.substring(c, d + 1)) < 0;
	}
}