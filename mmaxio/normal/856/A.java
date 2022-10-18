import java.io.*;
import java.util.*;

public class A {

	static final int N = 1_000_001;
	static final int ATTEMPTS = 2;

	boolean go(int ptr, int[] b, boolean[] bad) {
		if (ptr == b.length) {
			return true;
		}
		outer: for (int z = 0; z < ATTEMPTS; z++) {
			b[ptr] = rand(1, N - 1);

			for (int i = 0; i < ptr; i++) {
				if (bad[Math.abs(b[ptr] - b[i])]) {
					continue outer;
				}
			}

			if (go(ptr + 1, b, bad)) {
				return true;
			}
		}
		return false;
	}

	int[] solve(int[] a) {
		boolean[] bad = new boolean[N];
		int n = a.length;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				bad[Math.abs(a[i] - a[j])] = true;
			}
		}
		bad[0] = true;

		int[] b = new int[n];
		if (go(0, b, bad)) {
			return b;
		} else {
			return null;
		}
	}

	void submit() {
		int t = nextInt();
		while (t-- > 0) {
			int n = nextInt();
			int[] a = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = nextInt();
			}
			Arrays.sort(a);

			int[] b = solve(a);
			if (b == null) {
				out.println("NO");
			} else {
				out.println("YES");
				for (int x : b) {
					out.print(x + " ");
				}
				out.println();
			}
		}
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {
		int[] a = new int[100];
		for (int i = 0; i < a.length; i++) {
			a[i] = i + 1;
		}
		System.err.println(Arrays.toString(solve(a)));
	}

	A() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		 submit();
		// stress();
//		test();
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