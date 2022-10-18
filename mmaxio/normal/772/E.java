import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int[] par, lft, rgh;
	int[] leaf;
	
	
	boolean[] isLeaf;
	int[] sz;
	
	int dfs(int v) {
		sz[v] = 1;
		if (!isLeaf[v]) {
			sz[v] += dfs(lft[v]) + dfs(rgh[v]);
		}
		return sz[v];
	}
	
	void work(int last) {
		int root = -1;
		isLeaf = new boolean[2 * last - 3];
		for (int i = 0; i < 2 * last - 3; i++) {
			if (par[i] == -1) {
				root = i;
			}
			if (lft[i] == -1) {
				isLeaf[i] = true;
			}
		}
		
		sz = new int[2 * last - 3];
		
		while (!isLeaf[root]) {
			dfs(root);
			int mid = root;
			while (true) {
				if (isLeaf[mid]) {
					throw new AssertionError();
				}
				if (2 * sz[lft[mid]] > sz[root]) {
					mid = lft[mid];
					continue;
				}
				if (2 * sz[rgh[mid]] > sz[root]) {
					mid = rgh[mid];
					continue;
				}
				break;
 			}
			
			out.println(leaf[lft[mid]] + " " + leaf[rgh[mid]] + " " + last);
			out.flush();
			
			String resp = nextToken();
			if (resp.equals("X")) {
				isLeaf[mid] = true;
			} else if (resp.equals("Y")) {
				root = rgh[mid];
			} else {
				root = lft[mid];
			}
		}
		
		splitPar(root, 2 * last - 3);
		addRightSon(2 * last - 3, 2 * last - 2);
		leaf[2 * last - 2] = last;
	}
	
	void splitPar(int v, int u) {
		int pv = par[v];
		if (pv != -1) {
			if (lft[pv] == v) {
				lft[pv] = u;
			} else {
				rgh[pv] = u;
			}
		}
		par[u] = pv;
		
		lft[u] = v;
		par[v] = u;
		
		leaf[u] = leaf[v];
	}
	
	void addRightSon(int v, int u) {
		rgh[v] = u;
		par[u] = v;
	}
	
	void solve() throws IOException {
		int n = nextInt();
		
		par = new int[2 * n - 1];
		lft = new int[2 * n - 1];
		rgh = new int[2 * n - 1];
		Arrays.fill(par, -1);
		Arrays.fill(lft, -1);
		Arrays.fill(rgh, -1);
		
		leaf = new int[2 * n - 1];
		
		leaf[0] = 1;
		leaf[1] = 2;
		leaf[2] = 1;
		par[0] = 2;
		par[1] = 2;
		lft[2] = 0;
		rgh[2] = 1;
		
		for (int i = 3; i <= n; i++) {
			work(i);
		}
		
		out.println(-1);
		for (int i = 0; i < 2 * n - 1; i++) {
			if (par[i] == -1) {
				out.print("-1 ");
			} else {
				out.print((par[i] + 1) + " ");
			}
		}
		out.println();
		out.flush();
	}

	E() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new E();
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

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong(){
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}