import java.io.*;
import java.util.*;

public class G1 {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int countInv(int[] a) {
		int ret = 0;
		for (int i = 0; i < a.length; i++)
			for (int j = i + 1; j < a.length; j++) {
				if (a[i] > a[j]) {
					ret++;
				}
			}
		return ret;
	}
	
	void reverse(int[] a, int l, int r) {
		for (int i = l, j = r - 1; i < j; i++, j--) {
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}

	int go(int k, int[] a) {
		if (k == 0) {
			return countInv(a);
		}
		int ret = 0;
		
		for (int i = 0; i < a.length; i++)
			for (int j = i + 1; j <= a.length; j++) {
				reverse(a, i, j);
				ret += go(k - 1, a);
				reverse(a, i, j);
			}
		return ret;
	}

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		int inv = go(k, a);
		int ways = 1;
		for (int i = 0; i < k; i++) {
			ways *= n * (n + 1) / 2;
		}
		out.println(1.0 * inv / ways);
	}

	G1() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new G1();
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