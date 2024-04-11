import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int[] deg;
	long[] t;
	long[] val;
	int[] par;
	TreeSet<Integer>[] chld;
	TreeSet<Integer> all;

	long getSelf(int idx) {
		return t[idx] - t[idx] / deg[idx] * (deg[idx] - 1);
	}

	long getSend(int idx) {
		return t[idx] / deg[idx];
	}

	long getValue(int idx) {
		return val[idx] + getSend(par[idx]);
	}

	void addAll(int idx) {
//		if (inAll[idx]) {
//			return;
//		}
		if (chld[idx].size() >= 1) {
			all.add(chld[idx].first());
			if (chld[idx].size() >= 2) {
				all.add(chld[idx].last());
			}
		}
	}

	void removeAll(int idx) {
//		if (!inAll[idx]) {
//			return;
//		}
		if (chld[idx].size() >= 1) {
			all.remove(chld[idx].first());
			if (chld[idx].size() >= 2) {
				all.remove(chld[idx].last());
			}
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int q = nextInt();

		t = new long[n];
		for (int i = 0; i < n; i++) {
			t[i] = nextLong();
		}

		par = new int[n];
		deg = new int[n];

		Arrays.fill(deg, 2);

		for (int i = 0; i < n; i++) {
			par[i] = nextInt() - 1;
			deg[par[i]]++;
		}

		val = new long[n];
		for (int i = 0; i < n; i++) {
			val[i] += getSelf(i);
			val[par[i]] += getSend(i);
		}

		Comparator<Integer> childComp = (o1, o2) -> {
			if (val[o1] != val[o2]) {
				return val[o1] < val[o2] ? -1 : 1;
			}
			return o1.compareTo(o2);
		};

		chld = new TreeSet[n];
		for (int i = 0; i < n; i++) {
			chld[i] = new TreeSet<>(childComp);
		}

		for (int i = 0; i < n; i++) {
			chld[par[i]].add(i);
		}

		all = new TreeSet<>((o1, o2) -> {
			long val1 = getValue(o1);
			long val2 = getValue(o2);
			if (val1 != val2) {
				return val1 < val2 ? -1 : 1;
			}
			return o1.compareTo(o2);
		});
		
		for (int i = 0; i < n; i++) {
			addAll(i);
		}

		for (int i = 0; i < q; i++) {
			int type = nextInt();
			if (type == 1) {
				int v = nextInt() - 1;
				int u = nextInt() - 1;

				int pv = par[v];
				int ppv = par[pv];
				int pu = par[u];
				
				int pppv = par[ppv];
				int ppu = par[pu];

				removeAll(ppv);
				removeAll(pv);
				removeAll(pu);
				removeAll(u);
				removeAll(pppv);
				removeAll(ppu);

				chld[pppv].remove(ppv);
				chld[ppv].remove(pv);
				chld[pv].remove(v);
				chld[ppu].remove(pu);
				chld[pu].remove(u);

				val[ppv] -= getSend(pv);
				val[pv] -= getSelf(pv);
				val[pu] -= getSend(u);
				val[u] -= getSelf(u);

				val[pv] -= getSend(v);
				par[v] = u;
				deg[pv]--;
				deg[u]++;
				val[u] += getSend(v);

				val[u] += getSelf(u);
				val[pu] += getSend(u);
				val[pv] += getSelf(pv);
				val[ppv] += getSend(pv);

				chld[u].add(v);
				chld[pu].add(u);
				chld[ppv].add(pv);
				chld[pppv].add(ppv);
				chld[ppu].add(pu);

				addAll(u);
				addAll(pu);
				addAll(pv);
				addAll(ppv);
				addAll(pppv);
				addAll(ppu);

			}
			if (type == 2) {
				int v = nextInt() - 1;
				out.println(getValue(v));
			}
			if (type == 3) {
				int v = all.first();
				int u = all.last();
				out.println(getValue(v) + " " + getValue(u));
			}
		}
	}

	D() throws IOException {
		if (System.getProperty("ONLINE_JUDGE") != null) {
			br = new BufferedReader(new InputStreamReader(System.in));
		} else {
			br = new BufferedReader(new FileReader("in.txt"));
		}
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D();
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