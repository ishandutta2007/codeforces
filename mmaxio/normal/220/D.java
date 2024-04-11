import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int MOD = 1000000007;
	
	int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	void solve() throws IOException {
		int w = nextInt();
		int h = nextInt();

		int[] x = { w / 2 + 1, (w + 1) / 2 };
		int[] y = { h / 2 + 1, (h + 1) / 2 };
		int[][] c = new int[2][2];
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				c[i][j] = x[i] * y[j];

		int ans = 0;

		for (int x1 = 0; x1 < 2; x1++)
			for (int y1 = 0; y1 < 2; y1++)
				for (int x2 = 0; x2 < 2; x2++)
					for (int y2 = 0; y2 < 2; y2++)
						for (int x3 = 0; x3 < 2; x3++)
							for (int y3 = 0; y3 < 2; y3++) {

								int sq = (x1 * y2 - x2 * y1)
										+ (x2 * y3 - x3 * y2)
										+ (x3 * y1 - x1 * y3);
								if ((sq & 1) == 1)
									continue;
								ans += (int) ((long) c[x1][y1] * c[x2][y2]
										% MOD * c[x3][y3] % MOD);
								if (ans >= MOD)
									ans -= MOD;

							}
		
		for (int dx = 0; dx <= w; dx++)
			for (int dy = 0; dy <= h; dy++) {
				int mult = (w - dx + 1) * (h - dy + 1);
				if (dx == 0 && dy == 0) {
					ans -= mult;
					if (ans < 0)
						ans += MOD;
					continue;
				}
				if (dx != 0 && dy != 0)
					mult <<= 1;
				int all = gcd(dx, dy) * 6;
				
				ans -= (int)((long)mult * all % MOD);
				if (ans < 0)
					ans += MOD;
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
		new D().inp();
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