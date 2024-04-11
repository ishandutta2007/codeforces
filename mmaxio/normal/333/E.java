import java.io.*;
import java.util.*;

public class E_long {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int SIZE;
	static final int MASK = 31;

	static long MASK_V1 = (1 << 26) - 1;
	static long MASK_V2 = (1 << 13) - 1;

	static long makeEdgeInfo(int v1, int v2, int len) {
		return (((long)len) << 32) | (v1 << 13) | v2;
	}

	void solve() throws IOException {
		int n = nextInt();
		int[] x = new int[n];
		int[] y = new int[n];

		for (int i = 0; i < n; i++) {
			x[i] = nextInt();
			y[i] = nextInt();
		}

		long[] a = new long[n * (n - 1) / 2];
		for (int i = 0, k = 0; i < n; i++)
			for (int j = i + 1; j < n; j++) {

				long edgeInfo = makeEdgeInfo(i, j, sqr(x[i] - x[j])
						+ sqr(y[i] - y[j]));
				
				//System.err.println(edgeInfo);

				a[k++] = edgeInfo;
			}

		SIZE = (n + 31) >> 5;
		int[][] set = new int[n][SIZE];

		Arrays.sort(a);
		for (int i = a.length - 1; i >= 0; i--) {
			long edgeInfo = a[i];
			int v1 = (int) ((edgeInfo & MASK_V1) >> 13);
			int v2 = (int) ((edgeInfo) & MASK_V2);
			//System.err.println(v1 + " " + v2);
			int[] set1 = set[v1];
			int[] set2 = set[v2];
			for (int j = 0; j < SIZE; j++) {
				if ((set1[j] & set2[j]) != 0) {
					long edgeLen = (int) (edgeInfo >> 32);
					double ans = Math.sqrt(edgeLen) * 0.5;
					out.println(ans);
					return;
				}
			}
			set1[v2 >> 5] |= 1 << (v2 & MASK);
			set2[v1 >> 5] |= 1 << (v1 & MASK);
		}
	}

	static int sqr(int x) {
		return x * x;
	}

	static void setBit(int[] bitSet, int pos) {
		bitSet[pos >> 5] |= 1 << (pos & MASK);
	}

	E_long() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new E_long();
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