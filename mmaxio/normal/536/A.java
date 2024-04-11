import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int f(int A, int B, int low, int cnt, int size) {
		int just = Math.floorDiv(cnt - A, B) + 1;
		if (just < low) {
			return -1;
		}
		int initLow = low;
		int high = just + 1;
		while (high - low > 1) {
			int mid = (low + high) / 2;
			long total = ((2 * A + (long) B * (initLow - 1 + mid - 1)))
					* (mid - initLow + 1) / 2;
//			System.err.println(mid + " " + total);
			if (total <= (long) cnt * size) {
				low = mid;
			} else {
				high = mid;
			}
//			System.err.println(low + " " + high);
		}
		return low;
	}

	void solve() throws IOException {
		int A = nextInt();
		int B = nextInt();
		int q = nextInt();
		for (int i = 0; i < q; i++) {
			int low = nextInt();
			int cnt = nextInt();
			int size = nextInt();
			out.println(f(A, B, low, cnt, size));
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