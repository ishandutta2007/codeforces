import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int[][] how = new int[43][];

	void preCalc() {
		outer: for (int i = 0; i <= 42; i++) {
			for (int c4 = 0; c4 <= 6; c4++) {
				if ((i - 4 * c4) % 7 == 0) {
					int c7 = (i - 4 * c4) / 7;
					if (c7 >= 0 && c4 + c7 <= 6) {
						how[i] = new int[6];
						Arrays.fill(how[i], 0, c4, 4);
						Arrays.fill(how[i], c4, c4 + c7, 7);
						continue outer;
					}
				}
			}
		}
		// System.err.println(Arrays.deepToString(how));
	}

	Map<Long, long[]> map = new HashMap<>();
	static final long[] NO_ANSWER = {};

	long[] go(long x) {
		if (map.containsKey(x)) {
			return map.get(x);
		}

		if (x == 0) {
			long[] res = new long[6];
			map.put(x, res);
			return res;
		}

		int rem = (int) (x % 10);
		for (int i = rem; i <= 42; i += 10) {
			if (how[i] != null) {
				long to = (x - i) / 10;
				if (to < 0)
					break;
				long[] res = go(to);
				if (res.length == 6) {
					res = res.clone();
					for (int j = 0; j < 6; j++) {
						res[j] = res[j] * 10 + how[i][j];
					}
					map.put(x, res);
					return res;
				}
			}
		}

		map.put(x, NO_ANSWER);
		return NO_ANSWER;
	}

	void solve(long x) {
		long[] res = go(x);
		if (res.length == 6) {
			for (int i = 0; i < 6; i++) {
				out.print(res[i] + " ");
			}
			out.println();
		} else {
			out.println(-1);
		}
	}

	E() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		int t = nextInt();
		while (t-- > 0) {
			solve(nextLong());
		}
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new E();
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