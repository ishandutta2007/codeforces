import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class E_one_hash {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final long P1 = 239;
	static final int MOD1 = 1_000_000_007;
	static final long INV_P1 = BigInteger.valueOf(P1)
			.modInverse(BigInteger.valueOf(MOD1)).longValue();
	long[] POW1, INV_POW1;

	List<Integer>[] g;
	int[] depth;
	int[][] up;
	int[] tIn, tOut;
	int[] hashUp1, hashDown1;
	int[] s;
	int dfsTime;

	void dfs(int v, int p) {
		hashUp1[v] = s[v];
		hashDown1[v] = (int) (POW1[depth[v]] * s[v] % MOD1);
		if (p != -1) {
			hashUp1[v] += (int) (P1 * hashUp1[p] % MOD1);
			if (hashUp1[v] >= MOD1) {
				hashUp1[v] -= MOD1;
			}
			hashDown1[v] += hashDown1[p];
			if (hashDown1[v] >= MOD1) {
				hashDown1[v] -= MOD1;
			}
		}
		tIn[v] = dfsTime++;
		up[0][v] = p;
		for (int i = 1, cur = p; cur != -1; i++) {
			cur = up[i - 1][cur];
			if (cur == -1) {
				break;
			}
			up[i][v] = cur;
		}
		for (int i = 0; i < g[v].size(); i++) {
			int to = g[v].get(i);
			if (to == p) {
				continue;
			}
			depth[to] = depth[v] + 1;
			dfs(to, v);
		}
		tOut[v] = dfsTime;
	}

	int goUp(int v, int x) {
		for (int i = 0; x > 0; i++, x >>= 1) {
			if ((x & 1) == 1) {
				v = up[i][v];
			}
		}
		return v;
	}

	int goTo(int v, int u, int dist) {
		// System.err.println(v + " " + u + " " + dist);
		if (isAnc(u, v)) {
			return goUp(v, dist);
		}
		return goUp(u, depth[u] - depth[v] - dist);
	}

	int getLen(int v, int u) {
		return Math.abs(depth[v] - depth[u]) + 1;
	}

	int getHashUp1(int v, int k) {
		// 1 << k characters up from v
		int ret = hashUp1[v];
		int u = up[k][v];
		if (u != -1) {
			ret -= (int) (POW1[1 << k] * hashUp1[u] % MOD1);
			if (ret < 0) {
				ret += MOD1;
			}
		}
		return ret;
	}

	int getHashDown1(int v, int u, int len) {
		// hash of string from v down to u, WITHOUT v should be exactly len
		// characters
		int ret = hashDown1[u];
		long inverse = INV_POW1[v == -1 ? 0 : depth[v] + 1];
		if (v != -1) {
			ret -= hashDown1[v];
			if (ret < 0) {
				ret += MOD1;
			}
		}
		return (int) (inverse * ret % MOD1);
	}

	int lcpUp(int v1, int u1, int v2, int u2, int len) {
		int ret = 0;
		for (int i = LOG - 1; i >= 0; i--) {
			if ((1 << i) <= len) {
				int h11 = getHashUp1(v1, i);
				int h21 = getHashUp1(v2, i);
				if (h11 == h21) {
					v1 = up[i][v1];
					v2 = up[i][v2];
					len -= 1 << i;
					ret += 1 << i;
				}
			}
		}
		return ret;
	}

	int lcpDown(int v1, int u1, int v2, int u2, int len) {
		v1 = up[0][v1];
		v2 = up[0][v2];
//		System.err.println(v1 + " " + u1 + " " + v2 + " " + u2 + " " + len);
		int ret = 0;
		for (int i = LOG - 1; i >= 0; i--) {
			if ((1 << i) == len) {
				int h11 = getHashDown1(v1, u1, 1 << i);
				int h21 = getHashDown1(v2, u2, 1 << i);
				if (h11 == h21) {
					return ret + (1 << i);
				} else {
					// hmmm... do nothing i guess
				}
			} else if ((1 << i) < len) {
				int c1 = up[i][u1];
				int c2 = up[i][u2];

				int h11 = getHashDown1(v1, c1, len - (1 << i));
				int h21 = getHashDown1(v2, c2, len - (1 << i));
				if (h11 != h21) {
					len -= 1 << i;
					u1 = c1;
					u2 = c2;
				} else {
					ret += len - (1 << i);
					len = 1 << i;
					v1 = c1;
					v2 = c2;
					i++;
				}
			}
		}
		return ret;
	}

	static boolean test(int mask, int i) {
		return ((mask >> i) & 1) == 1;
	}

	int lcpUpDown(int v1, int u1, int v2, int u2, int len) {

		// System.err.println(v1 + " " + u1 + " " + v2 + " " + u2 + " " + len);

		int btc = Integer.bitCount(len);
		int[] bits = new int[btc];
		for (int i = LOG - 1, j = 0; i >= 0; i--) {
			if (test(len, i)) {
				bits[j++] = i;
			}
		}
		int[] mid1 = new int[btc + 1];
		mid1[0] = v1;
		for (int i = 0, v = v1; i < btc; i++) {
			mid1[i + 1] = v = up[bits[i]][v];
		}

		int[] mid2 = new int[btc + 1];
		mid2[btc] = u2;
		for (int i = btc - 1, v = u2; i >= 0; i--) {
			mid2[i] = v = up[bits[i]][v];
		}

		int ret = 0;

		// System.err.println(Arrays.toString(mid1));
		// System.err.println(Arrays.toString(mid2));
		// System.err.println(Arrays.toString(bits));

		for (int i = 0; i < btc; i++) {
			v1 = mid1[i];
			u1 = mid1[i + 1];
			v2 = mid2[i];
			u2 = mid2[i + 1];

			int h11 = getHashUp1(v1, bits[i]);
			int h21 = getHashDown1(v2, u2, 1 << bits[i]);

			// System.err.println(h11 + " " + h21 + " " + h12 + " " + h22);
			if (h11 == h21) {
				ret += 1 << bits[i];
				continue;
			}

			for (int j = bits[i] - 1; j >= 0; j--) {
				int mid = up[j][u2];
				h11 = getHashUp1(v1, j);
				h21 = getHashDown1(v2, mid, 1 << j);
				if (h11 == h21) {
					ret += 1 << j;
					v1 = up[j][v1];
					v2 = mid;
				} else {
					u2 = mid;
				}
			}
			return ret;
		}
		return ret;
	}

	int lcp(int v1, int u1, int v2, int u2, int len) {
		// System.err.println(v1 + " " + u1 + " " + v2 + " " + u2 + " " + len);
		boolean up1 = depth[u1] <= depth[v1];
		boolean up2 = depth[u2] <= depth[v2];
		if (up1 && up2) {
			return lcpUp(v1, u1, v2, u2, len);
		}
		if (!up1 && !up2) {
			return lcpDown(v1, u1, v2, u2, len);
		}
		if (up1 && !up2) {
			return lcpUpDown(v1, u1, v2, u2, len);
		}
		if (!up1 && up2) {
			return lcpUpDown(v2, u2, v1, u1, len);
		}
		throw new AssertionError();
	}

	int go(int v1, int u1, int v2, int u2) {
		int[] r1 = path(v1, u1);
		int[] r2 = path(v2, u2);

		int ret = 0;
		for (int i1 = 0, i2 = 0; i1 < r1.length && i2 < r2.length;) {
			int len1 = getLen(r1[i1], r1[i1 + 1]);
			int len2 = getLen(r2[i2], r2[i2 + 1]);
			int len = Math.min(len1, len2);
			int to1 = goTo(r1[i1], r1[i1 + 1], len - 1);
			int to2 = goTo(r2[i2], r2[i2 + 1], len - 1);
			int add = lcp(r1[i1], to1, r2[i2], to2, len);
//			System.err.println(len1 + " " + len2 + " " + add);
			if (add < len) {
				return ret + add;
			} else {
				ret += len;
			}
			if (len == len1) {
				i1 += 2;
			} else {
				r1[i1] = goTo(r1[i1], r1[i1 + 1], len);
			}
			if (len == len2) {
				i2 += 2;
			} else {
				r2[i2] = goTo(r2[i2], r2[i2 + 1], len);
			}
		}
		return ret;
	}

	boolean isAnc(int v, int u) {
		return tIn[v] <= tIn[u] && tOut[u] <= tOut[v];
	}

	int[] path(int v, int u) {
		if (isAnc(v, u) || isAnc(u, v)) {
			return new int[] { v, u };
		}
		int initU = u;
		for (int i = LOG - 1; i >= 0; i--) {
			int to = up[i][u];
			if (to != -1 && !isAnc(to, v)) {
				u = to;
			}
		}
		return new int[] { v, up[0][u], u, initU };
	}

	void solve() throws IOException {
		int n = nextInt();
		POW1 = new long[n + 1];
		INV_POW1 = new long[n + 1];
		POW1[0] = 1;
		INV_POW1[0] = 1;
		for (int i = 1; i < POW1.length; i++) {
			POW1[i] = P1 * POW1[i - 1] % MOD1;
			INV_POW1[i] = INV_P1 * INV_POW1[i - 1] % MOD1;
		}
		String ss = nextToken();
		s = new int[ss.length()];
		for (int i = 0; i < n; i++) {
			s[i] = ss.charAt(i) - 'a';
		}
		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>(2);
		}
		for (int i = 0; i < n - 1; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			g[v1].add(v2);
			g[v2].add(v1);
		}
		depth = new int[n];
		up = new int[LOG][n];
		for (int i = 0; i < LOG; i++) {
			Arrays.fill(up[i], -1);
		}
		tIn = new int[n];
		tOut = new int[n];
		hashUp1 = new int[n];
		hashDown1 = new int[n];
		dfs(0, -1);

		int q = nextInt();
		while (q-- > 0) {
			int v1 = nextInt() - 1;
			int u1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			int u2 = nextInt() - 1;
			out.println(go(v1, u1, v2, u2));
		}
	}

	static final int LOG = 19;

	E_one_hash() throws IOException {
		 br = new BufferedReader(new InputStreamReader(System.in));
//		br = new BufferedReader(new FileReader("in.txt"));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new E_one_hash();
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