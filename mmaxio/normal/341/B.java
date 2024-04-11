import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static int get(int[] fen, int x) {
		int ret = 0;
		while (x >= 0) {
			ret += fen[x];
			x = (x & (x + 1)) - 1;
		}
		return ret;
	}

	static void add(int[] fen, int pos) {
		for (int i = pos; i < fen.length; i |= i + 1) {
			fen[i]++;
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int ans = 0;
		int[] d = new int[n + 1];
		Arrays.fill(d, INF);
		d[0] = -INF;

		for (int i = 0; i < n; i++) {

			//System.err.println(Arrays.toString(d));

			int x = nextInt();
			int low = 0;
			int high = ans + 1;
			while (low + 1 < high) {
				int mid = (low + high) >> 1;
				if (d[mid] < x) {
					low = mid;
				} else {
					high = mid;
				}

			}

			d[high] = x;

			if (high > ans)
				ans = high;

		}

		out.println(ans);
	}

	static int INF = Integer.MAX_VALUE / 2;

	B() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B();
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