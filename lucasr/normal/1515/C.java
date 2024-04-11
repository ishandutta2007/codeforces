import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.util.Comparator;
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
		CPhoenixAndTowers solver = new CPhoenixAndTowers();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class CPhoenixAndTowers {
		public static MyScanner sc;
		public static PrintWriter out;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			CPhoenixAndTowers.sc = sc;
			CPhoenixAndTowers.out = out;
			int n = sc.nextInt();
			int m = sc.nextInt();
			int x = sc.nextInt();
			PriorityQueue<int[]> queue = new PriorityQueue<>(Comparator.comparingInt(k -> k[0]));
			for (int i = 0; i < m; i++) {
				queue.add(new int[]{0, i + 1});
			}
			out.println("YES");
			for (int i = 0; i < n; i++) {
				int cur = sc.nextInt();
				int[] me = queue.poll();
				out.print(me[1] + " ");
				me[0] += cur;
				queue.add(me);
			}
			out.println();
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