import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int[] f;

	int get(int v) {
		int ret = 0;
		for (int i = v; i >= 0; i = (i & (i + 1)) - 1) {
			ret += f[i];
		}
		return ret;
	}

	int get(int from, int to, int n) {
		while (from < 0) {
			from += n;
			to += n;
		}
		while (from >= n) {
			from -= n;
			to -= n;
		}

		if (to < n) {
			return get(to) - get(from - 1);
		} else {
			return get(to - n) + get(n - 1) - get(from - 1);
		}
	}
	
	void add(int to) {
		for (int i = to; i < f.length; i |= i + 1) {
			f[i]++;
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		
		if (2 * k > n) {
			k = n - k;
		}

		f = new int[n];

		long cur = 1;

		for (int i = 0; i < n; ) {
			int j = i + k;
			if (j >= n) {
				j -= n;
			}

			cur++;

			cur += get(i + 1, i + k - 1, n) + get(i - k + 1, i - 1, n);
			add(i);
			out.print(cur + " ");
			
			if (j == 0) {
				break;
			}
			i = j;
		}
		out.println();
	}

	D() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D();
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