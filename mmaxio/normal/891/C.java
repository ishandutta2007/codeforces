import java.io.*;
import java.util.*;

public class C_new {

	static class Edge implements Comparable<Edge> {
		int v, u, len;
		int id;

		public Edge(int v, int u, int len, int id) {
			this.v = v;
			this.u = u;
			this.len = len;
			this.id = id;
		}

		@Override
		public int compareTo(Edge o) {
			return Integer.compare(len, o.len);
		}
	}

	int[] p;
	int[] rank;

	void submit() {
		int n = nextInt();
		int m = nextInt();
		Edge[] es = new Edge[m];
		for (int i = 0; i < m; i++) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;
			int len = nextInt();
			es[i] = new Edge(v, u, len, i);
		}

		int[] next = new int[1000000];
		int[] head = new int[500001];
		int[] what = new int[1000000];
		Arrays.fill(head, -1);

		int ptr = 0;
		
		int[] lastUsedQry = new int[5000001];
		Arrays.fill(lastUsedQry, -1);

		int q = nextInt();
		for (int i = 0; i < q; i++) {
			int k = nextInt();
			int[] arr = new int[k];
			for (int j = 0; j < k; j++) {
				arr[j] = nextInt() - 1;
				int e = arr[j];
				int len = es[e].len;

				// add marker of query
				if (lastUsedQry[len] != i) {
					what[ptr] = ~i;
					next[ptr] = head[len];
					head[len] = ptr++;
					lastUsedQry[len] = i;
				}

				what[ptr] = e;
				next[ptr] = head[len];
				head[len] = ptr++;
			}
		}

		boolean[] ans = new boolean[q];
		Arrays.fill(ans, true);

		p = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = i;
		}

		Edge[] sorted = es.clone();
		Arrays.sort(sorted);

		hist = new int[10_000_000];

		ptr = 0;
		for (int len = 1; len <= 500000; len++) {
			while (ptr < m && sorted[ptr].len < len) {
				Edge edge = sorted[ptr++];
				unite(edge.v, edge.u);
			}
			for (int idx = head[len]; idx >= 0; idx = next[idx]) {

				int time = getTime();
				boolean failQuery = false;
				while (what[idx] >= 0) {
					Edge edge = es[what[idx]];
					if (!unite(edge.v, edge.u)) {
						failQuery = true;
					}
					idx = next[idx];
				}

				rollback(time);
				int query = ~what[idx];
				if (failQuery) {
					ans[query] = false;
				}
			}
		}
		
		for (boolean b : ans) {
			out.println(b ? "YES" : "NO");
		}
	}

	int getTime() {
		return time;
	}

	void rollback(int toTime) {
		while (time > toTime) {
			int oldVal = hist[--time];
			int idx = hist[--time];
			p[idx] = oldVal;
		}
	}

	boolean unite(int v, int u) {
		v = get(v);
		u = get(u);
		if (v == u) {
			return false;
		}
		if (rng.nextBoolean()) {
			int tmp = v;
			v = u;
			u = tmp;
		}
		hist[time++] = v;
		hist[time++] = p[v];
		p[v] = u;
		return true;
	}

	int get(int v) {
		if (p[v] == v) {
			return v;
		} else {
			int newVal = get(p[v]);
			hist[time++] = v;
			hist[time++] = p[v];
			p[v] = newVal;
			return newVal;
		}
	}

	int[] hist;
	int time;

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	C_new() throws IOException {
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
		new C_new();
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