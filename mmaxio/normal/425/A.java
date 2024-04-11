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
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}

		int ans = Integer.MIN_VALUE;

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j <= n; j++) {
				ans = Math.max(ans, go(a, i, j, k));
			}
		}

		out.println(ans);
	}

	int go(int[] a, int low, int high, int k) {
		int[] mid = Arrays.copyOfRange(a, low, high);
		int[] rest = new int[a.length - (high - low)];
		System.arraycopy(a, 0, rest, 0, low);
		System.arraycopy(a, high, rest, low, a.length - high);
		Arrays.sort(mid);
		Arrays.sort(rest);
		
		for (int i = 0; i < k; i++) {
			if (i < mid.length && i < rest.length && mid[i] < rest[rest.length - 1 - i]) {
				mid[i] = rest[rest.length - 1 - i];
			} else {
				break;
			}
		}
		int ret = 0;
		for (int i = 0; i < mid.length; i++) {
			ret += mid[i];
		}
		return ret;
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