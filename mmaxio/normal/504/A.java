import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int[] deg = new int[n];
		int[] xor = new int[n];
		int m = 0;
		for (int i = 0; i < n; i++) {
			deg[i] = nextInt();
			xor[i] = nextInt();
			m += deg[i];
		}
		
		m /= 2;
		
		Queue<Integer> q = new ArrayDeque<>();
		for (int i = 0; i < n; i++) {
			if (deg[i] == 1) {
				q.add(i);
			}
		}
		out.println(m);
		while (!q.isEmpty()) {
			int v = q.poll();
			if (deg[v] != 1) {
				continue;
			}
			int u = xor[v];
			out.println(v + " " + u);
			deg[v]--;
			deg[u]--;
			xor[u] ^= v;
			if (deg[u] == 1) {
				q.add(u);
			}
		}
	}

	A() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new A();
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