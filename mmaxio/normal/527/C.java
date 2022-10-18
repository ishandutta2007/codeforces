import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class MultiTreeSet<T extends Comparable<T>> {
		private TreeMap<T, Integer> map = new TreeMap<>();

		public int count(T x) {
			Integer ret = map.get(x);
			return ret == null ? 0 : ret;
		}

		void add(T x) {
			map.put(x, count(x) + 1);
		}

		T first() {
			return map.firstKey();
		}

		T last() {
			return map.lastKey();
		}

		boolean remove(T x) {
			int prev = count(x);
			if (prev == 0) {
				return false;
			}
			if (prev == 1) {
				map.remove(x);
			} else {
				map.put(x, prev - 1);
			}
			return true;
		}
	}

	void go(int x, TreeSet<Integer> pos, MultiTreeSet<Integer> sz,
			MultiTreeSet<Integer> otherSz) {
		if (!pos.contains(x)) {
			int prev = pos.lower(x);
			int next = pos.higher(x);
			sz.remove(next - prev);
			sz.add(x - prev);
			sz.add(next - x);
			pos.add(x);
		}
		long ret = (long) sz.last() * otherSz.last();
		out.println(ret);
	}

	void solve() throws IOException {
		int w = nextInt();
		int h = nextInt();
		int n = nextInt();
		TreeSet<Integer> ww = new TreeSet<>();
		TreeSet<Integer> hh = new TreeSet<>();
		ww.add(0);
		ww.add(w);
		hh.add(0);
		hh.add(h);
		MultiTreeSet<Integer> szW = new MultiTreeSet<>();
		MultiTreeSet<Integer> szH = new MultiTreeSet<>();
		szW.add(w);
		szH.add(h);
		for (int i = 0; i < n; i++) {
			char type = nextToken().charAt(0);
			int x = nextInt();
			if (type == 'H') {
				go(x, hh, szH, szW);
			} else {
				go(x, ww, szW, szH);
			}
		}
	}

	A() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new A();
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