import java.io.*;
import java.util.*;

public class C {

	static final int K = 10;
	static final String DATA = "AGCT";

	void add(int[] fen, int pos, int delta) {
		for (int i = pos; i < fen.length; i |= i + 1) {
			fen[i] += delta;
		}
	}

	int get(int[] fen, int l, int r) {
		return get(fen, r) - get(fen, l - 1);
	}

	int get(int[] fen, int pos) {
		int ret = 0;
		for (int i = pos; i >= 0; i = (i & (i + 1)) - 1) {
			ret += fen[i];
		}
		return ret;
	}

	void submit() {
		String ss = nextToken();

		int n = ss.length();

		int[] s = new int[n];
		for (int i = 0; i < n; i++) {
			s[i] = DATA.indexOf(ss.charAt(i));
		}

		int[][][][] dp = new int[4][K + 1][][];
		for (int i = 0; i < 4; i++) {
			for (int mod = 1; mod <= K; mod++) {

				dp[i][mod] = new int[mod][];

				for (int rem = 0; rem < mod; rem++) {

					int length = Math.max(n - rem + mod - 1, 0) / mod;
					dp[i][mod][rem] = new int[length];
				}

			}
		}

		for (int i = 0; i < n; i++) {
			int symb = s[i];

			for (int mod = 1; mod <= K; mod++) {
				add(dp[symb][mod][i % mod], i / mod, 1);
			}

		}

		int q = nextInt();
		while (q-- > 0) {
			int type = nextInt();
			if (type == 1) {
				int pos = nextInt() - 1;
				int newSymb = DATA.indexOf(nextToken().charAt(0));

				int oldSymb = s[pos];
				for (int mod = 1; mod <= K; mod++) {

					add(dp[oldSymb][mod][pos % mod], pos / mod, -1);
					add(dp[newSymb][mod][pos % mod], pos / mod, 1);
				}

				s[pos] = newSymb;
			} else {
				int l = nextInt() - 1;
				int r = nextInt() - 1;

				int ret = 0;

				String p = nextToken();

				for (int i = 0; i < p.length(); i++) {
					int symb = DATA.indexOf(p.charAt(i));
					int textRem = (i + l) % p.length();

					int start = (i + l) / p.length();
					int end = getLastPos(r, p.length(), textRem);
					if (end >= 0) {
						end /= p.length();
						if (start <= end) {
							ret += get(dp[symb][p.length()][textRem], start,
									end);
						}
					}
				}
				
				out.println(ret);
			}
		}

	}

	int getLastPos(int pos, int mod, int rem) {
		while (pos >= 0 && pos % mod != rem) {
			pos--;
		}
		if (pos < 0) {
			return -1;
		}
		return pos;
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
		// stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new C();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}