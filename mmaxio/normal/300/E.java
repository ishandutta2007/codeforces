import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int CNT = 664579;
	static final int N = 10_000_000;

	void solve() throws IOException {
		int[] P = new int[CNT];
		int cnt = 0;

		int[] lp = new int[N + 1];
		Arrays.fill(lp, -1);
		for (int i = 2; i <= N; i++) {
			if (lp[i] == -1) {
				lp[i] = cnt;
				P[cnt++] = i;
			}
			for (int j = 0; j <= lp[i]; j++) {
				int cur = i * P[j];
				if (cur > N)
					break;
				lp[cur] = j;
			}
		}

		int[] times = new int[N + 2];

		int n = nextInt();
		for (int i = 0; i < n; i++) {
			int a = nextInt();
			times[1]++;
			times[a + 1]--;
		}

		for (int i = 1; i <= N; i++)
			times[i] += times[i - 1];

		long[] pow = new long[CNT];
		for (int i = 0; i < CNT; i++) {
			int p = P[i];
			for (long curPow = p; curPow <= N; curPow *= p)
				for (int j = (int) curPow; j <= N; j += curPow)
					pow[i] += times[j];
		}

		long ans = 0;
		for (int i = 0; i < CNT; i++) {
			ans = Math.max(ans, go(P[i], pow[i]));
		}

		out.println(ans);
	}

	long go(int p, long cnt) {
//		System.err.println(p + " " + cnt);
		if (cnt == 0)
			return 1;
		long low = 0; // low! isn't enough
		long high = (long) p * cnt; // high! is enough
		while (low < high - 1) {
			long mid = (low + high) >> 1;
			long tmpMid = mid;
			long curCnt = 0;
			do {
				tmpMid /= p;
				curCnt += tmpMid;
			} while (tmpMid != 0);
			if (curCnt >= cnt)
				high = mid;
			else
				low = mid;
		}
		return high;
	}

	E() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
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