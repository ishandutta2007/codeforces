import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		
		int destr = 0;
		int parts = 0;
		
		for (int i = 0; i < k; i++) {
			int cnt = nextInt();
			int[] a = new int[cnt];
			
			for (int j = 0; j < cnt; j++) {
				a[j] = nextInt();
			}
			
			int j = 0;
			while (j < cnt && a[j] == j + 1) {
				j++;
			}
			if (j == 0) {
				parts += cnt;
				destr += cnt - 1;
			} else {
				parts += cnt - (j - 1);
				destr += cnt - 1 - (j - 1);
			}
		}
		out.println(parts + destr - 1);
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