import java.io.*;
import java.util.*;

public class cfEdu14F {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	static final int MAX = 3_000_001;

	void solve() throws IOException {
		int n = nextInt();
//		int n = 1_000_000;
		Random rng = new Random();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			int j = rng.nextInt(i + 1);
			a[i] = a[j];
			a[j] = nextInt();
//			a[j] = i + 1;
		}

		Arrays.sort(a);

		int[] vals = new int[n];
		int[] cnts = new int[n];
		int sz = 0;
		for (int i = 0; i < n;) {
			int j = i;
			while (j < n && a[j] == a[i]) {
				j++;
			}
			vals[sz] = a[i];
			cnts[sz] = j - i;
			sz++;
			
			i = j;
		}
		
		long[] cnt = new long[MAX];
		for (int i = 0; i < sz; i++) {
			if ((long)vals[i] * vals[i] >= MAX) {
				break;
			}
			cnt[vals[i] * vals[i]] += (long)cnts[i] * (cnts[i] - 1);
			int j = i + 1;
			while (j < sz && (long)vals[i] * vals[j] < MAX) {
				cnt[vals[i] * vals[j]] += 2L * cnts[i] * cnts[j];
				j++;
			}
		}
		
		long total = (long)n * (n - 1);
		
		for (int i = MAX - 2; i >= 1; i--) {
			cnt[i] += cnt[i + 1];
		}
		
		long delta = total - cnt[1];
		
		int q = nextInt();
//		int q = 0;
		while (q-- > 0) {
			int idx = nextInt();
			out.println(cnt[idx] + delta);
		}
	}

	cfEdu14F() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new cfEdu14F();
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