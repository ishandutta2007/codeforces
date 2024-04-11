import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int n, m, h, t;
	ArrayList<Integer>[] g;

	int[] use;
	int useVer = 0;

	void printAns(int u, int v) {
		out.println("YES");
		out.println((u + 1) + " " + (v + 1));
		ArrayList<Integer> onlyH = new ArrayList<>();
		ArrayList<Integer> onlyT = new ArrayList<>();
		ArrayList<Integer> both = new ArrayList<>();
		Arrays.fill(use, 0);
		for (int i = 0; i < g[u].size(); i++) {
			int to = g[u].get(i);
			if (to != v)
				use[to] |= 1;
		}
		for (int i = 0; i < g[v].size(); i++) {
			int to = g[v].get(i);
			if (to != u)
				use[to] |= 2;
		}
		for (int i = 0; i < n; i++) {
			if (use[i] == 1)
				onlyH.add(i);
			else if (use[i] == 2)
				onlyT.add(i);
			else if (use[i] == 3)
				both.add(i);
		}

		for (int i = 0; i < h && i < onlyH.size(); i++)
			out.print(onlyH.get(i) + 1 + " ");
		int getBoth = h - Math.min(h, onlyH.size());
		while (getBoth-- > 0)
			out.print(both.remove(both.size() - 1) + 1 + " ");
		out.println();

		for (int i = 0; i < t && i < onlyT.size(); i++)
			out.print(onlyT.get(i) + 1 + " ");
		getBoth = t - Math.min(t, onlyT.size());
		while (getBoth-- > 0)
			out.print(both.remove(both.size() - 1) + 1 + " ");
		out.println();

	}

	boolean check(int u, int v) {

//		if (u == 3 && v == 0)
//			System.err.println("?");

		int slotsH = g[u].size() - 1;
		int slotsT = g[v].size() - 1;
		if (slotsH < h || slotsT < t)
			return false;
//		if (u == 3 && v == 0)
//			System.err.println(slotsH + " " + slotsT);

		if (slotsH >= h + t || slotsT >= h + t) {
			printAns(u, v);
			return true;
		}

		int slotsHT = slotsH;

		useVer++;
		
		for (int i = 0; i < g[u].size(); i++) {
			int to = g[u].get(i);
			if (to != v)
				use[to] = useVer;
		}
		for (int i = 0; i < g[v].size(); i++) {
			int to = g[v].get(i);
			if (to != u && use[to] != useVer) {
				use[to] = useVer;
				slotsHT++;
			}
		}
		if (slotsHT >= h + t) {
			printAns(u, v);
			return true;
		}

		return false;
	}

	void solve() throws IOException {
		n = nextInt();
		m = nextInt();
		h = nextInt();
		t = nextInt();
		int[] v1 = new int[m];
		int[] v2 = new int[m];
		g = new ArrayList[n];
		for (int i = 0; i < n; i++)
			g[i] = new ArrayList<>();

		for (int i = 0; i < m; i++) {
			v1[i] = nextInt() - 1;
			v2[i] = nextInt() - 1;
			g[v1[i]].add(v2[i]);
			g[v2[i]].add(v1[i]);
		}

		use = new int[n];

		for (int i = 0; i < m; i++) {
			if (check(v1[i], v2[i]))
				return;
			if (check(v2[i], v1[i]))
				return;
		}
		out.println("NO");
		return;
	}

	B() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B();
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