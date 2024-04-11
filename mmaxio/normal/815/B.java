import java.io.*;
import java.util.*;

public class B {

	static final int P = 1_000_000_007;
	
	void submit() {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		
		int sign = 1;
		while (n % 4 != 1) {
			int[] b = new int[n - 1];
			for (int i = 0; i < n - 1; i++) {
				b[i] = a[i] + sign * a[i + 1];
				if (b[i] >= P) {
					b[i] -= P;
				} else if (b[i] < 0) {
					b[i] += P;
				}
				sign *= -1;
			}
			n--;
			a = b;
		}
		
		int cn = n / 2;
		int coef = 1;
		
		int ret = 0;
		
		for (int i = 0; i <= cn; i++) {
			ret += (int)((long)a[2 * i] * coef % P);
			if (ret >= P) {
				ret -= P;
			}
			if (i != cn) {
				coef = (int)((long)coef * (cn - i) % P * inv(i + 1) % P);
			}
		}
		
		out.println(ret);
	}
	
	int inv(int x) {
		return x == 1 ? 1 : (P - (int) ((long) (P / x) * inv(P % x) % P));
	}

	void preCalc() {

	}

	void stress() {

	}

	void go(int n) {
		int[][] a = new int[n][n];
		for (int i = 0; i < n; i++) {
			a[i][i] = 1;
		}
		
		int sign = -1;
		for (int sz = n; sz > 1; sz--) {
			int[][] b = new int[sz - 1][n];
			for (int i = 0; i < sz - 1; i++) {
				for (int j = 0; j < n; j++) {
					b[i][j] = a[i][j] + sign * a[i + 1][j];
				}
				sign *= -1;
			}
			a = b;
//			System.err.println(Arrays.deepToString(a));
		}
		System.err.println(n + ": " + Arrays.toString(a[0]));
	}
	
	void test() {
		go(5);
//		for (int n = 1; n <= 30; n += 4) {
//			go(n);
//		}
	}

	B() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
//		preCalc();
		submit();
		//stress();
//		test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new B();
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