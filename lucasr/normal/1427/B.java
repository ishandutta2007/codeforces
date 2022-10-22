import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Collections;
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
		BChessCheater solver = new BChessCheater();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class BChessCheater {
		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			int n = sc.nextInt();
			int k = sc.nextInt();
			char[] vals = sc.next().toCharArray();
			int score = 0;
			for (int i = 0; i < n; i++) {
				if (vals[i] == 'W') {
					score++;
					if (i > 0 && vals[i - 1] == 'W') score++;
				}
			}
			int simple = 0;
			for (int i = 0; i < n && vals[i] == 'L'; i++) simple++;
			if (simple < n) {
				for (int i = n - 1; i >= 0 && vals[i] == 'L'; i--) {
					simple++;
				}
			}
			if (simple == n) {
				out.println(Math.max(0, 2 * k - 1));
				return;
			}
			List<Integer> values = new ArrayList<>();
			boolean found = false;
			int acum = 0;
			for (int i = 0; i < n; i++) {
				if (vals[i] == 'W') {
					found = true;
					if (acum > 0) values.add(acum);
					acum = 0;
				} else if (found) {
					acum++;
				}
			}
			Collections.sort(values);
			int idx = 0;
			while (k > 0 && idx < values.size()) {
				int cur = values.get(idx++);
				int min = Math.min(k, cur);
				k -= min;
				score += 2 * min;
				if (min >= cur) score++;
			}
			int cur = simple;
			int min = Math.min(k, cur);
			k -= min;
			score += 2 * min;
			out.println(score);
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