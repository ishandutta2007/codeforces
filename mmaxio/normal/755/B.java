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
		HashSet<String> set = new HashSet<>();
		for (int i = 0; i < n; i++) {
			String s = nextToken();
			set.add(s);
		}
		
		int both = 0;
		
		for (int i = 0; i < m; i++) {
			String s = nextToken();
			if (set.contains(s)) {
				both++;
			}
		}
		
		n -= both;
		m -= both;
		
		while (true) {
			if (both != 0) {
				both--;
			} else if (n != 0) {
				n--;
			} else {
				out.println("NO");
				return;
			}
			
			if (both != 0) {
				both--;
			} else if (m != 0) {
				m--;
			} else {
				out.println("YES");
				return;
			}
			
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