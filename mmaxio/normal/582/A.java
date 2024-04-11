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

	static int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	void solve() throws IOException {
		int n = nextInt();
		MultiTreeSet<Integer> a = new MultiTreeSet<>();
		for (int i = 0; i < n * n; i++) {
			a.add(nextInt());
		}

		int[] ret = new int[n];

		for (int i = 0; i < n; i++) {
			ret[i] = a.last();
			for (int j = 0; j < i; j++) {
				int g = gcd(ret[i], ret[j]);
				a.remove(g);
				a.remove(g);
			}
			a.remove(ret[i]);
		}
		
		for (int x : ret) {
			out.print(x + " ");
		}
		out.println();
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