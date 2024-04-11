import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}

		Arrays.sort(a);
		int sz = 1;
		int[] cnt = new int[n];
		cnt[0] = 1;
		for (int i = 1; i < n; i++) {
			if (a[i] != a[sz - 1]) {
				a[sz++] = a[i];
			}
			cnt[sz - 1]++;
		}

		a = Arrays.copyOf(a, sz);
		cnt = Arrays.copyOf(cnt, sz);

		int ans = 2;

		int[] last = new int[sz];
		int[] tmpCnt = new int[sz];
		int time = 0;
		for (int i = 0; i < sz; i++)
			for (int j = 0; j < sz; j++) {
				if (i == j && cnt[i] < 2) {
					continue;
				}
				time++;
				
				tmpCnt[i] = cnt[i];
				tmpCnt[j] = cnt[j];
				last[i] = time;
				last[j] = time;
				tmpCnt[i]--;
				tmpCnt[j]--;

				int x = a[i];
				int y = a[j];

				int len = 2;

				while (true) {
					int newY = Arrays.binarySearch(a, x + y);
					if (newY < 0) {
						break;
					}
					if (last[newY] != time) {
						last[newY] = time;
						tmpCnt[newY] = cnt[newY];
					}
					if (tmpCnt[newY] == 0) {
						break;
					}
					tmpCnt[newY]--;
					len++;
					newY = x + y;
					x = y;
					y = newY;
				}

//				System.err.println(i + " " + j + " " + len);

				ans = Math.max(ans, len);
			}

		out.println(ans);

	}

	D() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D();
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