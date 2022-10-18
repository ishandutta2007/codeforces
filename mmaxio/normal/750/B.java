import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		
		int cur = 10_000;
		
		for (int i = 0; i < n; i++) {
			
			int len = nextInt();
			
			String dir = nextToken();
			
			if (cur == 10_000 && !dir.equals("South")) {
				out.println("NO");
				return;
			}
			
			if (cur == -10_000 && !dir.equals("North")) {
				out.println("NO");
				return;
			}
			
			if (dir.equals("South")) {
				cur -= len;
			} else if (dir.equals("North")) {
				cur += len;
			}
			
			if (cur < -10_000 || cur > 10_000) {
				out.println("NO");
				return;
			}
		}
		
		out.println(cur == 10_000 ? "YES" : "NO");
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