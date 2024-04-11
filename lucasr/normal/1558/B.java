import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author lucasr
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		MyScanner in = new MyScanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		BUpTheStrip solver = new BUpTheStrip();
		solver.solve(1, in, out);
		out.close();
	}

	static class BUpTheStrip {
		public static MyScanner sc;
		public static PrintWriter out;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			BUpTheStrip.sc = sc;
			BUpTheStrip.out = out;
			int n = sc.nextInt();
			Sieve sieve = new Sieve(n);
			MathLib.MOD = sc.nextInt();
			long[] values = new long[n + 1];
			values[1] = 1;
			values[2] = 2;
			long sum = 3, sum2 = 1;
			for (int i = 3; i <= n; i++) {
				IntArray divs = sieve.allDivisors(i);
				for (int j = 0; j < divs.size(); j++) {
					int me = divs.get(j);
					if (me != i) {
						sum2 += values[me] - values[me - 1];
					}
				}
				sum2 %= MathLib.MOD;
				sum2 += MathLib.MOD;
				sum2 %= MathLib.MOD;
				values[i] = (sum + sum2) % MathLib.MOD;
				sum = (sum + values[i]) % MathLib.MOD;
			}
			out.println(values[n]);
		}

	}

	static class MyScanner {
		private BufferedReader br;
		private StringTokenizer tokenizer;

		public MyScanner(InputStream is) {
			br = new BufferedReader(new InputStreamReader(is));
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

	}

	static class IntArray {
		int[] arr;
		int size;

		public IntArray() {
			arr = new int[4];
		}

		public void add(int val) {
			if (size == arr.length) {
				arr = Arrays.copyOf(arr, 2 * arr.length);
			}
			arr[size++] = val;
		}

		public int get(int pos) {
			return arr[pos];
		}

		public int last() {
			return arr[size - 1];
		}

		public int size() {
			return size;
		}

		public int[] toArray() {
			return Arrays.copyOf(arr, size);
		}

		public String toString() {
			return "IntArray " + Arrays.toString(toArray());
		}

	}

	static class MathLib {
		public static long MOD = 1000000007;

	}

	static class Sieve {
		public int[] firstPrime;

		public Sieve(int max) {
			firstPrime = getSieveFirstPrime(max);
		}

		public static int[] getSieveFirstPrime(int max) {
			int[] ret = new int[max + 1];
			for (int i = 2; i <= max; i++)
				if (ret[i] == 0) {
					if (i <= max / i) for (int j = i * i; j <= max; j += i) {
						if (ret[j] == 0) ret[j] = i;
					}
					ret[i] = i;
				}
			return ret;
		}

		public IntArray factorsAndExponents(int n) {
			IntArray ret = new IntArray();
			int exp = 0;
			while (n > 1) {
				int prime = firstPrime[n];
				if (ret.size() == 0 || ret.last() != prime) {
					if (exp > 0) ret.add(exp);
					ret.add(prime);
					exp = 0;
				}
				exp++;
				n /= prime;
			}
			if (exp > 0) ret.add(exp);
			return ret;
		}

		public IntArray allDivisors(int n) {
			IntArray fae = factorsAndExponents(n);
			IntArray ret = new IntArray();
			calcDivisors(1, fae, 0, ret);
			return ret;
		}

		private void calcDivisors(int n, IntArray factors, int index, IntArray result) {
			if (index + 1 >= factors.size()) {
				result.add(n);
				return;
			}
			int prime = factors.get(index);
			int exponent = factors.get(index + 1);
			for (int i = 0; i <= exponent; i++) {
				calcDivisors(n, factors, index + 2, result);
				if (i < exponent) n *= prime;
			}
		}

	}
}