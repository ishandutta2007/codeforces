import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		
		long low = Long.MIN_VALUE;
		long high = Long.MAX_VALUE;
		
		long delta = 0;
		
		for (int i = 0; i < n; i++) {
			int c = nextInt();
			int d = nextInt();
			
			if (d == 1) {
				// x + delta >= 1900
				low = Math.max(low, 1900 - delta);
			} else {
				// x + delta <= 1899
				high = Math.min(high, 1899 - delta);
			}
			
//			System.err.println(low + " " + high);
			
			delta += c;
		}
		
		if (low > high) {
			out.println("Impossible");
		} else if (high == Long.MAX_VALUE) {
			out.println("Infinity");
		} else {
			// x + delta = high
			out.println(high + delta);
		}
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