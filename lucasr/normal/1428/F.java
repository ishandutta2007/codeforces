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
		FFruitSequences solver = new FFruitSequences();
		solver.solve(1, in, out);
		out.close();
	}

	static class FFruitSequences {
		int n;
		boolean[] ok;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			n = sc.nextInt();
			char[] vals = sc.next().toCharArray();
			ok = new boolean[n];
			for (int i = 0; i < n; i++) {
				ok[i] = vals[i] == '1';
			}
			out.println(getFreqs(0, n));
		}

		long getFreqs(int from, int to) {
			if (to - from <= 1) {
				return ok[from] ? 1 : 0;
			}
			long ans = 0;
			int med = (from + to) / 2;
			ans += getFreqs(from, med);
			ans += getFreqs(med, to);
			int maxBeg = 0, maxEnd = 0;
			for (int i = med; i < to; i++) {
				if (ok[i]) maxBeg++;
				else break;
			}
			for (int i = med - 1; i >= from; i--) {
				if (ok[i]) maxEnd++;
				else break;
			}
			long[] fRight = freqsFrom(med, to);
			long[] fLeft = freqsTo(from, med);
			long rSum = (maxBeg * (long) (maxBeg + 1)) / 2;
			long lSum = (maxEnd * (long) (maxEnd + 1)) / 2;
			ans -= rSum * maxEnd + maxBeg * lSum;
			for (int i = 0; i < fRight.length; i++) {
				long ff = Math.max(i, Math.min(i + 1, maxBeg + 1));
				long tt = Math.max(i, Math.min(i + maxEnd, maxBeg + maxEnd));
				ans += fRight[i] * getSum(ff, tt, maxEnd);
			}
			for (int i = 0; i < fLeft.length; i++) {
				long ff = Math.max(i, Math.min(i + 1, maxEnd + 1));
				long tt = Math.max(i, Math.min(i + maxBeg, maxEnd + maxBeg));
				ans += fLeft[i] * getSum(ff, tt, maxBeg);
			}
			for (int i = 1; i <= maxBeg; i++) {
				fRight[i]--;
			}
			for (int i = 1; i <= maxEnd; i++) {
				fLeft[i]--;
			}
			long[] acumR = acum(fRight);
			long[] acumL = acum(fLeft);
			for (int i = 0; i < Math.max(fLeft.length, fRight.length); i++) {
				long real = Math.max(i, maxBeg + maxEnd);
				long tmp = getM(acumR, i) * get(fLeft, i) + getM(acumL, i) * get(fRight, i);
				tmp -= get(fRight, i) * get(fLeft, i);
				tmp *= real;
				ans += tmp;
			}
			return ans;
		}

		long get(long[] arr, int index) {
			return index < arr.length ? arr[index] : 0;
		}

		long getM(long[] arr, int index) {
			return index < arr.length ? arr[index] : arr[arr.length - 1];
		}

		long[] acum(long[] tmp) {
			long[] ret = new long[tmp.length];
			ret[0] = tmp[0];
			for (int i = 1; i < tmp.length; i++) {
				ret[i] = ret[i - 1] + tmp[i];
			}
			return ret;
		}

		long getSum(long from, long to, long cant) {
			long tmp1 = (to * (to + 1)) / 2;
			long tmp2 = (from * (from - 1)) / 2;
			long ans = tmp1 - tmp2;
			long got = to - from + 1;
			cant -= got;
			ans += from * cant;
			return ans;
		}

		int getMax(int from, int to) {
			int cur = 0, max = 0;
			for (int i = from; i < to; i++) {
				if (ok[i]) {
					cur++;
					max = Math.max(max, cur);
				} else {
					cur = 0;
				}
			}
			return max;
		}

		long[] freqsFrom(int from, int to) {
			long[] ret = new long[getMax(from, to) + 1];

			int cur = 0, max = 0;
			for (int i = from; i < to; i++) {
				if (ok[i]) {
					cur++;
					max = Math.max(max, cur);
				} else {
					cur = 0;
				}
				ret[max]++;
			}
			return ret;
		}

		long[] freqsTo(int from, int to) {
			long[] ret = new long[getMax(from, to) + 1];

			int cur = 0, max = 0;
			for (int i = to - 1; i >= from; i--) {
				if (ok[i]) {
					cur++;
					max = Math.max(max, cur);
				} else {
					cur = 0;
				}
				ret[max]++;
			}
			return ret;
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