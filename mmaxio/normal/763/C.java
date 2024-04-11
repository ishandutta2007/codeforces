import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	Random rng = new Random();

	int pow(int a, int b, int mod) {
		int ret = 1;
		for (; b > 0; b >>= 1) {
			if ((b & 1) == 1)
				ret = (int) (1L * ret * a % mod);
			a = (int) (1L * a * a % mod);
		}
		return ret;
	}

	void solve() throws IOException {
		int p = nextInt();
		int n = nextInt();

		int sum = 0;
		int sum2 = 0;

		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
			sum += a[i];
			if (sum >= p) {
				sum -= p;
			}
			sum2 += 1L * a[i] * a[i] % p;
			if (sum2 >= p) {
				sum2 -= p;
			}
		}

		for (int i = 0; i < n; i++) {
			int j = rng.nextInt(i + 1);
			int tmp = a[j];
			a[j] = a[i];
			a[i] = tmp;
		}

		Arrays.sort(a);

		if (n == p) {
			out.println("0 1");
			return;
		}

		if (n == 1) {
			out.println(a[0] + " " + 0);
			return;
		}

		if (p == 3) {
			out.println(a[0] + " " + (a[1] - a[0] + p) % p);
			return;
		}

		int invN = pow(n, p - 2, p);
		int invNsub1 = pow(n - 1, p - 2, p);
		int inv6 = pow(6 % p, p - 2, p);

		int symmSum = (int) (2L * sum * invN % p);

		outer: for (int i = 0; i < n; i++) {

			int first = a[i];
			int last = symmSum - first;
			if (last < 0) {
				last += p;
			}

			int diff = last - first;
			if (diff < 0) {
				diff += p;
			}
			diff = (int) (1L * diff * invNsub1 % p);
			
//			System.err.println(first + " " + diff);

			int expect = (int) (1L * first * first % p * n % p);
			expect += (int) (1L * first * diff % p * n % p * (n - 1) % p);
			if (expect >= p) {
				expect -= p;
			}

			expect += (int) (1L * diff * diff % p * n % p * (n - 1) % p
					* (2 * n - 1) % p * inv6 % p);
			if (expect >= p) {
				expect -= p;
			}

			if (expect != sum2) {
				continue outer;
			}

			int tmp = a[i];

			for (int j = 0; j < n; j++) {
				if (Arrays.binarySearch(a, tmp) < 0) {
					continue outer;
				}
				tmp += diff;
				if (tmp >= p) {
					tmp -= p;
				}
			}

			out.println(a[i] + " " + diff);
			return;
		}

		out.println(-1);
	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
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