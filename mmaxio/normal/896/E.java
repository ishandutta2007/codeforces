import java.io.*;
import java.util.*;

public class E {

	static final int N = 100_001;

	int K;

	static class Dsu {
		int[] p;
		int[] sz;

		int get(int v) {
			return p[v] == v ? v : (p[v] = get(p[v]));
		}

		void unite(int v, int u) {
			p[u] = v;
			sz[v] += sz[u];
		}

		public Dsu() {
			p = new int[N];
			sz = new int[N];
			for (int i = 0; i < N; i++) {
				p[i] = i;
			}
		}
	}

	Dsu[] ds;
	int[] max;
	int[] decr;
	int[] a;

	void updateSingle(int block, int i, int x) {
		a[i] = ds[block].get(a[i]);
		if (a[i] - decr[block] <= x) {
			return;
		}
		
		ds[block].sz[a[i]]--;
		a[i] -= x;
		
		ds[block].sz[a[i]]++;
	}
	
	void updateBlock(int block, int x) {
		if (max[block] <= x) {
			return;
		}
		
		if (x <= max[block] - x) {
			for (int i = 1; i <= x; i++) {
				ds[block].unite(i + x + decr[block], i + decr[block]);
			}
			decr[block] += x;
		} else {
			for (int i = x + 1; i <= max[block]; i++) {
				ds[block].unite(i - x + decr[block], i + decr[block]);
			}
		}
		max[block] = Math.max(x, max[block] - x);
	}
	
	int querySingle(int block, int i, int x) {
		a[i] = ds[block].get(a[i]);
		return a[i] - decr[block] == x ? 1 : 0;
	}
	
	int queryBlock(int block, int x) {
		int lookAt = x + decr[block];
		if (lookAt >= N || x > max[block]) {
			return 0;
		}
		lookAt = ds[block].get(lookAt);
		return ds[block].sz[lookAt];
	}

	void submit() {
		int n = nextInt();
		int q = nextInt();
		a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}

		K = (int) Math.sqrt(n);

		int blocks = (n - 1) / K + 1;

		ds = new Dsu[blocks];
		max = new int[blocks];
		decr = new int[blocks];
		Arrays.fill(max, N - 1);

		for (int i = 0; i < blocks; i++) {
			ds[i] = new Dsu();
			for (int j = i * K; j < Math.min(n, i * K + K); j++) {
				ds[i].sz[a[j]]++;
			}
		}

		while (q-- > 0) {
			int op = nextInt();
			int l = nextInt() - 1;
			int r = nextInt() - 1;
			int x = nextInt();
			
			int lb = l / K;
			int rb = r / K;

			if (op == 1) {
				if (lb == rb) {
					for (int i = l; i <= r; i++) {
						updateSingle(lb, i, x);
					}
				} else {
					for (int i = l; i < (lb + 1) * K; i++) {
						updateSingle(lb, i, x);
					}
					for (int i = rb * K; i <= r; i++) {
						updateSingle(rb, i, x);
					}
					for (int block = lb + 1; block < rb; block++) {
						updateBlock(block, x);
					}
				}
			} else {
				int ans = 0;
				if (lb == rb) {
					for (int i = l; i <= r; i++) {
						ans += querySingle(lb, i, x);
					}
				} else {
					for (int i = l; i < (lb + 1) * K; i++) {
						ans += querySingle(lb, i, x);
					}
					for (int i = rb * K; i <= r; i++) {
						ans += querySingle(rb, i, x);
					}
					for (int block = lb + 1; block < rb; block++) {
						ans += queryBlock(block, x);
					}
				}
				out.println(ans);
			}
		}
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	E() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
		// stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new E();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}