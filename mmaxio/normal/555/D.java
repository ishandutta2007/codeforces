import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int n;
	int[] xs;

	int highRight;
	int lowLeft;

	int goRight(int id, int len) {
		int low = id;
		int high = highRight;
		while (high - low > 1) {
			int mid = (low + high) >> 1;
			if (xs[mid] - xs[id] > len) {
				high = mid;
			} else {
				low = mid;
			}
		}
		highRight = high;
		return low;
	}

	int goLeft(int id, int len) {
		int low = lowLeft;
		int high = id;
		while (high - low > 1) {
			int mid = (low + high) >> 1;
			if (xs[id] - xs[mid] > len) {
				low = mid;
			} else {
				high = mid;
			}
		}
		lowLeft = low;
		return high;
	}

	int go(int v, int len) {
		highRight = n;
		lowLeft = -1;
		while (true) {
			int p = goRight(v, len);
			len -= xs[p] - xs[v];
			int q = goLeft(p, len);
			len -= xs[p] - xs[q];
			if (q != v) {
				v = q;
				continue;
			}
			if (p == v) {
				return v;
			}
			int times = len / (xs[p] - xs[v]);
			len %= xs[p] - xs[v];
			if ((times & 1) == 0) {
				continue;
			}
			v = goLeft(p, len);
			if (v == p) {
				return v;
			}
			len -= xs[p] - xs[v];
		}
	}

	void solve() throws IOException {
		n = nextInt();
		int m = nextInt();
		xs = new int[n];
		for (int i = 0; i < n; i++) {
			xs[i] = nextInt();
		}

		final int[] shit = xs.clone();
		Integer[] order = new Integer[n];
		for (int i = 0; i < n; i++) {
			order[i] = i;
		}
		Arrays.sort(order,
				(Integer o1, Integer o2) -> Integer.compare(shit[o1], shit[o2]));
		for (int i = 0; i < n; i++) {
			xs[i] = shit[order[i]];
		}
		int[] where = new int[n];
		for (int i = 0; i < n; i++) {
			where[order[i]] = i;
		}

		while (m-- > 0) {
			int id = nextInt() - 1;
			int len = nextInt();
			out.println(order[go(where[id], len)] + 1);
		}
	}

	D() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
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