import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	double f(int dist, double initSp, int a, int maxSp) {
		double distToReachMaxSpeed = 0.5 * (maxSp * maxSp - initSp * initSp)
				/ a;

		if (dist > distToReachMaxSpeed)
			return 1d * (maxSp - initSp) / a + (dist - distToReachMaxSpeed)
					/ maxSp;

		return (Math.sqrt(initSp * initSp + 2 * a * dist) - initSp) / a;
	}

	void solve() throws IOException {
		int a = nextInt();
		int maxSp = nextInt();
		int len = nextInt();
		int signX = nextInt();
		int signSp = nextInt();

		if (maxSp <= signSp) {
			out.printf("%.9f\n", f(len, 0, a, maxSp));
			return;
		}

		double distToReachSignSp = 0.5 * signSp * signSp / a;
		if (distToReachSignSp >= signX) {
			out.printf("%.9f\n", f(len, 0, a, maxSp));
			return;
		}

		double distToReachMaxThenSign = 0.5
				* (maxSp * maxSp + maxSp * maxSp - signSp * signSp) / a;
		if (distToReachMaxThenSign <= signX) {
			double t = 1d * (2 * maxSp - signSp) / a
					+ (signX - distToReachMaxThenSign) / maxSp
					+ f(len - signX, signSp, a, maxSp);
			out.printf("%.9f\n", t);
			return;
		}
		
		double xSp = Math.sqrt(a * signX + signSp * signSp * 0.5);
		double xTime = (2 * xSp - signSp) / a;
		out.printf("%.9f\n", xTime + f(len - signX, signSp, a, maxSp));
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