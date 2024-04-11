import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	long f(int x, int y, int sz) {
		if (x > y) {
			int tmp = x;
			x = y;
			y = tmp;
		}
		if (sz <= x)
			return (long) sz * (sz + 1) / 2;
		if (sz >= x + y - 1)
			return (long) x * y;
		long val = x * (x + 1) / 2;
		if (sz <= y)
			return val + (long) (sz - x) * x;

		long rest = x + y - 1 - sz;
		return (long) x * y - (long) rest * (rest + 1) / 2;
	}

	long count(int x, int y, int n, int time) {
		long DL = f(x + 1, y + 1, time + 1);
		long DR = f(n - x, y + 1, time + 1);
		long UL = f(x + 1, n - y, time + 1);
		long UR = f(n - x, n - y, time + 1);
//		if (time == 1)
//			System.err.println(DL + " " + DR + " " + UL + " " + UR);
		long L = Math.min(x + 1, time + 1);
		long R = Math.min(n - x, time + 1);
		long U = Math.min(n - y, time + 1);
		long D = Math.min(y + 1, time + 1);
//		if (time == 1)
//			System.err.println(L + " " + R + " " + U + " " + D);
		return DL + DR + UL + UR - L - R - U - D + 1;
	}

	void solve() throws IOException {
		int n = nextInt();
		int x = nextInt() - 1;
		int y = nextInt() - 1;
		long need = nextLong();

		if (need == 1) {
			out.println(0);
			return;
		}

		int low = 0;
		int high = Math.max(x, n - 1 - x) + Math.max(y, n - 1 - y);
		
//		for (int i = 0; i <= 100; i++)
//			System.err.println(count(x, y, n, i));

		while (low < high - 1) {
			int mid = (int) (((long) low + high) / 2);
			if (count(x, y, n, mid) >= need)
				high = mid;
			else
				low = mid;
		}

		out.println(high);

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