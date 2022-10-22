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
		DPermutationGraph solver = new DPermutationGraph();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class DPermutationGraph {
		public static MyScanner sc;
		public static PrintWriter out;
		MinMaxSegmentTree st;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			DPermutationGraph.sc = sc;
			DPermutationGraph.out = out;
			int n = sc.nextInt();
			int[] p = sc.nextIntArray(n);
			st = new MinMaxSegmentTree(n);
			for (int i = 0; i < n; i++) {
				st.set(i, p[i]);
			}
			out.println(calc(0, n - 1));
		}

		int calc(int from, int to) {
			if (from == to) return 0;
			int p1 = st.getMinPos(from, to + 1);
			int p2 = st.getMaxPos(from, to + 1);
			int min = Math.min(p1, p2);
			int max = Math.max(p1, p2);
			return 1 + calc(from, min) + calc(max, to);
		}

	}

	static class MinMaxSegmentTree {
		public int size;
		public long[] values;
		public int[] minPos;
		public int[] maxPos;

		public MinMaxSegmentTree(int capacity) {
			size = 1;
			while (size < capacity) size *= 2;
			values = new long[size];
			minPos = new int[2 * size];
			maxPos = new int[2 * size];
			fill(1, 0, size);
		}

		private void fill(int idx, int idxFrom, int idxTo) {
			minPos[idx] = idxFrom;
			maxPos[idx] = idxFrom;
			if (idxFrom + 1 < idxTo) {
				int med = (idxFrom + idxTo) / 2;
				fill(2 * idx, idxFrom, med);
				fill(2 * idx + 1, med, idxTo);
			}
		}

		public void set(int position, long value) {
			add(position, value - values[position]);
		}

		public void add(int position, long value) {
			add(position, 1, 0, size, value);
		}

		private int combineMin(int pos1, int pos2) {
			if (pos1 == -1) return pos2;
			if (pos2 == -1) return pos1;
			return values[pos1] < values[pos2] ? pos1 : pos2; // rightmost (if < )
		}

		private int combineMax(int pos1, int pos2) {
			if (pos1 == -1) return pos2;
			if (pos2 == -1) return pos1;
			return values[pos1] > values[pos2] ? pos1 : pos2;
		}

		private void add(int position, int idx, int idxFrom, int idxTo, long value) {
			if (idxTo <= position || position < idxFrom) return;
			if (position == idxFrom && idxTo == position + 1) {
				values[position] += value;
				return;
			}
			int med = (idxFrom + idxTo) / 2;
			add(position, 2 * idx, idxFrom, med, value);
			add(position, 2 * idx + 1, med, idxTo, value);
			minPos[idx] = combineMin(minPos[2 * idx], minPos[2 * idx + 1]);
			maxPos[idx] = combineMax(maxPos[2 * idx], maxPos[2 * idx + 1]);
		}

		public int getMinPos(int fromInclusive, int toExclusive) {
			return getMinPos(fromInclusive, toExclusive, 1, 0, size);
		}

		private int getMinPos(int fromInclusive, int toExclusive, int idx, int idxFrom, int idxTo) {
			if (idxTo <= fromInclusive || toExclusive <= idxFrom) return -1;
			if (fromInclusive <= idxFrom && idxTo <= toExclusive) {
				return minPos[idx];
			}
			// Previous conditions => not a leaf
			int med = (idxFrom + idxTo) / 2;
			int ret = getMinPos(fromInclusive, toExclusive, 2 * idx, idxFrom, med);
			return combineMin(ret, getMinPos(fromInclusive, toExclusive, 2 * idx + 1, med, idxTo));
		}

		public int getMaxPos(int fromInclusive, int toExclusive) {
			return getMaxPos(fromInclusive, toExclusive, 1, 0, size);
		}

		private int getMaxPos(int fromInclusive, int toExclusive, int idx, int idxFrom, int idxTo) {
			if (idxTo <= fromInclusive || toExclusive <= idxFrom) return -1;
			if (fromInclusive <= idxFrom && idxTo <= toExclusive) {
				return maxPos[idx];
			}
			// Previous conditions => not a leaf
			int med = (idxFrom + idxTo) / 2;
			int ret = getMaxPos(fromInclusive, toExclusive, 2 * idx, idxFrom, med);
			return combineMax(ret, getMaxPos(fromInclusive, toExclusive, 2 * idx + 1, med, idxTo));
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
			return nextIntArray(n, false);
		}

		public int[] nextIntArray(int n, boolean subtractOne) {
			int add = subtractOne ? -1 : 0;
			int[] ret = new int[n];
			for (int i = 0; i < n; i++) {
				ret[i] = nextInt() + add;
			}
			return ret;
		}

	}
}