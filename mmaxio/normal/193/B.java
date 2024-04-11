import java.io.*;
import java.util.*;

public class B_new {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int[] a, b, k, p;
	int n, r;
	
	int[] tmpAdd;
	
	long eval(int[] a) {
		long res = 0;
		for (int i = 0; i < n; i++)
			res += (long)a[i] * k[i];
		return res;
	}
	
	void add(int[] a) {
		for (int i = 0; i < n; i++)
			tmpAdd[i] = a[p[i] - 1] + r;
		System.arraycopy(tmpAdd, 0, a, 0, n);
	}

	long go(int[] a, int left, boolean prevXor) {
		
		if (left == 0)
			return eval(a);
		
		long res = Long.MIN_VALUE;
		
		if ((left & 1) == 0)
			res = eval(a);
		if (!prevXor) {
			int[] tmp = a.clone();
			for (int i = 0; i < n; i++)
				tmp[i] ^= b[i];
			res = Math.max(res, go(tmp, left - 1, true));
		}
		
		add(a);
		res = Math.max(res, go(a, left - 1, false));
		return res;
	}

	void solve() throws IOException {
		n = nextInt();
		int op = nextInt();
		r = nextInt();		

		a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = nextInt();

		b = new int[n];
		for (int i = 0; i < n; i++)
			b[i] = nextInt();

		k = new int[n];
		for (int i = 0; i < n; i++)
			k[i] = nextInt();

		p = new int[n];
		for (int i = 0; i < n; i++)
			p[i] = nextInt();
		
		tmpAdd = new int[n];
		
		long res = go(a, op, false);
		out.println(res);
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B_new().inp();
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