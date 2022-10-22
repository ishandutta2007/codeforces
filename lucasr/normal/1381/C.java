import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.AbstractCollection;
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
		CMastermind solver = new CMastermind();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class CMastermind {
		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			int n = sc.nextInt();
			int x = sc.nextInt();
			int y = sc.nextInt();
			int[] b = sc.nextIntArray(n);
			List<Integer>[] pos = new List[n + 2];
			for (int i = 1; i < pos.length; i++) {
				pos[i] = new ArrayList<>();
			}
			for (int i = 0; i < b.length; i++) {
				int col = b[i];
				pos[col].add(i);
			}
			int[] a = new int[n];
			int none = -1;
			for (int i = 1; i <= n + 1; i++) {
				if (pos[i].isEmpty()) {
					none = i;
					break;
				}
			}
			Arrays.fill(a, none);
			PriorityQueue<Integer> remColors = new PriorityQueue<>((a1, a2) -> Integer.compare(pos[a2].size(), pos[a1].size()));
			for (int i = 1; i < pos.length; i++) {
				if (!pos[i].isEmpty()) remColors.add(i);
			}
			for (int i = 0; i < x; i++) {
				int color = remColors.poll();
				int pp = pos[color].remove(pos[color].size() - 1);
				a[pp] = color;
				if (!pos[color].isEmpty()) {
					remColors.add(color);
				}
			}
			List<Integer> remPos = new ArrayList<>();
			while (!remColors.isEmpty()) {
				int color = remColors.poll();
				remPos.addAll(pos[color]);
			}
			int step = remPos.size() / 2;
			int rem = y - x;
			for (int i = 0; i < remPos.size() && rem > 0; i++) {
				int me = remPos.get(i);
				int to = remPos.get((i + step) % remPos.size());
				if (b[me] != b[to]) {
					a[to] = b[me];
					rem--;
				}
			}
			if (rem > 0) {
				out.println("NO");
			} else {
				out.println("YES");
				for (int i = 0; i < a.length; i++) {
					out.print(a[i] + " ");
				}
				out.println();
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
}