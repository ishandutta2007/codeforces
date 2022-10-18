import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		String[] ans = { "+------------------------+",
				"|#.#.#.#.#.#.#.#.#.#.#.|D|)", "|#.#.#.#.#.#.#.#.#.#.#.|.|",
				"|#.......................|", "|#.#.#.#.#.#.#.#.#.#.#.|.|)",
				"+------------------------+" };

		char[][] tmp = new char[ans.length][];
		for (int i = 0; i < ans.length; i++) {
			tmp[i] = ans[i].toCharArray();
		}
		int n = nextInt();
		outer: for (int i = 0; i < n; i++) {
			for (int col = 0;; col++) {
				for (int row = 0; row < tmp.length; row++) {
					if (tmp[row][col] == '#') {
						tmp[row][col] = 'O';
						continue outer;
					}
				}
			}
		}

		for (int i = 0; i < 6; i++) {
			out.println(new String(tmp[i]));
		}
	}

	A() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new A();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return null;
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			eof = true;
			return null;
		}
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}