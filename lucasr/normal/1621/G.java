import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
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
		GWeightedIncreasingSubsequences solver = new GWeightedIncreasingSubsequences();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class GWeightedIncreasingSubsequences {
		public static MyScanner sc;
		public static PrintWriter out;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			MathLib.MOD = 1000000007;
			GWeightedIncreasingSubsequences.sc = sc;
			GWeightedIncreasingSubsequences.out = out;
			int n = sc.nextInt();
			int[] vals = sc.nextIntArray(n);
			long ans = getAns(vals);
			out.println(ans);
		}

		static long getAns(int[] vals) {
			int n = vals.length;
			boolean[] border = new boolean[n];
			IntArray borders = new IntArray();
			int last = -1;
			for (int i = n - 1; i >= 0; i--) {
				if (last == -1 || vals[i] >= vals[last]) {
					border[i] = true;
					last = i;
					borders.add(i);
				}
			}
			borders.reverse();
			List<Integer> ids = new ArrayList<>();
			for (int i = 0; i < n; i++)
				if (!border[i]) {
					ids.add(i);
				}
			long[] before = new long[n];
			ids.sort((a, b) -> {
				int cmp = Integer.compare(vals[a], vals[b]);
				if (cmp != 0) return cmp;
				return Integer.compare(b, a);
			});
			SumSegmentTree bSt = new SumSegmentTree(n);
			for (int i = 0; i < ids.size(); i++) {
				int meIdx = ids.get(i);
				long sum = (bSt.getSum(0, meIdx) + 1) % MathLib.MOD;
				bSt.add(meIdx, sum);
				before[meIdx] = sum;
			}
			ids.sort((a, b) -> {
				int cmp = Integer.compare(vals[b], vals[a]);
				if (cmp != 0) return cmp;
				return Integer.compare(a, b);
			});
			long ans = 0;
			SumSegmentTree aSt = new SumSegmentTree(n);
			int borderIdx = 0;
			IntArray tmpArr = new IntArray();
			for (int i = 0; i < ids.size(); i++) {
				int meIdx = ids.get(i);
				int meVal = vals[meIdx];
				while (borderIdx + 1 < borders.size() && vals[borders.get(borderIdx + 1)] > meVal) {
					int bIdx = borders.get(borderIdx);
					aSt.add(bIdx, 1);
					if (tmpArr.size() > 0) {
						for (int j = 0; j < tmpArr.size(); j++) {
							int curIdx = tmpArr.get(j);
							aSt.set(curIdx, 0);
						}
						for (int j = 0; j < tmpArr.size(); j++) {
							int curIdx = tmpArr.get(j);
							long sum = (aSt.getSum(curIdx + 1, n) + 1) % MathLib.MOD;
							aSt.set(curIdx, sum);
						}
						tmpArr.clear();
					}
					borderIdx++;
				}
				tmpArr.add(meIdx);
				long sum = (aSt.getSum(meIdx + 1, n) + 1) % MathLib.MOD;
				aSt.add(meIdx, sum);
				ans += (before[meIdx] * sum) % MathLib.MOD;
			}
			ans %= MathLib.MOD;
			return ans;
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

	static class SumSegmentTree {
		public int size;
		public long[] values;

		public SumSegmentTree(int capacity) {
			size = 1;
			while (size < capacity) size *= 2;
			values = new long[2 * size];
		}

		public void add(int position, long value) {
			add(position, 1, 0, size, value);
		}

		public void set(int position, long value) {
			long old = getSum(position, position + 1);
			add(position, value - old);
		}

		private void add(int position, int idx, int idxFrom, int idxTo, long value) {
			if (idxTo <= position || position < idxFrom) return;
			if (position == idxFrom && idxTo == position + 1) {
				values[idx] += value;
				return;
			}
			int med = (idxFrom + idxTo) / 2;
			add(position, 2 * idx, idxFrom, med, value);
			add(position, 2 * idx + 1, med, idxTo, value);
			values[idx] = values[2 * idx] + values[2 * idx + 1];
		}

		public long getSum(int fromInclusive, int toExclusive) {
			return getSum(fromInclusive, toExclusive, 1, 0, size);
		}

		private long getSum(int fromInclusive, int toExclusive, int idx, int idxFrom, int idxTo) {
			if (idxTo <= fromInclusive || toExclusive <= idxFrom) return 0;
			if (fromInclusive <= idxFrom && idxTo <= toExclusive) {
				return values[idx];
			}
			// Previous conditions => not a leaf
			int med = (idxFrom + idxTo) / 2;
			long ret = getSum(fromInclusive, toExclusive, 2 * idx, idxFrom, med);
			ret += getSum(fromInclusive, toExclusive, 2 * idx + 1, med, idxTo);
			return ret;
		}

		private void print(StringBuilder sb, int fromInclusive, int toExclusive, int idx, int idxFrom, int idxTo) {
			if (idxTo <= fromInclusive || toExclusive <= idxFrom) return;
			if (idxTo == idxFrom + 1) {
				sb.append(values[idx] + " ");
				return;
			}
			// Previous conditions => not a leaf
			int med = (idxFrom + idxTo) / 2;
			print(sb, fromInclusive, toExclusive, 2 * idx, idxFrom, med);
			print(sb, fromInclusive, toExclusive, 2 * idx + 1, med, idxTo);
		}

		public String toString() {
			StringBuilder sb = new StringBuilder("SumSegmentTree{} => ");
			print(sb, 0, size, 1, 0, size);
			return sb.toString();
		}

	}

	static class MathLib {
		public static long MOD = 1000000007;

	}

	static class IntArray {
		int[] arr;
		int size;

		public IntArray() {
			arr = new int[4];
		}

		public void add(int val) {
			if (size == arr.length) {
				arr = Arrays.copyOf(arr, 2 * arr.length);
			}
			arr[size++] = val;
		}

		public int get(int pos) {
			return arr[pos];
		}

		public void clear() {
			size = 0;
		}

		public int size() {
			return size;
		}

		public void reverse() {
			ArrayUtils.reverse(arr, 0, size - 1);
		}

		public int[] toArray() {
			return Arrays.copyOf(arr, size);
		}

		public String toString() {
			return "IntArray " + Arrays.toString(toArray());
		}

	}

	static class ArrayUtils {
		public static void reverse(int[] array, int from, int to) {
			while (from < to) {
				int tmp = array[from];
				array[from] = array[to];
				array[to] = tmp;
				from++;
				to--;
			}
		}

	}
}