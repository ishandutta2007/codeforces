import java.io.*;
import java.util.*;

public class D_test {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	List<Integer>[] g;

	Random rng = new Random(System.currentTimeMillis() + 12983195189052L);

	long[] multHash;
	long addHash;

	HashMap<Long, Integer> myMap = new HashMap<>();
	
	void genHash() {
		multHash = new long[n];
		for (int i = 0; i < n; i++) {
			multHash[i] = rng.nextLong();
		}
		addHash = rng.nextLong();
	}

	long[][] arr;
	int[] ptr;

	long[] hashDown;
	long[] hashUp;

	int time;

	void dfs1(int v, int p) {
		ptr[v] = 0;
		for (int u : g[v]) {
			if (u != p) {
				depth[u] = depth[v] + 1;
				dfs1(u, v);
				arr[v][ptr[v]++] = hashDown[u];
			}
		}
		Arrays.sort(arr[v], 0, ptr[v]);
		hashDown[v] = addHash;
		for (int i = 0; i < ptr[v]; i++) {
			hashDown[v] += multHash[i] * arr[v][i];
		}
		
		Integer prev = myMap.get(hashDown[v]);
		if (prev == null) {
			prev = myMap.size() + 1;
			myMap.put(hashDown[v], prev);
		}
		
		hashDown[v] = prev;
	}

	int findWhere(long[] arr, int sz, long what) {
		int low = -1; // <
		int high = sz; // >=
		while (high - low > 1) {
			int mid = (low + high) >> 1;
			if (arr[mid] < what) {
				low = mid;
			} else {
				high = mid;
			}
		}
		return high;
	}

	void dfs2(int v, int p, long hashUp) {
		if (p != v) {
			
			Integer prev = myMap.get(hashUp);
			if (prev == null) {
				prev = myMap.size() + 1;
				myMap.put(hashUp, prev);
			}
			
			hashUp = prev;
			
			int where = findWhere(arr[v], ptr[v], hashUp);
			for (int i = ptr[v] - 1; i >= where; i--) {
				arr[v][i + 1] = arr[v][i];
			}
			arr[v][where] = hashUp;
			ptr[v]++;
			this.hashUp[v] = hashUp;
		}

		long[] newHash = new long[ptr[v]];
		long base = addHash;
		for (int i = 1; i < ptr[v]; i++) {
			base += multHash[i - 1] * arr[v][i];
		}
		newHash[0] = base;

		for (int i = 1; i < ptr[v]; i++) {
			base += multHash[i - 1] * (arr[v][i - 1] - arr[v][i]);
			newHash[i] = base;
		}

		for (int u : g[v]) {
			if (u == p) {
				continue;
			}

			int idx = findWhere(arr[v], ptr[v], hashDown[u]);
			dfs2(u, v, newHash[idx]);
		}
	}

	int[] delta;
	int[] depth;

	void dfs3(int v, int p) {
		for (int u : g[v]) {
			if (u != p) {
				delta[u] += delta[v];
				dfs3(u, v);
			}
		}
	}

	int n;
	
	int solve(){
		if (n == 1) {
			return 0;
		}

		genHash();

		arr = new long[n][];
		ptr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = new long[g[i].size()];
		}

		depth = new int[n];
		hashDown = new long[n];
		dfs1(0, 0);

		hashUp = new long[n];
		dfs2(0, 0, 0);

//		 System.err.println(Arrays.toString(hashDown));
//		 System.err.println(Arrays.toString(hashUp));

		HashMap<Long, ArrayList<Integer>> map = new HashMap<>();

		for (int i = 1; i < n; i++) {

			{
				long what = hashDown[i];
				int val = i;

				ArrayList<Integer> prev = map.get(what);
				if (prev == null) {
					prev = new ArrayList<>();
					map.put(what, prev);
				}
				prev.add(val);
			}

			{
				long what = hashUp[i];
				int val = ~i;

				ArrayList<Integer> prev = map.get(what);
				if (prev == null) {
					prev = new ArrayList<>();
					map.put(what, prev);
				}
				prev.add(val);
			}

		}

		delta = new int[n];

		outer: for (Map.Entry<Long, ArrayList<Integer>> e : map.entrySet()) {
			ArrayList<Integer> lst = e.getValue();

//			 System.err.println(lst);

			int cntDown = 0;

			int whoDown = -1;

			for (int v : lst) {
				if (v >= 0) {
					cntDown++;
					whoDown = v;
				}
			}
			if (cntDown >= 2) {
				continue;
			}

			if (cntDown == 0) {
				for (int v : lst) {
					if (v >= 0) {
						delta[v]--;
					} else {
						delta[~v]++;
					}
				}
				continue;
			}

			for (int v : lst) {
				if (v < 0) {
					v = ~v;
					if (depth[v] <= depth[whoDown]) {
						continue outer;
					}
				}
			}

			for (int v : lst) {
				if (v >= 0) {
					delta[v]--;
				} else {
					delta[~v]++;
				}
			}

			// System.err.println(Arrays.toString(delta));
		}
		
		dfs3(0, 0);

//		System.err.println(Arrays.toString(delta));
		
		int best = Integer.MIN_VALUE;
		int ans = -1;

		for (int i = 0; i < n; i++) {
			if (delta[i] > best) {
				best = delta[i];
				ans = i;
			}
		}
		
		return ans;
	}
	
	ArrayList<int[]> dict = new ArrayList<>();

	int getId(int[] arr) {
		for (int i = 0; i < dict.size(); i++) {
			if (Arrays.equals(arr, dict.get(i))) {
				return i;
			}
		}
		dict.add(arr);
		return dict.size() - 1;
	}
	
	int dfsSlow(int v, int p, HashSet<Integer> diff) {
		int[] arr = new int[g[v].size() - (v == p ? 0 : 1)];
		int ptr = 0;
		for (int u : g[v]) {
			if (u != p) {
				arr[ptr++] = dfsSlow(u, v, diff);
			}
		}
		Arrays.sort(arr);
		int ret = getId(arr);
		diff.add(ret);
		return ret;
	}
	
	int solveSlow() {
		int ans = -1;
		int best = -1;
		
		for (int i = 0; i < n; i++) {
			HashSet<Integer> diff = new HashSet<>();
			dfsSlow(i, i, diff);
			System.err.println(diff.size());
			if (diff.size() > best) {
				best = diff.size();
				ans = i;
			}
		}
		
		return ans;
	}
	
	void submit() throws IOException {
		n = nextInt();
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
		out.println(solve() + 1);
//		out.println(solveSlow() + 1);
	}
	
	void test() {
		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		
		for (int i = 1; i < n; i++) {
			int j = rng.nextInt(i);
			g[i].add(j);
			g[j].add(i);
		}
		
//		System.err.println(Arrays.toString(g));
		
		if (solve() != solveSlow()) {
			System.err.println(n);
			for (int v = 0; v < n; v++) {
				for (int u : g[v]) {
					if (v < u) {
						System.err.println((v + 1) + " " + (u + 1));
					}
				}
			}
			throw new AssertionError();
		}
	}
	
	D_test() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		submit();
		
//		n = 50;
//		for (int tst = 0; tst < Integer.MAX_VALUE; tst++) {
//			test();
//			System.err.println(tst);
//		}
		
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D_test();
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