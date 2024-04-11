import java.io.*;
import java.util.*;

public class D {

	static class Forest {
		int[] head;
		int[] next;
		int[] to;
		int ptr = 0;
		
		int n;
		
		boolean[] isRoot;
		
		public Forest(int n) {
			this.n = n;
			head = new int[n];
			Arrays.fill(head, -1);
			next = new int[n];
			to = new int[n];
			isRoot = new boolean[n];
			Arrays.fill(isRoot, true);
		}
		
		void addEdge(int v, int u) {
			if (!isRoot[u]) {
				throw new AssertionError();
			}
			isRoot[u] = false;
			to[ptr] = u;
			next[ptr] = head[v];
			head[v] = ptr;
			ptr++;
		}
		
		int[] tIn, tOut;
		int time;
		int[] whoRoot;
		
		void dfs(int v, int root) {
			whoRoot[v] = root;
			tIn[v] = time++;
			for (int e = head[v]; e >= 0; e = next[e]) {
				int u = to[e];
				dfs(u, root);
			}
			tOut[v] = time;
		}
		
		void buildTimes() {
			tIn = new int[n];
			tOut = new int[n];
			time = 0;
			whoRoot = new int[n];
			for (int i = 0; i < n; i++) {
				if (isRoot[i]) {
					dfs(i, i);
				}
			}
		}
		
		boolean isAnc(int v, int u) {
			return tIn[v] <= tIn[u] && tOut[u] <= tOut[v];
		}
	}
	
	void submit() {
		int n = nextInt();
		
		Forest spCase = new Forest(n);
		Forest partOf = new Forest(n);
		
		for (int i = 0; i < n; i++) {
			int par = nextInt();
			int type = nextInt();
			if (type == 0) {
				spCase.addEdge(par - 1, i);
			} else if (type == 1) {
				partOf.addEdge(par - 1, i);
			}
		}
		
		spCase.buildTimes();
		partOf.buildTimes();
		
		int q = nextInt();
		while (q-- > 0) {
			int type = nextInt();
			int a = nextInt() - 1;
			int b = nextInt() - 1;
			if (a == b) {
				out.println("NO");
				continue;
			}
			if (type == 1) {
				out.println(spCase.isAnc(a, b) ? "YES" : "NO");
			} else {
				int rootCaseA = spCase.whoRoot[a];
				if (rootCaseA == b) {
					out.println("NO");
					continue;
				}
				if (partOf.isAnc(rootCaseA, b)) {
					out.println("YES");
					continue;
				}
				
				int rootPartB = partOf.whoRoot[b];
				if (rootPartB != b && spCase.isAnc(rootPartB, a)) {
					out.println("YES");
					continue;
				}
				out.println("NO");
			}
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
		//stress();
		//test();
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