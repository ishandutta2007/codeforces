import java.io.*;
import java.util.*;

public class D_new {

	static final int INF = Integer.MAX_VALUE / 3;
	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static int[] buildSuffixArray(char[] s, int alphSize) {
		// sorts cyclic shifs, append a sentinel to the end if suffix array is
		// needed
		int n = s.length;
		int[] cnt = new int[Math.max(alphSize, n)];

		char minChar = (char) 255;
		for (int i = 0; i < n; i++) {
			if (s[i] < minChar) {
				minChar = s[i];
			}
		}

		for (int i = 0; i < n; i++) {
			cnt[s[i] - minChar]++;
		}
		for (int i = 1; i < alphSize; i++) {
			cnt[i] += cnt[i - 1];
		}

		int[] arr = new int[n];
		for (int i = n - 1; i >= 0; i--) {
			arr[--cnt[s[i] - minChar]] = i;
		}

		int[] cls = new int[n];
		int nCl = 1;

		for (int i = 1; i < n; i++) {
			int curSuff = arr[i];
			if (s[curSuff] != s[arr[i - 1]]) {
				nCl++;
			}
			cls[curSuff] = nCl - 1;
		}

		int[] aux = new int[n];

		for (int h = 1; nCl < n; h <<= 1) {

			// aux - suffixes ordered by second halves
			for (int i = 0; i < n; i++) {
				int tmp = arr[i] - h;
				if (tmp < 0)
					tmp += n;
				aux[i] = tmp;
			}

			Arrays.fill(cnt, 0, nCl, 0);
			for (int i = 0; i < n; i++) {
				cnt[cls[i]]++;
			}
			for (int i = 1; i < nCl; i++) {
				cnt[i] += cnt[i - 1];
			}

			for (int i = n - 1; i >= 0; i--) {
				int curSuff = aux[i];
				arr[--cnt[cls[curSuff]]] = curSuff;
			}

			// aux - new classes
			aux[arr[0]] = 0;
			nCl = 1;
			for (int i = 1; i < n; i++) {
				int curPos = arr[i];
				int prevPos = arr[i - 1];
				if (cls[curPos] == cls[prevPos]) {
					int tmpCurPos = curPos + h;
					if (tmpCurPos >= n)
						tmpCurPos -= n;
					prevPos += h;
					if (prevPos >= n)
						prevPos -= n;
					if (cls[tmpCurPos] != cls[prevPos])
						nCl++;
				} else {
					nCl++;
				}
				aux[curPos] = nCl - 1;
			}

			int[] tmp = aux;
			aux = cls;
			cls = tmp;
		}

		return arr;
	}

	static int[] buildLCP(char[] s, int[] arr, int[] inv) {

		int n = s.length;

		int[] lcp = new int[n - 1];
		for (int i = 0, x = 0; i < n; i++) {
			if (x != 0)
				x--;
			int pos = inv[i];
			if (pos == n - 1)
				continue;
			int j = arr[pos + 1];
			while (i + x < n && j + x < n && s[i + x] == s[j + x])
				x++;
			lcp[pos] = x;
		}
		return lcp;
	}

	char[] s;

	int[] inv;
	int[][] sparse;
	int[] sparseLen;

	int lcp(int st1, int st2) {
		int p1 = inv[st1];
		int p2 = inv[st2];
		if (p1 == p2) {
			throw new AssertionError();
		}
		if (p1 > p2) {
			int tmp = p1;
			p1 = p2;
			p2 = tmp;
		}
		int lvl = sparseLen[p2 - p1];
		// System.err.println(p1 + " " + p2 + " " + lvl);
		return Math.min(sparse[lvl][p1], sparse[lvl][p2 - (1 << lvl)]);
	}

	int substrCompare(int s1, int s2, int len) {
		int same = lcp(s1, s2);
		if (same >= len) {
			return 0;
		}
		return s[s1 + same] < s[s2 + same] ? -1 : 1;
	}

	static String repeat(String s, int times) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < times; i++) {
			sb.append(s);
		}
		return sb.toString();
	}

	static final int P = 1_000_000_007;

	int[][] dp, ways;

	void update(int i, int last, int val, int addWays) {
		dp[i][last] = Math.min(dp[i][last], val);
		ways[i][last] = (ways[i][last] + addWays) % P;
	}

	void solve() throws IOException {
		String ss = nextToken();
		s = (ss + "/").toCharArray();
		int n = ss.length();
		int[] sa = buildSuffixArray(s, 3);
		inv = new int[n + 1];
		for (int i = 0; i <= n; i++) {
			inv[sa[i]] = i;
		}
		int[] lcp = buildLCP(s, sa, inv);
		sparse = buildSparse(lcp);
		dp = new int[n + 1][n + 1];
		ways = new int[n + 1][n + 1];
		for (int i = 0; i <= n; i++) {
			Arrays.fill(dp[i], INF);
		}
		dp[0][0] = 0;
		ways[0][0] = 1;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				continue;
			}
			// same
			for (int last = 0; last <= n; last++) {
				if (dp[i][last] == INF) {
					continue;
				}
				if (last == 0 || i + last > n) {
					continue;
				}
				if (i + last < n && i + 2 * last > n) {
					continue;
				}
				if (substrCompare(i - last, i, last) > 0) {
					continue;
				}
				update(i + last, last, dp[i][last] + 1, ways[i][last]);
			}
			// longer
			int bestVal = INF;
			int bestWays = 0;
			for (int next = 1; next <= n; next++) {
				bestVal = Math.min(bestVal, dp[i][next - 1]);
				bestWays = (bestWays + ways[i][next - 1]) % P;
				
				if (bestVal == INF) {
					continue;
				}
				if (next == 0 || i + next > n) {
					continue;
				}
				if (i + next < n && i + 2 * next > n) {
					continue;
				}
				update(i + next, next, bestVal + 1, bestWays);
			}
		}

		boolean small = false;
		for (int len = 1; len <= 15 && len <= n; len++) {
			if (dp[n][len] != INF) {
				small = true;
				break;
			}
		}

		int ansWays = 0;
		for (int len = 1; len <= n; len++) {
			if (dp[n][len] != INF) {
				ansWays += ways[n][len];
				ansWays %= P;
			}
		}

		if (small) {
			int ansVal = INF;
			for (int len = 1; len <= 15 && len <= n; len++) {
				if (dp[n][len] != INF) {
					int curVal = Integer.parseInt(ss.substring(n - len, n), 2)
							+ dp[n][len];
					ansVal = Math.min(ansVal, curVal);
				}
			}
			out.println(ansWays);
			out.println(ansVal);
		} else {
			for (int len = 1; len <= n; len++) {
				if (dp[n][len] != INF) {
					int ansVal = (myParse(ss.substring(n - len, n)) + dp[n][len])
							% P;
					out.println(ansWays);
					out.println(ansVal);
					return;
				}
			}

		}

	}

	int myParse(String substring) {
		int ret = 0;
		for (char c : substring.toCharArray()) {
			ret = (ret * 2) % P;
			if (c == '1') {
				ret = (ret + 1) % P;
			}
		}
		return ret;
	}

	int[][] buildSparse(int[] a) {
		int lvls = 0;
		while ((1 << lvls) <= a.length) {
			lvls++;
		}
		int[][] ret = new int[lvls][];
		ret[0] = a.clone();
		for (int i = 1; i < lvls; i++) {
			ret[i] = new int[a.length - (1 << i) + 1];
			for (int j = 0; j < ret[i].length; j++) {
				ret[i][j] = Math.min(ret[i - 1][j], ret[i - 1][j
						+ (1 << (i - 1))]);
			}
		}
		sparseLen = new int[a.length + 1];
		sparseLen[1] = 0;
		for (int i = 2; i <= a.length; i++) {
			sparseLen[i] = sparseLen[i >> 1] + 1;
		}
		return ret;
	}

	D_new() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D_new();
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