import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;


public class Main {
	
	int n;

	BigInteger parentToMe[];
	BigInteger meToParent[];
	BigInteger other[];

	boolean visited[];
	boolean e[][];

	void dfs(int x) {
		visited[x] = true;
		BigInteger dp[] = new BigInteger[n + 1];
		for (int i = 1; i <= n; ++i)
			dp[i] = BigInteger.ZERO;
		dp[0] = BigInteger.ONE;
		int sons = 0;
		int myParent = -1;
		for (int i = 0; i < n; ++i) {
			if (!visited[i] && e[x][i]) {
				dfs(i);
				for (int j = sons; j >= 0; --j) {
					BigInteger prop1 = dp[j].multiply(meToParent[i]);
					BigInteger prop2 = dp[j + 1].multiply(other[i]);
					if (prop1.compareTo(prop2) == 1)
						dp[j + 1] = prop1;
					else
						dp[j + 1] = prop2;
				}
				dp[0] = dp[0].multiply(other[i]);
				++sons;
			} else if (e[x][i])
				myParent = i;
		}
		meToParent[x] = dp[0];
		parentToMe[x] = other[x] = BigInteger.ZERO;
		for (int i = 0; i <= sons; ++i) {
			BigInteger prop1 = dp[i].multiply(BigInteger.valueOf(i + 2));
			BigInteger prop2 = dp[i].multiply(BigInteger.valueOf(i + 1));
			if (prop1.compareTo(parentToMe[x]) == 1)
				parentToMe[x] = prop1;
			if (prop2.compareTo(other[x]) == 1)
				other[x] = prop2;
		}
		for (int i = 0; i < n; ++i) {
			if (e[x][i] && i != myParent) {
				BigInteger prop = dp[0].divide(other[i]).multiply(parentToMe[i]);
				if (prop.compareTo(other[x]) == 1)
					other[x] = prop;
			}
		}
	}
	
	void work() {
		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		if (n == 1) {
			System.out.println(1);
			return;
		}
		visited = new boolean[n];
		Arrays.fill(visited, false);
		e = new boolean[n][n];
		parentToMe = new BigInteger[n];
		meToParent = new BigInteger[n];
		other = new BigInteger[n];
		for (int i = 0; i < n; ++i)
			Arrays.fill(e[i], false);
		for (int i = 1; i < n; ++i) {
			int a = in.nextInt();
			int b = in.nextInt();
			--a;
			--b;
			e[a][b] = e[b][a] = true;
		}
		dfs(1);
		System.out.println(other[1]);
	}

	public static void main(String[] args) {
		(new Main()).work();
	}

}