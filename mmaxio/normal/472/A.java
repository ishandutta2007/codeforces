import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	boolean isComp(int x) {
		return !BigInteger.valueOf(x).isProbablePrime(100);
	}

	void solve() throws IOException {
		int n = nextInt();

		boolean[] isPrime = new boolean[n + 1];
		Arrays.fill(isPrime, true);
		for (int i = 2; i <= n; i++) {
			if (isPrime[i]) {
				long st = (long) i * i;
				if (st > n) {
					break;
				}
				for (int j = (int) st; j <= n; j += i) {
					isPrime[j] = false;
				}
			}
		}

		while (true) {
			for (int x = 4;; x++) {
				if (!isPrime[x] && !isPrime[n - x]) {
					out.println(x + " " + (n - x));
					return;
				}
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