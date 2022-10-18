import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	boolean match(char brOpen, char brClose) {
		return (brOpen == '(') && (brClose == ')')
				|| (brOpen == '[' && brClose == ']');
	}

	void solve(char[] s) {
		int n = s.length;
		ArrayDeque<Integer> br = new ArrayDeque<Integer>();

		int[] good = new int[n + 1];
		for (int i = 0; i < n; i++) {
			good[i + 1] = good[i] + (s[i] == '[' ? 1 : 0);
		}
		
		int[] match = new int[n];
		boolean[] was = new boolean[n];
		Arrays.fill(match, -1);
		
		int ans = 0;
		int from = -1;
		int to = -1;

		for (int i = 0; i < n; i++) {
			if (s[i] == '(' || s[i] == '[')
				br.add(i);
			else if (s[i] == ')' || s[i] == ']') {
				if (br.isEmpty())
					continue;
				int op = br.pollLast();
				if (!match(s[op], s[i]))
					br.clear();
				else {

					match[op] = i;
				}
			}
		}
		
		for (int i = 0; i < n; i++) {
			if (match[i] != -1 && !was[i]) {
				int en = i;
				while (en < n && match[en] != -1) {
					was[en] = true;
					en = match[en] + 1;
				}
				
				int curAns = good[en] - good[i];
				if (curAns > ans) {
					ans = curAns;
					from = i;
					to = en;
				}
				
			}
		}
		
		

		out.println(ans);
		if (ans != 0) {
			for (int i = from; i < to; i++)
				out.print(s[i]);
			out.println();
		}
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
//		char[] s = new char[100000];
//		for (int i = 0; i < 100000; i += 2) {
//			s[i] = '[';
//			s[i + 1] = ']';
//		}
		
		//solve(s);
		
		solve(nextToken().toCharArray());
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new A().inp();
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