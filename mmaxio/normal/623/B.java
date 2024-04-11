import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final long INF = Long.MAX_VALUE / 6;

	void fact(int x, HashSet<Integer> cand) {
		for (int i = 2; i * i <= x; i++) {
			if (x % i == 0) {
				cand.add(i);
				while (x % i == 0) {
					x /= i;
				}
			}
		}
		if (x != 1) {
			cand.add(x);
		}
	}

	long solve(int[] x, int p, int del, int edit) {
		long[] a = new long[x.length];
		for (int i = 0; i < x.length; i++) {
			int rem = x[i] % p;
			if (rem == 0) {
				a[i] = 0;
			} else if (rem == 1 || rem == p - 1) {
				a[i] = edit;
			} else {
				a[i] = INF;
			}
		}

		// don't delete
		long ans = 0;
		for (long v : a) {
			if (v == INF || ans == INF) {
				ans = INF;
			} else {
				ans += v;
			}
		}

		long[] costSuff = new long[a.length];
		for (int r = a.length - 1; r >= 1; r--) {
			if (a[r] == INF || costSuff[r] == INF) {
				costSuff[r - 1] = INF;
			} else {
				costSuff[r - 1] = costSuff[r] + (a[r] == 0 ? 0 : edit);
			}
		}
		
//		System.err.println(Arrays.toString(costSuff));

		long base = del;

		long lastPref = 0;
		long bestPref = 0;
		
		boolean hadShit = (a[0] == INF);
		
		ans = Math.min(ans, costSuff[0] + del);

		for (int r = 1; r < a.length - 1; r++) { // delete last position r(BUT NOT ALL!!!!)
			
			base += del;
			if (!hadShit) {
				lastPref += a[r - 1] - del;
				bestPref = Math.min(bestPref, lastPref);
			}
			
			ans = Math.min(ans, base + bestPref + costSuff[r]);

			if (a[r] == INF) {
				hadShit = true;
			}
		}
		
		// delete rightmost
		
		long[] pref = new long[a.length + 1];
		for (int i = 0; i < a.length - 1; i++) { // last not killed
			if (pref[i] == INF || a[i] == INF) {
				pref[i + 1] = INF;
			} else {
				pref[i + 1] = pref[i] + a[i];
			}
			
			if (i != a.length - 1 && pref[i + 1] != INF) {
				ans = Math.min(ans, pref[i + 1] + (long)del * (a.length - i - 1));
			}
		}
		
		return ans;
	}

	void solve() throws IOException {
		int n = nextInt();

		int del = nextInt();
		int edit = nextInt();

		int[] x = new int[n];
		for (int i = 0; i < n; i++) {
			x[i] = nextInt();
		}

		HashSet<Integer> cand = new HashSet<>();
		for (int i = x[0] - 1; i <= x[0] + 1; i++) {
			fact(i, cand);
		}

		for (int i = x[n - 1] - 1; i <= x[n - 1] + 1; i++) {
			fact(i, cand);
		}

//		cand.clear();
//		cand.add(5);
		
		long res = Long.MAX_VALUE;
		for (int p : cand) {
			res = Math.min(res, solve(x, p, del, edit));
		}

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