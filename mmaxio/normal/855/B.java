import java.io.*;
import java.util.*;

public class B {

	void submit() {
		int n = nextInt();
		long p = nextInt();
		long q = nextInt();
		long r = nextInt();
		long[] a = new long[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextLong();
		}
		
		long[] minSuff = new long[n + 1];
		long[] maxSuff = new long[n + 1];
		long[] minPref = new long[n + 1];
		long[] maxPref = new long[n + 1];
		minPref[0] = Long.MAX_VALUE;
		maxPref[0] = Long.MIN_VALUE;
		for (int i = 0; i < n; i++) {
			minPref[i + 1] = Math.min(minPref[i], a[i]);
			maxPref[i + 1] = Math.max(maxPref[i], a[i]);
		}
		
		minSuff[n] = Long.MAX_VALUE;
		maxSuff[n] = Long.MIN_VALUE;
		for (int i = n - 1; i >= 0; i--) {
			minSuff[i] = Math.min(minSuff[i + 1], a[i]);
			maxSuff[i] = Math.max(maxSuff[i + 1], a[i]);
		}
		
		long ans = Long.MIN_VALUE;
		
		for (int j = 0; j < n; j++) {
			long cur = q * a[j];
			cur += Math.max(p * minPref[j + 1], p * maxPref[j + 1]);
			cur += Math.max(r * minSuff[j], r * maxSuff[j]);
			ans = Math.max(ans, cur);
		}
		
		out.println(ans);
		
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	B() throws IOException {
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
		new B();
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