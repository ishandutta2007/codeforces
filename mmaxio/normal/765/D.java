import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int[] f = new int[n];

		boolean[] has = new boolean[n];

		for (int i = 0; i < n; i++) {
			f[i] = nextInt() - 1;
			has[f[i]] = true;
		}

		int m = 0;
		for (int i = 0; i < n; i++) {
			m += has[i] ? 1 : 0;
		}

		for (int i = 0; i < n; i++) {
			if (has[i]) {
				if (f[i] != i) {
					out.println(-1);
					return;
				}
			}
		}
		
//		out.println(m);
//		out.println("dunno");
		
		int[] g = new int[n];
		int[] h = new int[m];
		
		int ptr = 0;
		
		int[] where = new int[n];
		
		for (int i = 0; i < n; i++) {
			if (has[i]) {
				h[ptr] = i;
				where[i] = ptr;
				ptr++;
			}
		}
		
		
		for (int i = 0; i < n; i++) {
			g[i] = where[f[i]];
		}
		
		
		out.println(m);
		for (int i = 0; i < n; i++) {
			out.print(g[i] + 1 + " ");
		}
		out.println();
		
		for (int i = 0; i < m; i++) {
			out.print(h[i] + 1 + " ");
		}
		out.println();
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