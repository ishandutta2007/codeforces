import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Number implements Comparable<Number> {
		int val, x, y;

		@Override
		public int compareTo(Number o) {
			return Integer.compare(val, o.val);
		}

		public Number(int val, int x, int y) {
			this.val = val;
			this.x = x;
			this.y = y;
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();

		Number[] a = new Number[n * m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				a[i * m + j] = new Number(nextInt(), i, j);
			}

		Arrays.sort(a);

		int[] highR = new int[n];
		int[] highC = new int[m];

		List<Integer>[] byX = new List[n];
		for (int i = 0; i < n; i++) {
			byX[i] = new ArrayList<>(m);
		}

		List<Integer>[] byY = new List[m];
		for (int i = 0; i < m; i++) {
			byY[i] = new ArrayList<>(n);
		}

		int time = 0;
		int[] lastByX = new int[n];
		int[] lastByY = new int[m];

		int[][] ans = new int[n][m];

		List<Integer> fresh = new ArrayList<>(n * m);
		Queue<Integer> q = new ArrayDeque<>();

		int[] usedX = new int[n];
		int[] usedY = new int[m];

		boolean[] used = new boolean[n * m];

		for (int i = 0; i < n * m;) {
			time++;
			int j = i;
			while (j < n * m && a[j].val == a[i].val) {

				int x = a[j].x;
				int y = a[j].y;

				if (lastByX[x] != time) {
					lastByX[x] = time;
					byX[x].clear();
				}
				byX[x].add(j);

				if (lastByY[y] != time) {
					lastByY[y] = time;
					byY[y].clear();
				}
				byY[y].add(j);

				j++;
			}

			for (int k = i; k < j; k++) {
				if (ans[a[k].x][a[k].y] != 0) {
					continue;
				}
				fresh.clear();
				q.add(k);
				used[k] = true;
				int highSeen = 0;
				while (!q.isEmpty()) {
					int v = q.poll();
					fresh.add(v);
					int x = a[v].x;
					int y = a[v].y;
					highSeen = Math.max(highSeen, Math.max(highR[x], highC[y]));

					if (usedX[x] != time) {
						usedX[x] = time;
						for (int ii = 0; ii < byX[x].size(); ii++) {
							int u = byX[x].get(ii);
							if (!used[u]) {
								used[u] = true;
								q.add(u);
							}
						}
					}

					if (usedY[y] != time) {
						usedY[y] = time;
						for (int ii = 0; ii < byY[y].size(); ii++) {
							int u = byY[y].get(ii);
							if (!used[u]) {
								q.add(u);
								used[u] = true;
							}
						}
					}
				}

				for (int ii = 0; ii < fresh.size(); ii++) {
					int v = fresh.get(ii);
					ans[a[v].x][a[v].y] = highSeen + 1;
					highR[a[v].x] = highC[a[v].y] = highSeen + 1;
				}
			}
			
			i = j;
		}

		for (int i = 0; i < n; i++) {

			for (int j = 0; j < m; j++) {
				out.print(ans[i][j] + " ");
			}
			out.println();
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