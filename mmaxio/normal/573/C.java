import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	List<Integer>[] g;

	void solve() throws IOException {
		int n = nextInt();
		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>(2);
		}

		for (int i = 0; i < n - 1; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			g[v1].add(v2);
			g[v2].add(v1);
		}

		boolean more2 = false;
		for (int i = 0; i < n; i++) {
			more2 |= g[i].size() > 2;
		}

		if (!more2) {
			out.println("Yes");
			return;
		}

		for (int i = 0; i < n; i++) {
			int v = i;
			while (g[v].size() == 1) {
				int u = g[v].get(0);
				if (g[u].size() > 2) {
					break;
				}
				g[v].clear();
				g[u].remove(Integer.valueOf(v));
				v = u;
			}
		}

		boolean[] trash = new boolean[n];

		for (int v = 0; v < n; v++) {
			if (g[v].size() == 3) {
				int cnt = 0;
				for (int u : g[v]) {
					if (g[u].size() == 1) {
						cnt++;
					}
				}
				if (cnt == 3) {
					out.println("Yes");
					return;
				}
				if (cnt == 2) {
					trash[v] = true;
				}
			}
		}

		boolean[] watch = new boolean[n];
		for (int i = 0; i < n; i++) {
			watch[i] = g[i].size() > 1 && !trash[i];
		}

		int maxDeg = -1;

		for (int i = 0; i < n; i++) {
			if (watch[i]) {
				int deg = 0;
				for (int u : g[i]) {
					if (watch[u]) {
						deg++;
					}
				}
				maxDeg = Math.max(maxDeg, deg);
			}
		}

		out.println(maxDeg <= 2 ? "Yes" : "No");
	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C();
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