import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int LOG = 17;

	List<Integer>[] g;
	int[] tIn, tOut;
	int time;

	void dfs(int v, int p) {
		tIn[v] = time++;
		for (int to : g[v]) {
			if (to != p) {
				dfs(to, v);
			}
		}
		tOut[v] = time;
	}

	boolean isAnc(int v1, int v2) {
		return tIn[v1] <= tIn[v2] && tOut[v2] <= tOut[v1];
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();

		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}

		int[][] up = new int[n][LOG];
		int[][] max = new int[n][LOG];
		for (int i = 0; i < n; i++) {
			up[i][0] = i;
			max[i][0] = -1;
		}

		List<Integer> who = new ArrayList<>();
		List<Integer> when = new ArrayList<>();

		List<Integer> qWho = new ArrayList<>();
		List<Integer> qWhen = new ArrayList<>();

		for (int i = 0; i < m; i++) {
			int type = nextInt();
			int x = nextInt() - 1;
			if (type == 1) {
				int y = nextInt() - 1;
				g[y].add(x);
				up[x][0] = y;
				max[x][0] = i;
			} else if (type == 2) {
				who.add(x);
				when.add(i);
			} else {
				int num = nextInt() - 1;
				qWho.add(x);
				qWhen.add(num);
			}
		}

		tIn = new int[n];
		tOut = new int[n];
		for (int i = 0; i < n; i++) {
			if (up[i][0] == i) {
				dfs(i, -1);
			}
		}

		for (int i = 1; i < LOG; i++)
			for (int j = 0; j < n; j++) {
				up[j][i] = up[up[j][i - 1]][i - 1];
				max[j][i] = Math.max(max[j][i - 1], max[up[j][i - 1]][i - 1]);
			}
		
//		System.err.println(Arrays.toString(tIn));
//		System.err.println(Arrays.toString(tOut));

		for (int i = 0; i < qWho.size(); i++) {
			int init = who.get(qWhen.get(i));
			int v = init;
			int bound = when.get(qWhen.get(i));
			for (int j = LOG - 1; j >= 0; j--) {
				if (max[v][j] < bound) {
					v = up[v][j];
				}
			}
			boolean ans = isAnc(v, qWho.get(i)) && isAnc(qWho.get(i), init);
			out.println(ans ? "YES" : "NO");
		}
	}

	E() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new E();
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