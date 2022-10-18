import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int[] p;
	
	int get(int v) {
		return p[v] == v ? v : (p[v] = get(p[v]));
	}

	void merge(int a, int b) {
		a = get(a);
		b = get(b);
		if (a == b) {
			return;
		}

		if (((a + b) & 1) == 1) {
			p[a] = b;
		} else {
			p[b] = a;
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int maxW = nextInt();

		int[] ws = new int[n];
		for (int i = 0; i < n; i++) {
			ws[i] = nextInt();
		}

		int[] bs = new int[n];
		for (int i = 0; i < n; i++) {
			bs[i] = nextInt();
		}

		p = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = i;
		}

		for (int i = 0; i < m; i++) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;
			merge(v, u);
		}
		
		List<Integer>[] who = new List[n];
		for (int i = 0; i < n; i++) {
			who[i] = new ArrayList<>();
		}
		
		for (int i = 0; i < n; i++) {
			who[get(i)].add(i);
		}
		
		long[] dp = new long[maxW + 1];
		
		for (int i = 0; i < n; i++) {
			if (who[i].isEmpty()) {
				continue;
			}
			
			int sumW = 0;
			long sumB = 0;
			for (int j : who[i]) {
				sumW += ws[j];
				sumB += bs[j];
			}
			
			for (int w = maxW; w >= 0; w--) {
				if (w >= sumW) {
					dp[w] = Math.max(dp[w], dp[w - sumW] + sumB);
				}
				
				for (int j : who[i]) {
					if (w >= ws[j]) {
						dp[w] = Math.max(dp[w], dp[w - ws[j]] + bs[j]);
					}
				}
				
			}
			
		}
		
		long ans = 0;
		for (long x : dp) {
			ans = Math.max(ans, x);
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