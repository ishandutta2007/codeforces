import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int[] p, size;
	
	Random rng = new Random();
	
	int get(int v) {
		return p[v] == v ? v : (p[v] = get(p[v]));
	}
	
	void unite(int a, int b) {
		a = get(a);
		b = get(b);
		
		if (a == b) {
			return;
		}
		
		if (rng.nextBoolean()) {
			int tmp = a;
			a = b;
			b = tmp;
		}
		
		p[b] = a;
		size[a] += size[b];
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int k = nextInt();

		int[] mark = new int[k];
		for (int i = 0; i < k; i++) {
			mark[i] = nextInt() - 1;
		}

		p = new int[n];
		size = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = i;
			size[i] = 1;
		}

		for (int i = 0; i < m; i++) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;
			unite(v, u);
		}
		
		boolean[] used = new boolean[n];
		
		int[] szs = new int[k];
		
		for (int i = 0; i < k; i++) {
			int v = get(mark[i]);
			used[v] = true;
			szs[i] = size[v];
		}
		
		Arrays.sort(szs);
		
		for (int i = 0; i < n; i++) {
			int v = get(i);
			if (v == i && !used[v]) {
				szs[k - 1] += size[v];
			}
		}
		
		int total = 0;
		for (int x : szs) {
			total += x * (x - 1) / 2;
		}
		
		out.println(total - m);
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