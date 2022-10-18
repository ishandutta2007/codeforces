import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class F {

	static class Trip implements Comparable<Trip> {
		int from, to;
		int need;
		int id;
		public Trip(int from, int to, int need, int id) {
			this.from = from;
			this.to = to;
			this.need = need;
			this.id = id;
		}
		@Override
		public int compareTo(Trip o) {
			return Integer.compare(from, o.from);
		}
	}
	
	Trip[] a;
	int[] dp, last, lastStart;
	
	
	void submit() {
		int n = nextInt();
		int p = nextInt();
		a = new Trip[n];
		for (int i = 0; i < n; i++) {
			int s = nextInt();
			int len = nextInt();
			int need = nextInt();
			a[i] = new Trip(s, s + len, need, i);
		}
		
		Arrays.sort(a);
		
		dp = new int[1 << n];
		last = new int[1 << n];
		lastStart = new int[1 << n];
		
		Integer[] order = new Integer[n];
		for (int i = 0; i < n; i++) {
			order[i] = i;
		}
		
		Arrays.sort(order, Comparator.comparingInt(x -> a[x].need));
		
		Arrays.fill(dp, INF);
		dp[0] = 1;
		
		int[] wL = new int[n];
		int[] wR = new int[n];

		wL[0] = 1;
		for (int i = 0; i < n - 1; i++) {
			wL[i + 1] = a[i].to;
		}
		for (int i = 0; i < n; i++) {
			wR[i] = a[i].from;
		}
		
		for (int mask = 0; mask < 1 << n; mask++) {
			if (dp[mask] == INF) {
				continue;
			}
			
			int ptr = 0;
			int check = mask == 0 ? n : Integer.numberOfTrailingZeros(mask); 
			
			for (int add : order) {
				if (test(mask, add)) {
					continue;
				}
				while (ptr < n) {
					int start = Math.max(dp[mask], wL[ptr]);

					boolean advancePtr = false;
					
					if (start >= wR[ptr]) {
						advancePtr = true;
					} else if (check != n && start + a[add].need >= a[check].from) {
						advancePtr = true;
					} else {
						int newVal = start + a[add].need; 
						if (newVal < a[add].from) {
							if (dp[mask | (1 << add)] > newVal) {
								dp[mask | (1 << add)] = newVal;
								last[mask | (1 << add)] = add;
								lastStart[mask | (1 << add)] = start;
							}
						}
					}
					
					if (advancePtr) {
						if (ptr == check) {
							check++;
							while (check < n && !test(mask, check)) {
								check++;
							}
						}
						ptr++;
					} else {
						break;
					}

				}
			}
		}
		
		int[] ans1 = new int[n];
		int[] ans2 = new int[n];
		ans1[0] = -1;
		
		if (p == 1) {
			if (dp[(1 << n) - 1] < INF) {
				fillAns((1 << n) - 1, 1, ans1, ans2);
			}
		} else {
			for (int i = 0; i < 1 << n; i++) {
				if (dp[i] < INF && dp[((1 << n) - 1) ^ i] < INF) {
					fillAns(i, 1, ans1, ans2);
					fillAns(((1 << n) - 1) ^ i, 2, ans1, ans2);
					break;
				}
			}
		}
		
		if(ans1[0] == -1) {
			out.println("NO");
		} else {
			out.println("YES");
			for (int i = 0; i < n; i++) {
				out.println(ans1[i] + " " + ans2[i]);
			}
		}
	}
	
	void fillAns(int mask, int id, int[] ans1, int[] ans2) {
		while (mask > 0) {
			int x = last[mask];
			ans1[a[x].id] = id;
			ans2[a[x].id] = lastStart[mask];
			mask ^= (1 << x);
		}
	}
	
	static boolean test(int mask, int i) {
		return ((mask >> i) & 1) == 1;
	}
	
	static final int INF = Integer.MAX_VALUE / 2;

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