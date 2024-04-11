import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
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
		GSwitchAndFlip solver = new GSwitchAndFlip();
		solver.solve(1, in, out);
		out.close();
	}

	static class GSwitchAndFlip {
		public static MyScanner sc;
		public static PrintWriter out;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			GSwitchAndFlip.sc = sc;
			GSwitchAndFlip.out = out;
			int n = sc.nextInt();
			int[] vals = sc.nextIntArray(n);
			for (int i = 0; i < n; i++) {
				vals[i]--;
			}
			boolean[] vis = new boolean[n];
			List<IntArray> perm = new ArrayList<>();
			for (int i = 0; i < n; i++)
				if (!vis[i]) {
					vis[i] = true;
					IntArray tmp = new IntArray();
					tmp.add(i);
					int cur = vals[i];
					while (!vis[cur]) {
						vis[cur] = true;
						tmp.add(cur);
						cur = vals[cur];
					}
					perm.add(tmp);
				}
			System.err.println(testNumber + " => " + perm);
			List<int[]> res = new ArrayList<>();
			for (int i = 0; i + 1 < perm.size(); i += 2) {
				doIt(perm.get(i), perm.get(i + 1), res);
			}
			if (perm.size() % 2 == 1) {
				IntArray tmp = perm.get(perm.size() - 1);
				if (tmp.size() == 2) {
					IntArray tmp2 = new IntArray();
					tmp2.add(perm.get(0).get(0));
					doIt(tmp, tmp2, res);
				} else {
					doIt(tmp, res);
				}
			}
			out.println(res.size());
			for (int[] re : res) {
				out.println((re[0] + 1) + " " + (re[1] + 1));
			}
		}

		void doIt(IntArray p1, IntArray p2, List<int[]> res) {
			int size1 = p1.size();
			int size2 = p2.size();
			if (size1 == 1 && size2 == 1) return;
			res.add(new int[]{p2.get(0), p1.get(size1 - 1)});
			for (int i = 0; i < size1 - 1; i++) {
				res.add(new int[]{p1.get(i), p2.get(0)});
			}
			for (int i = 1; i < size2; i++) {
				res.add(new int[]{p1.get(size1 - 1), p2.get(i)});
			}
			res.add(new int[]{p2.get(0), p1.get(size1 - 1)});
		}

		void doIt(IntArray p, List<int[]> res) {
			int size = p.size();
			if (size == 1) return;
			res.add(new int[]{p.get(0), p.get(size - 1)});
			res.add(new int[]{p.get(0), p.get(1)});
			res.add(new int[]{p.get(1), p.get(size - 1)});
			for (int i = 2; i < size; i++) {
				res.add(new int[]{p.get(0), p.get(i)});
			}
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
}