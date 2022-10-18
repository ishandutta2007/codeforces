import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	List<Integer>[] g;
	boolean[] vis;
	
	void dfs(int v, List<Integer> comp) {
		vis[v] = true;
		comp.add(v);
		for (int i = 0; i < g[v].size(); i++) {
			int to = g[v].get(i);
			if (!vis[to]) {
				dfs(to, comp);
			}
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		g = new List[n];
		for (int i = 0; i < n; i++)
			g[i] = new ArrayList<>();
		int m = nextInt();
		for (int i = 0; i < m; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			g[v1].add(v2);
			g[v2].add(v1);
		}
		
		List<List<Integer>>[] arr = new List[3];
		for (int i = 0; i < 3; i++)
			arr[i] = new ArrayList<>();
		
		vis = new boolean[n];
		for (int i = 0; i < n; i++)
			if (!vis[i]) {
				List<Integer> comp = new ArrayList<>();
				dfs(i, comp);
				if (comp.size() > 3) {
					out.println(-1);
					return;
				}
				arr[comp.size() - 1].add(comp);
			}
		if (arr[0].size() < arr[1].size()) {
			out.println(-1);
			return;
		}
		for (List<Integer> team : arr[2]) {
			for (int x : team)
				out.print(x + 1 + " ");
			out.println();
		}
		
		for (int i = 0; i < arr[1].size(); i++) {
			for (int x : arr[1].get(i))
				out.print(x + 1 + " ");
			out.println(arr[0].get(i).get(0) + 1);
		}
		
		for (int i = arr[1].size(); i < arr[0].size(); i += 3) {
			for (int j = i; j < i + 3; j++)
				out.print(arr[0].get(j).get(0) + 1 + " ");
			out.println();
		}
		
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