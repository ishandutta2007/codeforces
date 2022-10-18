import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int res = nextInt();
		int high = nextInt() - 1;
		
		int pos = (n + 1) / 2;
		int neg = n / 2;
		
		res -= pos - neg;
		if (res < -neg * high || res > pos * high) {
			out.println(-1);
			return;
		}
		
		for (int i = 0; i < n; i++) {
			int x = 1;
			if ((i & 1) == 0) {
				if (res > 0) {
					int put = Math.min(res, high);
					x += put;
					res -= put;
				}
			} else {
				if (res < 0) {
					int put = Math.min(-res, high);
					x += put;
					res += put;
				}
			}
			out.print(x + " ");
		}
		out.println();
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