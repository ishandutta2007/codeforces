import java.io.*;
import java.util.*;

public class E {

	void submit() {
		int n = nextInt();
		long[] a = new long[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextLong();
		}
		
		TreeMap<Long, Long> map = new TreeMap<>();
		map.put(a[0], 0L);
		
		for (int i = 1; i < n; i++) {
			long x = a[i];
			while (true) {
				Map.Entry<Long, Long> top = map.lastEntry();
				long r = top.getKey();
				long add = top.getValue();
				if (r <= x) {
					break;
				}
				map.pollLastEntry();
				long quo = r / x;
				long rem = r % x;
				
				map.merge(x, add + i * x * (quo - 1), Long::max);
				if (rem > 0) {
					map.merge(rem, add + i * x * quo, Long::max);
				}
			}
		}
		
		long ans = 0;
		for (Map.Entry<Long, Long> e : map.entrySet()) {
			ans = Math.max(ans, (e.getKey() - 1) * n + e.getValue());
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
		//stress();
		//test();
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