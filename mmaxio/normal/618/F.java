import java.io.*;
import java.util.*;

public class F {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Number implements Comparable<Number> {
		int val, idx;

		@Override
		public int compareTo(Number o) {
			return Integer.compare(val, o.val);
		}

		public Number(int val, int idx) {
			this.val = val;
			this.idx = idx;
		}
	}

	void go(Number[] a, Number[] b, int fromA, int toA, int fromB, int toB,
			boolean flip) {
		if (flip) {
			Number[] tmp1 = a;
			a = b;
			b = tmp1;

			int tmp2 = fromA;
			fromA = fromB;
			fromB = tmp2;

			tmp2 = toA;
			toA = toB;
			toB = tmp2;
		}

		out.println(toA - fromA + 1);
		for (int i = fromA; i <= toA; i++) {
			out.print(a[i].idx + " ");
		}
		out.println();

		out.println(toB - fromB + 1);
		for (int i = fromB; i <= toB; i++) {
			out.print(b[i].idx + " ");
		}
		out.println();
	}

	void solve() throws IOException {
		int n = nextInt();
		

		Number[] a = new Number[n];
		Number[] b = new Number[n];

		for (int i = 0; i < n; i++) {
			a[i] = new Number(nextInt(), i + 1);
		}

		for (int i = 0; i < n; i++) {
			b[i] = new Number(nextInt(), i + 1);
		}
		
		Arrays.sort(a);
		Arrays.sort(b);

		long[] pa = new long[n];
		long[] pb = new long[n];
		for (int i = 0; i < n; i++) {
			pa[i] = a[i].val + (i == 0 ? 0 : pa[i - 1]);
			pb[i] = b[i].val + (i == 0 ? 0 : pb[i - 1]);
		}
		
		
//		System.err.println(Arrays.toString(pa));
//		System.err.println(Arrays.toString(pb));

		boolean flip = false;

		if (pa[n - 1] > pb[n - 1]) {
			Number[] tmp1 = a;
			a = b;
			b = tmp1;
			long[] tmp2 = pa;
			pa = pb;
			pb = tmp2;
			flip = true;
		}

		int[] whereA = new int[n + 1];
		int[] whereB = new int[n + 1];
		Arrays.fill(whereA, -1);

		for (int i = 0, j = 0; i < n; i++) {
			while (pb[j] < pa[i]) {
				j++;
			}
			if (pb[j] == pa[i]) {
				go(a, b, 0, i, 0, j, flip);
				return;
			}
			long idx = pb[j] - pa[i];

			if (idx >= n) {
				throw new AssertionError();
			}
			
			int intIdx = (int)idx;

			if (whereA[intIdx] == -1) {
				whereA[intIdx] = i;
				whereB[intIdx] = j;
			} else {
				go(a, b, whereA[intIdx] + 1, i, whereB[intIdx] + 1, j, flip);
				return;
			}
		}

	}

	F() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new F();
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