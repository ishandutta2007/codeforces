import java.io.*;
import java.util.*;

public class A {

	void submit() {
//		int[] dp = new int[100];
//		dp[0] = 1;
//		for (int i = 1; i < dp.length; i++) {
//			dp[i] += dp[i - 1];
//		}
//		for (int i = 2; i < dp.length; i++) {
//			dp[i] += dp[i - 2];
//		}
//		System.err.println(Arrays.toString(dp));
		int x = nextInt();
		out.println(2 * x - 1 + " " + 2);
		out.println("1 2");
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	A() throws IOException {
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
		new A();
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