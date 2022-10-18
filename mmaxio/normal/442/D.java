import java.io.*;
import java.util.*;

public class D_new {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int outp = 0;
		int[] p = new int[n];
		int[] val = new int[n];
		int[] childMax = new int[n];
		Arrays.fill(childMax, -1);
		for (int i = 0; i < n; i++) {
			p[i] = nextInt() - 2;
			val[i] = 1;
			if (p[i] == -1) {
				outp = Math.max(outp, 1);
			} else {
				do {
					if (childMax[p[i]] == -1) {
						childMax[p[i]] = 1;
						break;
					}
					if (val[p[i]] > 1) {
						break;
					}
					int v = p[i];
					val[v] = 2;
					while (p[v] != -1) {
//						if (i == n - 1) {
//							System.err.println(v + " " + val[v]);
//						}
						if (val[v] == childMax[p[v]]
								&& val[p[v]] == childMax[p[v]]) {
							val[p[v]]++;
							v = p[v];
						} else if (val[v] > childMax[p[v]]) {
							childMax[p[v]] = val[v];
							if (val[p[v]] < val[v]) {
								val[p[v]]++;
								v = p[v];
							} else {
								break;
							}
						} else {
							break;
						}
					}
					if (p[v] == -1) {
						outp = Math.max(outp, val[v]);
					}
				} while (false);
			}
			out.print(outp + " ");
		}
		out.println();
	}

	D_new() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D_new();
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