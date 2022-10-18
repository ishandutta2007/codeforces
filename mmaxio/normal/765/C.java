import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	int fast(int k, int a, int b) {
		
		if (a < b) {
			int tmp = a;
			a = b;
			b = tmp;
		}
		
		if (a < k) {
			return -1;
		}
		
		if (b < k) {
			if (a % k != 0) {
				return -1;
			}
			int games = a / k;
			if (0 <= b && b <= games * (k - 1)) {
				return games;
			}
			return -1;
		}
		
//		int ret = Math.min(a / k + b / k, (a + b) / (2 * k - 1));
//		return ret;
		
		return a / k + b / k;
	}
	
	int slow(int k, int a, int b) {
		int ret = -1;
		for (int x = 0; x * k <= a; x++)
			for (int y = 0; y * k <= b; y++) {
				if (k * x <= a && a <= k * x + (k - 1) * y && k * y <= b && b <= k * y + (k - 1) * x) {
					ret = Math.max(ret, x + y);
				}
			}
		return ret;
	}

	void solve() throws IOException {
		int k = nextInt();
		int a = nextInt();
		int b = nextInt();
		
		out.println(fast(k, a, b));
	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		
//		for (int k = 1; k < 1000; k++) {
//			for (int a = 1; a < 1000; a++)
//				for (int b = 0; b < 1000; b++) {
//					if (fast(k, a, b) != slow(k, a, b)) {
//						System.err.println(k + " " + a + " " + b);
//						System.err.println(fast(k, a, b));
//						System.err.println(slow(k, a, b));
//						throw new AssertionError();
//					}
//				}
//		}
		
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