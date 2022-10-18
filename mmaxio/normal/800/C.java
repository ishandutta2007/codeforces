import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}
	
	int[] head;
	int[] next;
	int[] val;
	
	int ptr = 0;
	
	void addEdge(int key, int what) {
		val[ptr] = what;
		next[ptr] = head[key];
		head[key] = ptr;
		ptr++;
	}
	
	static class ExtEuclid {
		int g, x, y;

		private ExtEuclid(int g, int x, int y) {
			this.g = g;
			this.x = x;
			this.y = y;
		}
		
		static ExtEuclid get(int a, int b) {
			if (b == 0) {
				return new ExtEuclid(a, 1, 0);
			}
			ExtEuclid ret = get(b, a % b);
			int newY = ret.x - a / b * ret.y;
			ret.x = ret.y;
			ret.y = newY;
			return ret;
		}
	}

	
	int multInverse(int a, int m) {
		if (gcd(a, m) != 1) {
			throw new AssertionError();
		}
		if (a < 0 || a >= m) {
			throw new AssertionError();
		}
		
		ExtEuclid euc = ExtEuclid.get(a, m);
		int ret = euc.x % m;
		if (ret < 0) {
			ret += m;
		}
		return ret;
		
	}
	
	int[] solve(int mod, boolean[] isGood) {
		ptr = 0;
		head = new int[mod + 1];
		next = new int[mod];
		val = new int[mod];
		Arrays.fill(head, -1);
		
		int[] cnt = new int[mod + 1];
		
		for (int i = 0; i < mod; i++) {
			if (isGood[i]) {
				int g = gcd(i, mod);
				addEdge(g, i);
				cnt[g]++;
			}
		}
		
		int[] dp = new int[mod + 1];
		int[] jump = new int[mod + 1];
		
		dp[mod] = 0;
		
		for (int i = mod; i >= 1; i--) {
			if (mod % i != 0) {
				dp[i] = -1;
			} else {
				dp[i] = dp[mod];
				jump[i] = mod;
				for (int j = i * 2; j < mod; j += i) {
					if (dp[j] > dp[i]) {
						dp[i] = dp[j];
						jump[i] = j;
					}
				}
				dp[i] += cnt[i];
			}
		}

		int was = 1;
		
		int nowG = 1;
		
		int[] ret = new int[dp[1]];
		int retPtr = 0;
		
		while (true) {
			for (int i = head[nowG]; i >= 0; i = next[i]) {
				int now = val[i];
//				System.err.println(now);
				int outp = divide(now, was, mod);
//				out.print(outp + " ");
				ret[retPtr++] = outp;
				was = now;
			}
			if (nowG == mod) {
				break;
			}
			nowG = jump[nowG];
		}
		
		return ret;
		
	}
	
	int divide(int a, int b, int mod) {
		if (a == 0) {
			return 0;
		}
		int g = gcd(b, mod);
		
		if (a % g != 0) {
			throw new AssertionError();
		}
		a /= g;
		b /= g;
		mod /= g;
		
		// now we are working in field Z(mod)
		return (int)((long)a * multInverse(b, mod) % mod);
	}

	void submit() {
		int bad = nextInt();
		int mod = nextInt();
		boolean[] isGood = new boolean[mod];
		Arrays.fill(isGood, true);
		for (int i = 0; i < bad; i++) {
			isGood[nextInt()] = false;
		}
		int[] ans = solve(mod, isGood);
		out.println(ans.length);
		for (int x : ans) {
			out.print(x + " ");
		}
		out.println();
	}
	
	static final int B = 20;
	static final Random rng = new Random();
	
	void test() {
		outer: for (int tst = 0;; tst++) {
			int mod = 1 + rng.nextInt(B);
			boolean[] isGood = new boolean[mod];
			for (int i = 0; i < mod; i++) {
				isGood[i] = rng.nextBoolean();
			}
			boolean allBad = true;
			for (boolean b : isGood) {
				allBad &= !b;
			}
			if (allBad) {
				continue outer;
			}
			int[] ans = solve(mod, isGood);
			int pref = 1;
			for (int i = 0; i < ans.length; i++) {
				pref = (int)((long)pref * ans[i] % mod);
				if (!isGood[pref]) {
					System.err.println(mod);
					System.err.println(Arrays.toString(isGood));
					System.err.println(i + " " + pref);
					throw new AssertionError();
				}
			}
			System.err.println(tst);
		}
	}
	
	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		submit();
//		test();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C();
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