import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Card implements Comparable<Card> {
		int x1, y1, x2, y2, id;

		public Card(int x1, int y1, int x2, int y2, int id) {
			this.x1 = x1;
			this.y1 = y1;
			this.x2 = x2;
			this.y2 = y2;
			this.id = id;
		}

		@Override
		public int compareTo(Card o) {
			if (y1 != o.y1) {
				return y1 < o.y1 ? -1 : 1;
			}
			return Integer.compare(id, o.id);
		}
	}

	static final Random rng = new Random();
	static final int INF = Integer.MAX_VALUE / 3;

	void add(TreeSet<Card>[] f, int pos, Card add) {
		for (int i = pos; i < f.length; i |= i + 1) {
			f[i].add(add);
		}
	}

	int nx;

	TreeSet<Card>[] fen;

	List<Card> getAdj(Card c) {
		List<Card> ret = new ArrayList<>();
		Card seeker = new Card(0, c.y2, 0, 0, INF);
		for (int i = c.x2; i >= 0; i = (i & (i + 1)) - 1) {
			ret.addAll(fen[i].headSet(seeker));
		}
		return ret;
	}
	
	void removeTotally(Card c) {
		for (int i = c.x1; i < fen.length; i |= i + 1){
			if (!fen[i].remove(c)) {
				throw new AssertionError();
			}
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int[] allX = new int[n];
		Card[] a = new Card[n];
		for (int i = 0; i < n; i++) {
			a[i] = new Card(nextInt(), nextInt(), nextInt(), nextInt(), i);
			allX[i] = a[i].x1;
		}
		allX = unique(allX);
		
		if (allX[0] > 0) {
			// no x = 0 card or no y = 0 card
			out.println(-1);
			return;
		}

		for (int i = 0; i < n; i++) {
			a[i].x1 = getPos(allX, a[i].x1);
			a[i].x2 = getPos(allX, a[i].x2);
		}

		nx = allX.length;

		fen = new TreeSet[nx];
		for (int i = 0; i < nx; i++) {
			fen[i] = new TreeSet<>();
		}

		for (int i = 0; i < n; i++) {
			add(fen, a[i].x1, a[i]);
		}

		int[] d = new int[n];
		Arrays.fill(d, INF);
		int[] from = new int[n];
		ArrayDeque<Card> q = new ArrayDeque<>();
		
		for (int i = 0; i < n; i++) {
			if (a[i].x1 == 0 && a[i].y1 == 0) {
				q.add(a[i]);
				d[i] = 0;
				from[i] = -1;
			}
		}

		while (!q.isEmpty()) {
			Card v = q.poll();
//			System.err.println(v.id);
			List<Card> adj = getAdj(v);
			for (Card c : adj) {
				if (d[c.id] > d[v.id] + 1) {
					d[c.id] = d[v.id] + 1;
					from[c.id] = v.id;
					q.add(c);
				}
				removeTotally(c);
			}
		}
		
		if (d[n - 1] == INF) {
			out.println(-1);
		} else {
			out.println(d[n - 1] + 1);
			List<Integer> outp = new ArrayList<>();
			for (int v = n - 1; v != -1; v = from[v]) {
				outp.add(v);
			}
			Collections.reverse(outp);
			for (int x : outp) {
				out.print((x + 1) + " ");
			}
			out.println();
		}
	}

	int getPos(int[] a, int x) {
		int ret = Arrays.binarySearch(a, x);
		if (ret < 0) {
			ret = -ret - 2;
		}
		return ret;
	}

	int[] unique(int[] a) {
		for (int i = 0; i < a.length; i++) {
			int j = rng.nextInt(i + 1);
			int tmp = a[j];
			a[j] = a[i];
			a[i] = tmp;
		}
		Arrays.sort(a);
		int sz = 1;
		for (int i = 1; i < a.length; i++) {
			if (a[i] != a[sz - 1]) {
				a[sz++] = a[i];
			}
		}
		return Arrays.copyOf(a, sz);
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