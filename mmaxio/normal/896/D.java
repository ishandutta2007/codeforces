import java.io.*;
import java.util.*;

public class D {

	int mod;

	int[] primes = new int[10];
	int[] pows = new int[10];
	int[][] prPows;
	int ps;
	int phi = 1;

	void prepare() {
		int mod = this.mod;
		ps = 0;
		for (int i = 2; i * i <= mod; i++) {
			if (mod % i == 0) {
				primes[ps] = i;
				phi *= i - 1;
				pows[ps] = 1;
				mod /= i;
				while (mod % i == 0) {
					pows[ps]++;
					mod /= i;
					phi *= i;
				}
				ps++;
			}
		}

		if (mod != 1) {
			primes[ps] = mod;
			pows[ps] = 1;
			ps++;
			phi *= mod - 1;
		}

		primes = Arrays.copyOf(primes, ps);
		pows = Arrays.copyOf(pows, ps);
	}

	int[] fact, invFact;
	int[][] factP;

	int c(int n, int k) {
		if (n < 0 || k < 0 || k > n) {
			return 0;
		}
		int ret = (int) ((long) fact[n] * invFact[n - k] % mod * invFact[k] % mod);
		for (int i = 0; i < ps; i++) {
			int val = factP[n][i] - factP[k][i] - factP[n - k][i];
			ret = (int) ((long) ret * prPows[i][val] % mod);
		}
		return ret;
	}

	void submit() {
		int n = nextInt();
		mod = nextInt();
		int l = nextInt();
		int r = nextInt();

		if (mod == 1) {
			out.println(0);
			return;
		}

		prepare();

		fact = new int[n + 1];
		invFact = new int[n + 1];
		factP = new int[n + 1][];

		fact[0] = invFact[0] = 1;
		factP[0] = new int[ps];
		
		for (int i = 1; i <= n; i++) {
			int ii = i;
			factP[i] = factP[i - 1].clone();
			for (int j = 0; j < ps; j++) {
				while (ii % primes[j] == 0) {
					factP[i][j]++;
					ii /= primes[j];
				}
			}
			fact[i] = (int) ((long) fact[i - 1] * ii % mod);
			invFact[i] = (int) ((long) invFact[i - 1] * inv(ii) % mod);
		}

		prPows = new int[ps][];
		for (int i = 0; i < ps; i++) {
			int p = primes[i];
			int q = factP[n][i];
			prPows[i] = new int[q + 1];
			prPows[i][0] = 1;
			for (int j = 1; j <= q; j++) {
				prPows[i][j] = (int) ((long) prPows[i][j - 1] * p % mod);
			}
		}
		
		int ret = 0;
		for (int pay = 0; pay <= n; pay++) {
			int low = Math.max((pay - r + 1) >> 1, 0);
			int high = (pay - l) >> 1;
			if (low > high) {
				continue;
			}
			int val = c(pay, high) - c(pay, low - 1);
			if (val < 0 || val >= mod) {
				val += mod;
			}
			val = (int)((long)val * c(n, pay) % mod);
			ret += val;
			if (ret >= mod || ret < 0) {
				ret -= mod;
			}
		}
		
		out.println(ret);
	}

	int inv(int x) {
		return pow(x % mod, phi - 1);
	}
	
	int pow(int a, int b) {
		int ret = 1;
		for (; b > 0; b >>= 1) {
			if ((b & 1) == 1) {
				ret = (int)((long)ret * a % mod);
			}
			a = (int)((long)a * a % mod);
		}
		return ret;
	}

	void preCalc() {

	}

	void stress() {

	}

	D() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		 submit();
		// stress();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new D();
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