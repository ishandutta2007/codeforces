import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int q = nextInt();
		
		int p0 = 0;
		int p1 = 1;
		
		while (q-- > 0) {
			int type = nextInt();
			if (type == 1) {
				int shift = nextInt();
				p0 = (p0 + shift + n) % n;
				p1 = (p1 + shift + n) % n;
			} else {
				p0 ^= 1;
				p1 ^= 1;
			}
		}
		
		int[] ans = new int[n];
		for (int i = 0, j = p0; i < n; i += 2) {
			ans[j] = i;
			j = (j + 2) % n;
		}
		
		for (int i = 1, j = p1; i < n; i += 2) {
			ans[j] = i;
			j = (j + 2) % n;
		}
		
		for (int x : ans) {
			out.print(x + 1 + " ");
		}
		out.println();
	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
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