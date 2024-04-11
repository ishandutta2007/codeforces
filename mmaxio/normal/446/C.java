import java.io.*;
import java.util.*;

public class C_new {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int MOD = 1_000_000_009;
	static final int PHI = 691504013;
	static final int PSI = 308495997;
	static final int INV_ROOT_5 = 276601605;

	int[] powPHI, prefPHI;
	int[] powPSI, prefPSI;

	class Node {
		int l, r;
		Node left, right;

		int sum;
		int addPHI;
		int addPSI;

		int getSum() {
			int ret = (int) ((long) addPHI * prefPHI[r - l] % MOD)
					- (int) ((long) addPSI * prefPSI[r - l] % MOD);
			if (ret < 0) {
				ret += MOD;
			}
			return (sum + ret) % MOD;
		}

		public Node(int l, int r) {
			this.l = l;
			this.r = r;
			if (r - l > 1) {
				int mid = (l + r) >> 1;
				left = new Node(l, mid);
				right = new Node(mid, r);
			}
		}

		void add(int ql, int qr) {
			if (l >= qr || ql >= r) {
				return;
			}
			if (ql <= l && r <= qr) {
				addPHI = (addPHI + powPHI[l - ql + 1]) % MOD;
				addPSI = (addPSI + powPSI[l - ql + 1]) % MOD;
				return;
			}
			left.add(ql, qr);
			right.add(ql, qr);
			sum = (left.getSum() + right.getSum()) % MOD;
		}

		int get(int ql, int qr) {
			if (l >= qr || ql >= r) {
				return 0;
			}
			if (ql <= l && r <= qr) {
				return getSum();
			}
			left.addPHI = (left.addPHI + addPHI) % MOD;
			left.addPSI = (left.addPSI + addPSI) % MOD;
			right.addPHI = (right.addPHI + (int) ((long) addPHI
					* powPHI[right.l - l] % MOD))
					% MOD;
			right.addPSI = (right.addPSI + (int) ((long) addPSI
					* powPSI[right.l - l] % MOD))
					% MOD;
			addPHI = addPSI = 0;
			int ret = (left.get(ql, qr) + right.get(ql, qr)) % MOD;
			sum = (left.getSum() + right.getSum()) % MOD;
			return ret;
		}
	}

	int[] gen(int x, int n) {
		int[] ret = new int[n];
		ret[0] = 1;
		for (int i = 1; i < n; i++) {
			ret[i] = (int) ((long) ret[i - 1] * x % MOD);
		}
		return ret;
	}

	int[] prefixSums(int[] a) {
		int[] ret = new int[a.length + 1];
		for (int i = 0; i < a.length; i++) {
			ret[i + 1] = (ret[i] + a[i]) % MOD;
		}
		return ret;
	}

	void solve() throws IOException {
		int n = nextInt();
		int q = nextInt();
		int[] pref = new int[n + 1];
		for (int i = 0; i < n; i++) {
			int x = nextInt();
			pref[i + 1] = (pref[i] + x) % MOD;
		}

		powPSI = gen(PSI, n + 1);
		powPHI = gen(PHI, n + 1);
		prefPSI = prefixSums(powPSI);
		prefPHI = prefixSums(powPHI);

		Node root = new Node(0, n);

		while (q-- > 0) {
			int type = nextInt();
			int l = nextInt() - 1;
			int r = nextInt() - 1;
			if (type == 1) {
				root.add(l, r + 1);
			} else {
				int ret = (int) ((long) root.get(l, r + 1) * INV_ROOT_5 % MOD);
				int ret2 = pref[r + 1] - pref[l];
				if (ret2 < 0) {
					ret2 += MOD;
				}
				out.println((ret + ret2) % MOD);
			}
		}
	}

	C_new() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C_new();
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