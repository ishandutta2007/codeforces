import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Edge {
		int to, id;

		public Edge(int to, int id) {
			this.to = to;
			this.id = id;
		}

	}

	List<Edge>[] g;

	int[] col;

	void dfs(int v, int p, int forbColor) {
		int ptr = 0;
		for (Edge e : g[v]) {
			if (e.to == p) {
				continue;
			}
			while (ptr == forbColor) {
				ptr++;
			}
			col[e.id] = ptr;
			dfs(e.to, v, ptr);
			ptr++;
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}

		for (int i = 0; i < n - 1; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			g[v1].add(new Edge(v2, i));
			g[v2].add(new Edge(v1, i));
		}

		col = new int[n - 1];
		dfs(0, -1, -1);

		int size = 0;
		for (int i = 0; i < n - 1; i++) {
			size = Math.max(size, col[i] + 1);
		}

		List<Integer>[] outp = new List[size];
		for (int i = 0; i < size; i++) {
			outp[i] = new ArrayList<>();
		}

		for (int i = 0; i < n - 1; i++) {
			outp[col[i]].add(i);
		}

		out.println(size);
		for (List<Integer> lst : outp) {
			out.print(lst.size() + " ");
			for (int x : lst) {
				out.print((x + 1) + " ");
			}
			out.println();
		}
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