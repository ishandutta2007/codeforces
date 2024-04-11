import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	// int n;
	// int[] to;
	//
	// boolean[] was;
	//
	// boolean check() {
	// for (int i = 1; i < n; i++) {
	// Arrays.fill(was, false);
	//
	// int v = i;
	// while (!was[v] && v != 0) {
	// was[v] = true;
	// v = to[v];
	// }
	// if (v != 0)
	// return false;
	// }
	// return true;
	// }
	//
	// int go(int pos) {
	// if (pos == n) {
	// if (check())
	// return 1;
	// else
	// return 0;
	// }
	// int res = 0;
	// for (int i = 0; i < n; i++) {
	// if (pos != 0 && i == pos)
	// continue;
	// to[pos] = i;
	// res += go(pos + 1);
	// }
	// return res;
	// }

	static final int[] CNT = { 0, 1, 2, 9, 64, 625, 7776, 117649, 2097152 };
	static final int MOD = 1_000_000_007;

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		
		int res = CNT[k];
		for (int i = k; i < n; i++)
			res = (int)((long)res * (n - k) % MOD);
		
		out.println(res);
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