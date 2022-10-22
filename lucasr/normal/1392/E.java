import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class E {
	static final PrintWriter out = new PrintWriter(System.out);
	static final MyScanner sc = new MyScanner();

	public static void main(String[] args) {
		int N = sc.nextInt();
		long[][] table = make(N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				out.print(table[i][j] + " ");
			}
			out.println();
		}
		out.flush();
		int q = sc.nextInt();

		for (int i = 0; i < q; i++) {
			long target = sc.nextLong();
			print(target, table);
		}

	}

	static long[][] make(int n) {
		long[][] ret = new long[n][n];

		for (int i = 1; i < n; i++) {
			for (int j = n - 2; j >= 0; j--) {
				long max = 0;
				for (int k = 0; k < i; k++) {
					max += ret[k][0];
				}
				for (int k = 1; k <= j + 1; k++) {
					max += ret[i-1][k];
				}
				for (int k = j + 1; k < n; k++) {
					max += ret[i][k];
				}
				long min = 0;
				for (int k = 0; k <= i; k++) {
					min += ret[k][j];
				}
				for (int k = j; k < n; k++) {
					min += ret[i][k];
				}
				ret[i][j] = max + 1 - min;
			}
		}

		return ret;
	}

	static void print(long sum, long[][] table) {
		int n = table[0].length;

		List<int[]> cells = new ArrayList<>();
		int i = n - 1, j = n - 1;
		while (i > 0 || j > 0) {
			cells.add(new int[] {i, j});
			sum -= table[i][j];
			if (i > 0 && maxUpTo(table, i - 1, j) >= sum) {
				i--;
			} else {
				j--;
			}
		}
		cells.add(new int[] {i, j});
		Collections.reverse(cells);
		for (int[] cell : cells) {
			print(cell[0], cell[1]);
		}
		out.flush();
	}

	static void print(int i, int j) {
		out.println((i + 1) + " " + (j + 1));
	}

	static long maxUpTo(long[][] table, int i, int j) {
		int n = table[0].length;
		long ret = 0;

		for (int k = 0; k < i; k++) {
			ret += table[k][0];
		}
		for (int k = 0; k <= j; k++) {
			ret += table[i][k];
		}

		return ret;
	}

	static class MyScanner {
		private BufferedReader br;
		private StringTokenizer tokenizer;
		
		public MyScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
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
		
		public long nextLong() {
			return Long.parseLong(next());
		}
	}
}