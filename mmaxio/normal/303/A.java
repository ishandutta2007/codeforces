import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve(int n) {
//		int sum = (int)((long)n * (n - 1) / 2 % n);
//		
//		if (2 * sum % n != sum)
//			System.err.println("bad");
//		else
//			System.err.println("good");
		if (n % 2 == 0) {
			out.println(-1);
		} else {
			for (int i = 0; i < n; i++) {
				out.print(i + " ");
			}
			out.println();
			for (int i = 0; i < n; i++) {
				out.print(i + " ");
			}
			out.println();
			for (int i = 0; i < n; i++) {
				out.print((2 * i % n) + " ");
			}
			out.println();
		}
	}

	A() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve(nextInt());
//		for (int n = 1; n <= 10; n++)
//			solve(n);
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