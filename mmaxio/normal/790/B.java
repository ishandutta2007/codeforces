import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	List<Integer>[] g;
	
	int n, k;
	
	int[][] cnt;
	int[] size;
	
	long sumRem;
	long sumFull;
	
	void dfs(int v, int p) {
		size[v] = 1;
		cnt[v][0] = 1;
		for (int u : g[v]) {
			if (u == p) {
				continue;
			}
			
			dfs(u, v);
			size[v] += size[u];
			
			for (int i = 0; i < k; i++) {
				for (int j = 0; j < k; j++) {
					int rem = (i + j + 1) % k;
					if (rem != 0) {
						rem = k - rem;
					}
					sumRem += (long)cnt[v][i] * cnt[u][j] * rem; 
				}
			}
			
			for (int i = 0; i < k; i++) {
				cnt[v][(i + 1) % k] += cnt[u][i];
			}
			
		}
		
		sumFull += (long)size[v] * (n - size[v]); 
	}
	
	static final Random rng = new Random();
	
	void solve() throws IOException {
		n = nextInt();
		k = nextInt();
		
		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		
		for (int i = 0; i < n - 1; i++) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;
			g[v].add(u);
			g[u].add(v);
		}
		
		cnt = new int[n][k];
		size = new int[n];
		sumRem = 0;
		sumFull = 0;
		
		dfs(0, -1);
		
		long ans = sumFull + sumRem;
		if (ans % k != 0) {
			throw new AssertionError();
		}
		
		out.println(ans / k);
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