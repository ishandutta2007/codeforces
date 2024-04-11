import java.util.Arrays;
import java.util.Scanner;

public class F {
	static final long MOD = 1000000007;
	static int[] vals;
	static int n;
	static int[][][] table;
	static int calc(int from, int open, int maxImbalance) {
		if (from == n) return open == 0 ? 1 : 0;
		if (table[from][open][maxImbalance] != -1) return table[from][open][maxImbalance];
		long ans = 0;
		int cost = from + 1 < n ? vals[from + 1] - vals[from] : 0;
		if (maxImbalance >= open * cost) ans += calc(from + 1, open, maxImbalance - open * cost);
		if (maxImbalance >= (open + 1) * cost && open < n / 2) ans += calc(from + 1, open + 1, maxImbalance - (open + 1)  * cost);
		if (open > 0 && maxImbalance >= (open - 1) * cost) ans += open * (long)calc(from + 1, open - 1, maxImbalance - (open - 1)  * cost);
		if (open > 0 && maxImbalance >= open * cost) ans += open * (long)calc(from + 1, open, maxImbalance - open  * cost);
		ans %= MOD;
		return table[from][open][maxImbalance] = (int)ans;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		int k = sc.nextInt();
		vals = new int[n];
		for (int i = 0; i < vals.length; i++) {
			vals[i] = sc.nextInt();
		}
		Arrays.sort(vals);
		table = new int[n][n/2 + 1][k+1];
		for (int i = 0; i < table.length; i++) {
			for (int j = 0; j < table[i].length; j++) {
				for (int j2 = 0; j2 < table[i][j].length; j2++) {
					table[i][j][j2] = -1;
				}
			}
		}
		System.out.println(calc(0, 0, k));
	}
}