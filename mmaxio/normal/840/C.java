import java.io.*;
import java.util.*;

public class C {

	int removeSq(int x) {
		for (int i = 2; i * i <= x; i++) {
			while (x % (i * i) == 0) {
				x /= i * i;
			}
		}
		return x;
	}
	
	void submit() {
		int n = nextInt();
		HashMap<Integer, Integer> map = new HashMap<>();
		for (int i = 0; i < n; i++) {
			int x = removeSq(nextInt());
			map.merge(x, 1, Integer::sum);
		}
		
		int[] a = new int[map.size()];
		int ptr = 0;
		for (Integer x : map.values()) {
			a[ptr++] = x;
		}

		int ret = go(a);
		for (int x : a) {
			ret = (int)((long)ret * fact[x] % P);
		}
		
		out.println(ret);
	}
	
	int go(int[] a) {
		int[] dp = new int[a[0]];
		dp[a[0] - 1] = 1;

		int places = a[0] + 1;
		
		int toInsert = 0;
		for (int x : a) {
			toInsert += x;
		}
		toInsert -= a[0];

		for (int i =1; i < a.length; i++) {

			int here = a[i];
			if (here == 0) {
				continue;
			}

			int[] nxt = new int[dp.length + here];

			for (int wasSame = 0; wasSame < dp.length; wasSame++) {
				if (wasSame > toInsert) {
					continue;
				}
				if (dp[wasSame] == 0) {
					continue;
				}

				int wasDiff = places - wasSame;

				for (int runsSame = 0; runsSame <= wasSame && runsSame <= here; runsSame++) {
					for (int runsDiff = 0; runsDiff <= wasDiff && runsSame + runsDiff <= here; runsDiff++) {
						if (runsSame + runsDiff == 0) {
							continue;
						}
						int delta = (int) ((long) dp[wasSame]
								* ways[wasSame][runsSame] % P * ways[wasDiff][runsDiff]
								% P * ways[here - 1][runsSame + runsDiff - 1] % P);
						if (delta == 0) {
							continue;
						}
						int nxtIdx = (wasSame - runsSame) + (here - runsSame - runsDiff);
						nxt[nxtIdx] += delta;
						if (nxt[nxtIdx] >= P) {
							nxt[nxtIdx] -= P;
						}
					}
				}

			}

			dp = nxt;
			places += here;
			toInsert -= here;
		}
		
//		System.err.println(Arrays.toString(a) + " " + idx);
//		System.err.println(Arrays.toString(dp));
		return dp[0];
	}
	
	int[][] ways;
	int[] fact;
	static final int N = 350;
	static final int P = 1_000_000_007;

	void preCalc() {
		ways = new int[N][];
		for (int i = 0; i < N; i++) {
			ways[i] = new int[i + 1];
			ways[i][0] = ways[i][i] = 1;
			for (int j = 1; j < i; j++) {
				ways[i][j] = ways[i - 1][j] + ways[i - 1][j - 1];
				if (ways[i][j] >= P) {
					ways[i][j] -= P;
				}
			}
		}
		fact = new int[N];
		fact[0] = 1;
		for (int i = 1; i < N; i++) {
			fact[i] = (int)((long)fact[i - 1] * i % P);
		}
	}

	void stress() {

	}

	void test() {

	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
		//stress();
		//test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new C();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}