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
		
		char c = nextToken().charAt(0);
		
		char[][]f = new char[n][];
		for (int i =0; i < n; i++)
			f[i] = nextToken().toCharArray();
		
		HashSet<Character> ans = new HashSet<Character>();
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m - 1; j++) {
				char c1 = f[i][j];
				char c2 = f[i][j + 1];
				if (c1 == c && c2 != c && c2 != '.')
					ans.add(c2);
				if (c2 == c && c1 != c && c1 != '.')
					ans.add(c1);
			}
		}
		
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < m; j++) {
				char c1 = f[i][j];
				char c2 = f[i + 1][j];
				if (c1 == c && c2 != c && c2 != '.')
					ans.add(c2);
				if (c2 == c && c1 != c && c1 != '.')
					ans.add(c1);
			}
		}
		
		out.println(ans.size());
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B().inp();
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