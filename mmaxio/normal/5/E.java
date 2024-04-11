import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	int[] b;
	
	void add(int val, ArrayDeque<Integer> st, ArrayDeque<Integer> cnt) {
		if (st.isEmpty() || st.peekLast() > val) {
			st.add(val);
			cnt.add(0);
		}
		
		int prev = cnt.pollLast();
		cnt.add(prev + 1);
	}
	
	long f(int l, int r) {
		if (r - l <= 0)
			return 0;
		ArrayDeque<Integer> st = new ArrayDeque<Integer>();
		ArrayDeque<Integer> cnt = new ArrayDeque<Integer>();
		long res = 0;
		for (int i = l; i <= r; i++) {
			int x = b[i];
			while (!st.isEmpty() && st.peekLast() < x) {
				res += cnt.pollLast();
				st.pollLast();
			}
			if (!st.isEmpty()) {
				if (st.peekLast() == x) {
					res += cnt.peekLast();
					if (st.size() > 1)
						res++;
				} else
					res++;
			}
			add(x, st, cnt);
		}
		return res;
	}

	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		
		int maxH = 0;
		int maxPos = -1;
		int maxCnt = 0;
		
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
			if (a[i] > maxH) {
				maxH = a[i];
				maxPos = i;
				maxCnt = 0;
			}
			if (maxH == a[i])
				maxCnt++;
		}
		
		b = new int[n];
		System.arraycopy(a, maxPos, b, 0, n - maxPos);
		System.arraycopy(a, 0, b, n - maxPos, maxPos);
		
		long ans = (long)maxCnt * (maxCnt - 1) >> 1;
		int j = 1;
		for (int i = 1; i < n; i++) {
			if (b[i] == maxH) {
				ans += f(j, i - 1);
				j = i + 1;
			}
		}
		ans += f(j, n - 1);
		
		if (maxCnt == 1) {
			boolean[] see = new boolean[n];
			int curMax = 0;
			for (int i = 1; i < n; i++)
				if (b[i] >= curMax) {
					see[i] = true;
					curMax = b[i];
				}
			curMax = 0;
			for (int i = n - 1; i >= 1; i--)
				if (b[i] >= curMax) {
					see[i] = true;
					curMax = b[i];
				}
			for (int i = 1; i < n; i++)
				if (see[i])
					ans++;
		} else {
			for (int i = 1, curMax = 0; i < n; i++) {
				if (b[i] == maxH)
					curMax = 0;
				else if (b[i] >= curMax) {
					curMax = b[i];
					ans++;
				}
			}
			for (int i = n - 1, curMax = 0; i >= 1; i--) {
				if (b[i] == maxH)
					curMax = 0;
				else if (b[i] >= curMax) {
					curMax = b[i];
					ans++;
				}
			}
		}
		
		out.println(ans);
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new E().inp();
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