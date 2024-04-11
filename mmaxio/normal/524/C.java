import java.io.*;
import java.util.*;

public class C {

	static final int INF = Integer.MAX_VALUE / 3;
	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Sum implements Comparable<Sum> {
		int value;
		int base;
		int qty;

		public Sum(int value, int base, int qty) {
			this.value = value;
			this.base = base;
			this.qty = qty;
		}

		@Override
		public int compareTo(Sum o) {
			return Integer.compare(value, o.value);
		}
	}

	int go(int need, int maxTake, Sum[] a) {
		int ret = INF;
		for (int i = 0, j = a.length - 1; i < a.length; i++) {
			if (a[i].value == need) {
				ret = Math.min(ret, a[i].qty);
			}
			while (j >= 0 && a[i].value + a[j].value > need) {
				j--;
			}
			if (j < 0 || a[i].value + a[j].value < need) {
				continue;
			}
			int j1 = j;
			while (j1 >= 0 && a[j1].value == a[j].value) {
				j1--;
			}
			for (int jj = j; jj > j1; jj--) {
				if (a[i].base != a[jj].base && a[i].qty + a[jj].qty <= maxTake) {
					ret = Math.min(ret, a[i].qty + a[jj].qty);
				}
			}
		}
		return ret == INF ? -1 : ret;
	}

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		Sum[] b = new Sum[n * k];
		for (int i = 0; i < n; i++)
			for (int j = 1; j <= k; j++) {
				b[i * k + j - 1] = new Sum(a[i] * j, a[i], j);
			}
		Arrays.sort(b);
		int q = nextInt();
		while (q-- > 0) {
			int need = nextInt();
			out.println(go(need, k, b));
		}
	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C();
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