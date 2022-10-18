import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	String fix(String s) {
		s = s.replaceAll("[-;_]", "");
		return s.toLowerCase();
	}

	void solve() throws IOException {
		String[] s = new String[3];
		for (int i = 0; i < 3; i++)
			s[i] = fix(nextToken());
		HashSet<String> memo = new HashSet<String>();
		memo.add(s[0] + s[1] + s[2]);
		memo.add(s[0] + s[2] + s[1]);
		memo.add(s[1] + s[2] + s[0]);
		memo.add(s[1] + s[0] + s[2]);
		memo.add(s[2] + s[1] + s[0]);
		memo.add(s[2] + s[0] + s[1]);
		int n = nextInt();
		for (int i = 0; i < n; i++) {
			String tmp = fix(nextString());
			out.println(memo.contains(tmp) ? "ACC" : "WA");
		}
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
				return "0";
			}
		}
		return st.nextToken();
	}

	String nextString() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken("\n");
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