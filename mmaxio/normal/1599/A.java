import java.io.*;
import java.util.*;

public class Task1481 {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = nextInt();
		String s = nextToken();
		Arrays.sort(a);

		int st = (s.charAt(n - 1) == 'R' ? n - 1 : n - 2);
		for (int i = st; i >= 0; i -= 2)
			a[i] = ~a[i];

		List<Integer> ans = new ArrayList<>(n);

		int low = 0;
		int high = n;

		for (int i = n - 1; i > 0; i--) {
			int val;
			if (s.charAt(i) != s.charAt(i - 1)) {
				val = a[--high];
			} else {
				val = a[low++];
			}
			ans.add(val);
		}

		ans.add(a[low]);

		Collections.reverse(ans);
		for (int i = 0; i < n; i++) {
			int val = ans.get(i);
			if (val >= 0) {
				out.println(val + " L");
			} else {
				out.println((~val) + " R");
			}
		}
	}

	Task1481() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new Task1481();
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