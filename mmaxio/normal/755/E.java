import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		if (k == 1 || k > 3 || n <= 3) {
			out.println(-1);
			return;
		}
		
		if (n == 4) {
			if (k == 3) {
				out.println("3\n1 2\n2 3\n3 4");
			} else {
				out.println(-1);
			}
			return;
		}
		
		if (k == 2) {
			out.println(n - 1);
			for (int i = 0; i < n - 1; i++) {
				out.println((i + 1) + " " + (i + 2));
			}
			return;
		}
		
		out.println((n - 2) * (n - 3) / 2 + 2);
		out.println("1 3");
		out.println("2 4");
		
		for (int i = 3; i <= n; i++)
			for (int j = i + 1; j <= n; j++) {
				out.println(i + " " + j);
			}
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