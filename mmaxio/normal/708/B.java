import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	int get(int x) {
		
		if (x == 0) {
			return 0;
		}
		
		if (x == 1) {
			return 2;
		}
		
		int cand = ((int) Math.sqrt(2 * x)) + 1;
		
		if (cand * (cand - 1) / 2 != x) {
			return -1;
		}
		return cand;
	}
	
	
	boolean solve(int zero, int one, int a01, int a10) {
		if (zero + one == 0) {
			return false;
		}
		long total = (long)zero * one;
		if (total != a01 + a10) {
			return false;
		}
		
		if (zero + one > 1_000_000) {
			return false;
		}
		
		if (zero == 0) {
			for (int i = 0; i < one; i++) {
				out.print('1');
			}
			return true;
		}
		
		if (one == 0) {
			for (int i = 0; i < zero; i++) {
				out.print('0');
			}
			return true;
		}
		
		if (a10 == 0) {
			for (int i = 0; i < zero; i++) {
				out.print('0');
			}
			for (int i = 0; i < one; i++) {
				out.print('1');
			}
			return true;
		}
		
		if (a01 == 0) {
			for (int i = 0; i < one; i++) {
				out.print('1');
			}
			for (int i = 0; i < zero; i++) {
				out.print('0');
			}
			return true;
		}
		
		while (a10 >= zero) {
			out.print('1');
			a10 -= zero;
			one--;
		}
		
		for (int i = 0; i < zero - a10; i++) {
			out.print('0');
		}
		
		out.print('1');
		one--;
		for (int i = 0; i < a10; i++) {
			out.print('0');
		}
		
		for (int i = 0; i < one; i++) {
			out.print('1');
		}
		return true;
	}

	void solve() throws IOException {
		int a00 = nextInt();
		int a01 = nextInt();
		int a10 = nextInt();
		int a11 = nextInt();
		
		int zero = get(a00);
		int one = get(a11);
		
		if (zero < 0 || one < 0) {
			out.println("Impossible");
			return;
		}
		
		int maxZero = zero == 0 ? 1 : zero;
		int maxOne = one == 0 ? 1 : one;
		
		for (int a0 = zero; a0 <= maxZero; a0++)
			for (int a1 = one; a1 <= maxOne; a1++) {
				if (solve(a0, a1, a01, a10)) {
					return;
				}
			}
		
		out.println("Impossible");

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