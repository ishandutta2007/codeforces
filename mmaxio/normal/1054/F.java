import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class F {

	static class Point {
		int x, y;
		
		boolean stopX, stopY;

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}

		int getX() {
			return x;
		}

		void setX(int x) {
			this.x = x;
		}

		int getY() {
			return y;
		}

		void setY(int y) {
			this.y = y;
		}

		@Override
		public String toString() {
			return "(" + x + ", " + y + ")";
		}
	}

	static class Segment {
		Point p, q;

		public Segment(Point p, Point q) {
			this.p = p;
			this.q = q;
		}

		@Override
		public String toString() {
			return p + ", " + q;
		}
	}

	boolean doesIntersect(Segment h, Segment v) {
		return v.p.y < h.p.y && v.q.y > h.p.y && h.p.x < v.p.x && h.q.x > v.q.x;
	}

	void submit() {
		int n = nextInt();
		Point[] a = new Point[n];
		for (int i = 0; i < n; i++) {
			int x = nextInt();
			int y = nextInt();
			a[i] = new Point(x, y);
		}

		Arrays.sort(
				a,
				Comparator.comparingInt(Point::getY).thenComparingInt(
						Point::getX));
		hor = new ArrayList<>();
		for (int i = 0; i < n - 1; i++) {
			if (a[i].y == a[i + 1].y) {
				hor.add(new Segment(a[i], a[i + 1]));
			}
		}

		Arrays.sort(
				a,
				Comparator.comparingInt(Point::getX).thenComparingInt(
						Point::getY));
		ver = new ArrayList<>();
		for (int i = 0; i < n - 1; i++) {
			if (a[i].x == a[i + 1].x) {
				ver.add(new Segment(a[i], a[i + 1]));
			}
		}

		vis = new boolean[hor.size()];
		pair = new int[ver.size()];
		Arrays.fill(pair, -1);

		g = new boolean[hor.size()][ver.size()];
		for (int i = 0; i < hor.size(); i++) {
			for (int j = 0; j < ver.size(); j++) {
				g[i][j] = doesIntersect(hor.get(i), ver.get(j));
			}
		}
		
		for (int i = 0; i < hor.size(); i++) {
			Arrays.fill(vis, false);
			dfs(i);
		}

		boolean[] matched = new boolean[hor.size()];
		for (int i = 0; i < ver.size(); i++) {
			if (pair[i] != -1) {
				matched[pair[i]] = true;
			}
		}

		Arrays.fill(vis, false);
		vis2 = new boolean[ver.size()];
		Arrays.fill(vis2, false);

		for (int i = 0; i < hor.size(); i++) {
			if (!matched[i]) {
				dfs2(i);
			}
		}

		
		int ans1 = n;
		
		for (int i = 0; i < hor.size(); i++) {
			if (vis[i]) {
//				System.err.println(hor.get(i));
				hor.get(i).p.stopX = true;
				ans1--;
			}
		}

		int ans2 = n;
		for (int i = 0; i < ver.size(); i++) {
			if (!vis2[i]) {
//				System.err.println(ver.get(i));
				ans2--;
				ver.get(i).p.stopY = true;
			}
		}
		
		Arrays.sort(
				a,
				Comparator.comparingInt(Point::getY).thenComparingInt(
						Point::getX));
		out.println(ans1);
		Point from = null;
		for (Point p : a) {
			if (from == null) {
				from = p;
			}
			if (!p.stopX) {
				out.println(from.x + " " + from.y + " " + p.x + " " + p.y);
				from = null;
			}
		}
		
		out.println(ans2);
		
		Arrays.sort(
				a,
				Comparator.comparingInt(Point::getX).thenComparingInt(
						Point::getY));
		ver = new ArrayList<>();
		for (int i = 0; i < n - 1; i++) {
			if (a[i].x == a[i + 1].x) {
				ver.add(new Segment(a[i], a[i + 1]));
			}
		}
		
		from = null;
		for (Point p : a) {
			if (from == null) {
				from = p;
			}
			if (!p.stopY) {
				out.println(from.x + " " + from.y + " " + p.x + " " + p.y);
				from = null;
			}
		}

	}
	
	boolean[][] g;

	void dfs2(int v) {
		vis[v] = true;
		for (int u = 0; u < ver.size(); u++) {
			if (!g[v][u]) {
				continue;
			}
			if (pair[u] == v) {
				continue;
			}
			if (vis2[u]) {
				continue;
			}
			vis2[u] = true;
			dfs2(pair[u]);
		}
	}

	ArrayList<Segment> hor, ver;

	boolean dfs(int v) {
		vis[v] = true;
		for (int u = 0; u < ver.size(); u++) {
			if (!g[v][u]) {
				continue;
			}
			if (pair[u] == -1 || (!vis[pair[u]] && dfs(pair[u]))) {
				pair[u] = v;
				return true;
			}
		}
		return false;
	}

	boolean[] vis, vis2;
	int[] pair;

	void test() {

	}

	void stress() {
		for (int tst = 0;; tst++) {
			if (false) {
				throw new AssertionError();
			}
			System.err.println(tst);
		}
	}

	F() throws IOException {
		is = System.in;
		out = new PrintWriter(System.out);
		submit();
		// stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();
	static final int C = 5;

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new F();
	}

	private InputStream is;
	PrintWriter out;

	private byte[] buf = new byte[1 << 14];
	private int bufSz = 0, bufPtr = 0;

	private int readByte() {
		if (bufSz == -1)
			throw new RuntimeException("Reading past EOF");
		if (bufPtr >= bufSz) {
			bufPtr = 0;
			try {
				bufSz = is.read(buf);
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
			if (bufSz <= 0)
				return -1;
		}
		return buf[bufPtr++];
	}

	private boolean isTrash(int c) {
		return c < 33 || c > 126;
	}

	private int skip() {
		int b;
		while ((b = readByte()) != -1 && isTrash(b))
			;
		return b;
	}

	String nextToken() {
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while (!isTrash(b)) {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	String nextString() {
		int b = readByte();
		StringBuilder sb = new StringBuilder();
		while (!isTrash(b) || b == ' ') {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	char nextChar() {
		return (char) skip();
	}

	int nextInt() {
		int ret = 0;
		int b = skip();
		if (b != '-' && (b < '0' || b > '9')) {
			throw new InputMismatchException();
		}
		boolean neg = false;
		if (b == '-') {
			neg = true;
			b = readByte();
		}
		while (true) {
			if (b >= '0' && b <= '9') {
				ret = ret * 10 + (b - '0');
			} else {
				if (b != -1 && !isTrash(b)) {
					throw new InputMismatchException();
				}
				return neg ? -ret : ret;
			}
			b = readByte();
		}
	}

	long nextLong() {
		long ret = 0;
		int b = skip();
		if (b != '-' && (b < '0' || b > '9')) {
			throw new InputMismatchException();
		}
		boolean neg = false;
		if (b == '-') {
			neg = true;
			b = readByte();
		}
		while (true) {
			if (b >= '0' && b <= '9') {
				ret = ret * 10 + (b - '0');
			} else {
				if (b != -1 && !isTrash(b)) {
					throw new InputMismatchException();
				}
				return neg ? -ret : ret;
			}
			b = readByte();
		}
	}
}