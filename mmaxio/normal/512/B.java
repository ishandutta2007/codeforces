import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static int makeVal(int x) {
		int ret = 1;
		for (int i = 2; i * i <= x; i++) {
			if (x % i == 0) {
				ret *= i;
				while (x % i == 0) {
					x /= i;
				}
			}
		}
		if (x != 1) {
			ret *= x;
		}
		return ret;
	}

	void solve() throws IOException {
		int n = nextInt();
		int[] vals = new int[n];
		int[] costs = new int[n];
		for (int i = 0; i < n; i++) {
			vals[i] = makeVal(nextInt());
			
		}
		for (int i = 0; i < n; i++) {
			costs[i] = nextInt();
		}
		Map<Integer, Integer> cur = new HashMap<>();
		Map<Integer, Integer> next = new HashMap<>();

		cur.put(0, 0);
		for (int i = 0; i < n; i++) {
			next.clear();
			int x = vals[i];
			for (Map.Entry<Integer, Integer> e : cur.entrySet()) {
				update(next, e.getKey(), e.getValue());
				update(next, gcd(e.getKey(), x), e.getValue() + costs[i]);
			}
//			System.err.println(next);
			Map<Integer, Integer> tmp = cur;
			cur = next;
			next = tmp;
		}

		if (cur.containsKey(1)) {
			out.println(cur.get(1));
		} else {
			out.println(-1);
		}
	}

	static int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	void update(Map<Integer, Integer> map, int newK, int newVal) {
		Integer prev = map.get(newK);
		if (prev == null || prev > newVal) {
			prev = newVal;
		}
		map.put(newK, prev);
	}

	B() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B();
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