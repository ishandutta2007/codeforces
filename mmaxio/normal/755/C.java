import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int[] p;
	
	int get(int v) {
		return p[v] == v ? v : (p[v] = get(p[v]));
	}
	
	boolean unite(int a, int b) {
		a = get(a);
		b = get(b);
		if (a == b) {
			return false;
		}
		
		p[a] = b;
		return true;
	}
	
	void solve() throws IOException {
		int n = nextInt();
		
		p = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = i;
		}
		
		int comps = n;
		
		for (int i = 0; i < n; i++) {
			int x = nextInt() - 1;
			if (unite(i, x)) {
				comps--;
			}
		}
		
		out.println(comps);
		
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