import java.io.*;
import java.util.*;

public class C {

	PrimeRoutines pr;

	void submit() {
		int t = nextInt();
		while (t-- > 0) {
			int[] n = new int[3];
			int[] m = new int[3];
			int[] s = new int[3];
			for (int i = 0; i < 3; i++) {
				n[i] = nextInt();
			}
			for (int i = 0; i < 3; i++) {
				m[i] = nextInt();
			}
			for (int i = 0; i < 3; i++) {
				s[i] = nextInt();
			}
//			out.println(slow(n, m, s));
			out.println(fast(n, m, s));
		}
	}

	int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	HashMap<Integer, Integer> factorize(int[] n) {
		HashMap<Integer, Integer> factN = new HashMap<>();
		for (int x : n) {
			int[] lowDiv = pr.lowDiv;
			while (x > 1) {
				int p = lowDiv[x];
				factN.merge(p, 1, Integer::sum);
				x /= p;
			}
		}

		return factN;
	}

	HashMap<Integer, Integer> gcd(HashMap<Integer, Integer> a,
			HashMap<Integer, Integer> b) {
		HashMap<Integer, Integer> ret = new HashMap<>();
		for (Map.Entry<Integer, Integer> e : a.entrySet()) {
			int p = e.getValue();
			p = Math.min(p, b.getOrDefault(e.getKey(), 0));
			if (p != 0) {
				ret.put(e.getKey(), p);
			}
		}
		return ret;
	}

	long gcd(long a, long b) {
		return b == 0 ? a : gcd(b, a % b);
	}
	
	long myPow(long a, long b) {
		long ret = 1;
		for (int i = 0; i < b; i++) {
			ret *= a;
		}
		return ret;
	}

	long fast(int[] n, int[] m, int[] s) {
		s[0] *= 2;

		long N = (long) n[0] * n[1] * n[2];
		long M = (long) m[0] * m[1] * m[2];
		long S = (long) s[0] * s[1] * s[2];

		HashMap<Integer, Integer> fn = factorize(n);
		HashMap<Integer, Integer> fs = factorize(s);
		HashMap<Integer, Integer> fg = gcd(fn, fs);

		long[] diff = new long[30];
		int ptr = 0;
		for (Map.Entry<Integer, Integer> e : fn.entrySet()) {
			int key = e.getKey();
			int value = e.getValue();
			
			int gValue = fg.getOrDefault(key, 0);
			
			if (gValue != value) {
				diff[ptr++] = myPow(key, gValue + 1);
			}
		}

		diff = Arrays.copyOf(diff, ptr);
		
//		System.err.println(Arrays.toString(diff));
		
//		long ret1 = M - go(M, diff, 0);
		long ret1 = go(M, diff, 0);

		int[] sp = new int[40];
		int[] sq = new int[40];
		ptr = 0;

		for (Map.Entry<Integer, Integer> e : fs.entrySet()) {
			int key = e.getKey();
			int value = e.getValue();
			sq[ptr] = value;
			sp[ptr] = key;
			ptr++;
		}

		sp = Arrays.copyOf(sp, ptr);
		sq = Arrays.copyOf(sq, ptr);

		long ret2 = go2(sp, sq, 0, 1, N);

		return ret1 + ret2;
	}

	int go2(int[] primes, int[] pows, int ptr, long now, long bound) {
		if (now > bound) {
			return 0;
		}
		if (ptr == primes.length) {
			return 1;
		}
		int upto = pows[ptr];
		int mult = primes[ptr];

		int ret = 0;

		for (int i = 0; i <= upto; i++) {
			ret += go2(primes, pows, ptr + 1, now, bound);
			now *= mult;
		}

		return ret;
	}

	long go(long x, long[] arr, int ptr) {
		if (x == 0 || ptr == arr.length) {
			return x;
		}
		return go(x, arr, ptr + 1) - go(x / arr[ptr], arr, ptr + 1);
	}

	int slow(int[] n, int[] m, int[] s) {
		int N = n[0] * n[1] * n[2];
		int M = m[0] * m[1] * m[2];
		int S = s[0] * s[1] * s[2];
		// if (S % 2 == 0) {
		// S /= 2;
		// }
		int ret = 0;
		for (int i = 1; i <= M; i++) {
			if (2 * S % gcd(N, i) == 0) {
				ret++;
			}
		}
		for (int i = 1; i <= N; i++) {
			if (2 * S % i == 0) {
				ret++;
			}
		}
		return ret;
	}

	void preCalc() {
		pr = new PrimeRoutines(2_000_000);
	}

	void stress() {
		int tst = 0;
		for (;;) {
			int[] n = new int[3];
			int[] m = new int[3];
			int[] s = new int[3];
			for (int i = 0; i < 3; i++) {
				n[i] = rand(1, 1000000);
				m[i] = rand(1, 1000000);
				s[i] = rand(1, 1000000);
			}
			fast(n, m, s);
			System.err.println(tst++);
		}
	}

	void test() {

	}

	public class PrimeRoutines {

		int[] lowDivIdx;
		int[] lowDiv;
		int[] p;
		int N;

		public PrimeRoutines(int N) {
			this.N = N;
			p = new int[(int) (N / Math.log(N))];
			lowDivIdx = new int[N + 1];
			lowDiv = new int[N + 1];
			Arrays.fill(lowDivIdx, -1);
			int pCnt = 0;
			for (int i = 2; i <= N; i++) {
				if (lowDivIdx[i] == -1) {
					if (p.length == pCnt) {
						p = Arrays.copyOf(p, 2 * p.length);
					}
					lowDivIdx[i] = pCnt;
					lowDiv[i] = i;
					p[pCnt++] = i;
				}
				int toJ = Math.min(pCnt, lowDivIdx[i] + 1);
				for (int j = 0; j < toJ; j++) {
					int x = i * p[j];
					if (x > N) {
						break;
					}
					lowDivIdx[x] = j;
					lowDiv[x] = p[j];
				}
			}
			p = Arrays.copyOf(p, pCnt);
		}

		int[] divCount() {
			int[] ret = new int[N + 1];
			int[] tmp = new int[N + 1];
			ret[1] = 1;
			for (int i = 2; i <= N; i++) {
				int p = lowDiv[i];
				int j = i / p;
				if (p == lowDiv[j]) {
					int k = tmp[j];
					ret[i] = ret[j] / k * (k + 1);
					tmp[i] = k + 1;
				} else {
					ret[i] = ret[j] * 2;
					tmp[i] = 2;
				}
			}
			return ret;
		}

		List<Integer> getDivsNotSorted(int x) {
			List<Integer> ret = new ArrayList<Integer>(0);
			ret.add(1);
			while (x > 1) {
				int sz = ret.size();
				int pr = lowDiv[x];
				while (lowDiv[x] == pr) {
					int to = ret.size();
					for (int i = ret.size() - sz; i < to; i++) {
						ret.add(ret.get(i) * pr);
					}
					x /= pr;
				}
			}
			return ret;
		}

		int[] moebiusFunction() {
			int[] mu = new int[N + 1];
			mu[1] = 1;
			for (int i = 2; i <= N; i++) {
				int p = lowDiv[i];
				int j = i / p;
				if (p != lowDiv[j]) {
					mu[i] = -mu[j];
				}
			}
			return mu;
		}

		int[] eulerFunction() {
			int[] phi = new int[N + 1];
			phi[1] = 1;
			for (int i = 2; i <= N; i++) {
				int p = lowDiv[i];
				int j = i / p;
				phi[i] = phi[j] * (p != lowDiv[j] ? p - 1 : p);
			}
			return phi;
		}
	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
//		 stress();
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