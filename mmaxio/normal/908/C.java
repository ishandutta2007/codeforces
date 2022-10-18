import java.io.*;
import java.util.*;

public class C {

	void submit() {
		int n = nextInt();
		int r = nextInt();
		int[] xs = new int[n];
		for (int i = 0; i < n; i++) {
			xs[i] = nextInt();
		}
		double[] ans = new double[n];
		for (int i = 0; i < n; i++) {
			ans[i] = r;
			for (int j = 0; j < i; j++) {
				int dx = Math.abs(xs[j] - xs[i]);
				if (dx > 2 * r) {
					continue;
				}
				double dy = Math.sqrt(4 * r * r - dx * dx);
				ans[i] = Math.max(ans[i], ans[j] + dy);
			}
		}
		
		for (double y : ans) {
			out.print(y + " ");
		}
	}

	void preCalc() {

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