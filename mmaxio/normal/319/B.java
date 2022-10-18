import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int go(int[] a, int l, int r) {
		List<Integer> lastVal = new ArrayList<>();
		List<Integer> lastPos = new ArrayList<>();

		lastVal.add(a[l]);
		lastPos.add(0);

		int curAns = 0;

		for (int i = l + 1; i < r; i++) {

			int x = a[i];
//			System.err.println("adding " + x);
			int lastPosRemoved = -1;
			while (lastVal.get(lastVal.size() - 1) < x) {
				lastVal.remove(lastVal.size() - 1);
				lastPosRemoved = lastPos.remove(lastPos.size() - 1);
			}
			if (lastPos.isEmpty()) {
				throw new AssertionError();
			}

			if (lastPos.get(lastPos.size() - 1).intValue() == lastPosRemoved + 1) {
				if (curAns == lastPosRemoved + 1) {
					if (lastPos.size() != 1) {
						throw new AssertionError();
					}
					curAns++;
					lastPos.set(0, curAns);
					lastVal.add(x);
					lastPos.add(lastPosRemoved + 1);
				} else {
					lastVal.set(lastVal.size() - 1, x);
				}
			} else {
				lastVal.add(x);
				lastPos.add(lastPosRemoved + 1);
			}
//			System.err.println(lastVal);
//			System.err.println(lastPos);
//			System.err.println("----");
		}

		return curAns;
	}

	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}

		int[] maxPos = new int[n];
		maxPos[0] = 0;

		for (int i = 1; i < n; i++) {
			if (a[i] > a[maxPos[i - 1]]) {
				maxPos[i] = i;
			} else {
				maxPos[i] = maxPos[i - 1];
			}
		}

		int ans = 0;

		for (int i = n - 1; i >= 0;) {
			int cur = maxPos[i];

			ans = Math.max(ans, go(a, cur, i + 1));

			i = cur - 1;
		}

		out.println(ans);
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