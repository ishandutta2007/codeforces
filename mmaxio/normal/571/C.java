import java.io.*;
import java.util.*;

public class C_noflow_burunduk {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int[] ret;

	List<Integer>[] where, what;
	boolean[] disjSat;

	int[] pair;
	int[] pair2;
	int[] vis;
	int visVer;

	int mustValue(int var) {
		if (ret[var] != 0) {
			return ret[var];
		}

		boolean canTrue = true;
		boolean canFalse = true;

		List<Integer> list = where[var];
		for (int i = 0; i < list.size(); i++) {
			int disj = list.get(i);
			int justDisj = disj >= 0 ? disj : ~disj;
			if (disjSat[justDisj]) {
				continue;
			}
			if (disj >= 0) {
				canFalse = false;
			} else {
				canTrue = false;
			}
		}

		if (canFalse) {
			return -1;
		}
		if (canTrue) {
			return 1;
		}
		return 0;
	}

	boolean dfs(int v) {
		vis[v] = visVer;
		List<Integer> list = where[v];
		for (int i = 0; i < list.size(); i++) {
			int to = list.get(i);
			if (to < 0) {
				to = ~to;
			}
			if (pair[to] == -1 || (vis[pair[to]] != visVer && dfs(pair[to]))) {
				pair[to] = v;
				pair2[v] = to;
				return true;
			}
		}
		return false;
	}

	void solve() throws IOException {
		int m = nextInt();
		int n = nextInt();

		where = new List[n];
		for (int i = 0; i < n; i++) {
			where[i] = new ArrayList<>(2);
		}

		what = new List[m];
		for (int i = 0; i < m; i++) {
			what[i] = new ArrayList<>();
		}

		for (int i = 0; i < m; i++) {
			int k = nextInt();
			for (int j = 0; j < k; j++) {
				int var = nextInt();
				if (var > 0) {
					var--;
				}
				what[i].add(var);
				int justVar = var >= 0 ? var : ~var;
				where[justVar].add(var >= 0 ? i : ~i);
			}
		}

		ret = new int[n];
		disjSat = new boolean[m];
		ArrayDeque<Integer> q = new ArrayDeque<>();
		for (int i = 0; i < n; i++) {
			int tmp = mustValue(i);
			if (tmp != 0) {
				// System.err.println(i + " " + tmp);
				q.add(i);
			}
		}

		while (!q.isEmpty()) {
			int var = q.poll();
			if (ret[var] != 0) {
				continue;
			}
			int val = mustValue(var);
			ret[var] = val;
			List<Integer> list = where[var];
			for (int i = 0; i < list.size(); i++) {
				int disj = list.get(i);
				int justDisj = disj >= 0 ? disj : ~disj;
				if (!disjSat[justDisj]) {
					disjSat[justDisj] = true;
					for (int var2 : what[justDisj]) {
						int justVar2 = var2 >= 0 ? var2 : ~var2;
						if (mustValue(justVar2) != 0) {
							q.add(justVar2);
						}
					}
				}
			}
		}

		pair = new int[m];
		vis = new int[n];
		Arrays.fill(pair, -1);

		pair2 = new int[n];
		Arrays.fill(pair2, -1);

		outer: for (int v = 0; v < n; v++) {
			if (ret[v] == 0) {
				List<Integer> list = where[v];
				for (int i = 0; i < list.size(); i++) {
					int to = list.get(i);
					if (to < 0) {
						to = ~to;
					}
					if (pair[to] == -1) {
						pair[to] = v;
						pair2[v] = to;
						continue outer;
					}
				}
			}
		}

		for (boolean run = true; run;) {

			run = false;
			visVer++;

			for (int i = 0; i < n; i++) {
				if (ret[i] == 0 && pair2[i] == -1 && dfs(i)) {
					run = true;
				}
			}

		}

		for (int i = 0; i < m; i++) {
			if (disjSat[i]) {
				continue;
			}
			if (!disjSat[i] && pair[i] == -1) {
				out.println("NO");
				return;
			}
			int var = pair[i];
			if (find(where[var], i)) {
				ret[var] = 1;
			} else if (find(where[var], ~i)) {
				ret[var] = -1;
			} else {
				throw new AssertionError();
			}
		}

		out.println("YES");
		for (int i = 0; i < n; i++) {
			if (ret[i] >= 0) {
				out.print(1);
			} else {
				out.print(0);
			}
		}
		out.println();
	}

	boolean find(List<Integer> list, int x) {
		for (int y : list) {
			if (x == y) {
				return true;
			}
		}
		return false;
	}

	C_noflow_burunduk() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C_noflow_burunduk();
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