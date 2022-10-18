import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Take implements Comparable<Take> {
		int d1, d2, fst;
		int val;

		public Take(int d1, int d2, int fst, int val) {
			this.d1 = d1;
			this.d2 = d2;
			this.fst = fst;
			this.val = val;
		}

		int softCmp(Take o) {
			if (d1 != o.d1) {
				return d1 < o.d1 ? -1 : 1;
			}
			return Integer.compare(d2, o.d2);
		}

		@Override
		public int compareTo(Take o) {
			int ret = softCmp(o);
			return ret != 0 ? ret : -Integer.compare(fst, o.fst);
		}
	}

	Take[] genTake(int[][] a, int sign) {
		int n = a.length;
		int p3 = 1;
		for (int i = 0; i < n; i++) {
			p3 *= 3;
		}

		Take[] ret = new Take[p3];
		for (int i = 0; i < p3; i++) {
			int d1 = 0;
			int d2 = 0;
			int fst = 0;
			for (int j = 0, ii = i; j < n; j++, ii /= 3) {
				int type = ii % 3;
				if (type == 0) { // 01
					d1 += a[j][0] - a[j][1];
					d2 += a[j][0];
					fst += a[j][0];
				} else if (type == 1) { // 02
					d1 += a[j][0];
					d2 += a[j][0] - a[j][2];
					fst += a[j][0];
				} else { // 12
					d1 -= a[j][1];
					d2 -= a[j][2];
				}
			}
			ret[i] = new Take(d1 * sign, d2 * sign, fst, i);
		}
		return ret;
	}

	void solve() throws IOException {
		int n = nextInt();
		int[][] a = new int[n][3];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				a[i][j] = nextInt();
			}
		}

		int h1 = n / 2;
		int h2 = n - h1;

		Take[] a1 = genTake(Arrays.copyOfRange(a, 0, h1), 1);
		Take[] a2 = genTake(Arrays.copyOfRange(a, h1, n), -1);

		Arrays.sort(a1);
		Arrays.sort(a2);

		int ans1 = -1;
		int ans2 = -1;
		int ansFst = Integer.MIN_VALUE;

		for (int i1 = 0, i2 = 0; i1 < a1.length && i2 < a2.length;) {
			int comp = a1[i1].softCmp(a2[i2]);

			boolean adv1 = false, adv2 = false;

			if (comp == 0) {
				if (a1[i1].fst + a2[i2].fst > ansFst) {
					ans1 = a1[i1].val;
					ans2 = a2[i2].val;
					ansFst = a1[i1].fst + a2[i2].fst;
				}
				adv1 = adv2 = true;
			} else if (comp == -1) {
				adv1 = true;
			} else {
				adv2 = true;
			}
			if (adv1) {
				Take tmp = a1[i1];
				while (i1 < a1.length && a1[i1].softCmp(tmp) == 0) {
					i1++;
				}
			}

			if (adv2) {
				Take tmp = a2[i2];
				while (i2 < a2.length && a2[i2].softCmp(tmp) == 0) {
					i2++;
				}
			}
		}

		if (ansFst == Integer.MIN_VALUE) {
			out.println("Impossible");
		} else {

			for (int j = 0, ii = ans1; j < h1; j++, ii /= 3) {
				int type = ii % 3;
				if (type == 0) { // 01
					out.println("LM");
				} else if (type == 1) { // 02
					out.println("LW");
				} else { // 12
					out.println("MW");
				}
			}

			for (int j = 0, ii = ans2; j < h2; j++, ii /= 3) {
				int type = ii % 3;
				if (type == 0) { // 01
					out.println("LM");
				} else if (type == 1) { // 02
					out.println("LW");
				} else { // 12
					out.println("MW");
				}
			}
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