import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		char[] s = nextToken().toCharArray();
		
		long ans = 1;
		int pow10 = 0;
		
		boolean firstLetter = false;
		
		Set<Character> lets = new HashSet<>(); 
		
		for (int i = 0; i < s.length; i++) {
			char c = s[i];
			if (c >= '0' && c <= '9') {
				if (c == '0' && i == 0) {
					out.println(0);
					return;
				}
			} else if (c == '?') {
				if (i == 0)
					ans *= 9;
				else
					pow10++;
			} else {
				lets.add(c);
				if (i == 0)
					firstLetter = true;
			}
		}
		
		for (int i = 0, mult = 10; i < lets.size(); i++, mult--) {
			ans *= mult;
		}
		if (firstLetter) {
			ans = ans / 10 * 9;
		}
		
		out.print(ans);
		for (int i = 0; i < pow10; i++)
			out.print('0');
		out.println();
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