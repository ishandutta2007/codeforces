import java.io.*;
import java.util.*;

public class B {

	int[] next;
	int[] head;
	int[] to;
	
	int[] ds;
	
	boolean[] vis;
	
	int dfs(int v, int p) {
		vis[v] = true;
		
		int here = (ds[v] == 1 ? 1 : 0);
		
		for (int e = head[v]; e >= 0; e = next[e]) {
			int u = to[e];
			if (!vis[u]) {
				int hereU = dfs(u, v);
				if (hereU == 1) {
					ans.add(e / 2 + 1);
				}
				here ^= hereU;
			}
		}
		
		return here;
	}
	
	ArrayList<Integer> ans = new ArrayList<>();
	
	void submit() {
		int n = nextInt();
		int m = nextInt();
		ds = new int[n];
		
		int unk = -1;
		
		int cntOdd = 0;
		for (int i = 0; i < n; i++) {
			ds[i] = nextInt();
			if (ds[i] == -1) {
				unk = i;
			} else if (ds[i] == 1) {
				cntOdd++;
			}
		}
		
		if (cntOdd % 2 == 1 && unk == -1) {
			out.println(-1);
			return;
		}
		
		if (cntOdd % 2 == 1) {
			ds[unk] = 1;
		}
		
		head = new int[n];
		next = new int[2 * m];
		to = new int[2 * m];
		
		Arrays.fill(head, -1);
		for (int i = 0; i < m; i++) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;
			
			next[2 * i] = head[v];
			to[2 * i] = u;
			head[v] = 2 * i;
			
			next[2 * i + 1] = head[u];
			to[2 * i + 1] = v;
			head[u] = 2 * i + 1;
		}
		
		vis = new boolean[n];
		
		dfs(0, -1);
		out.println(ans.size());
		for (int x : ans) {
			out.println(x);
		}
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	B() throws IOException {
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
		new B();
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