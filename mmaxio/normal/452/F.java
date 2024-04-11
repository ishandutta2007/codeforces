import java.io.*;
import java.util.*;

public class F {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	boolean free(int[] p) {
		int n = p.length;
		if (n <= 15) {
			for (int i = 0; i < n; i++)
				for (int j = i + 1; j < n; j++)
					for (int k = j + 1; k < n; k++) {
						if (p[i] + p[k] == 2 * p[j]) {
							return false;
						}
					}
			return true;
		}
		int same = n / 2 - 6;
		for (int i = 0; i < same; i++) {
			if (!even(p[0] ^ p[i]) || !even(p[n - 1] ^ p[n - 1 - i])) {
				return false;
			}
		}
		int from = same;
		int to = n - same + 1;

		for (int i = from; i < to; i++)
			main: for (int j = i + 1; j < to; j++) {
				if (!even(p[i] ^ p[j])) {
					l1: do{
						int need = 2 * p[j] - p[i];
						if (need < 0 || need >= n) {
							break;
						}
						if (even(need ^ p[n - 1])) {
							for (int k = from; k < j; k++) {
								if (p[k] == need) {
									break l1;
								}
							}
							return false;
						} else {
							for (int k = j + 1; k < to; k++) {
								if (p[k] == need) {
									return false;
								}
							}
						}
					} while (false);
					l2: do {
						int need = 2 * p[i] - p[j];
						if (need < 0 || need >= n) {
							break;
						}
						if (even(need ^ p[0])) {
							for (int k = j + 1; k < to; k++) {
								if (p[k] == need) {
									break l2;
								}
							}
							return false;
						} else {
							for (int k = from; k < i; k++) {
								if (p[k] == need) {
									return false;
								}
							}
						}
					} while (false);
				}
			}

		int[] evens = new int[(n + 1) / 2];
		int evensPtr = 0;
		int[] odds = new int[n / 2];
		int oddsPtr = 0;
		for (int i = 0; i < n; i++) {
			if (even(p[i])) {
				evens[evensPtr++] = p[i] / 2;
			} else {
				odds[oddsPtr++] = p[i] / 2;
			}
		}
		if (evensPtr != evens.length || oddsPtr != odds.length) {
			throw new AssertionError();
		}
		return free(evens) && free(odds);
	}

	static boolean even(int x) {
		return (x & 1) == 0;
	}

	void solve() throws IOException {
		int n = nextInt();
		int[] p = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = nextInt() - 1;
		}
		out.println(free(p) ? "NO" : "YES");

	}

	F() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new F();
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