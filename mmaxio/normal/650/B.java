import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	int n, move, flip, total;
	
	int go(String s) {
		
		long[] pref = new long[n + 1];
		for (int i = 0; i < n; i++) {
			pref[i + 1] = pref[i] + (s.charAt(i) == 'w' ? flip : 0) + 1;
		}
		
		int ret = 0;
		
		for (int i = 0; i < n; i++) {
			long base = (long)i * move + pref[i + 1];
			if (base > total) {
				break;
			}
			int low = 0;
			int high = n - i;
			while (high - low > 1) {
				int mid = (low + high) >> 1;
				long add = (long)(i + mid) * move + pref[n] - pref[n - mid];
				if (base + add <= total) {
					low = mid;
				} else {
					high = mid;
				}
			}
			
//			System.err.println(i + " " + low);
			
			ret = Math.max(ret, i + 1 + low);
		}
		
		return ret;
	}

	void solve() throws IOException {
		n = nextInt();
		move = nextInt();
		flip = nextInt();
		total = nextInt();
		
		String s = nextToken();
		
		int ans = go(s);
		
		s = new StringBuilder(s).reverse().toString();
		s = s.substring(n - 1) + s.substring(0, n - 1);
		ans = Math.max(ans, go(s));
		
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