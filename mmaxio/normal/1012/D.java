import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class D {

	static class State {
		String x, y;

		public State(String x, String y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + ((x == null) ? 0 : x.hashCode());
			result = prime * result + ((y == null) ? 0 : y.hashCode());
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			State other = (State) obj;
			if (x == null) {
				if (other.x != null)
					return false;
			} else if (!x.equals(other.x))
				return false;
			if (y == null) {
				if (other.y != null)
					return false;
			} else if (!y.equals(other.y))
				return false;
			return true;
		}
	}

	ArrayList<Integer> runs(String s) {
		ArrayList<Integer> ret = new ArrayList<>();
		int run = 0;
		for (int i = s.length() - 1; i >= 0; i--) {
			if (i != s.length() - 1 && s.charAt(i + 1) != s.charAt(i)) {
				ret.add(run);
				run = 0;
			}
			run++;
		}
		ret.add(run);
		return ret;
	}

	int slow(String s, String t) {
		ArrayDeque<State> que = new ArrayDeque<>();

		que.add(new State(s, t));
		HashMap<State, Integer> dist = new HashMap<>();

		dist.put(new State(s, t), 0);

		while (!que.isEmpty()) {
			State st = que.poll();

			String x = st.x;
			String y = st.y;

			int curD = dist.get(st);

			if ((x.indexOf('a') == -1 || x.indexOf('b') == -1)
					&& (y.indexOf('a') == -1 || y.indexOf('b') == -1)) {

				// System.err.println(x + " " + y);

				return dist.get(st);
			}

			for (int i = 0; i <= x.length(); i++) {
				for (int j = 0; j <= y.length(); j++) {

					String x0 = x.substring(0, i);
					String x1 = x.substring(i);

					String y0 = y.substring(0, j);
					String y1 = y.substring(j);

					String nx = y0 + x1;
					String ny = x0 + y1;

					State nst = new State(nx, ny);
					if (!dist.containsKey(nst)) {

						// System.err.println(x + " " + y + " ---> " + nx + " "
						// + ny);

						dist.put(nst, curD + 1);
						que.add(nst);
					}
				}
			}
		}

		throw new AssertionError();
	}

	int fast(String s, String t) {

		ArrayList<Integer> ret = new ArrayList<>();

		ArrayList<Integer> rs = runs(s);
		ArrayList<Integer> rt = runs(t);
		boolean areSame = s.charAt(0) == t.charAt(0);

		while (areSame) {
			int p = rs.size();
			int q = rt.size();

			int x = -1, y = -1;

			shiiit: for (int xx = 0; xx <= 3 && xx <= p; xx++)
				for (int yy = 0; yy <= 3 && yy <= q; yy++) {

					if (xx + yy == 0 || x + y == xx + yy) {
						continue;
					}

					if (xx % 2 == yy % 2) {
						continue;
					}

					int nx = p - xx + yy;
					if (xx != p && yy != 0) {
						nx--;
					}

					int ny = q - yy + xx;
					if (yy != q && xx != 0) {
						ny--;
					}

					if (nx == 0 || ny == 0) {
						continue;
					}

					if (nx + ny == p + q) {
						continue;
					}

					int val;
					if ((xx == 0 || yy == 0) && (xx + yy) % 2 == 1) {
						val = fastDiff(nx, ny) + 1;
					} else {
						val = fastSame(nx, ny) + 1;
					}

					if (fastSame(p, q) == val) {
						x = xx;
						y = yy;
						break shiiit;
					}
				}

//			System.err.println(p + " " + q + " " + x + " " + y);

			if ((x == 0 || y == 0) && (x + y) % 2 == 1) {
				areSame = false;
			}

			ArrayList<Integer> delS = new ArrayList<>(x);
			ArrayList<Integer> delT = new ArrayList<>(y);

			int ans1 = 0;
			int ans2 = 0;

			for (int i = 0; i < x; i++) {
				int delta = rs.remove(rs.size() - 1);
				ans1 += delta;
				delS.add(delta);
			}

			for (int i = 0; i < y; i++) {
				int delta = rt.remove(rt.size() - 1);
				ans2 += delta;
				delT.add(delta);
			}

			ret.add(ans1);
			ret.add(ans2);

			Collections.reverse(delS);
			Collections.reverse(delT);

			for (int i = 0; i < x; i++) {
				if (i == 0 && !rt.isEmpty()) {
					rt.set(rt.size() - 1, rt.get(rt.size() - 1) + delS.get(i));
				} else {
					rt.add(delS.get(i));
				}
			}

			for (int i = 0; i < y; i++) {
				if (i == 0 && !rs.isEmpty()) {
					rs.set(rs.size() - 1, rs.get(rs.size() - 1) + delT.get(i));
				} else {
					rs.add(delT.get(i));
				}
			}

		}

		while (rs.size() > 1 || rt.size() > 1) {

			int p = rs.size();
			int q = rt.size();

			int x = -1, y = -1;

			shiiit: for (int tp = 1; tp <= 3 && tp <= p; tp += 2)
				for (int tq = 1; tq <= 3 && tq <= q; tq += 2) {

					int newP = p - tp + tq;
					if (tp != p) {
						newP--;
					}

					int newQ = q - tq + tp;
					if (tq != q) {
						newQ--;
					}

					if (newP == 0 || newQ == 0) {
						continue;
					}

					if (newP + newQ == p + q) {
						continue;
					}

					if (fastDiff(p, q) == fastDiff(newP, newQ) + 1) {
						x = tp;
						y = tq;
						break shiiit;
					}
				}

			// System.err.println(x + " " + y);

			ArrayList<Integer> delS = new ArrayList<>(x);
			ArrayList<Integer> delT = new ArrayList<>(y);

			int ans1 = 0;
			int ans2 = 0;

			for (int i = 0; i < x; i++) {
				int delta = rs.remove(rs.size() - 1);
				ans1 += delta;
				delS.add(delta);
			}

			for (int i = 0; i < y; i++) {
				int delta = rt.remove(rt.size() - 1);
				ans2 += delta;
				delT.add(delta);
			}

			ret.add(ans1);
			ret.add(ans2);

			Collections.reverse(delS);
			Collections.reverse(delT);

			for (int i = 0; i < x; i++) {
				if (i == 0 && !rt.isEmpty()) {
					rt.set(rt.size() - 1, rt.get(rt.size() - 1) + delS.get(i));
				} else {
					rt.add(delS.get(i));
				}
			}

			for (int i = 0; i < y; i++) {
				if (i == 0 && !rs.isEmpty()) {
					rs.set(rs.size() - 1, rs.get(rs.size() - 1) + delT.get(i));
				} else {
					rs.add(delT.get(i));
				}
			}

		}

		out.println(ret.size() / 2);
		for (int i = 0; i < ret.size(); i += 2) {
			out.println(ret.get(i) + " " + ret.get(i + 1));
		}
		return ret.size() / 2;
	}

	void submit() {
		String s = nextToken();
		String t = nextToken();

		fast(s, t);
	}

	int fastSame(int x, int y) {
		int ret = (x + y) / 2;
		if ((x + y) % 4 == 1 && (x == 1 || y == 1)) {
			ret++;
		}
		return ret;
	}

	int fastDiff(int x, int y) {
		if (x == 1 && y == 1) {
			return 0;
		}
		int ret;
		if ((x + y) % 4 == 0) {
			ret = (x + y) / 2;
			if (x % 2 == 0) {
				ret--;
			}
		} else if ((x + y) % 4 == 1) {
			ret = (x + y) / 2;
			if (x == 1 || y == 1) {
				ret++;
			}
		} else if ((x + y) % 4 == 2) {
			ret = (x + y) / 2;
			if (x != 1 && x != 2 && y != 1 && y != 2 && x % 2 == 1) {
				ret--;
			}
		} else if ((x + y) % 4 == 3) {
			ret = (x + y) / 2;
		} else {
			throw new AssertionError();
		}
		return ret;
	}

	void test() {
		int[][] dp = new int[100][100];
		dp[1][1] = 0;

		for (int sum = 3; sum < 20; sum++) {
			System.err.println("---------");
			for (int p = 1; sum - p > 0; p++) {

				int q = sum - p;

				dp[p][q] = Integer.MAX_VALUE / 3;

				// for (int tp = 1; tp <= p; tp++) {
				// for (int tq = 1; tq <= q; tq++) {
				for (int tp = 1; tp <= p && tp <= 3; tp += 2) {
					for (int tq = 1; tq <= q && tq <= 3; tq += 2) {

						if (tp % 2 != tq % 2) {
							continue;
						}

						int newP = p - tp + tq;
						if (tp != p && tq != 0) {
							newP--;
						}

						int newQ = q - tq + tp;
						if (tq != q && tp != 0) {
							newQ--;
						}

						if (newP == 0 || newQ == 0) {
							continue;
						}

						if (newP + newQ == p + q) {
							continue;
						}

						// System.err.println(p + " " + q + " --> " + newP + " "
						// + newQ);

						dp[p][q] = Math.min(dp[p][q], dp[newP][newQ] + 1);

						// if (dp[newP][newQ] + 1 == fastAnswer(p, q)) {
						// System.err.println(tp + " " + tq);
						// }

					}
				}

				if (dp[p][q] != fastDiff(p, q)) {
					throw new AssertionError();
				}

				// System.err.println(p + " " + q + " -> " + dp[p][q]);

				// String testP = "";
				// for (int i = 0; i < p; i++) {
				// testP += i % 2 == 0 ? "a" : "b";
				// }
				//
				// String testQ = "";
				// for (int i = 0; i < q; i++) {
				// testQ += i % 2 == 0 ? "b" : "a";
				// }

				// System.err.println("real is " + slow(testP, testQ));
				// if (slow(testP, testQ) != dp[p][q]) {
				// System.err.println("!!!!!!!!");
				// }

			}
		}
	}

	String genRand() {
		int len = rand(1, C);
		char[] buf = new char[len];
		for (int i = 0; i < buf.length; i++) {
			buf[i] = rng.nextBoolean() ? 'a' : 'b';
		}
		return new String(buf);
	}

	void stress() {
		outer: for (int tst = 0;; tst++) {

			String s = genRand();
			String t = genRand();

			String st = s + t;
			if (st.indexOf('a') == -1 || st.indexOf('b') == -1) {
				continue outer;
			}

//			if (s.charAt(0) != t.charAt(0)) {
//				continue outer;
//			}

			if (fast(s, t) != slow(s, t)) {
				System.err.println(s + " " + t);
				System.err.println(fast(s, t));
				System.err.println(slow(s, t));
				throw new AssertionError();
			}
			System.err.println(tst);
		}
	}

	void testSame() {
		int[][] dp = new int[100][100];
		dp[1][1] = Integer.MAX_VALUE / 3;
		for (int sum = 3; sum < 10; sum++) {
			System.err.println("----");
			for (int p = 1; p < sum; p++) {
				int q = sum - p;

				dp[p][q] = Integer.MAX_VALUE / 3;

				for (int x = 0; x <= p; x++) {
					for (int y = 0; y <= q; y++) {

						if (x + y == 0 || x + y == p + q) {
							continue;
						}

						if (x % 2 == y % 2) {
							continue;
						}

						int nx = p - x + y;
						if (x != p && y != 0) {
							nx--;
						}

						int ny = q - y + x;
						if (y != q && x != 0) {
							ny--;
						}

						if (nx == 0 || ny == 0) {
							continue;
						}

						if (nx + ny == sum) {
							continue;
						}

						int val;
						if ((x == 0 || y == 0) && (x + y) % 2 == 1) {
							val = fastDiff(nx, ny) + 1;
						} else {
							val = fastSame(nx, ny) + 1;
						}

						// dp[p][q] = Math.min(dp[p][q], val);

						if (val == fastSame(p, q)) {
							System.err.println(p + " " + q + " USE " + x + " "
									+ y);
						}

					}
				}

				String testP = "";
				for (int i = 0; i < p; i++) {
					testP += i % 2 == 0 ? "a" : "b";
				}

				String testQ = "";
				for (int i = 0; i < q; i++) {
					testQ += i % 2 == 0 ? "a" : "b";
				}

				// System.err.println(p + " " + q + " -> " + dp[p][q]);

				// if (slow(testP, testQ) != dp[p][q]) {
				// System.err.println("!!!!!!!!");
				// System.err.println("real is " + slow(testP, testQ));
				// }

				// if (fastSame(p, q) != dp[p][q]) {
				// throw new AssertionError();
				// }

			}
		}
	}

	void test2() {
		System.err.println(slow("ababa", "ab"));
		System.err.println(fast("ababa", "ab"));
	}

	D() throws IOException {
		is = System.in;
		out = new PrintWriter(System.out);
		 submit();
//		stress();
		// test();
		// test2();
		// testSame();
		out.close();
	}

	static final Random rng = new Random(0);
	static final int C = 7;

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new D();
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