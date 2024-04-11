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
		DLostTree solver = new DLostTree();
		solver.solve(1, in, out);
		out.close();
	}

	static class DLostTree {
		public static MyScanner sc;
		public static PrintWriter out;
		int n;
		int[] parent;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			DLostTree.sc = sc;
			DLostTree.out = out;
			n = sc.nextInt();
			parent = new int[n];
			Arrays.fill(parent, -1);
			int[] dist = query(0);
			int impar = 0, par = 0;
			for (int i = 1; i < n; i++) {
				if (dist[i] == 1) parent[i] = 0;
				if (dist[i] % 2 == 0) par++;
				else impar++;
			}
			boolean doImp = impar <= par;
			for (int i = 1; i < n; i++)
				if (doImp && dist[i] % 2 == 1 || !doImp && dist[i] % 2 == 0) {
					int[] cur = query(i);
					for (int j = 0; j < n; j++) {
						if (cur[j] == 1) {
							if (dist[j] > dist[i]) parent[j] = i;
							else parent[i] = j;
						}
					}
				}
			guess();
		}

		int[] query(int node) {
			node++;
			out.println("? " + node);
			out.flush();
			return sc.nextIntArray(n);
		}

		void guess() {
			out.println("!");
			for (int i = 0; i < n; i++) {
				if (parent[i] != -1) {
					out.println((parent[i] + 1) + " " + (i + 1));
				}
			}
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

		public int[] nextIntArray(int n) {
			int[] ret = new int[n];
			for (int i = 0; i < n; i++) {
				ret[i] = nextInt();
			}
			return ret;
		}

	}
}