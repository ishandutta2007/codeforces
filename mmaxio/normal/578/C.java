import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		long[] a = new long[n + 1];
		for (int i = 0; i < n; i++) {
			a[i + 1] = a[i] + nextLong();
		}

		n++;

		int[] low = new int[n];
		double[] xL = new double[n - 1];
		int lowSz = 0;
		low[lowSz++] = n - 1;

		for (int i = n - 2; i >= 0; i--) {
			while (true) {
				double where = 1.0 * (a[i] - a[low[lowSz - 1]])
						/ (low[lowSz - 1] - i);
				if (lowSz > 1 && where < xL[lowSz - 2]) {
					lowSz--;
				} else {
					low[lowSz] = i;
					xL[lowSz - 1] = where;
					lowSz++;
					break;
				}
			}
		}

		int[] high = new int[n];
		double[] xH = new double[n - 1];
		int highSz = 0;
		high[highSz++] = 0;

		for (int i = 1; i < n; i++) {
			while (true) {
				double where = 1.0 * (a[high[highSz - 1]] - a[i])
						/ (i - high[highSz - 1]);
				if (highSz > 1 && where < xH[highSz - 2]) {
					highSz--;
				} else {
					high[highSz] = i;
					xH[highSz - 1] = where;
					highSz++;
					break;
				}
			}
		}
//		
//		for (int i = 0, j = highSz - 1; i < j; i++, j--) {
//			int tmp = high[i];
//			high[i] = high[j];
//			high[j] = tmp;
//		}
//		
//		for (int i = 0, j = highSz - 2; i < j; i++, j--) {
//			double tmp = xH[i];
//			xH[i] = xH[j];
//			xH[j] = tmp;
//		}

//		System.err.println(Arrays.toString(low));
//		System.err.println(Arrays.toString(xL));
//		System.err.println(lowSz);
//
//		System.err.println(Arrays.toString(high));
//		System.err.println(Arrays.toString(xH));
//		System.err.println(highSz);

		double ans = 1e100;

		for (int i = 0, j = 0; i < lowSz - 1 || j < highSz - 1;) {

//			System.err.println(i + " " + j);

			int lowIdx = low[i];
			int highIdx = high[j];

			if (j == highSz - 1 || (i != lowSz - 1 && xL[i] <= xH[j])) {
				double x = xL[i];
				ans = Math.min(
						ans,
						Math.abs(a[lowIdx] + lowIdx * x - a[highIdx] - highIdx
								* x));
				i++;
			} else {
				double x = xH[j];
				ans = Math.min(
						ans,
						Math.abs(a[lowIdx] + lowIdx * x - a[highIdx] - highIdx
								* x));
				j++;
			}

		}

		out.println(ans);

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