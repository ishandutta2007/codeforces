import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int M = 300000;

	static class Node {
		int l, r;
		Node left, right;
		int max, maxPos;
		int add;

		public Node(int l, int r) {
			this.l = l;
			this.r = r;
			max = 0;
			maxPos = l;
			if (r - l > 1) {
				int mid = (l + r) >> 1;
				left = new Node(l, mid);
				right = new Node(mid, r);
			}
		}

		int getMax() {
			return max + add;
		}

		void add(int ql, int qr, int delta) {
			if (ql >= r || l >= qr) {
				return;
			}
			if (ql <= l && r <= qr) {
				add += delta;
				return;
			}
			left.add(ql, qr, delta);
			right.add(ql, qr, delta);
			if (left.getMax() >= right.getMax()) {
				max = left.getMax();
				maxPos = left.maxPos;
			} else {
				max = right.getMax();
				maxPos = right.maxPos;
			}
		}
	}

	static class Worker {
		int l, self, r, ind;

		public Worker(int l, int self, int r) {
			this.l = l;
			this.self = self;
			this.r = r;
		}
	}

	static class Event implements Comparable<Event> {
		boolean add;
		int pos;
		Worker w;

		public Event(boolean add, int pos, Worker w) {
			this.add = add;
			this.pos = pos;
			this.w = w;
		}

		@Override
		public int compareTo(Event o) {
			if (pos != o.pos)
				return Integer.compare(pos, o.pos);
			if (add != o.add)
				return add ? -1 : 1;
			return 0;
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		Worker[] a = new Worker[n];
		Event[] ev = new Event[2 * n];
		Node root = new Node(0, M);
		for (int i = 0; i < n; i++) {
			a[i] = new Worker(nextInt() - 1, nextInt() - 1, nextInt() - 1);

			ev[2 * i] = new Event(true, a[i].l, a[i]);
			ev[2 * i + 1] = new Event(false, a[i].self, a[i]);
		}

		Arrays.sort(ev);

		int ans = 0;
		int ansPosL = -1;
		int ansPosR = -1;

		for (int i = 0; i < 2 * n; i++) {
			Event e = ev[i];
			root.add(e.w.self, e.w.r + 1, e.add ? 1 : -1);
			if (e.add) {
				if (root.max > ans) {
					ans = root.max;
					ansPosL = e.pos;
					ansPosR = root.maxPos;
				}
			}
		}

		out.println(ans);
		for (int i = 0; i < n; i++) {
			if (a[i].l <= ansPosL && a[i].self >= ansPosL
					&& a[i].self <= ansPosR && a[i].r >= ansPosR) {
				out.print(i + 1 + " ");
			}
		}
		out.println();
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