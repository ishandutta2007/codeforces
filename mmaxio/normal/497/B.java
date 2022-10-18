import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Pair implements Comparable<Pair> {
		int s, t;

		public Pair(int s, int t) {
			this.s = s;
			this.t = t;
		}

		@Override
		public int compareTo(Pair o) {
			if (s != o.s) {
				return s < o.s ? -1 : 1;
			}
			return Integer.compare(t, o.t);
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt() - 1;
		}

		int[] win0 = new int[n + 1];
		int[] win1 = new int[n + 1];
		for (int i = 0; i < n; i++) {
			win0[i + 1] = win0[i] + (a[i] == 0 ? 1 : 0);
			win1[i + 1] = win1[i] + (a[i] == 1 ? 1 : 0);
		}

		List<Pair> ans = new ArrayList<>();

		outer: for (int t = 1; t <= Math.max(win0[n], win1[n]); t++) {
			// System.err.println(t);
			int ptr = 0;
			int s0 = 0;
			int s1 = 0;
			int lastWin = -1;
			while (ptr < n) {
				// System.err.println(ptr);
				int nxt0 = findFirst(win0, win0[ptr] + t);
				int nxt1 = findFirst(win1, win1[ptr] + t);
				// System.err.println(nxt0 + " " + nxt1);
				if (Math.min(nxt0, nxt1) == n + 1) {
					continue outer;
				}
				if (nxt0 < nxt1) {
					lastWin = 0;
					s0++;
					ptr = nxt0;
				} else if (nxt0 > nxt1) {
					lastWin = 1;
					s1++;
					ptr = nxt1;
				}
			}
			if (s0 != s1) {
				if ((s0 > s1) == (lastWin == 0)) {
					ans.add(new Pair(Math.max(s0, s1), t));
				}
			}
		}
		Collections.sort(ans);
		out.println(ans.size());
		for (Pair p : ans) {
			out.println(p.s + " " + p.t);
		}
	}

	int findFirst(int[] a, int x) {
		int low = -1;
		int high = a.length;
		while (high - low > 1) {
			int mid = (low + high) >> 1;
			if (a[mid] >= x) {
				high = mid;
			} else {
				low = mid;
			}
		}
		// System.err.println(Arrays.toString(a) + " " + x + " -> " + high);
		return high;
	}

	B() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B();
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