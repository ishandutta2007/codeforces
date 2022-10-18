import java.io.*;
import java.util.*;

public class B {

	static final int Q = 10000;
	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int get(int[] f, int pos) {
		int ret = 0;
		for (int i = pos; i >= 0; i = (i & (i + 1)) - 1) {
			ret = Math.max(ret, f[i]);
		}
		return ret;
	}

	void put(int[] f, int pos, int val) {
		for (int i = pos; i < f.length; i |= i + 1) {
			f[i] = Math.max(f[i], val);
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int t = nextInt();
		int[] a = new int[n];

		TreeSet<Integer> b = new TreeSet<>();

		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
			b.add(a[i]);
		}

		int[] map = new int[301];

		int jj = 0;
		for (int x : b) {
			map[x] = jj++;
		}

		int m = b.size();
		int[] cnt = new int[m];

		for (int i = 0; i < n; i++) {
			a[i] = map[a[i]];
			cnt[a[i]]++;
		}

		int iters = Math.min(t, Q);

		int[] fPref = new int[m];
		int[] gPref = new int[m];
		for (int j = 0; j < iters; j++) {
			for (int i = 0; i < n; i++) {
				int tmp = get(fPref, a[i]) + 1;
				put(fPref, a[i], tmp);
				gPref[a[i]] = tmp;
			}
		}

		for (int i = 1; i < m; i++) {
			gPref[i] = Math.max(gPref[i], gPref[i - 1]);
		}

		if (t <= Q) {
			out.println(gPref[m - 1]);
		} else {

			iters = Math.min(t - Q, Q);

			int[] fSuff = new int[m];
			int[] gSuff = new int[m];
			for (int j = 0; j < iters; j++) {
				for (int i = n - 1; i >= 0; i--) {
					int tmp = get(fSuff, m - 1 - a[i]) + 1;
					put(fSuff, m - 1 - a[i], tmp);
					gSuff[a[i]] = tmp;
				}
			}
			for (int i = m - 2; i >= 0; i--) {
				gSuff[i] = Math.max(gSuff[i], gSuff[i + 1]);
			}

			int betw = Math.max(t - 2 * Q, 0);

//			System.err.println(Arrays.toString(gPref) + " "
//					+ Arrays.toString(gSuff));
			// System.err.println(gPref[0] + " " + gSuff[0] + " " + cnt[0] + " "
			// + betw);
			// System.err.println(gPref[0] + gSuff[0] + cnt[0] * betw);

			int ans = 0;
			for (int i = 0; i < m; i++) {
				ans = Math.max(ans, gPref[i] + gSuff[i] + cnt[i] * betw);
			}

			out.println(ans);
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