import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int[] gcdN;

	long go(int[] a, int div) {
		int n = a.length;
		boolean[] ok = new boolean[n];

		int from = -1;

		for (int rem = 0; rem < div; rem++) {
			int tmp = 0;
			for (int i = rem; i < n; i += div) {
				tmp = Math.max(tmp, a[i]);
			}
			for (int i = rem; i < n; i += div) {
				ok[i] = a[i] == tmp;
				if (!ok[i]) {
					from = i;
				}
			}
		}

		if (from == -1) {
			int tmp = 0;
			for (int i = 1; i < n; i++) {
				tmp += gcdN[i] == div ? 1 : 0;
			}
			return (long) tmp * n;
		}

		// System.err.println(div + " " + Arrays.toString(ok));

		int[] pref = new int[n];
		Arrays.fill(pref, -1);
		pref[0] = 0;
		int cons = 0;
		long ret = 0;
		for (int i = from; i < n; i++) {
			cons = ok[i] ? cons + 1 : 0;
			if (pref[cons] == -1) {
				pref[cons] = pref[cons - 1] + (gcdN[cons] == div ? 1 : 0);
			}
			ret += pref[cons];
		}

		for (int i = 0; i < from; i++) {
			cons = ok[i] ? cons + 1 : 0;
			if (pref[cons] == -1) {
				pref[cons] = pref[cons - 1] + (gcdN[cons] == div ? 1 : 0);
			}
			ret += pref[cons];
		}

		return ret;

	}

	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}


		gcdN = new int[n + 1];
		for (int i = 1; i <= n; i++) {
			gcdN[i] = gcd(i, n);
		}

		long ans = 0;

		for (int l = 1; l * l <= n; l++) {
			if (n % l == 0) {
				ans += go(a, l);
				if (l != 1 && l * l != n) {
					ans += go(a, n / l);
				}
			}
		}

		out.println(ans);
	}

	int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C();
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