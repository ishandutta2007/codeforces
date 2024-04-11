import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int N = 100_001;

	void solve() throws IOException {
		int n = nextInt();
		int[] cnt = new int[N];

		for (int i = 0; i < n; i++) {
			int x = nextInt();
			cnt[x]++;
		}

		int[] div = new int[N];
		for (int i = 1; i < N; i++)
			for (int j = i; j < N; j += i) {
				div[i] += cnt[j];
			}

		int ret = 1;
		for (int i = 2; i < N; i++) {
			ret = Math.max(ret, div[i]);
		}

		out.println(ret);
	}

	B() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B();
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