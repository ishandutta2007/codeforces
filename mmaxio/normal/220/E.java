import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int comp(int[] a) {
		int[] b = a.clone();
		Arrays.sort(b);
		int res = 1;
		for (int i = 1; i < b.length; i++) {
			if (b[i] != b[res - 1]) {
				b[res] = b[i];
				res++;
			}
		}
		for (int i = 0; i < a.length; i++)
			a[i] = Arrays.binarySearch(b, 0, res, a[i]);
		return res;
	}

	class Fenwick {
		private int[] a;
		int sz;

		Fenwick(int sz) {
			a = new int[sz];
			this.sz = sz;
		}

		void add(int i, int delta) {
			for (; i < sz; i |= i + 1)
				a[i] += delta;
		}

		int get(int l, int r) {
			return get(r) - get(l - 1);
		}

		int get(int i) {
			int res = 0;
			for (; i >= 0; i = (i & (i + 1)) - 1)
				res += a[i];
			return res;
		}
	}

	long curInv = 0;
	int N;

	void add(int x, Fenwick f) {
		curInv += left.get(x + 1, N - 1) + right.get(x - 1);
		f.add(x, 1);
	}

	void remove(int x, Fenwick f) {
		curInv -= left.get(x + 1, N - 1) + right.get(x - 1);
		f.add(x, -1);
	}

	Fenwick left, right;

	void solve() throws IOException {
		int n = nextInt();
		long k = nextLong();
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = nextInt();

		N = comp(a);
		left = new Fenwick(N);
		right = new Fenwick(N);

		long ans = 0;

		int r;

		for (r = n - 1; r >= 0; r--) {
			add(a[r], right);
			if (curInv > k) {
				remove(a[r++], right);
				break;
			}
		}

		if (r == -1) {
			out.println((long) n * (n - 1) >> 1);
			return;
		}

		for (int l = 0; l < n; l++) {
			add(a[l], left);
			while (r < n && curInv > k)
				remove(a[r++], right);
			ans += n - r;
		}

		out.println(ans);

	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new E().inp();
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