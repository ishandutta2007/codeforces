import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void test(int n) {
		char from = 'a';
		char to = (char) (from + n - 1);

		StringBuilder sb = new StringBuilder();
		for (char c = from; c <= to; c++) {
			sb.append(c);
		}

		String s = sb.toString();

		HashSet<String> seen = new HashSet<>();
		seen.add(s);

		ArrayDeque<String> q = new ArrayDeque<>();
		q.add(s);

		while (!q.isEmpty()) {
			s = q.poll();
			out.println(s);

			for (int i = 0; i + 1 < n; i++) {
				String t = morph(s, i, i + 1);
				if (!seen.contains(t)) {
					seen.add(t);
					q.add(t);
				}

				t = morph(s, i + 1, i);
				if (!seen.contains(t)) {
					seen.add(t);
					q.add(t);
				}
			}
		}

		out.println(seen.size());
	}

	String morph(String s, int from, int to) {
		char[] buf = s.toCharArray();
		buf[to] = buf[from];
		return new String(buf);
	}

	static final int ALPH = 26;
	static final int P = 1_000_000_007;

	void solve() throws IOException {

		int n = nextInt();
		String s = nextToken();

		int[][] pref = new int[n + 1][n + 1]; // pos, length
		pref[0][0] = 1;

		int[] last = new int[ALPH];
		Arrays.fill(last, -1);

		for (int i = 0; i < n; i++) {
			int idx = s.charAt(i) - 'a';

			int prev = last[idx];

			for (int len = 1; len <= i + 1; len++) {
				int delta = pref[i][len - 1];

				if (prev != -1) {
					delta -= pref[prev + 1][len - 1];
					if (delta < 0) {
						delta += P;
					}
				}
				
				pref[i + 1][len] = pref[i][len] + delta;
				if (pref[i + 1][len] >= P) {
					pref[i + 1][len] -= P;
				}

			}
			
			pref[i + 1][0] = 1;
			
			last[idx] = i;
		}
		
//		System.err.println(Arrays.toString(pref[n]));
		
		int[] inv = new int[n + 2];
		inv[0] = 0;
		inv[1] = 1;
		for (int i = 2; i < inv.length; i++) {
			inv[i] = P - (int) ((long) (P / i) * inv[P % i] % P);
		}
			
		// HINT: p % x = p - (p / x) * x
		// here '/' stands for integer division
		
		int ans = 0;
		
		int coef = 1;
		for (int k = 1; k <= n; k++) {
			ans += (int)((long)pref[n][k] * coef % P);
			if (ans >= P) {
				ans -= P;
			}
			
			coef = (int)((long)coef * inv[k] % P * (n - k) % P);
		}
		
		out.println(ans);

	}

	D() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		// test(6);
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D();
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