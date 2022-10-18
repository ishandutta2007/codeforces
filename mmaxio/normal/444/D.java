import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int[] ADD = { 0, 26, 26 + 26 * 26, 26 + 26 * 26 + 26 * 26 * 26 };
	static final int N = 26 * 26 * 26 * 26 + 26 * 26 * 26 + 26 * 26 + 26;

	int[] cnt = new int[N];
	int[][] occ = new int[N][];

	static int hash(String s) {
		return hash(s, 0, s.length());
	}

	static int hash(String s, int l, int r) {
		int ret = 0;
		for (int i = l; i < r; i++) {
			ret = ret * 26 + s.charAt(i) - 'a';
		}
		return ADD[r - l - 1] + ret;
	}

	static final double LN2 = Math.log(2);

	int f(int st1, int len1, int st2, int len2) {
		return Math.max(st1 + len1, st2 + len2) - Math.min(st1, st2);
	}

	int go(int[] occ1, int len1, int[] occ2, int len2) {
		int ret = Integer.MAX_VALUE;
//		System.err.println(Arrays.toString(occ1) + " " + len1);
//		System.err.println(Arrays.toString(occ2) + " " + len2);
		// if (Math.log(occ2.length) / LN2 < 1 + occ2.length * 1.0 /
		// occ1.length) {
		for (int i = 0; i < occ1.length; i++) {
			int x1 = occ1[i];
			int pos = Arrays.binarySearch(occ2, x1);
			if (pos >= 0) {
				ret = Math.min(ret, f(x1, len1, occ2[pos], len2));
			} else {
				if (pos != -1) {
					ret = Math.min(ret, f(x1, len1, occ2[-pos - 2], len2));
				}
				if (pos != -occ2.length - 1) {
					ret = Math.min(ret, f(x1, len1, occ2[-pos - 1], len2));
				}
			}
		}
		// }
		return ret;
	}

	void solve() throws IOException {
		String s = nextToken();
		for (int len = 1; len <= 4; len++)
			for (int i = 0; i <= s.length() - len; i++) {
				cnt[hash(s, i, i + len)]++;
			}
		for (int i = 0; i < N; i++) {
			occ[i] = new int[cnt[i]];
		}
		Arrays.fill(cnt, 0);
		for (int len = 1; len <= 4; len++)
			for (int i = 0; i <= s.length() - len; i++) {
				int h = hash(s, i, i + len);
				occ[h][cnt[h]++] = i;
			}

		int q = nextInt();
		Map<Long, Integer> memo = new HashMap<Long, Integer>(q);
		while (q-- > 0) {
			String s1 = nextToken();
			int h1 = hash(s1);
			String s2 = nextToken();
			int h2 = hash(s2);
			if (occ[h1].length == 0 || occ[h2].length == 0) {
				out.println(-1);
				continue;
			}
			if (h1 > h2) {
				int tmp = h1;
				h1 = h2;
				h2 = tmp;
				String tmp1 = s1;
				s1 = s2;
				s2 = tmp1;
			}
			long val = (long) N * h1 + h2;
			if (memo.containsKey(val)) {
				out.println(memo.get(val));
				continue;
			}
			int[] occ1 = occ[h1];
			int[] occ2 = occ[h2];
			int res;
			if (occ1.length < occ2.length) {
				res = go(occ1, s1.length(), occ2, s2.length());
			} else {
				res = go(occ2, s2.length(), occ1, s1.length());
			}
			out.println(res);
			memo.put(val, res);
		}
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