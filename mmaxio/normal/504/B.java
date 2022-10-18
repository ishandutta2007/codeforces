import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	void add(int[] f, int pos, int delta) {
		for (int i = pos; i < f.length; i |= i + 1) {
			f[i] += delta;
		}
	}
	
	int get(int[] f, int pos) {
		int ret = 0;
		for (int i = pos; i >= 0; i = (i & (i + 1)) - 1) {
			ret += f[i];
		}
		return ret;
	}
	
	int[] getPerm(int n) throws IOException {
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		int[] f = new int[n];
		int[] ret = new int[n];
		for (int i = n - 1; i >= 0; i--) {
			ret[n - 1 - i] = get(f, a[i]);
			add(f, a[i], 1);
		}
		return ret;
	}
	
	int[] makePerm(int[] a) {
		int n = a.length;
		int[] ret = new int[n];
		int[] f = new int[n];
		for (int i = 0; i < n; i++) {
			add(f, i, 1);
		}
		for (int i = 0, j = n - 1; i < n; i++, j--) {
			int need = a[j];
			int low = -1; // <= k
			int high = n - 1; // > k
			while (high - low > 1) {
				int mid = (low + high) >> 1;
				int val = get(f, mid);
				if (val <= need) {
					low = mid;
				} else {
					high = mid;
				}
			}
			add(f, high, -1);
			ret[i] = high;
		}
		return ret;
	}

	void solve() throws IOException {
		int n = nextInt();
		int[] a = getPerm(n);
		int[] b = getPerm(n);
		int[] c = new int[n];
		for (int i = 0, carry = 0; i < n; i++ ){
			c[i] = a[i] + b[i] + carry;
			if (c[i] >= i + 1) {
				c[i] -= i + 1;
				carry = 1;
			} else {
				carry = 0;
			}
		}
		int[] ans = makePerm(c);
		for (int x : ans) {
			out.print(x + " ");
		}
		out.println();
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