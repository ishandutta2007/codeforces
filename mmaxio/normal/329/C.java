import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	long startTime = System.currentTimeMillis();

	int n, m;
	int[] a, b;
	int[] ind;
	int[] deg;

	void bruteForce() throws IOException {
		boolean[][] ban = new boolean[n][n];

		for (int i = 0; i < m; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			ban[v1][v2] = ban[v2][v1] = true;
		}

		int newM = n * (n - 1) / 2 - m;
		a = new int[newM];
		b = new int[newM];
		int ptr = 0;

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (!ban[i][j]) {
					a[ptr] = i;
					b[ptr] = j;
					ptr++;
				}
			}
		}

		deg = new int[n];
		ind = new int[m];
		if (gen(0, 0)) {
			for (int i = 0; i < m; i++) {
				out.println((a[ind[i]] + 1) + " " + (b[ind[i]] + 1));
			}
		} else {
			out.println(-1);
		}
	}

	boolean gen(int i, int pick) {
		if (pick == m) {
			return true;
		}
		if (i == a.length) {
			return false;
		}
		if (deg[a[i]] < 2 && deg[b[i]] < 2) {
			deg[a[i]]++;
			deg[b[i]]++;
			ind[pick] = i;
			if (gen(i + 1, pick + 1))
				return true;
			deg[a[i]]--;
			deg[b[i]]--;
		}

		if (gen(i + 1, pick)) {
			return true;
		}
		return false;
	}

	void solve() throws IOException {
		n = nextInt();
		m = nextInt();

		long edges = (long) n * (n - 1) / 2;
		if (m > edges - m) {
			out.println(-1);
			return;
		}

		if (n <= 8) {
			bruteForce();
		} else {
			smart();
		}

	}

	void smart() throws IOException {
		Random rng = new Random();
		List<Integer>[] g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>(2);
		}

		for (int i = 0; i < m; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			g[v1].add(v2);
			g[v2].add(v1);
		}

		int[] order = new int[n + 1];

		outer: while (System.currentTimeMillis() - startTime < 2300) {
			for (int i = 0; i < n; i++) {
				int j = rng.nextInt(i + 1);
				order[i] = order[j];
				order[j] = i;
			}
			order[n] = order[0];
			for (int i = 0; i < m; i++) {
				int v1 = order[i];
				int v2 = order[i + 1];
				if (g[v1].contains(v2))
					continue outer;
			}
			for (int i = 0; i < m; i++) {
				out.println((order[i] + 1) + " " + (order[i + 1] + 1));
			}
			return;
		}
		out.println(-1);
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