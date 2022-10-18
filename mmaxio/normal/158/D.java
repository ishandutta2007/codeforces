import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	int n;
	int ans;
	int[] a;
	
	void go(int v) {
		if (v < 3)
			return;
		for (int st = 0; st < n / v; st++) {
			int sum = 0;
			for (int i = st; i < n; i += n / v)
				sum += a[i];
			ans = Math.max(ans, sum);
		}
	}

	void solve() throws IOException {
		n = nextInt();
		a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = nextInt();
		
		ans = Integer.MIN_VALUE;
		
		for (int div = 1; div * div <= n; div++) 
			if (n % div == 0) {
				go(div);
				if (div * div != n)
					go(n / div);
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
		new D().inp();
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