import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve(int n) {

		int initN = n;

		int[] ans = new int[n + 1];

		while (n > 0) {
			int mid = Integer.highestOneBit(n);
			int j = mid - 1;
			for (int i = mid; i <= n; i++, j--) {
				ans[i] = j;
				ans[j] = i;
			}
			n = j;
		}
		long res = 0;
		for (int i = 0; i <= initN; i++)
			res += i ^ ans[i];
		out.println(res);
		for (int i = 0; i <= initN; i++) {
			out.print(ans[i] + " ");
		}
		out.println();
	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve(nextInt());
		// for (int n = 1; n <= 20; n++) {
		// System.err.println(n);
		// solve(n);
		// }
		// solve(1);
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C();
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