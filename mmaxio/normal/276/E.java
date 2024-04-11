import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	ArrayList<Integer>[] g;

	void dfs(int v, int p, ArrayList<Integer> chain) {
		chain.add(v);
		for (int i = 0; i < g[v].size(); i++) {
			int to = g[v].get(i);
			if (to != p)
				dfs(to, v, chain);
		}
	}

	static class Fenwick {

		private int[] f;
		private int size;

		public Fenwick(int size) {
			this.size = size;
			f = new int[size];
		}

		void add(int l, int r, int delta) {
			if (l >= size)
				return;
			r = Math.min(r, size - 1);
			fenwickAdd(l, delta);
			fenwickAdd(r + 1, -delta);
		}

		private void fenwickAdd(int pos, int delta) {
			for (; pos < f.length; pos |= pos + 1)
				f[pos] += delta;
		}
		
		int get(int pos) {
			if (pos >= size)
				return 0;
			return fenwickGet(pos);
		}
		
		private int fenwickGet(int pos) {
			int res = 0;
			for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
				res += f[pos];
			return res;
		}

	}

	void solve() throws IOException {
		int n = nextInt();
		int q = nextInt();

		g = new ArrayList[n];
		for (int i = 0; i < n; i++)
			g[i] = new ArrayList<>();

		for (int i = 0; i < n - 1; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			g[v1].add(v2);
			g[v2].add(v1);
		}

		ArrayList<Integer>[] chains = new ArrayList[g[0].size()];
		for (int i = 0; i < g[0].size(); i++) {
			chains[i] = new ArrayList<>();
			dfs(g[0].get(i), 0, chains[i]);
		}

		int[] chainNum = new int[n];
		int[] inChainPos = new int[n];

		chainNum[0] = -1;
		inChainPos[0] = 0;

		for (int i = 0; i < chains.length; i++) {
			ArrayList<Integer> chain = chains[i];
			for (int j = 0; j < chain.size(); j++) {
				int v = chain.get(j);
				chainNum[v] = i;
				inChainPos[v] = j + 1;
			}
		}
		
//		System.err.println(Arrays.toString(chainNum));
//		System.err.println(Arrays.toString(inChainPos));
		
		Fenwick all = new Fenwick(n);
		Fenwick[] byChain = new Fenwick[chains.length];
		
		for (int i = 0; i < chains.length; i++)
			byChain[i] = new Fenwick(chains[i].size() + 1);
		
		for (int i = 0; i < q; i++) {
			int type = nextInt();
			if (type == 0) {
				int v = nextInt() - 1;
				int delta = nextInt();
				int dist = nextInt();
				
				if (v == 0) {
					all.add(0, dist, delta);
					continue;
				}
				
				if (dist < inChainPos[v]) {
					byChain[chainNum[v]].add(inChainPos[v] - dist, inChainPos[v] + dist, delta);
					continue;
				}
				
				int allAdd = dist - inChainPos[v];
				
				all.add(0, allAdd, delta);
				
//				System.err.println(allAdd + 1 + " " + (inChainPos[v] + dist));
				
				byChain[chainNum[v]].add(allAdd + 1, inChainPos[v] + dist, delta);
				
				
			} else if (type == 1) {
				int v = nextInt() - 1;
				if (v == 0) {
					out.println(all.get(0));
				} else {
					out.println(all.get(inChainPos[v]) + byChain[chainNum[v]].get(inChainPos[v]));
				}
			}
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