import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int INF = Integer.MAX_VALUE >> 1;

	int C(int n, int k) {
		long res = 1;
		for (int i = 1; i <= k; i++) {
			res = res * (n - k + i) / i;
			if (res >= INF)
				return INF;
		}
		return (int) res;
	}

	long minT(int n, int k) {
		long res = 0;
		for (int i = 0; i <= k; i++) {
			int tmp = C(k, i);
			if (n <= tmp)
				return res + (long) n * i;
			else {
				res += (long) tmp * i;
				n -= tmp;
			}
		}
		return Long.MAX_VALUE;
	}

	int solve(int n, int m) {
		if (n == 1)
			return 0;

		if (m == 1)
			return n - 1;

		int low = 0; // not enough
		int high = n - 1; // enough

		while (low < high - 1) {
			int mid = (low + high) >> 1;
			long cur = minT(n, mid);
			if (cur <= (long) mid * m)
				high = mid;
			else
				low = mid;
		}

		return high;
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		int t = nextInt();
		while (t-- > 0)
			out.println(solve(nextInt(), nextInt()));
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new E().inp();
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