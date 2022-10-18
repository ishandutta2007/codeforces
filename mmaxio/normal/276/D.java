import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	String toStr(long a) {
		String s = Long.toBinaryString(a);
		while (s.length() < 64)
			s = "0" + s;
		return s;
	}

	void solve() throws IOException {
		long a = nextLong();
		long b = nextLong();
		
		String sa = toStr(a);
		String sb = toStr(b);
		
		int i = 0;
		while (i < 64 && sa.charAt(i) == sb.charAt(i))
			i++;
		
		int left = 64 - i;
		out.println((1L << left) - 1);
	}

	D() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D();
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