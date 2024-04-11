import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	static final Random rng = new Random();
	
	static final long INF = Long.MAX_VALUE / 2;
	
	long safeProd(long a, long b) {
		if (INF / a < b) {
			return INF;
		}
		return a * b;
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int[] a = new int[n];
		int[] b = new int[m];
		for (int i = 0; i < n; i++) {
			int j = rng.nextInt(i + 1);
			a[i] = a[j];
			a[j] = nextInt();
//			a[i] = nextInt();
		}
		for (int i = 0; i < m; i++) {
			int j = rng.nextInt(i + 1);
			b[i] = b[j];
			b[j] = nextInt();
//			b[i] = nextInt();
		}
		Arrays.sort(a);
		Arrays.sort(b);
		long ans = Long.MAX_VALUE;
		long sum = 0;
		for (int i = 0; i < n; i++) {
			sum += a[i];
		}
		ans = Math.min(ans, safeProd(sum, m));
		long sum2 = 0;
		for (int i = 0; i < m - 1; i++) {
			sum2 += b[i];
			ans = Math.min(ans, safeProd(sum, m - i - 1) + sum2);
		}
		
		sum = 0;
		for (int i = 0; i < m; i++) {
			sum += b[i];
		}
		ans = Math.min(ans, safeProd(sum, n));
		sum2 = 0;
		for (int i = 0; i < n - 1; i++) {
			sum2 += a[i];
			ans = Math.min(ans, safeProd(sum, n - i - 1) + sum2);
		}
		
		out.println(ans);
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