import java.io.*;
import java.util.*;

public class cf10E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	boolean good(int[] cnt, int[] a, int sum) {
		int greed = 0;
		int us = 0;
		for (int i = 0; i < a.length; i++) {
			greed += sum / a[i];
			us += cnt[i];
			sum %= a[i];
		}
		return greed > us;
	}

	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		
		long ans = Long.MAX_VALUE;
		for (int i = n - 2; i >= 0; i--) {
			int x = a[i] - 1;
			int[] cnt = new int[n];
			for (int j = 0; j < n; j++) {
				cnt[j] = x / a[j];
				x %= a[j];
			}
			if (cnt[i + 1] == 0) {
				continue;
			}
			
			int sum = a[i] - 1;
			
			for (int j = n - 1; j > i; j--) {
				cnt[j]++;
				sum += a[j];
				if (good(cnt, a, sum)) {
					ans = Math.min(ans, sum);
				}
				sum -= a[j] * cnt[j];
				cnt[j] = 0;
			}
		}
		
		if (ans == Long.MAX_VALUE) {
			ans = -1;
		}
		out.println(ans);
	}

	cf10E() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new cf10E();
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