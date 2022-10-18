import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int[] a = new int[4];
		for (int i = 0; i < 4; i++) {
			a[i] = nextInt();
		}

		arifm: do {
			for (int i = 1; i < 3; i++) {
				if (2 * a[i] != a[i - 1] + a[i + 1]) {
					break arifm;
				}
			}
			out.println(2 * a[3] - a[2]);
			return;
		} while (false);

		geom: do {
			if (a[0] == 0)
				break geom;
			for (int i = 0; i < 3; i++) {
				if (a[i] == a[i + 1])
					break geom;
			}
			for (int i = 1; i < 3; i++) {
				if (a[i] * a[i] != a[i - 1] * a[i + 1]) {
					break geom;
				}
			}
			int num = a[3] * a[3];
			int denom = a[2];
			if (num % denom != 0)
				break geom;
			out.println(num / denom);
			return;
		} while (false);
		
		out.println(42);
	}

	A() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new A();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return null;
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			eof = true;
			return null;
		}
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}