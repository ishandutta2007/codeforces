import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	static final int D = 5000;

	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		
		Arrays.sort(a);
		long[] ways = new long[D];
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				ways[a[j] - a[i]]++;
			}
		}
		
		long[] ways2 = new long[2 * D];
		for (int i = 0; i < D; i++)
			for (int j = 0; j < D; j++) {
				ways2[i + j] += ways[i] * ways[j];
			}
		
		long cnt = 0;
		long pref = 0;
		for (int i = 0; i < D; i++) {
			cnt += ways[i] * pref;
			pref += ways2[i];
		}
		
		long total = n * (n - 1) / 2;
		total = total * total * total;
		
		double ans = 1.0 * cnt / total;
		out.println(ans);
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