import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		String s = nextToken();
		String t = nextToken();
		
		int[] c = new int[3];
		
		int onesT = 0;
		
		for (int i = 0; i < 2 * n; i++) {
			char cs = s.charAt(i);
			char ts = t.charAt(i);
			
			c[(cs - '0') + (ts - '0')]++;
			
			if (ts == '1')
				onesT++;
		}
		
		int sc1;
		if (c[2] % 2 == 0)
			sc1 = 2 * (c[2] / 2) + (c[1] + 1) / 2;
		else
			sc1 = 2 * ((c[2] + 1) / 2) + c[1] / 2;
		
		sc1 -= onesT;
		if (sc1 > 0)
			out.println("First");
		else if (sc1 == 0)
			out.println("Draw");
		else
			out.println("Second");
		
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