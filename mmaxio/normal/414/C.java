import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int n, N;

	long[] inv, tot;
	int[] tmp;
	int[] a;

	void go(int l, int r) {
		if (r - l == 1) {
			return;
		}
		int mid = (l + r) >> 1;
		go(l, mid);
		go(mid, r);

		int level = Integer.numberOfTrailingZeros(r - l) - 1;

		for (int i1 = l, i2 = mid, i = l; i < r;) {
			

			if (i1 < mid && i2 < r && a[i1] == a[i2]) {
				int j1 = i1;
				while (j1 < mid && a[j1] == a[i1]) {
					j1++;
				}
				int j2 = i2;
				while (j2 < r && a[j2] == a[i2]) {
					j2++;
				}

				tot[level] -= (long) (j1 - i1) * (j2 - i2);
				while (i1 < j1) {
					tmp[i++] = a[i1++];
				}
				while (i2 < j2) {
					inv[level] += mid - i1;
					tmp[i++] = a[i2++];
				}
				

				
			} else if (i2 == r || (i1 != mid && a[i1] < a[i2])) {
				tmp[i++] = a[i1++];
			} else {
				inv[level] += mid - i1;
				tmp[i++] = a[i2++];
			}
		}

		System.arraycopy(tmp, l, a, l, r - l);
	}

	void solve() throws IOException {
		n = nextInt();
		N = 1 << n;

		a = new int[N];
		for (int i = 0; i < N; i++) {
			a[i] = nextInt();
		}

		tmp = new int[N];

		inv = new long[n];
		tot = new long[n];
		for (int i = 0; i < n; i++) {
			tot[i] = 1L << (n - 1 + i);
		}

		go(0, N);

//		System.err.println(Arrays.toString(inv));
//		System.err.println(Arrays.toString(tot));

		int qq = nextInt();
		while (qq-- > 0) {
			int lev = nextInt();
			for (int i = 0; i < lev; i++) {
				inv[i] = tot[i] - inv[i];
			}
			long outp = 0;
			for (int i = 0; i < n; i++) {
				outp += inv[i];
			}
			out.println(outp);
		}
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