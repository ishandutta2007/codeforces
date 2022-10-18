import java.io.*;
import java.math.*;
import java.util.*;

public class D_zheska {

	static final int ALPH = 26;

	static class AhoCorasick {
		int[][] go;
		int[] link;
		int[] jump;

		int[] who;

		int size;

		public AhoCorasick(int[][] dict) {
			int maxSize = 1;
			for (int[] word : dict) {
				maxSize += word.length;
			}

			go = new int[maxSize][];
			link = new int[maxSize];
			who = new int[maxSize];
			jump = new int[maxSize];

			int root = newNode();
			for (int i = 0; i < dict.length; i++) {
				int v = root;
				for (int symb : dict[i]) {
					int u = go[v][symb];
					if (u == -1) {
						u = go[v][symb] = newNode();
					}
					v = u;
				}
				who[v] = i;
			}

			int[] que = new int[size];
			int qh = 0, qt = 0;

			for (int symb = 0; symb < ALPH; symb++) {
				int u = go[root][symb];
				if (u != -1) {
					que[qt++] = u;
					link[u] = root;
				} else {
					go[root][symb] = root;
				}
			}

			while (qh < qt) {
				int v = que[qh++];
				jump[v] = who[v] == -1 ? jump[link[v]] : v;
				for (int symb = 0; symb < ALPH; symb++) {
					int u = go[v][symb];
					if (u != -1) {
						que[qt++] = u;
						link[u] = go[link[v]][symb];
					} else {
						go[v][symb] = go[link[v]][symb];
					}
				}
			}

		}

		private int newNode() {
			go[size] = new int[ALPH];
			Arrays.fill(go[size], -1);
			who[size] = -1;
			return size++;
		}
	}

	int[] getStr() {
		String s = nextToken();
		int[] t = new int[s.length()];
		for (int i = 0; i < t.length; i++) {
			t[i] = s.charAt(i) - 'a';
		}
		return t;
	}

	void submit() {
		int[] s = getStr();
		int q = nextInt();
		int[][] dict = new int[q][];
		int[] qs = new int[q];

		for (int i = 0; i < q; i++) {
			qs[i] = nextInt();
			dict[i] = getStr();
		}

		AhoCorasick ac = new AhoCorasick(dict);

		int[][] go = ac.go;
		int[] jump = ac.jump;
		int[] link = ac.link;
		int[] who = ac.who;

		int v = 0;

		int[] occ = new int[q];
		int[] lens = new int[q];
		
		for (int i = 0; i < q; i++) {
			lens[i] = dict[i].length;
		}
		
		for (int i = 0; i < s.length; i++) {
			v = go[v][s[i]];
			for (int u = jump[v]; u > 0; u = jump[link[u]]) {
				int idx = who[u];
				occ[idx]++;
			}
		}
		
		dict = new int[q][];
		for (int i = 0; i < q; i++) {
			dict[i] = new int[occ[i]];
		}
		
		v = 0;
		
		for (int i = 0; i < s.length; i++) {
			v = go[v][s[i]];
			for (int u = jump[v]; u > 0; u = jump[link[u]]) {
				int idx = who[u];
				dict[idx][--occ[idx]] = i;
			}
		}

//		boolean tst47 = s.length == 100000;
//		for (int c : s) {
//			tst47 &= c == 0;
//		}
		
//		if (tst47) {
//			out.println(q);
//			for (int i = 0; i < q && i < 10; i++) {
//				int p1 = head[i];
//				out.println(p1);
//				while (p1 != -1) {
//					p1 = next[p1];
//				}
//			}
//			return;
//		}

		for (int i = 0; i < q; i++) {
			int[] what = dict[i];
			int x = qs[i];
			if (what.length < x) {
				out.println(-1);
				continue;
			}
			int ans = Integer.MAX_VALUE;
			for (int j = 0; j + x <= what.length; j++) {
				ans = Math.min(ans, what[j] - what[j + x - 1]);
			}
			out.println(ans + lens[i]);
		}
	}

	static final int N_15 = 45_000_000;

	void preCalc() {

	}

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

	D_zheska() throws IOException {
		is = System.in;
		out = new PrintWriter(System.out);
		preCalc();
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
		new D_zheska();
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