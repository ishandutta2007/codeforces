import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Segment {
		int l, r, id;

		public Segment(int l, int r, int id) {
			this.l = l;
			this.r = r;
			this.id = id;
		}

		@Override
		public String toString() {
			return "[l=" + l + ", r=" + r + ", id=" + id + "]";
		}
	}

	static Comparator<Segment> byL = (Segment a, Segment b) -> {
		if (a.l != b.l) {
			return a.l < b.l ? -1 : 1;
		}
		return Integer.compare(a.id, b.id);
	};

	static Comparator<Segment> byR = (Segment a, Segment b) -> {
		if (a.r != b.r) {
			return a.r < b.r ? -1 : 1;
		}
		return Integer.compare(a.id, b.id);
	};

	static Segment min(Segment a, Segment b, Comparator<Segment> comp) {
		return comp.compare(a, b) < 0 ? a : b;
	}

	void solve() throws IOException {
		int n = nextInt();
		Segment[] a = new Segment[n];
		for (int i = 0; i < n; i++) {
			int mid = nextInt();
			int delta = nextInt();
			a[i] = new Segment(mid - delta, mid + delta, i);
		}
		Arrays.sort(a, byL);
		Segment[] suffMinR = new Segment[n];
		suffMinR[n - 1] = a[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			suffMinR[i] = min(a[i], suffMinR[i + 1], byR);
		}
//		System.err.println(Arrays.toString(a) + "\n" + Arrays.toString(suffMinR));
		int ret = 0;
		for (int i = 0; i < n;) {
			Segment pick = suffMinR[i];
			ret++;
			while (i < n && a[i].l < pick.r) {
				i++;
			}
		}
		out.println(ret);
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