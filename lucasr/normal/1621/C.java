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
		CHiddenPermutations solver = new CHiddenPermutations();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class CHiddenPermutations {
		public static MyScanner sc;
		public static PrintWriter out;
		static int ops;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			CHiddenPermutations.sc = sc;
			CHiddenPermutations.out = out;
			int n = sc.nextInt();
			int[] p = new int[n];
			Arrays.fill(p, -1);
			ops = -1;
			get(0);
			int rem = n;
			for (int i = 0; i < p.length; i++) {
				if (p[i] == -1) {
					if (rem == 1) {
						boolean[] got = new boolean[n];
						for (int j = 0; j < n; j++)
							if (i != j) {
								got[p[j]] = true;
							}
						for (int j = 0; j < n; j++) {
							if (!got[j]) {
								p[i] = j;
								break;
							}
						}
						break;
					}
					IntArray elems = new IntArray();
					int first = get(i);
					int tmp;
					elems.add(first);
					while ((tmp = get(i)) != first) {
						elems.add(tmp);
					}
					int size = elems.size();
					for (int j = 0; j < size; j++) {
						p[elems.get((j) % size)] = elems.get((j + 1) % size);
					}
					rem -= size;
				}
			}
			guess(p);
		}

		static int get(int pos) {
			out.println("? " + (pos + 1));
			out.flush();
			ops++;
			return sc.nextInt() - 1;
		}

		static void guess(int[] p) {
			out.print("!");
			for (int i = 0; i < p.length; i++) {
				out.print(" " + (p[i] + 1));
			}
			out.println();
			out.flush();
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