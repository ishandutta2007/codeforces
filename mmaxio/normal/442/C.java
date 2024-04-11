import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	Integer[] cache;

	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		if (n <= 2) {
			out.println(0);
			return;
		}
		cache = new Integer[n];
		for (int i = 0; i < n; i++) {
			cache[i] = i;
		}
		int[] next = new int[n];
		int[] prev = new int[n];
		for (int i = 0; i < n - 1; i++) {
			next[i] = i + 1;
		}
		next[n - 1] = -1;
		prev[0] = -1;
		for (int i = 1; i < n; i++) {
			prev[i] = i - 1;
		}

		boolean[] inQ = new boolean[n];
		Queue<Integer> q = new ArrayDeque<>();
		for (int i = 1; i < n - 1; i++) {
			if (a[i] <= a[i - 1] && a[i] <= a[i + 1]) {
				inQ[i] = true;
				q.add(cache[i]);
			}
		}

		long ans = 0;

		while (!q.isEmpty()) {
			int idx = q.poll();
			int prevIdx = prev[idx];
			int nextIdx = next[idx];
			ans += Math.min(a[prevIdx], a[nextIdx]);
			next[prevIdx] = nextIdx;
			prev[nextIdx] = prevIdx;
			if (prevIdx != 0 && !inQ[prevIdx] && a[prevIdx] <= a[prev[prevIdx]]
					&& a[prevIdx] <= a[nextIdx]) {
				inQ[prevIdx] = true;
				q.add(cache[prevIdx]);
			}
			if (nextIdx != n - 1 && !inQ[nextIdx] && a[nextIdx] <= a[prevIdx]
					&& a[nextIdx] <= a[next[nextIdx]]) {
				inQ[nextIdx] = true;
				q.add(cache[nextIdx]);
			}
		}

		for (int i = next[0]; i != n - 1; i = next[i]) {
			ans += Math.min(a[prev[i]], a[next[i]]);
		}
		out.println(ans);
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