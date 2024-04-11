import java.io.*;
import java.util.*;

public class C_faster {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	int[] unique(int[] a) {
		a = a.clone();
		Arrays.sort(a);
		int sz = 1;
		for (int i = 1; i < a.length; i++) {
			if (a[i] != a[sz - 1]) {
				a[sz++] = a[i];
			}
		}
		
		return Arrays.copyOf(a, sz);
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int s = nextInt();
		int e = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		
		int[] all = unique(a);
		for (int i = 0; i < n; i++) {
			a[i] = Arrays.binarySearch(all, a[i]);
		}
		
		int[] bucketSize = new int[all.length];

		int[] b = new int[m];
		for (int i = 0; i < m; i++) {
			b[i] = Arrays.binarySearch(all, nextInt());
			if (b[i] >= 0) {
				bucketSize[b[i]]++;
			}
		}
		
		int[][] buckets = new int[all.length][];
		for (int i = 0; i < all.length; i++) {
			buckets[i] = new int[bucketSize[i]];
		}
		
		for (int i = 0; i < m; i++) {
			int x = b[i];
			if (x >= 0) {
				int[] where = buckets[x];
				where[where.length - bucketSize[x]] = i;
				bucketSize[x]--;
			}
		}
		
		int ans = 0;

		Arrays.sort(b);
		int[] dp = new int[n];
		for (int i = 0; i < n; i++) {
			int x = a[i];
			int[] bucket = buckets[x];
			int idx = Arrays.binarySearch(bucket, -1);
			if (idx < 0) {
				idx = ~idx;
			}
			if (idx == bucket.length) {
				dp[i] = m;
			} else {
				dp[i] = bucket[idx];
			}

			if (dp[i] != m && (i + 1) + (dp[i] + 1) + e <= s) {
				ans = 1;
			}
		}

		if (ans == 0) {
			out.println(0);
			return;
		}

		int[] prev = dp.clone();
		for (ans = 2; true; ans++) {
			boolean canThis = false;
			int minPos = m;
			for (int i = 0; i < n; i++) {
				int x = a[i];
				int[] bucket = buckets[x];
				// int idx = binSearch(a[i], minPos);
				int idx = Arrays.binarySearch(bucket, minPos);
				if (idx < 0) {
					idx = ~idx;
				}
				if (idx == bucket.length) {
					dp[i] = m;
				} else {
					dp[i] = bucket[idx];
				}
				
				if (dp[i] != m && (i + 1) + (dp[i] + 1) + e * ans <= s) {
					canThis = true;
				}
				
				minPos = Math.min(minPos, prev[i] + 1);
			}
			if (!canThis) {
				out.println(ans - 1);
				return;
			}
			int[] tmp = dp;
			dp = prev;
			prev = tmp;
		}

	}

	C_faster() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C_faster();
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