import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	boolean[][] f;
	int[][] up, down, left, right;

	int n, m;

	void updLeft(int r) {
		for (int c = 1; c < m + 1; c++) {
			left[c][r] = f[r][c] ? 1 + left[c - 1][r] : 0;
		}
	}

	void updRight(int r) {
		for (int c = m; c >= 1; c--) {
			right[c][r] = f[r][c] ? 1 + right[c + 1][r] : 0;
		}
	}

	void updUp(int c) {
		for (int r = 1; r < n + 1; r++) {
			up[r][c] = f[r][c] ? 1 + up[r - 1][c] : 0;
		}
	}

	void updDown(int c) {
		for (int r = n; r >= 1; r--) {
			down[r][c] = f[r][c] ? 1 + down[r + 1][c] : 0;
		}
	}

	void solve() throws IOException {
		
//		System.err.println(go1(new int[]{0, 2, 3, 2, 0}, 2));
		
		n = nextInt();
		m = nextInt();
		int q = nextInt();

		f = new boolean[n + 2][m + 2];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				f[i + 1][j + 1] = nextInt() == 1;
			}
		}
		up = new int[n + 2][m + 2];
		down = new int[n + 2][m + 2];
		left = new int[m + 2][n + 2];
		right = new int[m + 2][n + 2];

		for (int i = 1; i < n + 1; i++) {
			updLeft(i);
			updRight(i);
		}

		for (int i = 1; i < m + 1; i++) {
			updUp(i);
			updDown(i);
		}
		
//		System.err.println(go(new int[]{0, 2, 3, 2, 0}, 2));
		
		while (q-- > 0) {
			int type = nextInt();
			int x = nextInt();
			int y = nextInt();
			if (type == 1) {
				f[x][y] = !f[x][y];
				updLeft(x);
				updRight(x);
				updUp(y);
				updDown(y);
			} else {
				int ans = 0;
				ans = Math.max(ans, go1(up[x], y));
				ans = Math.max(ans, go1(down[x], y));
				ans = Math.max(ans, go1(left[y], x));
				ans = Math.max(ans, go1(right[y], x));
				out.println(ans);
			}
		}
	}
	
	int[] leftPos = new int[1100];
	int[] leftH = new int[1100];
	int szLeft;
	
	int[] rightPos = new int[1100];
	int[] rightH = new int[1100];
	int szRight;
	
	int go1(int[] a, int mid) {
		szLeft = 0;
		leftPos[szLeft] = mid;
		leftH[szLeft] = a[mid];
		szLeft++;
		for (int i = mid - 1; i >= 0; i--) {
			if (a[i] < leftH[szLeft - 1]) {
				leftH[szLeft] = a[i];
				leftPos[szLeft] = i;
				szLeft++;
			}
		}
		
		szRight = 0;
		rightPos[szRight] = mid;
		rightH[szRight] = a[mid];
		szRight++;
		for (int i = mid + 1; i < a.length; i++) {
			if (a[i] < rightH[szRight - 1]) {
				rightH[szRight] = a[i];
				rightPos[szRight] = i;
				szRight++;
			}
		}
		
		int ans = 0;
		
		for (int i = 0, j = 0; i < szLeft - 1; i++) {
			while (j < szRight && rightH[j] >= leftH[i]) {
				j++;
			}
//			System.err.println(i + " " + j);
//			System.err.println(leftH[i] + " " + leftPos[i + 1] + " " + rightPos[j]);
			ans = Math.max(ans, leftH[i] * (rightPos[j] - leftPos[i + 1] - 1));
		}
		
		for (int i = 0, j = 0; i < szRight - 1; i++) {
			while (j < szLeft && leftH[j] >= rightH[i]) {
				j++;
			}
			ans = Math.max(ans, rightH[i] * (rightPos[i + 1] - leftPos[j] - 1));
		}
		
		return ans;
	}
	
	
//	int go(int[] a, int mid) {
//		
//		sz = 0;
//		int ret = 0;
//		
//		for (int i = 0; i < a.length; i++) {
//			int x = a[i];
//			while (true) {
//				if (sz == 0 || x > stH[sz - 1]) {
//					stPos[sz] = i;
//					stH[sz] = x;
//					sz++;
//				} else if (sz > 0 && x < stH[sz - 1]) {
//					if (i > mid && stPos[sz - 1] <= mid) {
//						ret = Math.max(ret, stH[sz - 1] * (i - stPos[sz - 1]));
//					}
//					sz--;
//					continue;
//				}
//				break;
//			}
//		}
//		
//		return ret;
//	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B().inp();
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