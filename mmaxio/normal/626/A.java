import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int[] DX = { -1, 0, 1, 0 };
	static final int[] DY = { 0, -1, 0, 1 };
	static final String DIRS = "URDL";

	void solve() throws IOException {
		int n = nextInt();
		int[] xs = new int[n + 1];
		int[] ys = new int[n + 1];
		String s = nextToken();
		
		int ret = 0;
		
		for (int i = 0; i < n; i++) {
			int id = DIRS.indexOf(s.charAt(i));
			xs[i + 1] = xs[i] + DX[id];
			ys[i + 1] = ys[i] + DY[id];
			
			for (int j = 0; j <= i; j++) {
				if (xs[j] == xs[i + 1] && ys[j] == ys[i + 1]) {
					ret++;
				}
			}
			
		}
		
		out.println(ret);
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