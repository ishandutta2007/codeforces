import java.io.*;
import java.util.*;

public class C {

	long[] ans;

	long[] c2;

	static class Query implements Comparable<Query> {
		int x, y, id;

		public Query(int x, int y, int id) {
			this.x = x;
			this.y = y;
			this.id = id;
		}

		@Override
		public int compareTo(Query o) {
			return Integer.compare(x, o.x);
		}
	}

	void submit() {
		int n = nextInt();
		int q = nextInt();

		c2 = new long[n + 1];
		for (int i = 0; i <= n; i++) {
			c2[i] = (long) i * (i - 1) / 2;
		}

		int[] p = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = nextInt() - 1;
		}

		ans = new long[q];

		Query[][] qs = new Query[4][q];

		for (int i = 0; i < q; i++) {
			int x1 = nextInt() - 1;
			int y1 = nextInt() - 1;
			int x2 = nextInt();
			int y2 = nextInt();

			ans[i] = c2[x1] + c2[y1] + c2[n - x2] + c2[n - y2];
			qs[0][i] = new Query(x1, y1, i);
			qs[1][i] = new Query(n - x2, y1, i);
			qs[2][i] = new Query(x1, n - y2, i);
			qs[3][i] = new Query(n - x2, n - y2, i);
		}

		process(qs[0], p);

		reverse(p);
		process(qs[1], p);

		flip(p);
		process(qs[3], p);

		reverse(p);
		process(qs[2], p);

		for (long x : ans) {
			out.println(c2[n] - x);
		}
	}

	void reverse(int[] a) {
		for (int i = 0, j = a.length - 1; i < j; i++, j--) {
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}

	void flip(int[] a) {
		int n = a.length;
		for (int i = 0; i < a.length; i++) {
			a[i] = n - 1 - a[i];
		}
	}
	
	void process(Query[] qs, int[] p) {
		Arrays.sort(qs);
		int n = p.length;
		int[] fen = new int[n];
		
		int ptr = 0;
		for (Query q : qs) {
			while (ptr < q.x) {
				add(fen, p[ptr]);
				ptr++;
			}
			
			int cnt = get(fen, q.y - 1);
			ans[q.id] -= c2[cnt];
		}
	}
	
	void add(int[] fen, int pos) {
		for (int i = pos; i < fen.length; i |= i + 1) {
			fen[i]++;
		}
	}
	
	int get(int[] fen, int pos) {
		int ret = 0;
		for (int i = pos; i >= 0; i = (i & (i + 1)) - 1) {
			ret += fen[i];
		}
		return ret;
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
		// stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new C();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}