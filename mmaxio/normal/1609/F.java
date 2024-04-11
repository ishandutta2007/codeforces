import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class F_fenwick {

	void submit() {
		int n = nextInt();
//		int n = 1_000_000;
		long[] a = new long[n];
		int[] b = new int[n];
		boolean[] check = new boolean[62];
		for (int i = 0; i < n; i++) {
			a[i] = nextLong();
//			a[i] = i & 15;
//			a[i] = i ^ (i >> 1);
			b[i] = Long.bitCount(a[i]);
			check[b[i]] = true;
		}

		int[] a0 = new int[n];
		int[] a1 = new int[n];
		int[] b0 = new int[n];
		int[] b1 = new int[n];

		int[] min = new int[n + 1];
		int[] max = new int[n + 1];
		min[0] = max[0] = -1;

		long ret = 0;
		int szMin = 1, szMax = 1;

		int CUR_VAL = 0;

		for (int bit = 0; bit < 62; bit++) {
			if (!check[bit]) {
				continue;
			}
			for (int j = 0; j < n; j++) {
				long x = a[j];

				// min
				while (szMin > 1 && a[min[szMin - 1]] >= x) {
					if (b[min[szMin - 1]] == bit) {
						int low = min[szMin - 2];
						int high = min[szMin - 1];
						for (int i = high; i >= 0; i = (i & (i + 1)) - 1) {
							CUR_VAL -= b1[i] * high + b0[i];
						}
						for (int i = low; i >= 0; i = (i & (i + 1)) - 1) {
							CUR_VAL += b1[i] * low + b0[i];
						}

						for (int i = low + 1; i < n; i |= i + 1) {
							a0[i] += low;
							a1[i]--;
						}
						for (int i = high; i < n; i |= i + 1) {
							a0[i] -= high;
							a1[i]++;
						}

//						st.modifySegm(min[szMin - 2] + 1, min[szMin - 1] + 1, -1);
					}
					--szMin;
				}
				if (b[j] == bit) {
					int low = min[szMin - 1];
					int high = j;
					for (int i = high; i >= 0; i = (i & (i + 1)) - 1) {
						CUR_VAL += b1[i] * high + b0[i];
					}
					for (int i = low; i >= 0; i = (i & (i + 1)) - 1) {
						CUR_VAL -= b1[i] * low + b0[i];
					}

					for (int i = low + 1; i < n; i |= i + 1) {
						a0[i] -= low;
						a1[i]++;
					}
					for (int i = high; i < n; i |= i + 1) {
						a0[i] += high;
						a1[i]--;
					}

//					st.modifySegm(min[szMin - 1] + 1, j + 1, 1);
				}
				min[szMin++] = j;

				// max
				while (szMax > 1 && a[max[szMax - 1]] <= x) {
					if (b[max[szMax - 1]] == bit) {
						int low = max[szMax - 2];
						int high = max[szMax - 1];
						for (int i = high; i >= 0; i = (i & (i + 1)) - 1) {
							CUR_VAL -= a1[i] * high + a0[i];
						}
						for (int i = low; i >= 0; i = (i & (i + 1)) - 1) {
							CUR_VAL += a1[i] * low + a0[i];
						}

						for (int i = low + 1; i < n; i |= i + 1) {
							b0[i] += low;
							b1[i]--;
						}
						for (int i = high; i < n; i |= i + 1) {
							b0[i] -= high;
							b1[i]++;
						}

//						st.modifySegm(max[szMax - 2] + 1, max[szMax - 1] + 1, -1);
					}
					--szMax;
				}
				if (b[j] == bit) {
					int low = max[szMax - 1];
					int high = j;
					for (int i = high; i >= 0; i = (i & (i + 1)) - 1) {
						CUR_VAL += a1[i] * high + a0[i];
					}
					for (int i = low; i >= 0; i = (i & (i + 1)) - 1) {
						CUR_VAL -= a1[i] * low + a0[i];
					}

					for (int i = low + 1; i < n; i |= i + 1) {
						b0[i] -= low;
						b1[i]++;
					}
					for (int i = high; i < n; i |= i + 1) {
						b0[i] += high;
						b1[i]--;
					}

//					st.modifySegm(max[szMax - 1] + 1, j + 1, 1);
				}
				max[szMax++] = j;
				
				ret += CUR_VAL;
			}

			szMin = szMax = 1;
			Arrays.fill(a0, 0);
			Arrays.fill(a1, 0);
			Arrays.fill(b0, 0);
			Arrays.fill(b1, 0);

			CUR_VAL = 0;
		}
		out.println(ret);
	}

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

	F_fenwick() throws IOException {
		is = System.in;
		out = new PrintWriter(System.out);
		submit();
		// stress();
//		 test();
		out.close();
	}

	static final Random rng = new Random();
	static final int C = 5;

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new F_fenwick();
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