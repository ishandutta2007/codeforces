import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int w = nextInt();
		int c = nextInt();
		int d = nextInt();
		int a = nextInt();
		int b = nextInt();
		// if (c == d) {
		// int cnt = w / Math.min(a, b);
		// out.println((long)cnt * c);
		// return;
		// }

		int maxX = w / a;

		long ret = 0;
		for (int x = 0; x < 1000000; x++) {
			long rest = w - (long) x * a;
			if (rest >= 0) {
				long y = rest / b;
				ret = Math.max(ret, (long) x * c + (long) y * d);
			}
		}
		
		for (int x = Math.max(0, maxX - 1000000); x <= maxX; x++) {
			long rest = w - (long) x * a;
			if (rest >= 0) {
				long y = rest / b;
				ret = Math.max(ret, (long) x * c + (long) y * d);
			}
		}
		
		int maxY = w / a;

		for (int y = 0; y < 1000000; y++) {
			long rest = w - (long) y * b;
			if (rest >= 0) {
				long x = rest / a;
				ret = Math.max(ret, (long) x * c + (long) y * d);
			}
		}
		
		for (int y = Math.max(0, maxY - 1000000); y <= maxY; y++) {
			long rest = w - (long) y * b;
			if (rest >= 0) {
				long x = rest / a;
				ret = Math.max(ret, (long) x * c + (long) y * d);
			}
		}
		
		out.println(ret);

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