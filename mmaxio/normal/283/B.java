import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	int[][] color;
	boolean[][] cycle;
	long[][] val;
	
	int[] a;
	int n;
	
	void dfs(int dir, int v) {
		// 0 forward
		// 1 backward
		
		color[dir][v] = 1;
		
		int newDir = dir ^ 1;
		int newV = (dir == 0) ? (v + a[v]) : (v - a[v]);
		
		if (newV < 0 || newV >= n) {
			val[dir][v] = a[v];
			color[dir][v] = 2;
			return;
		}
		
		if (cycle[newDir][newV] || color[newDir][newV] == 1) {
			cycle[dir][v] = true;
			color[dir][v] = 2;
			return;
		}
		
		if (color[newDir][newV] == 2) {
			val[dir][v] = a[v] + val[newDir][newV];
			color[dir][v] = 2;
			return;
		}
		
		dfs(newDir, newV);
		
		if (cycle[newDir][newV]) {
			cycle[dir][v] = true;
		} else {
			val[dir][v] = a[v] + val[newDir][newV];
		}
		
		color[dir][v] = 2;
	}

	void solve() throws IOException {
		n = nextInt();
		a = new int[n];
		for (int i = 1; i < n; i++) {
			a[i] = nextInt();
		}
		
		color = new int[2][n];
		cycle = new boolean[2][n];
		val = new long[2][n];
		
		cycle[0][0] = true;
		
		for (int i = 0; i < 2; i++)
			for (int j = 1; j < n; j++)
				if (color[i][j] == 0) {
					dfs(i, j);
				}
		
		for (int i = 1; i < n; i++) {
			if (cycle[1][i])
				out.println(-1);
			else
				out.println(i + val[1][i]);
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