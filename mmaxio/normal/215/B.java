import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int cR1 = nextInt();
		int maxR1 = Integer.MIN_VALUE;
		for (int i = 0; i < cR1; i++)
			maxR1 = Math.max(maxR1, nextInt());
		
		int cP1 = nextInt();
		int maxP1 = Integer.MIN_VALUE;
		for (int i = 0; i < cP1; i++)
			maxP1 = Math.max(maxP1, nextInt());
		
		int cP2 = nextInt();
		int minP2 = Integer.MAX_VALUE;
		for (int i = 0; i < cP2; i++)
			minP2 = Math.min(minP2, nextInt());
		
		double c = 1.0 * nextInt() / nextInt();
		double res = maxR1 / Math.sqrt(c * minP2 / maxP1 + 1);
		
		out.printf("%.12f\n", res);
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