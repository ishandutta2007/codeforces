import java.io.*;
import java.util.*;

public class B {

	static final int INF = Integer.MAX_VALUE / 2;
	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt(); // lol not needed?
		
		int[] d = new int[n + 1];
		Arrays.fill(d, INF);
		d[0] = -INF;
		
		for (int i = 0; i < n; i++) {
			int x = nextInt() - 1;
			
			int l = 0; // d[l] <= x
			int r = i + 1; // d[r] > x
			while (l < r - 1) {
				int mid = (l + r) >> 1;
				if (d[mid] <= x)
					l = mid;
				else
					r = mid;
			}
			
			d[r] = x;
			
			nextToken(); // coord not needed?
		}
		
		int max = n;
		while (d[max] == INF)
			max--;
		
		out.println(n - max);
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B().inp();
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