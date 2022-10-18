import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		char[] s = nextToken().toCharArray();
		
		int ptr = 0;
		while (ptr < s.length && s[ptr] == 'a') {
			ptr++;
		}
		
		if (ptr == s.length) {
			s[s.length - 1] = 'z';
			out.println(s);
			return;
		}
		
		while (ptr < s.length && s[ptr] != 'a') {
			s[ptr] = (char) (s[ptr] - 1);
			ptr++;
		}
		
		out.println(s);
	}

	A() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new A();
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