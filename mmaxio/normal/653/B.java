import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	int[][] a;
	
	boolean good(int[] b) {
		b = b.clone();
		for (int i = 0; i < b.length - 1; i++) {
			int nxt = a[b[i]][b[i + 1]];
			if (nxt == -1) 
				return false;
			b[i + 1] = nxt;
		}
		return b[b.length - 1] == 0;
	}
	
	int go(int pos, int[] b) {
		int ret =0;
		if (pos == b.length) {
			return good(b) ? 1 : 0;
		}
		for (int i = 0; i < 6; i++) {
			b[pos] = i;
			ret += go(pos + 1, b);
		}
		return ret;
	}

	void solve() throws IOException {
		int n = nextInt();
		int q = nextInt();
		
		a = new int[6][6];
		for (int i = 0; i < 6; i++) {
			Arrays.fill(a[i], -1);
		}
		
		for (int i = 0; i < q; i++) {
			String from = nextToken();
			String to = nextToken();
			a[from.charAt(0) - 'a'][from.charAt(1) - 'a'] = to.charAt(0) - 'a';
		}
		
		int[] b = new int[n];
		out.println(go(0, b));
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