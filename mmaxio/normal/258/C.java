import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int MOD = 1000000007;

	static final int MAX = 100001; // !!!!!!!!!!!!!!!!!!1

	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}

		// Random rng = new Random();
		// for (int i = 0; i < n; i++) {
		// int j = rng.nextInt(i + 1);
		// int tmp = a[j];
		// a[j] = a[i];
		// a[i] = tmp;
		// }
		// Arrays.sort(a);

		int[] cnt = new int[MAX];
		for (int i = 0; i < n; i++)
			cnt[a[i]]++;

		for (int i = 1; i < MAX; i++)
			cnt[i] += cnt[i - 1];

		// cnt[i] - how many numbers are <= i

		ArrayList<Integer> div = new ArrayList<>();

		int ans = 1; // for max = 1

		for (int max = 2; max < MAX; max++) {

			div.clear();
			for (int j = 1; j * j <= max; j++) {
				if (max % j == 0) {
					div.add(j);
					if (j * j != max)
						div.add(max / j);
				}
			}
			Collections.sort(div);

			int cntGood = 1;
			int cntBad = 1;

			for (int i = 0; i < div.size() - 1; i++) {
				int now = div.get(i);
				int next = div.get(i + 1);
				int val = pow(i + 1, cnt[next - 1] - cnt[now - 1]);
				cntGood = (int) ((long) cntGood * val % MOD);
				if (i != div.size() - 2)
					cntBad = (int) ((long) cntBad * val % MOD);
			}
			int valLast = pow(div.size(), cnt[MAX - 1] - cnt[max - 1]);
			cntGood = (int) ((long) cntGood * valLast % MOD);
			
			valLast = pow(div.size() - 1, cnt[MAX - 1] - cnt[div.get(div.size() - 2) - 1]);
			cntBad = (int) ((long) cntBad * valLast % MOD);

//			System.err.println(max + " " + cntGood + " " + cntBad);

			ans += cntGood;
			if (ans >= MOD)
				ans -= MOD;
			ans -= cntBad;
			if (ans < 0)
				ans += MOD;
		}

		out.println(ans);
	}

	int pow(int a, int b) {
		int res = 1;
		while (b != 0) {
			if ((b & 1) == 1)
				res = (int) ((long) res * a % MOD);
			a = (int) ((long) a * a % MOD);
			b >>= 1;
		}
		return res;
	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
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