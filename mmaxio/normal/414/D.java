import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	List<Integer>[] g;

	List<Integer> deps;

	void dfs(int v, int p, int dep) {
		if (v != 0) {
			deps.add(dep);
		}
		for (int i = 0; i < g[v].size(); i++) {
			int to = g[v].get(i);
			if (to == p) {
				continue;
			}
			dfs(to, v, dep + 1);
		}
	}

	void solve() throws IOException {
		int n = nextInt();

		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<Integer>(0);
		}

		int k = nextInt();
		int p = nextInt();
		for (int i = 0; i < n - 1; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			g[v1].add(v2);
			g[v2].add(v1);
		}

		deps = new ArrayList<>(n - 1);
		dfs(0, -1, 0);
		
		k = Math.min(k, n - 1);
		
		Collections.sort(deps);
		Collections.reverse(deps);
		int ans = 0;
		long curVal = 0;
		
		for (int i = 0, j = 0; i < n - 1; i++) {
			while (j - i < k && j < n - 1) {
				long newCurVal = curVal + deps.get(i) - deps.get(j);
				if (newCurVal > p) {
					break;
				} else {
					curVal = newCurVal;
					j++;
				}
			}
			ans = Math.max(ans, j - i);
			if (i != n - 2 && deps.get(i + 1).intValue() != deps.get(i).intValue()) {
				curVal -= j - i - 1;
			}
		}
		
		out.println(ans);
	}

	D() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
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