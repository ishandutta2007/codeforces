import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		char[] s = nextToken().toCharArray();

		int maxLen = 0;
		int cnt = 1;

		ArrayDeque<Integer> stack = new ArrayDeque<Integer>();
		stack.add(0);
		for (int i = 0; i < s.length; i++) {
			if (s[i] == '(')
				stack.add(i + 1);
			else {
				if (stack.isEmpty())
					throw new AssertionError();
				stack.pollLast();
				if (stack.isEmpty()) {
					stack.add(i + 1);
					continue;
				}
				int prev = stack.peekLast();
				int curLen = i + 1 - prev;
				if (curLen > maxLen)
					cnt = 0;
				maxLen = Math.max(maxLen, curLen);
				if (maxLen == curLen)
					cnt++;
			}
		}

		out.println(maxLen + " " + cnt);

	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C().inp();
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