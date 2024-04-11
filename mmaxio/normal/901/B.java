import java.io.*;
import java.util.*;

public class B {

	int[] mult(int[] a, int[] b) {
		int[] c = new int[a.length + b.length - 1];
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < b.length; j++) {
				c[i + j] += a[i] * b[j];
				c[i + j] %= 2;
			}
		}
		return c;
	}

	int[] sum(int[] a, int[] b) {
		int[] c = new int[Math.max(a.length, b.length)];
		for (int i = 0; i < a.length; i++) {
			c[i] += a[i];
		}
		for (int i = 0; i < b.length; i++) {
			c[i] += b[i];
			c[i] %= 2;
		}
		return c;
	}

	static final int N = 151;


	void submit() {
		int[][] ps = new int[N + 1][];
		ps[0] = new int[] { 0 };
		ps[1] = new int[] { 1 };

		for (int i = 2; i < ps.length; i++) {
			ps[i] = mult(ps[i - 1], new int[] { 0, 1 });
			ps[i] = sum(ps[i], ps[i - 2]);
		}
		
		int x = nextInt();
		out.println(x);
		for (int i = 0; i <= x; i++) {
			out.print(ps[x + 1][i] + " ");
		}
		out.println();
		
		out.println(x - 1);
		for (int i = 0; i <= x - 1; i++) {
			out.print(ps[x][i] + " ");
		}
		out.println();
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