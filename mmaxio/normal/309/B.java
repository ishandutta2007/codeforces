import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int[] buildNext(int[] next, int iter) {
		int[] res = new int[next.length];
		for (int i = 0; i < res.length; i++)
			res[i] = i;
		while (iter != 0) {
			if ((iter & 1) == 1) {
				res = combine(res, next);
			}
			next = combine(next, next);
			iter >>= 1;
		}
		return res;
	}

	int[] combine(int[] a, int[] b) {
		int[] ret = new int[a.length];
		for (int i = 0; i < ret.length; i++) {
			if (a[i] == -1)
				ret[i] = -1;
			else if (b[a[i]] == -1)
				ret[i] = a[i];
			else
				ret[i] = b[a[i]];
		}
		return ret;
	}

	void solve() throws IOException {
		int n = nextInt();
		int r = nextInt();
		int c = nextInt() + 1;

		int[] st = new int[n + 1];
		int[] len = new int[n + 1];

		String s = nextString();

		for (int i = 0, j = 0; i < n; i++) {
			st[i] = j;
			while (j < s.length() && s.charAt(j) != ' ')
				j++;
			j++;
			len[i] = j - st[i];
		}

		st[n] = s.length() + 1;
		len[n] = c + 1;

		int[] next = new int[n + 1];
		for (int i = 0, j = 0, sum = 0; i < n; i++) {
			while (j <= n && sum <= c) {
				sum += len[j];
				j++;
			}
			if (j == i + 1) {
				next[i] = -1;
			} else {
				next[i] = j - 1;
			}
			sum -= len[i];
		}
		next[n] = n;

//		System.err.println(Arrays.toString(len));
//		System.err.println(Arrays.toString(next));

		int[] res = buildNext(next.clone(), r);

		int maxAns = -1;
		int maxSt = 0;

		for (int i = 0; i < n; i++) {
			if (res[i] - i > maxAns) {
				maxAns = res[i] - i;
				maxSt = i;
			}
		}

		for (int it = 0, now = maxSt; it < r; it++) {
			if (now == n || next[now] == -1) {
				break;
			}
			int to = next[now];
			out.println(s.substring(st[now], st[to] - 1));
			now = to;
		}
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