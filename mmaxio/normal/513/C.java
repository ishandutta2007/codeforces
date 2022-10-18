import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class C_bigint {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int N = 10002;

	void solve() throws IOException {
		int n = nextInt();
		int[] low = new int[n];
		int[] high = new int[n];

		BigInteger[] cache = new BigInteger[N];
		for (int i = 0; i < N; i++) {
			cache[i] = BigInteger.valueOf(i);
		}

		BigInteger totWays = cache[1];
		for (int i = 0; i < n; i++) {
			low[i] = nextInt();
			high[i] = nextInt() + 1;
			totWays = totWays.multiply(cache[high[i] - low[i]]);
		}

		BigInteger[] ways = new BigInteger[N];
		Arrays.fill(ways, cache[0]);

		for (int mask = 0; mask < (1 << n); mask++) {
			int btc = Integer.bitCount(mask);
			if (btc < 2) {
				continue;
			}
			for (int i = 0; i < N; i++) {
				BigInteger cur = cache[1];
				for (int j = 0; j < n; j++) {
					if (test(mask, j)) {
						cur = cur.multiply(cache[Math.max(
								high[j] - Math.max(low[j], i), 0)]);
					} else {
						cur = cur.multiply(cache[Math.max(Math.min(high[j], i)
								- low[j], 0)]);
					}
				}
				ways[i] = ways[i].add(cur);
			}
		}

		// System.err.println(Arrays.toString(ways));

		for (int i = 0; i < N - 1; i++) {
			ways[i] = ways[i].subtract(ways[i + 1]);
		}
		// double ret = 0;
		// for (int i = 0; i < N; i++) {
		// ret += 1.0 * ways[i] * i / totWays;
		// }
		// out.println(ret);
		BigInteger sum = cache[0];
		for (int i = 0; i < N; i++) {
			sum = sum.add(cache[i].multiply(ways[i]));
		}
		out.println(sum.doubleValue() / totWays.doubleValue());
	}

	boolean test(int mask, int i) {
		return ((mask >> i) & 1) == 1;
	}

	C_bigint() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C_bigint();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return null;
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			eof = true;
			return null;
		}
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}