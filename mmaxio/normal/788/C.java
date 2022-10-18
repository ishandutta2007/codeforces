import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int[] unique(int[] a) {
		Arrays.sort(a);
		int sz = 1;
		for (int i = 0; i < a.length; i++) {
			if (a[i] != a[sz - 1]) {
				a[sz++] = a[i];
			}
		}
		return Arrays.copyOf(a, sz);
	}
	
	void solve() throws IOException {
		int need = nextInt();
		int n = nextInt();
		
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt() - need;
		}
		
		a = unique(a);
		
		boolean hasNeg = false;
		boolean hasPos = false;
		
		for (int x : a) {
			if (x == 0) {
				out.println(1);
				return;
			}
			hasNeg |= x < 0;
			hasPos |= x > 0;
		}
		
		if (!hasNeg || !hasPos) {
			out.println(-1);
			return;
		}
		
		int[] d = new int[X * 2 + 1];
		Arrays.fill(d, INF);
		int[] que = new int[X * 2 + 1];
		int head = 0;
		int tail = 0;
		que[tail++] = X;
		d[X] = 0;
		
		while (head < tail) {
			int v = que[head++];
			for (int x : a) {
				int u = v + x;
				if (u < 0 || u >= d.length) {
					continue;
				}
				if (u == X) {
					out.println(d[v] + 1);
					return;
				}
				if (d[u] > d[v] + 1) {
					d[u] = d[v] + 1;
					que[tail++] = u;
				}
			}
		}
		
		throw new AssertionError();
	}
	
	static final int X = 3000;
	static final int INF = Integer.MAX_VALUE / 3;
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