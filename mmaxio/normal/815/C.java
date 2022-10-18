import java.io.*;
import java.util.*;

public class C {

	int[] to;
	int[] next;
	int[] head;

	int[] baseCost;
	int[] cheapCost;

	long[][] just;
	long[][] cool;
	
	int[] sz;
	
	static final long INF = Long.MAX_VALUE / 10;
	
	void dfs(int v) {
		sz[v] = 1;
		for (int e = head[v]; e >= 0; e = next[e]) {
			int u = to[e];
			
			dfs(u);
			sz[v] += sz[u];
		}
		
		int arrSz = sz[v];
		
		just[v] = new long[arrSz + 1];
		long[] arrJust = just[v];
		Arrays.fill(arrJust, INF);
		arrJust[0] = 0;
		arrJust[1] = baseCost[v];
		
		cool[v] = new long[arrSz + 1];
		long[] arrCool = cool[v];
		Arrays.fill(arrCool, INF);
//		arrCool[0] = 0;
		arrCool[1] = cheapCost[v];
		
		int curSz = 1;
		
		for (int e = head[v]; e >= 0; e = next[e]) {
			int u = to[e];
			
			mergeInto(arrJust, just[u], curSz);
			mergeInto(arrCool, cool[u], curSz);
			curSz += sz[u];
		}
		
		for (int i = 0; i <= arrSz; i++) {
			arrCool[i] = Math.min(arrCool[i], arrJust[i]);
		}
		
		
//		System.err.println(v + " " + Arrays.toString(arrCool) + " " + Arrays.toString(arrJust));
		
	}
	
	void mergeInto(long[] a, long[] b, int aSz) {
		for (int i = aSz; i >= 0; i--) {
			for (int j = 1; j < b.length; j++) {
				a[i + j] = Math.min(a[i + j], a[i] + b[j]);
			}
		}
	}
	
	void submit() {
		int n = nextInt();
		int b = nextInt();
		
		to = new int[n - 1];
		next = new int[n - 1];
		head = new int[n];
		Arrays.fill(head, -1);
		
		baseCost = new int[n];
		cheapCost = new int[n];
		
		for (int i = 0; i < n; i++) {
			int c = nextInt();
			int d = nextInt();
			baseCost[i] = c;
			cheapCost[i] = c - d;
			if (i > 0) {
				int j = nextInt() - 1;
				to[i - 1] = i;
				next[i - 1] = head[j];
				head[j] = i - 1;
			}
		}
		
		just = new long[n][];
		cool = new long[n][];
		sz = new int[n];
		
		dfs(0);
		
//		System.err.println(Arrays.toString(cool[0]) + " " + Arrays.toString(just[0]));
		
		for (int ans = n; ; ans--) {
			if (cool[0][ans] <= b) {
				out.println(ans);
				return;
			}
		}
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	C() throws IOException {
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
		new C();
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