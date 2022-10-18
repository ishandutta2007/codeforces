import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int s = nextInt();
		
		long ans = 0;
		
		// rectangles
		for (int h = 1; h <= n; h += 2) {
			if (s % h != 0)
				continue;
			int w = s / h;
			if (((w & 1) == 0) || (w > m))
				continue;
			
			long pos = (long)(n - h + 1) * (m - w + 1);
			long sz = 2L * (h / 2 + 1) * (w / 2 + 1) - 1;
			ans += pos * sz;
		}
		
		// crosses
		for (int h = 3; h <= n; h += 2) {
			for (int w = 3; w <= m; w += 2) {
				if (w * h <= s)
					continue;
				int leftArea = w * h - s;
				long pos = (long)(n - h + 1) * (m - w + 1);
				long sz = 0;
				for (int rH = 1; 2 * rH + 1 <= h; rH++) {
					// h * w - 4 * rH * rW = s
					if (leftArea % (4 * rH) != 0)
						continue;
					int rW = leftArea / (4 * rH);
					if (rW < 1 || 2 * rW + 1 > w)
						continue;
					sz += 2;
				}
				ans += pos * sz;
			}
		}
		
		out.println(ans);
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C().inp();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	String nextString() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken("\n");
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