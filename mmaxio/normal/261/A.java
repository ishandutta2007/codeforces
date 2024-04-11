import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int m = nextInt();
		
		int minQ = Integer.MAX_VALUE;
		
		for (int i = 0; i < m; i++) {
			int q = nextInt();
			minQ = Math.min(minQ, q);
		}
		
		Random rng = new Random();
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			int j = rng.nextInt(i + 1);
			a[i] = a[j];
			a[j] = nextInt();
		}
		
		int ans = 0;
		
		Arrays.sort(a);
		for (int i = n - 1; i >= 0;) {
			
			int rest = i + 1;
			
			if (rest < minQ) {
				while (i >= 0) {
					ans += a[i];
					i--;
				}
				break;
			}
			
			for (int j = 0; j < minQ && i >= 0; j++, i--)
				ans += a[i];
			for (int j = 0; j < 2 && i >= 0; j++, i--)
				;
		}
		
		out.println(ans);
	}

	A() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new A();
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