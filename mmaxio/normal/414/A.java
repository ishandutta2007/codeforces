import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();

		int m = n / 2;
		if (k < m) {
			out.println(-1);
			return;
		}
		
		if (m == 0) {
			if (k == 0) {
				out.println(1);
			} else {
				out.println(-1);
			}
			return;
		}

		int x = k / m;
		int big = k % m;
		int small = m - k % m;
		Set<Integer> used = new HashSet<>();
		for (int i = 0; i < small; i++) {
			int v1 = x * (2 * i + 1);
			int v2 = x * (2 * i + 2);
			out.print(v1 + " " + v2 + " ");
			used.add(v1);
			used.add(v2);
		}
		for (int i = 0, j = 1; i < big; i++) {
			int v1, v2;
			while (true) {
				v1 = (x + 1) * j;
				v2 = (x + 1) * (j + 1);
				if (used.contains(v1) || used.contains(v2)) {
					j++;
				} else {
					break;
				}
			}
			out.print(v1 + " " + v2 + " ");
			used.add(v1);
			used.add(v2);
		}

		if (n % 2 == 1) {
			int outp = 1;
			while (used.contains(outp)) {
				outp++;
			}
			out.println(outp);
		}
		out.println();
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