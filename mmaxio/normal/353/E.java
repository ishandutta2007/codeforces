import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		String s = nextToken();
		List<Integer> a = new ArrayList<>();

		for (int i = 0; i < s.length();) {
			int j = i + 1;
			while (j < s.length() && s.charAt(j) == s.charAt(i)) {
				j++;
			}
			a.add(j - i);
			i = j;
		}

		if (s.charAt(s.length() - 1) == s.charAt(0)) {
			int last = a.remove(a.size() - 1);
			a.set(0, a.get(0) + last);
		}

		for (int i = 0; i < a.size(); i++) {
			if (a.get(i) > 1) {
				a.set(i, 2);
			}
		}
		int ptr = a.indexOf(2);
		if (ptr == -1) {
			out.println(s.length() / 2);
			return;
		}

		Collections.rotate(a, -ptr);

		// System.err.println(a);

		int ans = 0;

		for (int i = 0; i < a.size();) {
			if (a.get(i) == 2) {
				ans++;
				i++;
			} else {
				int j = i + 1;
				int tmp = 1;
				while (j < a.size() && a.get(j) == 1) {
					tmp++;
					j++;
				}
				ans += tmp / 2;
				i = j;
			}
		}

		out.println(ans);

	}

	E() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new E();
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