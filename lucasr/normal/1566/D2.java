import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Map;
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
		D2SeatingArrangementsHardVersion solver = new D2SeatingArrangementsHardVersion();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class D2SeatingArrangementsHardVersion {
		public static MyScanner sc;
		public static PrintWriter out;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			D2SeatingArrangementsHardVersion.sc = sc;
			D2SeatingArrangementsHardVersion.out = out;
			int n = sc.nextInt();
			int m = sc.nextInt();
			Map<Integer, IntArray> pos = new HashMap<>();
			int[] all = new int[n * m];
			int idx = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					int s = sc.nextInt();
					all[idx++] = s;
				}
			}
			int[] sorted = all.clone();
			Arrays.sort(sorted);
			for (int i = 0; i < n; i++) {
				for (int j = m - 1; j >= 0; j--) {
					idx = i * m + j;
					IntArray positions = pos.computeIfAbsent(sorted[idx], k -> new IntArray());
					positions.add(idx);
				}
			}
			int ans = 0;
			Map<Integer, Integer> where = new HashMap<>();
			boolean[][] used = new boolean[n][m];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					idx = i * m + j;
					int pp = where.getOrDefault(all[idx], 0);
					where.put(all[idx], pp + 1);
					int toIdx = pos.get(all[idx]).get(pp);
					int toI = toIdx / m;
					int toJ = toIdx % m;
					for (int k = 0; k < toJ; k++) {
						if (used[toI][k]) ans++;
					}
					used[toI][toJ] = true;
				}
			}
			out.println(ans);
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

		public int[] toArray() {
			return Arrays.copyOf(arr, size);
		}

		public String toString() {
			return "IntArray " + Arrays.toString(toArray());
		}

	}
}