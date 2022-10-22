import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
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
		ENewSchool solver = new ENewSchool();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class ENewSchool {
		public static MyScanner sc;
		public static PrintWriter out;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			ENewSchool.sc = sc;
			ENewSchool.out = out;
			int n = sc.nextInt();
			int m = sc.nextInt();
			int[] teachersTmp = sc.nextIntArray(n);
			Arrays.sort(teachersTmp);
			Fraction[] teachers = new Fraction[m];
			for (int i = n - m; i < n; i++) {
				teachers[i - (n - m)] = new Fraction(teachersTmp[i], 1);
			}
			int[][] students = new int[m][];
			long[] sSum = new long[m];
			Fraction[] avg = new Fraction[m];
			List<Integer> ids = new ArrayList<>();
			for (int i = 0; i < m; i++) {
				int tmp = sc.nextInt();
				students[i] = sc.nextIntArray(tmp);
				sSum[i] = 0;
				for (int age : students[i]) {
					sSum[i] += age;
				}
				avg[i] = new Fraction(sSum[i], students[i].length);
				ids.add(i);
			}
			ids.sort(Comparator.comparing(a -> avg[a]));
			boolean can = true;
			for (int i = 0; i < m; i++) {
				if (avg[ids.get(i)].compareTo(teachers[i]) > 0) {
					can = false;
				}
			}
			char[][] res = new char[m][];
			for (int i = 0; i < m; i++) {
				res[i] = new char[students[i].length];
				Arrays.fill(res[i], '0');
			}
			if (can) {
				boolean[] okPrev = new boolean[m];
				for (int i = 0; i < m; i++) {
					if (i > 0 && avg[ids.get(i)].compareTo(teachers[i - 1]) <= 0) {
						okPrev[i] = true;
					}
				}
				int[] lastOkPrev = new int[m];
				Arrays.fill(lastOkPrev, -1);
				for (int i = m - 1; i >= 0; i--) {
					if (okPrev[i]) {
						lastOkPrev[i] = i;
						if (i < m - 1) {
							lastOkPrev[i] = Math.max(lastOkPrev[i], lastOkPrev[i + 1]);
						}
					}
				}
				for (int i = 0; i < m; i++) {
					int me = ids.get(i);
					Fraction max = teachers[i];
					if (i + 1 < m && lastOkPrev[i + 1] != -1) {
						max = teachers[lastOkPrev[i + 1]];
					}
					for (int j = 0; j < students[me].length; j++) {
						long sum = sSum[me] - students[me][j];
						if (new Fraction(sum, students[me].length - 1).compareTo(max) <= 0) {
							res[me][j] = '1';
						} else {
							res[me][j] = '0';
						}
					}
				}
			} else {
				boolean may = true;
				int first = -1, last = -1;
				for (int i = 0; i < m && may; i++) {
					if (avg[ids.get(i)].compareTo(teachers[i]) > 0) {
						if (first == -1) first = i;
						last = i;
						if (i + 1 < m && avg[ids.get(i)].compareTo(teachers[i + 1]) > 0) {
							may = false;
						}
					}
				}

				if (may) {
					Fraction max = teachers[first];
					for (int i = last; i < m; i++) {
						int me = ids.get(i);
						for (int j = 0; j < students[me].length; j++) {
							long sum = sSum[me] - students[me][j];
							if (new Fraction(sum, students[me].length - 1).compareTo(max) <= 0) {
								res[me][j] = '1';
							} else {
								res[me][j] = '0';
							}
						}
					}
				}
			}

			for (int i = 0; i < res.length; i++) {
				out.print(new String(res[i]));
			}
			out.println();
		}

	}

	static class Fraction implements Comparable<Fraction> {
		public long num;
		public long den;

		public Fraction(long num, long den) {
			if (den < 0) {
				den = -den;
				num = -num;
			}
			long g = MathLib.gcd(num, den);
			this.num = num / g;
			this.den = den / g;
		}

		public int compareTo(Fraction o) {
			return Long.compare(num * o.den, o.num * den);
		}

		public String toString() {
			return num + "/" + den;
		}

	}

	static class MathLib {
		public static long gcd(long a, long b) {
			a = Math.abs(a);
			b = Math.abs(b);
			while (b != 0) {
				long tmp = b;
				b = a % b;
				a = tmp;
			}
			return a;
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

		public int[] nextIntArray(int n) {
			int[] ret = new int[n];
			for (int i = 0; i < n; i++) {
				ret[i] = nextInt();
			}
			return ret;
		}

	}
}