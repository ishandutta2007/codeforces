import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int nextTime() throws IOException {
		String s = nextToken();
		return Integer.parseInt(s.substring(0, 2)) * 60 * 60
				+ Integer.parseInt(s.substring(3, 5)) * 60
				+ Integer.parseInt(s.substring(6, 8));
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int t = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextTime();
		}
		boolean[] lastOcc = new boolean[n];
		int cnt = 0;
		int cntDiff = 0;
		int[] ans = new int[n];
		boolean hadM = false;
		for (int i = 0, j = 0; i < n; i++) {
			while (a[j] <= a[i] - t) {
				if (j == i - 1 || lastOcc[j]) {
					cntDiff--;
				}
				j++;
			}
			
			if (cntDiff == m) {
				ans[i] = cnt - 1;
			} else {
				if (i != 0) {
					lastOcc[i - 1] = true;
				}
				cnt++;
				ans[i] = cnt - 1;
				cntDiff++;
			}
			if (cntDiff == m) {
				hadM = true;
			}
		}
		if (!hadM) {
			out.println("No solution");
		} else {
			out.println(cnt);
			for (int x : ans) {
				out.println(x + 1);
			}
		}
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