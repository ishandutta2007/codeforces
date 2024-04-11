import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
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
		CContinuousCity solver = new CContinuousCity();
		solver.solve(1, in, out);
		out.close();
	}

	static class CContinuousCity {
		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			int L = sc.nextInt();
			int R = sc.nextInt();
			int k = R - L + 1;
			int total = Integer.numberOfTrailingZeros(Integer.highestOneBit(k - 1));
			if (total == 32) total = 0;
			total += 3;
			List<int[]> edges = new ArrayList<>();
			for (int i = total - 1; i > 1; i--) {
				edges.add(new int[]{i, total, 1});
				for (int j = 1; i < total - j; j++) {
					edges.add(new int[]{i, total - j, 1 << (j - 1)});
				}
			}
			int cur = k, pot = total >= 3 ? (1 << (total - 3)) : 1;
			for (int j = 2; j < total; j++) {
				if (pot < cur) {
					edges.add(new int[]{1, j, cur - pot});
					cur -= pot;
				}
				pot /= 2;
			}
			if (cur != 1) throw new RuntimeException();
			edges.add(new int[]{1, total, 1});
			if (L > 1) {
				edges.add(new int[]{total, total + 1, L - 1});
				total++;
			}
			out.println("YES");
			out.println(total + " " + edges.size());
			for (int[] edge : edges) {
				out.println(edge[0] + " " + edge[1] + " " + edge[2]);
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

	}
}