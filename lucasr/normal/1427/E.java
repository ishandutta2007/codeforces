import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;
import java.util.ArrayList;

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
		EXum solver = new EXum();
		solver.solve(1, in, out);
		out.close();
	}

	static class EXum {
		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			long x = sc.nextLong();
			for (int i = 1; i < 20; i++) {
				long tmp = (x) ^ (x << i);
				long gcd = MathLib.gcd(x, tmp);
				if (gcd == 1) {
					List<String> ret = times(x, 1L << i);
					ret.add(xor(x, x << i));
					long inv = MathLib.inverse(tmp, x);
					ret.addAll(times(tmp, inv));
					long a = tmp * inv;
					long div = (tmp * inv - 1) / x;
					ret.addAll(times(x, div));
					long b = x * div;
					if (Math.abs(a - b) != 1) throw new RuntimeException();
					ret.add(xor(a, b));
					if ((a ^ b) != 1) {
						ret.add(sum(a, x));
						ret.add(sum(b, x));
						ret.add(xor(a + x, b + x));
					}
//                Set<Long> got = new HashSet<>();
//                got.add(x);
//                List<String> real = new ArrayList<>();
//                for (String s : ret) {
//                    String[] parts = s.split(" ");
//                    long tmp1 = Long.parseLong(parts[0]);
//                    long tmp2 = Long.parseLong(parts[2]);
//                    if (!got.contains(tmp1)) throw new RuntimeException();
//                    if (!got.contains(tmp2)) throw new RuntimeException();
//                    long nVal;
//                    if ("+".equals(parts[1])) {
//                        nVal = tmp1 + tmp2;
//                    } else {
//                        nVal = tmp1 ^ tmp2;
//                    }
//                    if (!got.contains(nVal)) {
//                        got.add(nVal);
//                        real.add(s);
//                    }
//                }
					out.println(ret.size());
					for (String s : ret) {
						out.println(s);
					}
					return;
				}
			}
		}

		static List<String> times(long a, long t) {
			List<String> ret = new ArrayList<>();
			if (t == 1) return ret;
			ret.addAll(times(a, t / 2));
			long val = a * (t / 2);
			ret.add(sum(val, val));
			if (t % 2 == 1) {
				ret.add(sum(2 * val, a));
			}
			return ret;
		}

		static String sum(long a, long b) {
			return a + " + " + b;
		}

		static String xor(long a, long b) {
			return a + " ^ " + b;
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

		public long nextLong() {
			return Long.parseLong(next());
		}

	}

	static class MathLib {
		private static long xEuclid;
		private static long yEuclid;

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

		public static long positiveModule(long a, long mod) {
			return (a % mod + mod) % mod;
		}

		public static long inverse(long a, long mod) {
			euclid(a, mod);
			return positiveModule(xEuclid, mod);
		}

		private static void euclid(long a, long b) {
			if (b == 0) {
				xEuclid = 1;
				yEuclid = 0;
				return;
			}
			euclid(b, a % b);
			long tmp = xEuclid - a / b * yEuclid;
			xEuclid = yEuclid;
			yEuclid = tmp;
		}

	}
}