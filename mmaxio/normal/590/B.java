import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		double x0 = nextDouble();
		double y0 = nextDouble();
		double x = nextDouble() - x0;
		double y = nextDouble() - y0;
		
		double vMax = nextDouble();
		double t = nextDouble();
		
		double vx = nextDouble();
		double vy = nextDouble();
		double wx = nextDouble();
		double wy = nextDouble();
		
		double low = 0;
		double high = 1e30;
		
//		double low = 11;
//		double high = 12;
		
		for (int iter = 0; iter < 200; iter++) {
			double mid = (low + high) * 0.5;
			double xc = Math.min(t, mid) * vx + Math.max(mid - t, 0) * wx;
			double yc = Math.min(t, mid) * vy + Math.max(mid - t, 0) * wy;
			double sqDist = (xc - x) * (xc - x) + (yc - y) * (yc - y);
			
			if (sqDist <= (vMax * mid) * (vMax * mid)) {
				high = mid;
			} else {
				low = mid;
			}
		}
		
		out.println((low + high) * 0.5);
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