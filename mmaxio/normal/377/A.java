import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	char[][] f;
	int n, m;

	boolean good(int i, int j) {
		return i >= 0 && i < n && j >= 0 && j < m && f[i][j] == '.';
	}

	static final int[] dx = { -1, 0, 1, 0 };
	static final int[] dy = { 0, -1, 0, 1 };

	void solve() throws IOException {
		n = nextInt();
		m = nextInt();
		int k = nextInt();

		f = new char[n][];
		for (int i = 0; i < n; i++) {
			f[i] = nextToken().toCharArray();
		}

		int x0 = -1, y0 = -1;

		outer: for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (good(i, j)) {
					x0 = i;
					y0 = j;
					break outer;
				}
			}
		}

		int[][] d = new int[n][m];
		for (int i = 0; i < n; i++) {
			Arrays.fill(d[i], Integer.MAX_VALUE / 4);
		}

		ArrayDeque<Integer> q = new ArrayDeque<>();
		List<Integer> order = new ArrayList<>();

		d[x0][y0] = 0;
		q.add(x0);
		q.add(y0);

		while (!q.isEmpty()) {
			int x = q.poll();
			int y = q.poll();

			order.add(x);
			order.add(y);

			for (int i = 0; i < 4; i++) {
				int cx = x + dx[i];
				int cy = y + dy[i];
				if (good(cx, cy) && d[cx][cy] > d[x][y] + 1) {
					d[cx][cy] = d[x][y] + 1;
					q.add(cx);
					q.add(cy);
				}
			}
		}
		
		for (int i = 0; i < k; i++) {
			int x = order.get(order.size() - 2 * i - 2);
			int y = order.get(order.size() - 2 * i - 1);
			f[x][y] = 'X';
		}
		
		for (int i = 0; i < n; i++) {
			out.println(f[i]);
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