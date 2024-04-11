import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		String s = br.readLine();
		for (int i = 0; i < s.length();) {
			if (s.charAt(i) == ' ') {
				i++;
			} else if (s.charAt(i) == '"') {
				int j = s.indexOf('"', i + 1);
				out.print("<");
				out.print(s.substring(i + 1, j));
				out.println(">");
				i = j + 1;
			} else {
				int j = s.indexOf(' ', i);
				if (j == -1)
					j = s.length();
				out.print("<");
				out.print(s.substring(i, j));
				out.println(">");
				i = j + 1;
			}
		}
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