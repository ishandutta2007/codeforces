import java.io.*;
import java.util.*;

public class D1 {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int b;

	int decode(int x, int y) {
		return x * b + y;
	}

	static final String DIRS = "ULDR";
	static final int[] DX = { 0, -1, 0, 1 };
	static final int[] DY = { 1, 0, -1, 0 };

	static int getDir(int dx, int dy) {
		for (int i = 0; i < 4; i++) {
			if (DX[i] == dx && DY[i] == dy)
				return i;
		}
		throw new AssertionError();
	}

	List<Integer> path = new ArrayList<>();
	int[] color = new int[b * b];

	void solve() throws IOException {
		int n = nextInt();
		b = nextInt() + 1;
		
		int N = b * b * 4;

		int[] next = new int[N];

		for (int i = 0; i < N; i++) {
			int cDir = i & 3;
			int x = (i >> 2) / b;
			int y = (i >> 2) % b;

			int nx = x + DX[cDir];
			int ny = y + DY[cDir];

			if (nx < 0 || ny < 0 || nx >= b || ny >= b) {
				next[i] = i;
			} else {
				next[i] = (decode(nx, ny) << 2) | cDir;
			}
		}

		for (int i = 0; i < n; i++) {
			int x0 = nextInt();
			int y0 = nextInt();
			int x1 = nextInt();
			int y1 = nextInt();

			int len = Math.abs(x1 - x0) + Math.abs(y1 - y0) + 1;
			int dx = Integer.signum(x1 - x0);
			int dy = Integer.signum(y1 - y0);

			int cDir = getDir(dx, dy);

			for (int j = 0; j < len; j++) {

				int v = decode(x0, y0);

				for (int dd = 0; dd < 4; dd++) {
					next[(v << 2) | dd] = next[(v << 2) | cDir];
				}

				x0 += DX[cDir];
				y0 += DY[cDir];
			}
		}

		int q = nextInt();
		int[] qV = new int[q];
		long[] timeV = new long[q];
		
		for (int i = 0; i < q; i++) {
			int x = nextInt();
			int y = nextInt();
			int dir = DIRS.indexOf(nextToken().charAt(0));
			qV[i] = (decode(x, y) << 2) | dir;
			timeV[i] = nextLong();
		}
		
		int[] newNext = new int[N];
		
		for (int iter = 0; iter < 50; iter++) {
			for (int i = 0; i < q; i++) {
				if ((timeV[i] & 1) == 1 && qV[i] != -1) {
					qV[i] = next[qV[i]];
				}
				timeV[i] >>= 1;
			}
			
			for (int i = 0; i < N; i++) {
				newNext[i] = next[next[i]];
			}
			

			int[] tmp = next;
			next = newNext;
			newNext = tmp;

		}
		
		for (int i = 0; i < q; i++) {
			int ret = qV[i] >> 2;
			out.println(ret / b + " " + ret % b);
		}
	}

	D1() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D1();
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