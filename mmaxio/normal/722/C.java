import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n + 2];
		for (int i = 1; i <= n; i++) {
			a[i] = nextInt();
		}
		
		int[] order = new int[n];
		for (int i = 0; i < n; i++) {
			order[i] = nextInt();
		}
		
		int[] left = new int[n + 2];
		int[] right = new int[n + 2];
		long[] sum = new long[n + 2];
		Arrays.fill(left, -1);
		Arrays.fill(right, -1);
		
		long ans = 0;
		
		long[] outp = new long[n];
		for (int i = n - 1; i >= 0; i--) {
			outp[i] = ans;
			int pos = order[i];
			int newLeft = (left[pos - 1] == -1 ? pos : left[pos - 1]);
			int newRight = (right[pos + 1] == -1 ? pos : right[pos + 1]);
			long newSum = a[pos] + sum[newLeft] + sum[newRight];
			ans = Math.max(ans, newSum);
			sum[newLeft] = sum[newRight] = newSum;
			right[newLeft] = newRight;
			left[newRight] = newLeft;
		}
		
		for (long x : outp) {
			out.println(x);
		}
		
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