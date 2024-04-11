import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int n;
	int k;

	char[][] f;

	int[][] color;
	List<Integer> sizeAL;

	int[] size;

	static final int[] DX = { -1, 0, 1, 0 };
	static final int[] DY = { 0, -1, 0, 1 };

	int dfs(int x, int y, int cur) {
		color[x][y] = cur;
		int ret = 1;
		for (int d = 0; d < 4; d++) {
			int cx = x + DX[d];
			int cy = y + DY[d];
			if (cx >= 0 && cx < n && cy >= 0 && cy < n && f[cx][cy] == '.'
					&& color[cx][cy] == 0) {
				ret += dfs(cx, cy, cur);
			}
		}
		return ret;
	}

	static class Counter {
		int[] count;
		int[] score;

		int sum = 0;

		void modify(int idx, int delta) {
			if (count[idx] != 0) {
				sum -= score[idx];
			}
			count[idx] += delta;
			if (count[idx] != 0) {
				sum += score[idx];
			}
		}

		int getSum() {
			return sum;
		}

		void clear() {
			Arrays.fill(count, 0);
			sum = 0;
		}

		public Counter(int[] score) {
			this.score = score;
			count = new int[score.length];
		}

	}

	void solve() throws IOException {
		n = nextInt();
		k = nextInt();

		f = new char[n][];
		for (int i = 0; i < n; i++) {
			f[i] = nextToken().toCharArray();
		}

		color = new int[n][n];
		sizeAL = new ArrayList<>();

		int comps = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (f[i][j] == '.' && color[i][j] == 0) {
					comps++;
					sizeAL.add(dfs(i, j, comps));
				}
			}
		}

		size = new int[comps];
		for (int i = 0; i < comps; i++) {
			size[i] = sizeAL.get(i);
		}
		
//		System.err.println(Arrays.deepToString(color));
//		System.err.println(Arrays.toString(size));

		Counter counter = new Counter(size);

		int ans = -1;

		for (int top = 0; top <= n - k; top++) {

			counter.clear();
			int xs = 0;

			for (int x = top - 1; x < top + k + 1; x++)
				for (int y = 0; y < k + 1 && y < n; y++) {

					if (x < 0 || x >= n) {
						continue;
					}

					int status = ((x == top - 1 || x == top + k) ? 1 : 0)
							+ (y == k ? 1 : 0);

					if (status == 2) {
						continue;
					}

					if (color[x][y] != 0) {
						counter.modify(color[x][y] - 1, 1);
					} else {
						if (status == 0) {
							xs++;
						}
					}
				}

			int value = counter.getSum() + xs;
//			System.err.println(value - xs);
//			System.err.println(xs);
//			System.err.println("--------");
			ans = Math.max(ans, value);
			

			for (int left = 1; left <= n - k; left++) {

				// update counter
				for (int x = top - 1; x <= top + k; x++) {
					if (x < 0 || x >= n) {
						continue;
					}
					int y1 = (x == top - 1 || x == top + k) ? left  - 1: left - 2;
					if (y1 >= 0 && y1 < n && color[x][y1] != 0) {
						counter.modify(color[x][y1] - 1, -1);
					}

					int y2 = (x == top - 1 || x == top + k) ? left + k - 1
							: left + k;
					if (y2 >= 0 && y2 < n && color[x][y2] != 0) {
						counter.modify(color[x][y2] - 1, 1);
					}
				}
				
				// update xs
				for (int x = top; x < top + k; x++) {
					if (color[x][left - 1] == 0) {
						xs--;
					}
					if (left + k - 1 < n && color[x][left + k - 1] == 0) {
						xs++;
					}
				}
				
				value = counter.getSum() + xs;
//				System.err.println(value);
				ans = Math.max(ans, value);

			}

		}
		
		out.println(ans);
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