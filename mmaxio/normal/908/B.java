import java.io.*;
import java.util.*;

public class B {

	void submit() {
		int r = nextInt();
		int c = nextInt();
		char[][] f = new char[r][];
		int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
		for (int i = 0; i < r; i++) {
			f[i] = nextToken().toCharArray();

			for (int j = 0; j < c; j++) {
				if (f[i][j] == 'S') {
					x1 = i;
					y1 = j;
					f[i][j] = '.';
				}
				if (f[i][j] == 'E') {
					x2 = i;
					y2 = j;
					f[i][j] = '.';
				}
			}
		}
		String ss = nextToken();
		int[] a = new int[ss.length()];
		for (int i = 0; i < ss.length(); i++) {
			a[i] = ss.charAt(i) - '0';
		}

		int[] p = { 0, 1, 2, 3 };
		int ans = 0;
		outer: do {
			int x = x1, y = y1;
			for (int d : a) {
				x += DX[p[d]];
				y += DY[p[d]];
				if (!(0 <= x && x < r && 0 <= y && y < c && f[x][y] == '.')) {
					continue outer;
				}
				if (x == x2 && y == y2) {
					ans++;
					continue outer;
				}
			}
		} while (nextPermutation(p));
		out.println(ans);
	}

	static final int[] DX = { -1, 0, 1, 0 };
	static final int[] DY = { 0, -1, 0, 1 };

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

	static boolean nextCombination(int[] a, int n) {
		int k = a.length;
		int ptr = k - 1;
		while (ptr >= 0 && a[ptr] == ptr - k + n) {
			ptr--;
		}
		if (ptr < 0) {
			return false;
		}
		a[ptr]++;
		for (int i = ptr + 1; i < k; i++) {
			a[i] = a[ptr] + i - ptr;
		}
		return true;
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