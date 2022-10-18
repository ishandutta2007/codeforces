import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	static final int P = 1_000_000_007;
	static final int INV2 = (P + 1) / 2;

	void solve() throws IOException {
		long a = nextInt();
		long b = nextInt();
		long ans = 0;
		for (long r = 1; r < b; r++) {
			long fst = (r * b + r) % P;
			long last = (a * r % P * b % P + r) % P;
			long sum = (fst + last) * INV2 % P;
			ans += sum;
			ans %= P;
		}
		ans = ans * a % P;
		out.println(ans);
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