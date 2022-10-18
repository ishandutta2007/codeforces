import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int l = nextInt();
		int v1 = nextInt();
		int v2 = nextInt();
		int cap = nextInt();
		
		n = (n + cap - 1) / cap;
		if (n == 1) {
			out.println(1.0 * l / v2);
			return;
		}
		
		double low = 0;
		double high = 1e10;
		
		double mult = 2.0 * v2 / (v1 + v2);
		
		outer: for (int it = 0; it < 100; it++) {
			double mid = (low + high) * 0.5;
			double x = 0;
			double t = 0;
			for (int i = 0; i < n; i++) {
				double timeBack = (x - v1 * t) / (v1 + v2);
				
				x = x + (mid - timeBack) * v2;
				t += timeBack + mid;
				if (x > l) {
					high = mid;
					continue outer;
				}
			}
			low = mid;
		}
		
		double busT = (low + high) * 0.5;
		double walkT = (l - busT * v2) / v1;
		
		out.println(busT + walkT);
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