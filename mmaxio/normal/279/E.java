import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		char[] s = nextToken().toCharArray();
		int i = s.length - 1;
		int ans = 0;
		while (i >= 0) {
			if (s[i] == '0') {
				i--;
				continue;
			}
			ans++;
			if (i == 0) {
				break;
			}
			int j = i - 1;
			while (j >= 0 && s[j] == s[i - 1])
				j--;
			if (s[i - 1] == '0')
				i = j;
			else {
				if (j == -1)
					ans++;
				else
					s[j] = '1';
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