import java.io.*;
import java.util.*;

public class F {

	void submit() {
		int n = nextInt();
		int[] a = new int[n];
		int s = 0;
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
			s += a[i];
		}

		int[] b = new int[100001];
		b[1] = (int) ((long) (s - 1) * (s - 1) % P * inv(s) % P);
		for (int i = 2; i <= s && i < b.length; i++) {
			long tmp = 2L * b[i - 1] - (long)(s - 1) * inv(s - (i - 1)) - b[i - 2];
			b[i] = (int) Math.floorMod(tmp, P);
		}
		
		long ans = 0;
		for (int x : a) {
			ans += b[x];
		}
		
		out.println(ans % P);
	}

	static final int P = 1_000_000_007;

	static int inv(int x) {
		return x == 1 ? 1 : P - (int) ((long) (P / x) * inv(P % x) % P);
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	F() throws IOException {
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
		new F();
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