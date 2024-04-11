import java.io.*;
import java.util.*;

public class A {

	void submit() {
		int h = nextInt();
		int[] a = new int[h + 1];
		int two = 0;
		for (int i = 0; i <= h; i++) {
			a[i] = nextInt();
		}

		int bad = -1;
		for (int i = 0; i < h; i++) {
			if (a[i] > 1 && a[i + 1] > 1) {
				bad = i;
				break;
			}
		}

		if (bad == -1) {
			out.println("perfect");
			return;
		}

		out.println("ambiguous");
		// to last always
		int what = 0;
		for (int i = 0; i <= h; i++) {
			for (int j = 0; j < a[i]; j++) {
				out.print(what + " ");
			}
			what += a[i];
		}
		out.println();

		what = 0;
		for (int i = 0; i <= h; i++) {
			if (i != bad + 1) {
				for (int j = 0; j < a[i]; j++) {
					out.print(what + " ");
				}
			} else {
				for (int j = 0; j < a[i] - 1; j++) {
					out.print(what + " ");
				}
				out.print(what - 1 + " ");
			}
			what += a[i];
		}
		out.println();
		
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
		// stress();
		// test();
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