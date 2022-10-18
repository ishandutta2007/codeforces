import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final String DNA = "ACGT";

	void solve() throws IOException {
		int n = nextInt();
		int[] cnt = new int[4];
		char[] s = nextToken().toCharArray();
		for (char c : s) {
			cnt[DNA.indexOf(c)]++;
		}
		Arrays.sort(cnt);
		int p = 0;
		for (int i = 0; i < 4; i++) {
			if (cnt[i] == cnt[3]) {
				p++;
			}
		}
		long ret = 1;
		for (int i = 0; i < n; i++) {
			ret = ret * p % 1_000_000_007;
		}
		out.println(ret);
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