import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static int rot(int a, int b, int n) {
		if (a < b) {
			return b - a;
		} else {
			return b - a + n;
		}
	}

	static int doRotate(int a, int go, int n) {
		return (a + go) % n;
	}

	static class Triang {
		int n;
		TreeSet<Integer>[] to;

		public Triang(int n, int[] es) {
			this.n = n;
			to = new TreeSet[n];
			for (int i = 0; i < n; i++) {
				to[i] = new TreeSet<>();
				to[i].add(1);
				to[i].add(n - 1);
			}
			if (es.length != 2 * (n - 3)) {
				throw new AssertionError();
			}
			for (int i = 0; i < es.length; i += 2) {
				int v1 = es[i];
				int v2 = es[i + 1];
				to[v1].add(rot(v1, v2, n));
				to[v2].add(rot(v2, v1, n));
			}
		}

		int[] flip(int v, int u) {
			int rotVU = rot(v, u, n);
			int rotUV = rot(u, v, n);
//			System.err.println(v + " " + to[v]);
			int p = doRotate(v, to[v].higher(rotVU), n);
			int q = doRotate(v, to[v].lower(rotVU), n);
			if (!to[v].remove(rotVU) || !to[u].remove(rotUV)) {
				throw new AssertionError();
			}
			to[p].add(rot(p, q, n));
			to[q].add(rot(q, p, n));
			return new int[] { p, q };
		}

	}

	void go(Triang t, int p, int q, List<Integer> log, boolean fst) {
//		System.err.println(p + " " + q);
		if (q - p == 1) {
			return;
		}
		int[] newD = t.flip(p, q);
		if (fst) {
			log.add(p);
			log.add(q);
		} else {
			log.add(newD[0]);
			log.add(newD[1]);
		}
//		System.err.println(Arrays.toString(newD));
		if (newD[0] != 0) {
			throw new AssertionError();
		}
		go(t, p, newD[1], log, fst);
		go(t, newD[1], q, log, fst);
	}

	List<Integer> go(Triang t, boolean ifFst) {
		// System.err.println(Arrays.toString(t.to));
		List<Integer> fst = new ArrayList<>(t.to[0]);
		List<Integer> ret = new ArrayList<>();
		for (int i = 0; i < fst.size() - 1; i++) {
			go(t, fst.get(i), fst.get(i + 1), ret, ifFst);
		}
		return ret;
	}

	void solve() throws IOException {
		int n = nextInt();
		int[] es1 = new int[2 * (n - 3)];
		for (int i = 0; i < es1.length; i++) {
			es1[i] = nextInt() - 1;
		}
		int[] es2 = new int[2 * (n - 3)];
		for (int i = 0; i < es2.length; i++) {
			es2[i] = nextInt() - 1;
		}
		Triang from = new Triang(n, es1);
		Triang to = new Triang(n, es2);
		List<Integer> p1 = go(from, true);
		List<Integer> p2 = go(to, false);
		out.println(p1.size() / 2 + p2.size() / 2);
		for (int i = 0; i < p1.size(); i += 2) {
			out.println(p1.get(i) + 1 + " " + (p1.get(i + 1) + 1));
		}
		for (int i = p2.size() - 2; i >= 0; i -= 2) {
			out.println(p2.get(i) + 1 + " " + (p2.get(i + 1) + 1));
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