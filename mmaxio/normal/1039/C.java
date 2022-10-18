import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class C {

	void submit() {
		int n = nextInt();
		int m = nextInt();
		int k = nextInt();
		
		long[] a = new long[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextLong();
		}
		
		HashMap<Long, ArrayList<Integer>> map = new HashMap<>();
		
		for (int i = 0; i < m; i++) {
			int u = nextInt() - 1;
			int v = nextInt() - 1;
			long x = a[v] ^ a[u];
			ArrayList<Integer> lst = map.get(x);
			if (lst == null) {
				lst = new ArrayList<>(4);
				map.put(x, lst);
			}
			lst.add(v);
			lst.add(u);
		}
		
		p = IntStream.range(0, n).toArray();
		rank = new int[n];
		
		used = new boolean[n];
		who = new int[n];
		
		int[] p2 = new int[n + 1];
		p2[0] = 1;
		for (int i = 1; i < p2.length; i++) {
			p2[i] = p2[i - 1] * 2 % P;
		}
		
		int ans = 0;
		
		for (ArrayList<Integer> lst : map.values()) {
			int comps = n;
			for (int i = 0; i < lst.size(); i += 2) {
				int v = lst.get(i);
				int u = lst.get(i + 1);
				if (unite(v, u)) {
					comps--;
				}
			}
			ans += p2[comps];
			if (ans >= P) {
				ans -= P;
			}
			
			for (int i = 0; i < sz; i++) {
				int v = who[i];
				used[v] = false;
				p[v] = v;
				rank[v] = 0;
			}
			
			sz = 0;
			
		}
		
		long rest = (1L << k) - map.size();
		ans += rest % P * p2[n] % P;
		if (ans >= P) {
			ans -= P;
		}
		
		out.println(ans);
	}
	
	boolean[] used;
	int[] who;
	int sz;
	
	int[] p;
	int[] rank;
	
	boolean unite(int v, int u) {
		v = get(v);
		u = get(u);
		if (v == u) {
			return false;
		}
		
		if (rank[v] < rank[u]) {
			int tmp = v;
			v = u;
			u = tmp;
		}
		
		if (rank[v] == rank[u]) {
			rank[v]++;
		}
		
		p[u] = v;
		return true;
	}
	
	int get(int v) {
		if (!used[v]) {
			used[v] = true;
			who[sz++] = v;
		}
		return p[v] == v ? v : (p[v] = get(p[v]));
	}
	
	static final int P = 1_000_000_007;

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

	C() throws IOException {
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
		new C();
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