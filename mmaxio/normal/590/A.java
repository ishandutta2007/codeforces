import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}

		int[] ret = new int[n];

		int cnt = 0;
		for (int i = 0; i < n;) {
			int j = i;
			while (j + 1 < n && a[j] != a[j + 1]) {
				j++;
			}
			j++;
//			System.err.println(i + " " + j);
			cnt = Math.max(cnt, (j - i - 1) / 2);
			
			if ((j - i) % 2 == 1) { // 0 1 0 1 0
				for (int k = i; k < j; k++) {
					ret[k] = a[i];
				}
			} else { // 0 1 0 1
				for (int k = i; k < (i + j) / 2; k++) {
					ret[k] = a[i];
				}
				for (int k = (i + j) / 2; k < j; k++) {
					ret[k] = a[j - 1];
				}
			}
			i = j;
		}
		
		out.println(cnt);
		for (int x : ret) {
			out.print(x + " ");
		}
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