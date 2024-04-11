import java.io.*;
import java.util.*;

public class E {

	int[] a;

	static final int LOG = 8;
	static final int BLOCK = 1 << LOG;
	static final int LOW_MASK = BLOCK - 1;

	int[] head;
	int[] next;
	int[] to;

	int[] par;
	int[] depth;

	void dfs(int v, int p) {
		par[v] = p;
		for (int e = head[v]; e >= 0; e = next[e]) {
			int u = to[e];
			if (u == p) {
				continue;
			}
			depth[u] = depth[v] + 1;
			dfs(u, v);
		}
	}

	int[][] go = new int[2][BLOCK * LOG + 1];
	int triePtr = 0;

	int newNode() {
		go[0][triePtr] = go[1][triePtr] = -1;
		return triePtr++;
	}

	void submit() {
		int n = nextInt();
		int q = nextInt();

		a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}

		head = new int[n];
		next = new int[2 * n - 2];
		to = new int[2 * n - 2];
		Arrays.fill(head, -1);

		for (int i = 0; i < n - 1; i++) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;

			to[2 * i] = u;
			next[2 * i] = head[v];
			head[v] = 2 * i;

			to[2 * i + 1] = v;
			next[2 * i + 1] = head[u];
			head[u] = 2 * i + 1;
		}

		par = new int[n];
		depth = new int[n];
		dfs(0, -1);

		int[] parBlock = new int[n];
		
		int[][] prec = new int[n][];

		for (int i = 0; i < n; i++) {
			if (depth[i] < BLOCK) {
				continue;
			}
			int[] bestLow = new int[BLOCK];
			Arrays.fill(bestLow, -1);

			int v = i;
			for (int j = 0; j < BLOCK; j++) {
				int now = a[v] ^ j;
				int low = now & LOW_MASK;
				int high = now >> LOG;
				bestLow[high] = Math.max(bestLow[high], low);
				v = par[v];
			}

			parBlock[i] = v;
			
			triePtr = 0;
			int root = newNode();
			
			for (int j = 0; j < BLOCK; j++) {
				if (bestLow[j] == -1) {
					continue;
				}
				
				v = root;
				
				for (int k = LOG - 1; k >= 0; k--) {
					int bit = getBit(j, k);
					if (go[bit][v] == -1) {
						go[bit][v] = newNode();
					}
					v = go[bit][v];
				}
			}
			
			prec[i] = new int[BLOCK];
			
			for (int j = 0; j < BLOCK; j++) {
				v = root;
				
				int highPicked = 0;
				
				for (int k = LOG - 1; k >= 0; k--) {
					int bit = getBit(j, k);
					if (go[bit ^ 1][v] != -1) {
						highPicked |= (bit ^ 1) << k;
						v = go[bit ^ 1][v];
					} else {
						highPicked |= bit << k;
						v = go[bit][v];
					}
				}
				
				prec[i][j] = ((highPicked ^ j) << LOG) | bestLow[highPicked];
			}
			
		}
		
		while (q-- > 0) {
			int top = nextInt() - 1;
			int btm = nextInt() - 1;
			
			int ret = 0;
			int i = 0;
			for (;; i++) {
				if (depth[btm] - BLOCK >= depth[top]) {
					ret = Math.max(ret, prec[btm][i]);
					btm = parBlock[btm];
				} else {
					break;
				}
			}
			
			i <<= LOG;
			while (btm != -1 && depth[btm] >= depth[top]) {
				ret = Math.max(ret, a[btm] ^ i);
				btm = par[btm];
				i++;
			}
			
			out.println(ret);
		}
	}
	
	int getBit(int mask, int i) {
		return (mask >> i) & 1;
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