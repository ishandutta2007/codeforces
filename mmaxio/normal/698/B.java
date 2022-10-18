import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int[] col;

	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt() - 1;
		}

		col = new int[n];

		List<List<Integer>> lst = new ArrayList<>();
		
		int root = -1;

		for (int i = 0; i < n; i++) {
			if (col[i] == 0) {
				int v = i;
				while (col[v] == 0) {
					col[v] = 1;
					v = a[v];
				}
				List<Integer> cycle = new ArrayList<>();
				if (col[v] == 1) {
					cycle.add(v);
					for (int u = a[v]; u != v; u = a[u]) {
						cycle.add(u);
					}
					lst.add(cycle);
					if (cycle.size() == 1) {
						root = v;
					}
				}
				
				v = i;
				while (col[v] != 2) {
					col[v] = 2;
					v = a[v];
				}
			}
		}
		
		if (root == -1) {
			root = lst.get(0).get(0);
		}
		
		int ans = 0;
		
		for (List<Integer> cycle : lst) {
			if (a[cycle.get(0)] != root) {
				ans++;
				a[cycle.get(0)] = root;
			}
		}
		
		out.println(ans);
		for (int x : a) {
			out.print((x + 1) + " ");
		}
		out.println();
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