import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final Random rng = new Random();

	void union(int[] p, int v1, int v2) {
		v1 = get(p, v1);
		v2 = get(p, v2);
		if (v1 != v2) {
			if (rng.nextBoolean()) {
				p[v2] = v1;
			} else {
				p[v1] = v2;
			}
		}
	}

	int get(int[] p, int v) {
		return p[v] == v ? v : (p[v] = get(p, p[v]));
	}
	
	
	int n;
	int go(int[] p1, int[] p2) {
		p1 = p1.clone();
		for (int i = 0; i < p2.length; i++) {
			union(p1, i, p2[i]);
		}
		int res = 0;
		for (int i = 0; i < p1.length; i++) {
			if (get(p1, i) == i)
				res++;
		}
		return res;
	}

	void solve() throws IOException {
		n = nextInt();
		int m = nextInt();
		int[] v1 = new int[m];
		int[] v2 = new int[m];

		for (int i = 0; i < m; i++) {
			v1[i] = nextInt() - 1;
			v2[i] = nextInt() - 1;
		}

		int[][] prefDSU = new int[m + 1][n];
		for (int i = 0; i < n; i++)
			prefDSU[0][i] = i;

		for (int i = 0; i < m; i++) {
			System.arraycopy(prefDSU[i], 0, prefDSU[i + 1], 0, n);
			union(prefDSU[i + 1], v1[i], v2[i]);
		}

		int[][] suffDSU = new int[m + 1][n];
		for (int i = 0; i < n; i++)
			suffDSU[m][i] = i;

		for (int i = m - 1; i >= 0; i--) {
			System.arraycopy(suffDSU[i + 1], 0, suffDSU[i], 0, n);
			union(suffDSU[i], v1[i], v2[i]);
		}
		
		
		int k = nextInt();
		while (k-- > 0) {
			int pref = nextInt() - 1;
			int suff = nextInt();
			
			out.println(go(prefDSU[pref], suffDSU[suff]));
		}

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