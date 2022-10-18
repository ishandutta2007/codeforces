import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int n;
	ArrayList<Integer>[] part = new ArrayList[3];
	{
		for (int i = 0; i < part.length; i++)
			part[i] = new ArrayList<Integer>();
	}

	int[] cntNeed;

	ArrayList<Integer>[] open;

	int go(int st) {
		ArrayList<Integer>[] cur = new ArrayList[3];
		for (int i = 0; i < 3; i++)
			cur[i] = (ArrayList<Integer>) part[i].clone();

		int[] curNeed = cntNeed.clone();

		int ret = 0;
		int left = n;
		do {
			for (int i = cur[st].size() - 1; i >= 0; i--) {
				int v = cur[st].get(i);
				if (curNeed[v] == 0) {
					cur[st].remove(i);
					for (int j : open[v])
						curNeed[j]--;
					left--;
				}
			}
			if (left == 0)
				break;
			st = (st + 1) % 3;
			ret++;
		} while (true);
		return ret + n;
	}

	int[] tmeOut;
	boolean[] use;
	int tme = 0;

	void dfs(int v) {
		use[v] = true;
		for (int to : open[v])
			if (!use[to])
				dfs(to);
		tmeOut[v] = tme++;
	}

	void solve() throws IOException {
		n = nextInt();
		for (int i = 0; i < n; i++) {
			int p = nextInt() - 1;
			part[p].add(i);
		}

		open = new ArrayList[n];
		for (int i = 0; i < n; i++)
			open[i] = new ArrayList<Integer>();

		cntNeed = new int[n];

		for (int i = 0; i < n; i++) {
			int k = nextInt();
			cntNeed[i] = k;
			while (k-- > 0) {
				int x = nextInt() - 1;
				open[x].add(i);
			}
		}

		use = new boolean[n];
		tmeOut = new int[n];

		for (int i = 0; i < n; i++) {
			if (!use[i])
				dfs(i);
		}

		for (int i = 0; i < 3; i++)
			Collections.sort(part[i], new Comparator<Integer>() {

				@Override
				public int compare(Integer o1, Integer o2) {
					int v1 = o1;
					int v2 = o2;
					if (v1 == v2)
						return 0;
					if (tmeOut[v1] < tmeOut[v2])
						return -1;
					else
						return 1;
				}
			});

		int ans = Integer.MAX_VALUE;
		for (int i = 0; i < 3; i++)
			ans = Math.min(ans, go(i));

		out.println(ans);

	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new A().inp();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	String nextString() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken("\n");
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