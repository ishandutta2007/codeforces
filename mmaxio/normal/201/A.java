import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	boolean can(int n, int set) {
		if ((n % 2) == 0) {
			if ((set % 4) != 0)
				return false;
			int tmp = n / 2 - 1;
			tmp = (tmp * tmp + 1) / 2;
			return set / 4 <= tmp;
		}
		if (n == 1)
			return set <= 1;
		if (n == 3)
			return set <= 5 && set != 3;
		int tmp = n / 2;
		
		int max4 = (tmp * tmp + 1) / 2;
		
		int maxRes = max4 * 4 + (tmp / 2) * 4 + 1;
		return set <= maxRes;
	}

	void solve(int need) throws IOException {
		for (int sz = 1; true; sz++)
			if (can(sz, need)) {
				//out.print(need + " ");
				out.println(sz);
				return;
			}
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
//		for (int n = 1; n <= 100; n++)
//			solve(n);
		solve(nextInt());
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