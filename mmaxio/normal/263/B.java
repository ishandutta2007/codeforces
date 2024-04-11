import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	static final int MAX = 1_000_000_000;

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = nextInt();
		
		Arrays.sort(a);
		
		if (k > n) {
			out.println(-1);
			return;
		}
		
		if (k == 0) {
			/*if (a[n - 1] == MAX)
				out.println(-1);
			else*/
				out.println(MAX + " " + MAX);
			return;
		}
		
		out.println(a[n - k] + " " + a[n - k]);
		
		
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