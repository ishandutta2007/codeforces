import java.io.*;
import java.util.*;

public class E {

	static final int P = 1_000_000_007;

	void submit() {
		int n = nextInt();
		int k = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}

		int[] b = new int[n + 1];
		b[0] = 1;

		for (int c : a) {
			for (int i = n; i > 0; i--) {
				b[i] = (int) ((long) b[i] * c % P) - b[i - 1];
				if (b[i] < 0) {
					b[i] += P;
				}
			}
			b[0] = (int) ((long) b[0] * c % P);
		}

		int invN = inv(n);

		int ans = 0;

		int coef = 1;

		for (int j = 1; j <= n && j <= k; j++) {
			coef = (int) ((long) coef * (k - j + 1) % P * invN % P);
			ans -= (int)((long)coef * b[j] % P);
			if(ans < 0) {
				ans += P;
			}
		}
		
		out.println(ans);

	}

	int inv(int x) {
		return x == 1 ? 1 : (P - (int) ((long) (P / x) * inv(P % x) % P));
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