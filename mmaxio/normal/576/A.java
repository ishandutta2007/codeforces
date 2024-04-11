import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		boolean[] isPrime = new boolean[n + 1];
		Arrays.fill(isPrime, true);
		List<Integer> ret = new ArrayList<>();
		for (int i = 2; i <= n; i++) {
			if (isPrime[i]) {
				for (int j = i; j <= n; j *= i) {
					ret.add(j);
				}
				for (int j = i * i; j <= n; j += i) {
					isPrime[j] = false;
				}
			}
		}
		out.println(ret.size());
		for (int x : ret) {
			out.print(x + " ");
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