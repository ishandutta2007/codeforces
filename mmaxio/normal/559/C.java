import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Point implements Comparable<Point> {
		int x, y;

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public int compareTo(Point o) {
			if (x != o.x) {
				return x < o.x ? -1 : 1;
			}
			return Integer.compare(y, o.y);
		}
	}

	static final int P = 1_000_000_007;
	static final int N = 200001;

	static int pow(int a, int b) {
		int ret = 1;
		for (; b > 0; b >>= 1) {
			if ((b & 1) == 1) {
				ret = (int) ((long) ret * a % P);
			}
			a = (int) ((long) a * a % P);
		}
		return ret;
	}

	static final int[] fact = new int[N];
	static final int[] invFact = new int[N];
	static {
		fact[0] = invFact[0] = 1;
		for (int i = 1; i < N; i++) {
			fact[i] = (int) ((long) fact[i - 1] * i % P);
			invFact[i] = pow(fact[i], P - 2);
		}
	}

	static int C(int n, int k) {
		if (n < 0 || k < 0 || k > n) {
			return 0;
		}
		return (int) ((long) fact[n] * invFact[k] % P * invFact[n - k] % P);
	}

	static int ways(int w, int h) {
		return C(w + h, w);
	}

	void solve() throws IOException {
		int n = nextInt() - 1;
		int m = nextInt() - 1;
		int q = nextInt();
		Point[] qs = new Point[q];
		for (int i = 0; i < q; i++) {
			qs[i] = new Point(nextInt() - 1, nextInt() - 1);
		}

		Arrays.sort(qs);

		int ret = ways(n, m);

		int[] even = new int[q];
		int[] odd = new int[q];

		for (int i = 0; i < q; i++) {
			// change answer
			int x = qs[i].x;
			int y = qs[i].y;

			int toEnd = ways(n - x, m - y);
			int fromStart = ways(x, y);

			// from start
			ret -= (int) ((long) fromStart * toEnd % P);
			if (ret < 0) {
				ret += P;
			}
			odd[i] = fromStart;

			// from prev
			for (int j = 0; j < i; j++) {
				int dx = x - qs[j].x;
				int dy = y - qs[j].y;
				int here = ways(dx, dy);
				if (dx >= 0 && dy >= 0) {

					long optVar = (long) even[j] * here % P;

					ret -= (int) (optVar * toEnd % P);
					if (ret < 0) {
						ret += P;
					}
					odd[i] += (int) optVar;
					if (odd[i] >= P) {
						odd[i] -= P;
					}

					optVar = (long) odd[j] * here % P;

					ret += (int) (optVar * toEnd % P);
					if (ret >= P) {
						ret -= P;
					}
					even[i] += (int) optVar;
					if (even[i] >= P) {
						even[i] -= P;
					}
				}
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