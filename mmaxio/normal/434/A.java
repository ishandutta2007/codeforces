import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int[] a = new int[m];
		for (int i = 0; i < m; i++) {
			a[i] = nextInt() - 1;
		}
		
		List<Integer>[] adj = new List[n];
		for (int i = 0; i < n; i++) {
			adj[i] = new ArrayList<>(0);
		}
		
		long init = 0;
		for (int i = 0; i < m - 1; i++) {
			init += Math.abs(a[i + 1] - a[i]);
			if (a[i] != a[i + 1]) {
				adj[a[i]].add(a[i + 1]);
				adj[a[i + 1]].add(a[i]);
			}
		}
		
		long ans = init;
		
		for (int i = 0; i < n; i++) {
			if (adj[i].isEmpty()) {
				continue;
			}
			Collections.sort(adj[i]);
			long cur = 0;
			int newI = adj[i].get(adj[i].size() / 2);
			long newV = 0;
			for (int j = 0; j < adj[i].size(); j++) {
				int x = adj[i].get(j);
				cur += Math.abs(i - x);
				newV += Math.abs(newI - x);
			}
			ans = Math.min(ans, init - cur + newV);
		}
		
		out.println(ans);
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new A().inp();
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