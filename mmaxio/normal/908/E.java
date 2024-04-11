import java.io.*;
import java.util.*;

public class E {

	static final int P = 1_000_000_007;

	void submit() {
		int m = nextInt();
		int n = nextInt();

		int[][] ways = new int[m + 10][];
		for (int i = 0; i < ways.length; i++) {
			ways[i] = new int[i + 1];
			ways[i][0] = ways[i][i] = 1;
			for (int j = 1; j < i; j++) {
				ways[i][j] = (ways[i - 1][j] + ways[i - 1][j - 1]) % P;
			}
		}

		int[] bell = new int[m + 1];
		bell[0] = 1;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j <= i; j++) {
				bell[i + 1] += (int) ((long) bell[j] * ways[i][j] % P);
				if (bell[i + 1] >= P) {
					bell[i + 1] -= P;
				}
			}
		}

		char[][] f = new char[n][];
		for (int i = 0; i < n; i++) {
			f[i] = nextToken().toCharArray();
		}
		
		HashMap<Long, Integer> map = new HashMap<>();
		
		for (int i = 0; i < m; i++) {
			long key = 0;
			for (int j = 0; j < n; j++) {
				key *= 2;
				if (f[j][i] == '1') {
					key++;
				}
			}
			map.merge(key, 1, Integer::sum);
		}
		
		int ans = 1;
		for (int size : map.values()) {
			ans = (int)((long)ans * bell[size] % P);
		}
		
		out.println(ans);
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	E() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
		// stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new E();
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