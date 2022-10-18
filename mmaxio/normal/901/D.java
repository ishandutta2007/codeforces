import java.io.*;
import java.util.*;

public class D {

	int[] head;
	int[] next;
	int[] to;

	int[] cs;

	int[] parEdge;
	int[] col;

	long[] ans;

	int v1 = -1, v2 = -1;
	int eOdd = -1;

	long val0;
	
	void dfs(int v, int p) {
		long sumLeft = cs[v];
		parEdge[v] = p;
		for (int e = head[v]; e >= 0; e = next[e]) {
			int u = to[e];
			if (col[u] == -1) {
				col[u] = col[v] ^ 1;
				dfs(u, e);
				sumLeft -= ans[e >> 1];
			} else if (col[u] == col[v]) {
				v1 = v;
				v2 = u;
				eOdd = e;
			}
		}
		if (p != -1) {
			ans[p >> 1] = sumLeft;
		} else {
			val0 = sumLeft;
		}
	}

	void submit() {
		int n = nextInt();
		int m = nextInt();

		head = new int[n];
		Arrays.fill(head, -1);
		next = new int[2 * m];
		to = new int[2 * m];

		cs = new int[n];
		for (int i = 0; i < n; i++) {
			cs[i] = nextInt();
		}

		for (int i = 0; i < m; i++) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;

			to[2 * i] = u;
			next[2 * i] = head[v];
			head[v] = 2 * i;

			to[2 * i + 1] = v;
			next[2 * i + 1] = head[u];
			head[u] = 2 * i + 1;
		}

		parEdge = new int[n];
		col = new int[n];
		Arrays.fill(col, -1);
		col[0] = 0;
		ans = new long[m];
		dfs(0, -1);
		
		if (val0 == 0) {
			out.println("YES");
			for (long x : ans) {
				out.println(x);
			}
			return;
		}
		
		if (eOdd == -1) {
			out.println("NO");
			return;
		}
		
		List<Integer> path = new ArrayList<>();
		for (int i = v1; i > 0; i = to[parEdge[i] ^ 1]) {
			path.add(parEdge[i] >> 1);
		}
		Collections.reverse(path);
		path.add(eOdd >> 1);
		for (int i = v2; i > 0; i = to[parEdge[i] ^ 1]) {
			path.add(parEdge[i] >> 1);
		}
		
		if (val0 % 2 != 0) {
			throw new AssertionError();
		}
		
		long delta = -val0 / 2;
		
		for (int i = 0; i < path.size(); i++) {
			int idx = path.get(i);
			if (i % 2 == 0) {
				ans[idx] -= delta;
			} else {
				ans[idx] += delta;
			}
		}
		
		out.println("YES");
		for (long x : ans) {
			out.println(x);
		}
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	D() throws IOException {
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
		new D();
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