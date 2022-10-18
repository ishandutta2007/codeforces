import java.io.*;
import java.util.*;

public class C_arr {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final Random rng = new Random();

	void solve(int[] a, int n, int k) {
		if (n <= k + 1) {
			out.println(1);
			return;
		}
		int maxDiff = a[n - 1] - a[0];
		int[][] suchDiff = new int[maxDiff + 1][2 * (k + 2)];
		int[] szSuchDiff = new int[maxDiff + 1];

		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++) {
				int diff = a[j] - a[i];
				if (szSuchDiff[diff] != k + 2) {
					int tmp = szSuchDiff[diff];
					int[] addArr = suchDiff[diff];
					addArr[tmp << 1] = i;
					addArr[(tmp << 1) + 1] = j;
					szSuchDiff[diff]++;
				}
			}
		
		int[] p = new int[n];
		int[] pVer = new int[n];
		
		outer: for (int ans = n - k; ans <= maxDiff + 1; ans++) {
			int nUnions = 0;
			for (int j = ans; j <= maxDiff; j += ans) {
				int[] cur = suchDiff[j];
				int curSz = 2 * szSuchDiff[j];
				if (curSz == 2 * (k + 2))
					continue outer;
				for (int i = 0; i < curSz; i += 2) {
					int v1 = cur[i];
					int v2 = cur[i + 1];
					if (pVer[v1] != ans) {
						pVer[v1] = ans;
						p[v1] = v1;
					}
					if (pVer[v2] != ans) {
						pVer[v2] = ans;
						p[v2] = v2;
					}
					v1 = get(p, v1);
					v2 = get(p, v2);
					if (v1 != v2) {
						nUnions++;
						if (rng.nextBoolean()) {
							p[v2] = v1;
						} else {
							p[v1] = v2;
						}
					}
					if (nUnions > k) {
						continue outer;
					}
				}
			}
			out.println(ans);
			return;
		}

	}

	int get(int[] p, int v) {
		return p[v] == v ? v : (p[v] = get(p, p[v]));
	}

	void solveStupid(int[] a, int n, int k) {

		int minAns = n - k;
		int maxAns = a[n - 1] - a[0] + 1;

		int[] cnt = new int[maxAns];
		int[] cntVer = new int[maxAns];
		int curVer = 0;

		for (int ans = minAns; ans < maxAns; ans++) {
			curVer++;
			int curBad = 0;
			for (int i = 0; i < n; i++) {
				int rem = a[i] % ans;
				if (cntVer[rem] != curVer) {
					cntVer[rem] = curVer;
					cnt[rem] = 0;
				}
				cnt[rem]++;
				if (cnt[rem] > 1)
					curBad++;
				if (curBad > k)
					break;
			}
			if (curBad <= k) {
				out.println(ans);
				return;
			}
		}
	}

	C_arr() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		int n = nextInt();
		int k = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			int j = rng.nextInt(i + 1);
			a[i] = a[j];
			a[j] = nextInt();
		}
		Arrays.sort(a);

//		solveStupid(a, n, k);
		solve(a, n, k);
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C_arr();
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