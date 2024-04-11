import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int MASK = -2;

	boolean isOdd(int x) {
		return (x & 1) == 1;
	}

	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n - 1];
		for (int i = 0; i < n - 1; i++)
			a[i] = nextInt();
		long[] ansPref = new long[n]; // start from right
		long[] ansPrefStay = new long[n];

		for (int i = 1; i < n; i++) {
			if (a[i - 1] == 1)
				ansPrefStay[i] = 0;
			else
				ansPrefStay[i] = ansPrefStay[i - 1] + (a[i - 1] & MASK);
			if (isOdd(a[i - 1])) {
				ansPref[i] = ansPref[i - 1] + a[i - 1];
			} else {
				ansPref[i] = Math.max(ansPref[i - 1] + (a[i - 1] - 1),
						ansPrefStay[i - 1] + a[i - 1]);
			}
		}
		
//		System.err.println(Arrays.toString(ansPrefStay));
//		System.err.println(Arrays.toString(ansPref));

		long[] ansSuff = new long[n]; // start from left
		long[] ansSuffStay = new long[n];

		for (int i = n - 2; i >= 0; i--) {
			if (a[i] == 1)
				ansSuffStay[i] = 0;
			else
				ansSuffStay[i] = ansSuffStay[i + 1] + (a[i] & MASK);
			if (isOdd(a[i])) {
				ansSuff[i] = ansSuff[i + 1] + a[i];
			} else {
				ansSuff[i] = Math.max(ansSuff[i + 1] + (a[i]  - 1),
						ansSuffStay[i + 1] + a[i]);
			}
		}

		long ans = 0;
		for (int i = 0; i < n; i++) {
			ans = Math.max(ans, ansPrefStay[i] + ansSuff[i]);
			ans = Math.max(ans, ansSuffStay[i] + ansPref[i]);
		}

		out.println(ans);

	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C().inp();
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