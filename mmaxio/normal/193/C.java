import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	boolean odd(int x) {
		return (x & 1) == 1;
	}
	
	boolean test(int mask, int i) {
		return ((mask >> i) & 1) == 1;
	}

	void solve() throws IOException {
		int a1 = nextInt();
		int a2 = nextInt();
		int a3 = nextInt();
		int a4 = nextInt();
		int a5 = nextInt();
		int a6 = nextInt();

		int atLeast = Integer.MIN_VALUE;
		int atMost = Integer.MAX_VALUE;
		
		int[] cnt = {a2 + a3 + a6, a1 + a3 + a5, a1 + a2 + a5 + a6, a1 + a2 + a4, a1 + a3 + a4 + a6, a2 + a3 + a4 + a5, a4 + a5 + a6}; 
		
		for (int i = 0; i < 7; i++) {
			if (odd(cnt[i])) {
				out.println(-1);
				return;
			}
			cnt[i] /= 2;
		}
		
		atLeast = Math.max(Math.max(Math.max(cnt[0], cnt[1]), cnt[3]), cnt[6]);
		atMost = Math.min(Math.min(cnt[2], cnt[4]), cnt[5]);
		
		if (atLeast > atMost) {
			out.println(-1);
			return;
		}
		
		int ans = atLeast;
		cnt[0] = ans - cnt[0];
		cnt[1] = ans - cnt[1];
		cnt[2] = cnt[2] - ans;
		cnt[3] = ans - cnt[3];
		cnt[4] = cnt[4] - ans;
		cnt[5] = cnt[5] - ans;
		cnt[6] = ans - cnt[6];
		
		out.println(ans);
		char[][] a = new char[4][ans];
		for (int i = 1, j = 0; i < 8; i++) {
			for (int cur = cnt[i - 1]; cur > 0; cur--, j++) {
				a[1][j] = test(i, 0) ? 'b' : 'a';
				a[2][j] = test(i, 1) ? 'b' : 'a';
				a[3][j] = test(i, 2) ? 'b' : 'a';
			}
		}
		
		Arrays.fill(a[0], 'a');
		for (int i = 0; i < 4; i++)
			out.println(new String(a[i]));
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C().inp();
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