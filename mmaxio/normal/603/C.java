import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	int f(int x, int k) {
		if (k == 0) {
			if (x <= 2) {
				return x;
			}
			return 1 - x % 2;
		}
		// k == 1
		if (x < 4) {
			return x % 2;
		}
		if (x % 2 == 1) {
			return 0;
		}
		
		int trail = 0;
		while (x % 2 == 0) {
			trail++;
			x /= 2;
		}
		
		if (x == 1) {
			return trail % 2 == 0 ? 2 : 1;
		}
		
		if (x == 3) {
			return trail % 2 == 1 ? 2 : 1;
		}
		
		return trail % 2 == 0 ? 2 : 1;
	}

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt() % 2;
		
		int xor = 0;
		for (int i = 0; i < n; i++) {
			int x = nextInt();
			xor ^= f(x, k);
		}
		
		out.println(xor == 0 ? "Nicky" : "Kevin");
	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C();
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