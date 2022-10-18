import java.io.*;
import java.util.*;

public class C {

	void submit() {
		int n = nextInt();
		HashMap<Integer, Integer> map = new HashMap<>();
		while (n-- > 0) {
			int x = nextInt();
			
			for (int i = 2; i * i <= x; i++) {
				if (x % i == 0) {
					int key = i;
					int val = 0;
					while (x % i == 0) {
						x /= i;
						val++;
					}
					Integer prev = map.get(key);
					if (prev == null) {
						prev = 0;
					}
					map.put(key, prev | (1 << (val - 1)));
				}
			}
			
			if (x != 1) {
				Integer prev = map.get(x);
				if (prev == null) {
					prev = 0;
				}
				map.put(x, prev | 1);
			}
			
		}
		
		int xor = 0;
		for (int mask : map.values()) {
			
//			System.err.println(mask);
			xor ^= dfs(mask);
		}
		
		out.println(xor == 0 ? "Arpa" : "Mojtaba");
	}

	void preCalc() {

	}

	void stress() {

	}

	HashMap<Integer, Integer> memo = new HashMap<>();

	int dfs(int mask) {
		if (memo.containsKey(mask)) {
			return memo.get(mask);
		}

		long bs = 0;

		for (int move = 0;; move++) {

			int low = mask & ((1 << move) - 1);
			int high = mask >> move;

			if (high == 0) {
				break;
			}

			int to = low | (high >> 1);
			int val = dfs(to);
			if (val >= 63) {
				throw new AssertionError();
			}
			bs |= 1L << val;
		}
		
		int ret = Long.numberOfTrailingZeros(bs + 1);
		memo.put(mask, ret);
		return ret;
	}

	void testGrundy() {
		int N = 5;
		int[] gr = new int[1 << N];

		for (int mask = 1; mask < (1 << N); mask++) {

			HashSet<Integer> can = new HashSet<>();

			for (int move = 0; move < N; move++) {

				int low = mask & ((1 << move) - 1);
				int high = mask >> move;

				if (high == 0) {
					continue;
				}

				int to = low | (high >> 1);

				// System.err.println(toStr(mask) + " -> " + toStr(to));

				can.add(gr[to]);
			}

			while (can.contains(gr[mask])) {
				gr[mask]++;
			}

			System.err.println(toStr(mask) + ": " + gr[mask]);
		}

	}

	void testDfs() {
		// HashSet<Integer> vis = new HashSet<>();
		// dfs(rand(100_000_000, 1_000_000_000), vis);
		// System.err.println(vis.size());
	}

	String toStr(int mask) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < 20; i++) {
			if (test(mask, i)) {
				sb.append(i + 1);
				sb.append(" ");
			}
		}
		if (sb.length() == 0) {
			return "empty";
		}
		return sb.toString();
	}

	static final boolean test(int mask, int i) {
		return ((mask >> i) & 1) == 1;
	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
		// stress();
		// testGrundy();
		// for (int i = 0; i >= 0; i++) {
		// testDfs();
		// }
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