import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		boolean[] freeRow = new boolean[n];
		boolean[] freeCol = new boolean[n];
		
		Arrays.fill(freeRow, true);
		Arrays.fill(freeCol, true);
		
		int m = nextInt();
		for (int i = 0; i < m; i++) {
			int x = nextInt() - 1;
			int y = nextInt() - 1;
			freeRow[x] = false;
			freeCol[y] = false;
		}
		
		int ans = 0;
		
		for (int i = 1, j = n - 2; i < j; i++, j--) {
			
			//System.err.println(i + " " + j);
			
			boolean r1 = freeRow[i];
			boolean r2 = freeRow[j];
			boolean c1 = freeCol[i];
			boolean c2 = freeCol[j];
			
			int cnt = (r1 ? 1 : 0) + (r2 ? 1 : 0) + (c1 ? 1 : 0) + (c2 ? 1 : 0);
			ans += cnt;
		}
		
		if (n % 2 == 1) {
			int mid = n / 2;
			boolean r = freeRow[mid];
			boolean c = freeCol[mid];
			if (r || c)
				ans++;
		}
		
		out.println(ans);
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