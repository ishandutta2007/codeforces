import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = nextInt();

		int[] b = a.clone();
		Arrays.sort(b);
		int sz = 1;
		for (int i = 1; i < n; i++) {
			if (b[i] != b[sz - 1]) {
				b[sz++] = b[i];
			}
		}
		b = Arrays.copyOf(b, sz);
		for (int i = 0; i < n; i++)
			a[i] = Arrays.binarySearch(b, a[i]);

		boolean[] was = new boolean[sz];
		int[] cnt = new int[sz];
		
		int[] wasCur = new int[sz];
		int wasCurVer = 1;

		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (was[a[i]])
				continue;
			was[a[i]] = true;

			int thisCnt = 0;
			Arrays.fill(cnt, 0);
			boolean isFirst = true;
			for (int j = 0; j < n; j++) {
				if (a[j] == a[i]) {
					wasCurVer++;
					thisCnt++;
					isFirst = false;
				} else {
					if (wasCur[a[j]] != wasCurVer) {
						wasCur[a[j]] = wasCurVer;
						cnt[a[j]] += isFirst ? 1 : 2;
					}
				}
			}
			
			for (int j = 0; j < sz; j++)
				if (wasCur[j] == wasCurVer)
					cnt[j]--;

			int max = 0;
			for (int j = 0; j < sz; j++)
				max = Math.max(max, cnt[j]);
			ans = Math.max(ans, thisCnt);
			ans = Math.max(ans, max + 1);
		}
		out.println(ans);
	}

	A() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new A();
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