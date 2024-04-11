import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		final int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		Integer[] order = new Integer[n];
		for (int i = 0; i < n; i++) {
			order[i] = i;
		}
		Arrays.sort(order, new Comparator<Integer>() {

			@Override
			public int compare(Integer o1, Integer o2) {
				if (a[o1] != a[o2]) {
					return a[o1] < a[o2] ? -1 : 1;
				}
				return o1.compareTo(o2);
			}
		});
		
		int[] l = new int[n + 2];
		int[] r = new int[n + 2];
		Arrays.fill(l, -1);
		Arrays.fill(r, -1);
		int[] ans = new int[n + 1];
		
		Arrays.fill(ans, -1);
		
		for (int i = n - 1; i >= 0; i--) {
			int pos = order[i] + 1;
			int newL = l[pos - 1];
			if (newL == -1) {
				newL = pos;
			}
			int newR = r[pos + 1];
			if (newR == -1) {
				newR = pos;
			}
			ans[newR - newL + 1] = Math.max(ans[newR - newL + 1], a[pos - 1]);
			r[newL] = newR;
			l[newR] = newL;
		}
		
		for (int i = n - 1; i >= 1; i--) {
			ans[i] = Math.max(ans[i], ans[i + 1]);
		}
		
		for (int i = 1; i <= n; i++) {
			out.print(ans[i] + " ");
		}
		out.println();

	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B().inp();
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