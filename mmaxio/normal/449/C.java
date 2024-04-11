import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve(int n) {
		boolean[] isPrime = new boolean[n + 1];
		Arrays.fill(isPrime, true);
		for (int i = 2; i * i <= n; i++) {
			if (isPrime[i]) {
				for (int j = i * i; j <= n; j += i) {
					isPrime[j] = false;
				}
			}
		}

		List<Integer> ans = new ArrayList<>();

		boolean[] used = new boolean[n + 1];

		for (int i = n / 2; i >= 2; i--) {
			if (isPrime[i]) {
				int prev = i;
				for (int j = n / i * i; j > i; j -= i) {
					if (!used[j]) {
						if (prev == -1) {
							prev = j;
						} else {
							ans.add(prev);
							ans.add(j);
							used[prev] = used[j] = true;
							prev = -1;
						}
					}
				}
			}
		}

		out.println(ans.size() / 2);
		for (int i = 0; i < ans.size(); i += 2) {
			out.println(ans.get(i) + " " + ans.get(i + 1));
		}

	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
//		for (int n = 1; n <= 20; n++) {
//			out.println("n = " + n);
//			solve(n);
//		}
		 solve(nextInt());
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