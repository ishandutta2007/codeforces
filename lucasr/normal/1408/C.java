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
		CDiscreteAcceleration solver = new CDiscreteAcceleration();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class CDiscreteAcceleration {
		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			int n = sc.nextInt();
			int l = sc.nextInt();
			int[] p = new int[n + 2];
			p[n + 1] = l;
			for (int i = 1; i <= n; i++) {
				p[i] = sc.nextInt();
			}
			int[] clone = p.clone();
			Utils.reverse(clone);
			double[] first = times(p);
			double[] second = times(clone);
			Utils.reverse(second);
			double ret = 0;
			for (int i = 0; i < n + 1; i++) {
				if (first[i] <= second[i] && first[i + 1] >= second[i + 1]) {
					double moment = Math.max(first[i], second[i + 1]);
					double dist = (p[i + 1] - p[i]);
					if (first[i] < second[i + 1]) {
						double vel = i + 1;
						dist -= vel * Math.abs(first[i] - second[i + 1]);
					} else if (first[i] > second[i + 1]) {
						double vel = n + 1 - i;
						dist -= vel * Math.abs(first[i] - second[i + 1]);
					}
					ret = moment + dist * 1.0 / (n + 2);
					break;
				}
			}
			out.println(String.format("%.15f", ret));
		}

		static double[] times(int[] pos) {
			double[] ret = new double[pos.length];
			ret[0] = 0;
			double curV = 1;
			for (int i = 1; i < pos.length; i++) {
				ret[i] = ret[i - 1] + Math.abs(pos[i] - pos[i - 1]) / curV;
				curV++;
			}
			return ret;
		}

	}

	static class Utils {
		public static void reverse(int[] array) {
			int from = 0, to = array.length - 1;
			while (from < to) {
				int tmp = array[from];
				array[from] = array[to];
				array[to] = tmp;
				from++;
				to--;
			}
		}

		public static void reverse(double[] array) {
			int from = 0, to = array.length - 1;
			while (from < to) {
				double tmp = array[from];
				array[from] = array[to];
				array[to] = tmp;
				from++;
				to--;
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