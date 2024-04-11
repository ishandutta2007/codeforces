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
		FStrangeInstructions solver = new FStrangeInstructions();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class FStrangeInstructions {
		public static MyScanner sc;
		public static PrintWriter out;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			FStrangeInstructions.sc = sc;
			FStrangeInstructions.out = out;
			int n = sc.nextInt();
			long a = sc.nextInt();
			long b = sc.nextInt();
			long c = sc.nextInt();
			char[] vals = sc.next().toCharArray();
			int tot1 = 0, extra1 = 0;
			List<Integer> mid0 = new ArrayList<>();
			int singleMid0 = 0, leftBorder = 0, rightBorder = 0;
			for (leftBorder = 0; leftBorder < n; leftBorder++) {
				if (vals[leftBorder] != '0') break;
			}
			if (leftBorder == n) {
				out.println(n > 1 ? a : 0);
				return;
			}
			int from = leftBorder;
			for (rightBorder = 0; rightBorder < n; rightBorder++) {
				if (vals[n - rightBorder - 1] != '0') break;
			}
			int to = n - rightBorder;
			int tmp = leftBorder;
			int border = 0, extraBorder = 0;
			if (leftBorder > 0) {
				border++;
				extraBorder += leftBorder - 1;
			}
			if (rightBorder > 0) {
				border++;
				extraBorder += rightBorder - 1;
			}
			int got = 1;
			char last = '1';
			for (int i = from + 1; i < to; i++) {
				if (vals[i] == last) {
					got++;
				} else {
					if (last == '1') {
						tot1++;
						extra1 += got - 1;
					} else {
						if (got > 1) {
							mid0.add(got - 1);
						} else {
							singleMid0++;
						}
					}
					got = 1;
				}
				last = vals[i];
			}
			tot1++;
			extra1 += got - 1;
			long ans = 0;
			Collections.sort(mid0);
			int mid0Idx = 0;
			while (extra1 > 0 && mid0Idx < mid0.size()) {
				int val = mid0.get(mid0Idx);
				int min = Math.min(extra1, val);
				extra1 -= min;
				mid0.set(mid0Idx, val - min);
				ans += (a + b) * min;
				if (val - min == 0) {
					mid0Idx++;
					singleMid0++;
				}
			}
			if (extra1 > 0 && extraBorder > 0) {
				int min = Math.min(extra1, extraBorder);
				extra1 -= min;
				extraBorder -= min;
				ans += (a + b) * min;
			}
			if (extra1 == 0) {
				if (mid0Idx < mid0.size() || extraBorder > 0) {
					ans += a;
				}
				ans += Math.max(0, (b - c) * singleMid0);
			} else {
				if (mid0Idx < mid0.size() || extraBorder > 0) {
					throw new RuntimeException();
				}
				ans += b;
				extra1--;
				if (b > c) {
					ans += (b - c) * singleMid0;
					ans += (b - c) * Math.min(border, extra1);
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
}