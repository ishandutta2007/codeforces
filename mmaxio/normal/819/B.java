import java.io.*;
import java.util.*;

public class B {

	void submit() {
		int n = nextInt();
		int[] p = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = nextInt() - 1;
		}

		long[] delta = new long[n + 1];
		long initVal = 0;

		long[] justBonus = new long[n];

		for (int i = 0; i < n; i++) {
			int x = p[i];
			initVal += Math.abs(x - i);
			if (x >= i) {
				delta[0]--;
				delta[x - i] += 2;
			} else {
				delta[0]++;
				delta[n + x - i] += 2;
			}
			delta[n - i - 1] -= 2;

			// after n - i - 1 it goes around
			if (i != 0) {
				justBonus[n - i - 1] = Math.abs(x - 0) - Math.abs(x - (n - 1)) + 1;
			}
		}

		int ans = -1;
		long val = Long.MAX_VALUE;
		long deltaNow = 0;
		for (int i = 0; i < n; i++) {
			if (initVal < val) {
				val = initVal;
				ans = i;
			}
			deltaNow += delta[i];
			initVal += deltaNow;
			initVal += justBonus[i];
		}

		out.println(val + " " + ans);
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