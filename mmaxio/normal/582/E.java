import java.io.*;
import java.util.*;
import java.util.concurrent.atomic.AtomicInteger;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int P = 1_000_000_007;
	static final int VARS = 4;
	static final int INPS = 1 << VARS;
	static final int FUNS = 1 << INPS;

	int func(int x) {
		int pos = x >= 0 ? x : ~x;
		int val = x >= 0 ? 1 : 0;
		int ret = 0;
		for (int i = 0; i < INPS; i++) {
			if (((i >> pos) & 1) == val) {
				ret |= 1 << i;
			}
		}
//		System.err.println(x + " " + ret);
		return ret;
	}

	int[] singleVar(char c) {
		int[] ret = new int[FUNS];
		if (c == '?') {
			for (int i = -VARS; i < VARS; i++) {
				ret[func(i)]++;
			}
			return ret;
		}
		ret[func(c >= 'A' && c <= 'Z' ? c - 'A' : ~(c - 'a'))]++;
		return ret;
	}

	int[] or(int[] a, int[] b) {
		a = tr(a.clone());	
		b = tr(b.clone());
		
//		System.err.println("tr a " + Arrays.toString(a));
//		System.err.println("tr b " +Arrays.toString(b));
		int[] c = mul(a, b);
//		System.err.println(Arrays.toString(invTr(c)));
		return invTr(c);
	}
	
	int[] rev(int[] a) {
		int[] b = new int[FUNS];
		for (int i = 0, j = FUNS - 1; i < FUNS; i++, j--) {
			b[i] = a[j];
		}
		return b;
	}

	int[] and(int[] a, int[] b) {
		
		a = tr(rev(a));
		b = tr(rev(b));
		
		int[] c = mul(a, b);
		return rev(invTr(c));
	}

	int[] sum(int[] a, int[] b) {
		int[] ret = new int[FUNS];
		for (int i = 0; i < FUNS; i++) {
			ret[i] = a[i] + b[i];
			if (ret[i] >= P) {
				ret[i] -= P;
			}
		}
		return ret;
	}

	int[] mul(int[] a, int[] b) {
		int[] ret = new int[FUNS];
		for (int i = 0; i < FUNS; i++) {
			ret[i] = (int) ((long) a[i] * b[i] % P);
		}
		return ret;
	}
	
	int[] tr(int[] a) {
		for (int i = 0; i < INPS; i++) {
			for (int j = 0; j < FUNS; j++) {
				if (((j >> i) & 1) == 0) {
					int to = j ^ (1 << i);
					a[to] += a[j];
					if (a[to] >= P) {
						a[to] -= P;
					}
				}
			}
		}
		return a;
	}
	
	int[] invTr(int[] a) {
		for (int i = 0; i < INPS; i++) {
			for (int j = 0; j < FUNS; j++) {
				if (((j >> i) & 1) == 0) {
					int to = j ^ (1 << i);
					a[to] -= a[j];
					if (a[to] < 0) {
						a[to] += P;
					}
				}
			}
		}
		return a;
	}
	

	int[] parse(String s, AtomicInteger ptr) {
		if (s.charAt(ptr.get()) == '(') {
			ptr.incrementAndGet();
			int[] a = parse(s, ptr);
			ptr.incrementAndGet();
			char type = s.charAt(ptr.get());
			ptr.incrementAndGet();
			ptr.incrementAndGet();
			int[] b = parse(s, ptr);
			int[] ret = type == '|' ? or(a, b) : (type == '&' ? and(a, b) : sum(
					or(a, b), and(a, b)));
			ptr.incrementAndGet();
//			System.err.println(Arrays.toString(ret));
			return ret;
		}
		char var = s.charAt(ptr.get());
		ptr.incrementAndGet();
		return singleVar(var);
	}

	void solve() throws IOException {
		String s = nextToken();
		int[] dp = parse(s, new AtomicInteger(0));
		int n = nextInt();
		int m1 = 0, m2 = 0;
		for (int i = 0; i < n; i++) {
			int where = 0;
			for (int j = 0; j < VARS; j++) {
				where += nextInt() << j;
			}
			int val = nextInt();
			m1 |= val << where;
			m2 |= 1 << where;
		}
		
//		System.err.println(Arrays.toString(dp));

		int ret = 0;
		for (int i = 0; i < dp.length; i++) {
			if ((i & m2) == m1) {
				ret += dp[i];
				if (ret >= P) {
					ret -= P;
				}
			}
		}
		out.println(ret);
	}

	E() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new E();
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