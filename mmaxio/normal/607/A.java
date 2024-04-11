import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	static class Beacon implements Comparable<Beacon>{
		int pos, power;

		public Beacon(int pos, int power) {
			this.pos = pos;
			this.power = power;
		}

		@Override
		public int compareTo(Beacon o) {
			return Integer.compare(pos, o.pos);
		}
		
	}

	void solve() throws IOException {
		int n = nextInt();
		Beacon[] a = new Beacon[n];
		for (int i = 0; i < n; i++) {
			a[i] = new Beacon(nextInt(), nextInt());
		}
		Arrays.sort(a);
		
		int maxSave = 0;
		
		int[] dp = new int[n];
		for (int i = 0; i < n; i++) {
			int l = -1; // can't reach
			int r = i; // can reach
			while (r - l > 1) {
				int mid = (l + r) >> 1;
				if (a[mid].pos >= a[i].pos - a[i].power) {
					r = mid;
				} else {
					l = mid;
				}
			}
			dp[i] = 1;
			if (l != -1) {
				dp[i] += dp[l];
			}
			maxSave = Math.max(maxSave, dp[i]);
		}
		
		out.println(n - maxSave);
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