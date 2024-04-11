import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
		AColourTheFlag solver = new AColourTheFlag();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class AColourTheFlag {
		public static MyScanner sc;
		public static PrintWriter out;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			AColourTheFlag.sc = sc;
			AColourTheFlag.out = out;
			int r = sc.nextInt();
			int c = sc.nextInt();
			char[][] table = new char[r][];
			for (int i = 0; i < r; i++) {
				table[i] = sc.next().toCharArray();
			}
			boolean can = true;
			char first = 'R';
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (table[i][j] != '.') {
						first = (i + j) % 2 == 0 ? table[i][j] : other(table[i][j]);
					}
				}
			}
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					char me = (i + j) % 2 == 0 ? first : other(first);
					if (table[i][j] == '.') {
						table[i][j] = me;
					}
					if (table[i][j] != me) can = false;
				}
			}
			out.println(can ? "YES" : "NO");
			if (can) {
				for (int i = 0; i < r; i++) {
					out.println(new String(table[i]));
				}
			}
		}

		static char other(char c) {
			return c == 'R' ? 'W' : 'R';
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