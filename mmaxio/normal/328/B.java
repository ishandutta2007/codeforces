import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	int[] count(String s) {
		int[] ret = new int[10];
		for (int i = 0; i < s.length(); i++) {
			ret[s.charAt(i) - '0']++;
		}
		ret[2] += ret[5];
		ret[5] = 0;
		ret[6] += ret[9];
		ret[9] = 0;
		return ret;
	}

	void solve() throws IOException {
		int[] need = count(nextToken());

		int[] have = count(nextToken());
		
		int ans = Integer.MAX_VALUE;
		for (int i = 0; i < 10; i++) {
			if (need[i] > 0) {
				ans = Math.min(ans, have[i] / need[i]);
			}
		}
		
		out.println(ans);
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