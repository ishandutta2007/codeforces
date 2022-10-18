import java.io.*;
import java.util.*;

public class C_even_shorter {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int INF = 314000000;

	static class Split {
		int from;

		int[] to;
		int profit;

		int unknown;

		int curUnknown;

		public Split(int from, int[] inp) {

			this.from = from;
			for (int i = 0; i < inp.length; i++) {
				if (inp[i] < 0)
					profit++;
			}
			curUnknown = unknown = inp.length - profit;
			to = new int[unknown];
			for (int i = 0, j = 0; i < inp.length; i++) {
				if (inp[i] >= 0) {
					to[j++] = inp[i];
				}
			}
		}

	}

	void dfs1(int v) {
		vis[v] = 1;
		loop: for (int i = 0; i < g[v].size(); i++) {
			Split s = g[v].get(i);
			for (int j = 0; j < s.to.length; j++) {
				int to = s.to[j];
				if (!canEnd[to]) {
					continue loop;
				}
			}
			for (int j = 0; j < s.to.length; j++) {
				int to = s.to[j];
				if (vis[to] == 0) {
					dfs1(to);
					// now vis[to] == 2!
				}
				if (canInf[to] || vis[to] == 1) {
					canInf[v] = true;
					break loop;
				}
			}
		}
		vis[v] = 2;
	}

	void dfs3(int v) {
		vis[v] = 1;
		ansMax[v] = -1;
		outer: for (int i = 0; i < g[v].size(); i++) {
			Split s = g[v].get(i);

			int curSum = s.profit;

			for (int j = 0; j < s.to.length; j++) {
				if (!canEnd[s.to[j]])
					continue outer;
				if (vis[s.to[j]] == 0) {
					dfs3(s.to[j]);
				}
				curSum = Math.min(curSum + ansMax[s.to[j]], INF);
			}

			ansMax[v] = Math.max(ansMax[v], curSum);
		}
	}

	int[] vis;
	List<Split>[] g;

	int[] ansMax;

	boolean[] canInf;
	boolean[] canEnd;

	void solve() throws IOException {
		int m = nextInt();
		int n = nextInt();

		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}

		List<Split>[] backLink = new List[n];
		for (int i = 0; i < n; i++) {
			backLink[i] = new ArrayList<>();
		}

		for (int i = 0; i < m; i++) {
			int from = nextInt() - 1;
			int len = nextInt();
			int[] inp = new int[len];
			for (int j = 0; j < len; j++) {
				inp[j] = nextInt() - 1;
			}
			Split s = new Split(from, inp);
			g[from].add(s);

			for (int j = 0; j < s.to.length; j++) {
				backLink[s.to[j]].add(s);
			}
		}

		// minimum
		final int[] ansMin = new int[n];
		Arrays.fill(ansMin, INF + 1);
		TreeSet<Integer> set = new TreeSet<>(new Comparator<Integer>() {

			@Override
			public int compare(Integer o1, Integer o2) {
				if (ansMin[o1] != ansMin[o2]) {
					return Integer.compare(ansMin[o1], ansMin[o2]);
				}
				return o1.compareTo(o2);
			}

		});

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < g[i].size(); j++) {
				Split s = g[i].get(j);
				if (s.unknown == 0) {
					ansMin[i] = Math.min(ansMin[i], s.profit);
				}
			}

			if (ansMin[i] <= INF) {
				set.add(i);
			}

		}

		while (!set.isEmpty()) {
			int v = set.pollFirst();
			for (int i = 0; i < backLink[v].size(); i++) {
				Split s = backLink[v].get(i);
				s.curUnknown--;
				if (s.curUnknown == 0) {

					int sProfit = s.profit;
					for (int j = 0; j < s.to.length; j++) {
						sProfit = Math.min(sProfit + ansMin[s.to[j]], INF);
					}
					if (sProfit < ansMin[s.from]) {
						set.remove(s.from);
						ansMin[s.from] = sProfit;
						set.add(s.from);
					}
				}
			}
		}

		canEnd = new boolean[n];
		for (int i = 0; i < n; i++) {
			canEnd[i] = ansMin[i] <= INF;
		}

		// maximum
		
		canInf = new boolean[n];
		vis = new int[n];

		for (int i = 0; i < n; i++) {
			if (canEnd[i] && vis[i] == 0) {
				dfs1(i);
			}
		}

		Arrays.fill(vis, 0);
		ansMax = new int[n];

		for (int i = 0; i < n; i++) {
			if (vis[i] == 0 && !canInf[i] && canEnd[i]) {
				dfs3(i);
			}
		}

		for (int i = 0; i < n; i++) {
			if (!canEnd[i]) {
				out.println("-1 -1");
			} else {
				out.print(ansMin[i] + " ");
				out.println(canInf[i] ? -2 : ansMax[i]);
			}
		}

	}

	C_even_shorter() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C_even_shorter();
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