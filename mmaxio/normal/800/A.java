import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final double ITERS = 75;
	
	void solve() throws IOException {
		int n = nextInt();
		int[] as = new int[n];
		int[] bs = new int[n];
		
		int p = nextInt();
		long sumA = 0;
		long sumB = 0;
		for (int i = 0; i < n; i++) {
			as[i] = nextInt();
			bs[i] = nextInt();
			sumA += as[i];
			sumB += bs[i];
		}
		
		if (sumA <= p) {
			out.println(-1);
			return;
		}
		
		double low = 0;
		double high = 1.0 * sumB / (sumA - p);
		
		for (int it = 0; it < ITERS; it++) {
			double mid = (low + high) * .5;
//			double mid = .5;
			double sumX = 0;
			
			long sumANow = 0;
			long sumBNow = 0;
			
			for (int i = 0; i < n; i++) {
//				double minXi = mid * as[i] - bs[i];
//				sumX += Math.max(minXi, 0);
				if (mid >= 1.0 * bs[i] / as[i]) {
					sumANow += as[i];
					sumBNow += bs[i];
				}
			}
			
//			System.err.println(mid + " " + sumX);
			
			sumX = mid * sumANow - sumBNow;
			
			if (sumX <= mid * p) {
				low = mid;
			} else {
				high = mid;
			}
		}
		
//		if (n == 100000 && p == 1000000000 && as[0] == 10000 && bs[0] == 100000 && as[1] == as[0] && bs[1] == bs[0]) {
//			out.println(sumA + " " + sumB);
//			for (int i = n - 5; i < n; i++) {
//				out.println(as[i] + " " + bs[i]);
//			}
//		}
		
		out.println((low + high) * 0.5);
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