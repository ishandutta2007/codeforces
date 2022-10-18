import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void submit() throws IOException {
		nextInt();
		String s = nextToken();
		out.println(fast(s));
//		out.println(slow(s));
	}

	static final String BAD = "VK";

	String prepare(String s) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < s.length(); i++) {
			char c = s.charAt(i);
			if (BAD.indexOf(c) != -1) {
				sb.append(c);
			} else {
				sb.append('A');
			}
		}
		return sb.toString();
	}

	int slow(String s) {
		s = prepare(s);
		HashMap<String, Integer> map = new HashMap<>();
		ArrayDeque<String> que = new ArrayDeque<>();
		que.add(s);
		map.put(s, 0);

		while (true) {
			s = que.poll();
			int curD = map.get(s);
			if (s.indexOf(BAD) == -1) {
				// System.err.println(s);
				return curD;
			}

			for (int i = 0; i < s.length() - 1; i++) {
				String nxt = swap(s, i, i + 1);
				if (nxt != null && !map.containsKey(nxt)) {
					map.put(nxt, curD + 1);
					que.add(nxt);
				}
			}
		}
	}

	String swap(String s, int i, int j) {
		if (s.charAt(i) == s.charAt(j)) {
			return null;
		}
		char[] buf = s.toCharArray();
		char tmp = buf[i];
		buf[i] = buf[j];
		buf[j] = tmp;
		return new String(buf);
	}

	static final String STR = "VKA";

	int fast(String s) {

		s = prepare(s);

		int n = s.length();

		int[] a = new int[n];
		int[][] pos = new int[3][n];
		int[] sz = new int[3];

		int[][][] cntHere = new int[3][n][3];

		int[][] pref = new int[n + 1][];

		pref[0] = new int[] { 0, 0, 0 };

		for (int i = 0; i < n; i++) {
			a[i] = STR.indexOf(s.charAt(i));
			int c = a[i];
			cntHere[c][sz[c]] = pref[i].clone();
			pos[c][sz[c]++] = i;

			pref[i + 1] = pref[i].clone();
			pref[i + 1][c]++;
		}

		int[][][][] dp = new int[2][sz[0] + 1][sz[1] + 1][sz[2] + 1];

		for (int i = 0; i < 2; i++) {
			for (int j0 = 0; j0 <= sz[0]; j0++) {
				for (int j1 = 0; j1 <= sz[1]; j1++) {
					Arrays.fill(dp[i][j0][j1], INF);
				}
			}
		}

		int ans = INF;

		dp[0][0][0][0] = 0;
		for (int j0 = 0; j0 <= sz[0]; j0++) {
			for (int j1 = 0; j1 <= sz[1]; j1++) {
				for (int j2 = 0; j2 <= sz[2]; j2++) {
					for (int last = 0; last < 2; last++) {
						//
						// if (j0 == 2 && j1 == 0 && j2 == 1) {
						// System.err.println(dp[last][j0][j1][j2]);
						// }

						int idx = j0 + j1 + j2;
						int curVal = dp[last][j0][j1][j2];
						if (curVal == INF) {
							continue;
						}

						if (idx == n) {
							ans = Math.min(ans, curVal);
							continue;
						}

						if (j0 < sz[0]) {
							int cost = Math.max(j1 - cntHere[0][j0][1], 0)
									+ Math.max(j2 - cntHere[0][j0][2], 0);
							dp[1][j0 + 1][j1][j2] = Math.min(
									dp[1][j0 + 1][j1][j2], curVal + cost);
						}

						if (j1 < sz[1] && last == 0) {
							int cost = Math.max(j0 - cntHere[1][j1][0], 0)
									+ Math.max(j2 - cntHere[1][j1][2], 0);
							dp[0][j0][j1 + 1][j2] = Math.min(
									dp[0][j0][j1 + 1][j2], curVal + cost);
						}

						if (j2 < sz[2]) {
							int cost = Math.max(j0 - cntHere[2][j2][0], 0)
									+ Math.max(j1 - cntHere[2][j2][1], 0);
							dp[0][j0][j1][j2 + 1] = Math.min(
									dp[0][j0][j1][j2 + 1], curVal + cost);
						}
					}
				}
			}
		}

		return ans;
	}

	static final int INF = 1_000_000;

	static final Random rng = new Random();

	String genStr() {
		int n = rng.nextInt(15) + 1;
		// int n = 6;
		char[] buf = new char[n];
		for (int i = 0; i < n; i++) {
			buf[i] = STR.charAt(rng.nextInt(3));
		}
		return new String(buf);
	}

	void stress() {
		for (int tst = 0;; tst++) {
			String s = genStr();
			int fast = fast(s);
			int slow = slow(s);
			if (fast != slow) {
				System.err.println(s);
				System.err.println(fast);
				System.err.println(slow);
				throw new AssertionError();
			}
			System.err.println(tst);
		}
	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		submit();
		// stress();
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