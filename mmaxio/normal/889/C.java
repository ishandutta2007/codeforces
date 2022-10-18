import java.io.*;
import java.util.*;

public class C {

	static final int P = 1_000_000_007;

	static boolean nextPermutation(int[] a) {
		int n = a.length;
		int ptr = n - 1;
		while (ptr > 0 && a[ptr - 1] >= a[ptr]) {
			ptr--;
		}

		for (int i = ptr, j = n - 1; i < j; i++, j--) {
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}

		if (ptr == 0) {
			return false;
		}

		for (int i = ptr;; i++) {
			if (a[ptr - 1] < a[i]) {
				int tmp = a[ptr - 1];
				a[ptr - 1] = a[i];
				a[i] = tmp;
				return true;
			}
		}
	}

	int slow(int n, int k) {
		int[] p = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = i;
		}
		int ans = 0;
		do {
			int m = 0;
			int offset = 0;
			for (int i = 0; i < n; ++i)
				if (m < p[i]) {
					m = p[i];
					offset = 0;
				} else {
					offset = offset + 1;
					if (offset == k)
						break;
				}
			ans += m == n - 1 ? 1 : 0;
		} while (nextPermutation(p));
		return ans;
	}

	void submit() {
		int n = nextInt();
		int k = nextInt();
		int[] a = new int[n + 1];
		a[0] = 1;
		for (int i = 1; i <= k && i <= n; i++) {
			a[i] = (int) ((long) (i + 1) * a[i - 1] % P);
		}

		if (n <= k) {
			out.println(0);
			return;
		}

		int mult = a[k - 1];

		for (int i = k + 1; i <= n; i++) {
			a[i] = (int) ((long) (i + 1) * a[i - 1] % P);
			a[i] -= (int) ((long) mult * a[i - k - 1] % P);
			if (a[i] < 0) {
				a[i] += P;
			}

			mult = (int) ((long) mult * i % P * inv(i - k) % P);
		}

		int fact = 1;
		for (int i = 1; i <= n; i++) {
			fact = (int) ((long) fact * i % P);
		}
		
		n--;

		fact -= a[n];
		if (fact < 0) {
			fact += P;
		}

		out.println(fact);
	}

	int inv(int x) {
		return x == 1 ? 1 : (P - (int) ((long) (P / x) * inv(P % x) % P));
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {
		int[] a = new int[11];
		a[0] = 1;
		a[1] = 2;
		a[2] = 6;
		for (int i = 3; i < a.length; i++) {
			a[i] = (i + 1) * a[i - 1] - (i - 1) * (i - 2) * a[i - 3];
		}
		System.err.println(Arrays.toString(a));

		a[0] = 1;
		a[1] = 2;
		a[2] = 6;
		a[3] = 24;
		for (int i = 4; i < a.length; i++) {
			a[i] = (i + 1) * a[i - 1] - (i - 1) * (i - 2) * (i - 3) * a[i - 4];
		}
		System.err.println(Arrays.toString(a));

		for (int n = 1; n <= 11; n++) {
			System.err.println(slow(n, 2) + " " + a[n]);
		}
	}

	C() throws IOException {
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