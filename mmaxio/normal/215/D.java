import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	int m;
	
	long f(int initT, int maxT, int pen, int bus) {
		int maxBusCap = maxT - initT;
		if (maxBusCap <= 0)
			return bus + (long)m * pen;
		int maxOk = (m + maxBusCap - 1) / maxBusCap;
		long res = (long)maxOk * bus;
		
		long A = bus - (long)maxBusCap * pen;
		long B = bus + (long)m * pen;
		// minimize Ax + b, where x \in [0; maxOk)
		long res2;
		if (A >= 0)
			res2 = B;
		else
			res2 = A * (maxOk - 1) + B;
		return Math.min(res, res2);
	}

	void solve() throws IOException {
		int q = nextInt();
		m = nextInt();
		
		long ans = 0;
		while (q-- > 0)
			ans += f(nextInt(), nextInt(), nextInt(), nextInt());
		
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
				return "0";
			}
		}
		return st.nextToken();
	}

	String nextString() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken("\n");
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