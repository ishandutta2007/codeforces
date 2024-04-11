import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
		E1JokingEasyVersion solver = new E1JokingEasyVersion();
		solver.solve(1, in, out);
		out.close();
	}

	static class E1JokingEasyVersion {
		public static MyScanner sc;
		public static PrintWriter out;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			E1JokingEasyVersion.sc = sc;
			E1JokingEasyVersion.out = out;
			int n = getN();
			boolean[] possible = new boolean[n + 1];
			Arrays.fill(possible, true);
			int rem = n;
			IntArray[] pos = new IntArray[4];
			for (int i = 0; i < 4; i++) {
				pos[i] = new IntArray();
			}
			while (rem >= 4) {
				System.err.println("posible: " + Arrays.toString(possible));
				calc(n, possible, pos);
				boolean[] valid = new boolean[4];
				if (inSet(pos[0], pos[1])) {
					valid[0] = valid[1] = true;
				} else {
					valid[2] = valid[3] = true;
				}
				if (inSet(pos[0], pos[2])) {
					valid[0] = valid[2] = true;
				} else {
					valid[1] = valid[3] = true;
				}
				for (int i = 0; i < 4; i++) {
					if (!valid[i]) {
						for (int j = 0; j < pos[i].size(); j++) {
							rem--;
							possible[pos[i].get(j)] = false;
						}
					}
				}
			}
			calc(n, possible, pos);
			if (rem == 3) {
				IntArray empty = pos[3];
				if (inSet(pos[0], empty)) {
					if (guess(pos[0].first())) return;
					if (inSet(pos[1], empty)) {
						if (!guess(pos[1].first())) throw new RuntimeException();
					} else {
						if (!guess(pos[2].first())) throw new RuntimeException();
					}
					return;
				} else {
					if (inSet(pos[0], empty)) {
						if (guess(pos[0].first())) return;
						if (inSet(pos[1], empty)) {
							if (!guess(pos[1].first())) throw new RuntimeException();
						} else {
							if (!guess(pos[2].first())) throw new RuntimeException();
						}
						return;
					} else {
						rem--;
						possible[pos[0].first()] = false;
					}
				}
			}
			for (int i = 1; i <= n; i++) {
				if (possible[i]) {
					if (guess(i)) return;
				}
			}
		}

		private void calc(int n, boolean[] possible, IntArray[] pos) {
			for (int i = 0; i < 4; i++) {
				pos[i].clear();
			}
			int cur = 0;
			for (int i = 1; i <= n; i++) {
				if (possible[i]) {
					pos[cur].add(i);
					cur++;
					cur %= 4;
				}
			}
		}

		static boolean inSet(IntArray a, IntArray b) {
			out.print("? " + (a.size() + b.size()));
			for (int i = 0; i < a.size(); i++) {
				out.print(" " + a.get(i));
			}
			for (int i = 0; i < b.size(); i++) {
				out.print(" " + b.get(i));
			}
			out.println();
			out.flush();
			return "YES".equals(sc.next());
		}

		static boolean guess(int val) {
			out.println("! " + val);
			out.flush();
			return ":)".equals(sc.next());
		}

		static int getN() {
			return sc.nextInt();
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

		public int first() {
			return arr[0];
		}

		public void clear() {
			size = 0;
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
}