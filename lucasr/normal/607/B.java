import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] vals = new int[n];
		for (int i = 0; i < vals.length; i++) {
			vals[i] = sc.nextInt();
		}
		int[][] best = new int[n + 1][n + 1];
		for (int i = 0; i < n; i++) {
			best[i][i] = 0;
			best[i][i+1] = 1;
		}
		best[n][n] = 0;
		for (int len = 2; len <= n; len++) {
			for (int from = 0; from + len <= n; from++) {
				int to = from + len;
				best[from][to] = 1 + best[from + 1][to];
				if (vals[from] == vals[from + 1])
					best[from][to] = Math.min(best[from][to], 1 + best[from + 2][to]);
				for (int k = from + 2; k < to; k++) {
					if (vals[from] == vals[k]) {
						best[from][to] = Math.min(best[from][to], best[from + 1][k] + best[k + 1][to]);
					}
				}
			}
		}
		System.out.println(best[0][n]);
	}
}