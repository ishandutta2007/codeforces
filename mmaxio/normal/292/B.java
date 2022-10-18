import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int[] deg = new int[n];
		for (int i = 0; i < m; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			deg[v1]++;
			deg[v2]++;
		}
		
		Arrays.sort(deg);
		if (deg[0] == 2 && deg[n - 1] == 2) {
			out.println("ring topology");
			return;
		}
		
		if (deg[0] == 1 && deg[1] == 1 && deg[2] == 2 && deg[n - 1] == 2) {
			out.println("bus topology");
			return;
		}
		
		if (deg[0] == 1 && deg[n - 2] == 1 && deg[n - 1] == n - 1) {
			out.println("star topology");
			return;
		}
		
		out.println("unknown topology");
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