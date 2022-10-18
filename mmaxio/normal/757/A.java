import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		String s = nextToken();
		int[] cnt = new int[256];
		for (char c : s.toCharArray()) {
			cnt[c]++;
		}
		
		int[] need = new int[256];
		for (char c : "Bulbasaur".toCharArray()) {
			need[c]++;
		}
		
		int ret = Integer.MAX_VALUE;
		for (int i = 0; i < 256; i++) {
			if (need[i] != 0) {
				ret = Math.min(ret, cnt[i] / need[i]);
			}
		}
		
		out.println(ret);
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