import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	HashSet<Integer>[] g;

	int n;

	void checkAndOutput(int[] ans) {
		for (int i = 0; i < n; i++) {
			int v = ans[i];
			int j = i + 1;
			if (j >= n)
				j -= n;
			if (!g[v].contains(ans[j])) {
				out.println(-1);
				return;
			}
			j++;
			if (j >= n)
				j -= n;
			if (!g[v].contains(ans[j])) {
				out.println(-1);
				return;
			}

			j = i - 1;
			if (j < 0)
				j += n;
			if (!g[v].contains(ans[j])) {
				out.println(-1);
				return;
			}
			j--;
			if (j < 0)
				j += n;
			if (!g[v].contains(ans[j])) {
				out.println(-1);
				return;
			}
		}
		for (int i = 0; i < n; i++)
			out.print(ans[i] + 1 + " ");
		out.println();
	}

	void solve() throws IOException {
		n = nextInt();
		g = new HashSet[n];
		for (int i = 0; i < n; i++)
			g[i] = new HashSet<>();

		for (int i = 0; i < 2 * n; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			g[v1].add(v2);
			g[v2].add(v1);
		}

		for (int i = 0; i < n; i++)
			if (g[i].size() != 4) {
				out.println(-1);
				return;
			}

		if (n == 5) {
			out.println("1 2 3 4 5");
			return;
		}

		if (n == 6) {
			int[] ans = new int[n];
			boolean[] used = new boolean[n];
			int ptr = 0;
			outer: for (int i = 0; i < n; i++)
				if (!used[i]) {
					ans[ptr] = i;

					for (int j = 0; j < n; j++)
						if (i != j && !used[j] && !g[i].contains(j)) {
							ans[ptr + 3] = j;
							used[i] = used[j] = true;
							ptr++;
							continue outer;
						}
					out.println(-1);
					return;
				}
			checkAndOutput(ans);
			return;
		}

		int[] aux = new int[4];

		int[] ans = new int[n];

		cycle: for (int i = 0, v = 0, prev = -1; i < n; i++) {
			ans[i] = v;
			int ptr = 0;
			for (Iterator<Integer> e = g[v].iterator(); e.hasNext();)
				aux[ptr++] = e.next();

			for (int j = 0; j < 4; j++) {
				int u = aux[j];
				int deg = 0;
				for (int k = 0; k < 4; k++)
					if (g[u].contains(aux[k]))
						deg++;
				if (deg == 2 && u != prev) {
					prev = v;
					v = u;
					continue cycle;
				}
			}

			out.println(-1);
			return;
		}

		checkAndOutput(ans);

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