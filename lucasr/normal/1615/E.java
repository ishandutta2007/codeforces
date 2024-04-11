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
		EPurpleCrayon solver = new EPurpleCrayon();
		solver.solve(1, in, out);
		out.close();
	}

	static class EPurpleCrayon {
		public static MyScanner sc;
		public static PrintWriter out;
		int n;
		IntArray[] adj;
		int[] left;
		int[] right;
		int[] parent;
		boolean[] chosen;
		int index;
		LazyMaxAddSegmentTree st;
		IntArray leaves;

		public void solve(int testNumber, MyScanner sc, PrintWriter out) {
			EPurpleCrayon.sc = sc;
			EPurpleCrayon.out = out;

			n = sc.nextInt();
			int k = sc.nextInt();
			adj = new IntArray[n];
			for (int i = 0; i < n; i++) {
				adj[i] = new IntArray();
			}
			for (int i = 0; i < n - 1; i++) {
				int tmp1 = sc.nextInt() - 1;
				int tmp2 = sc.nextInt() - 1;
				adj[tmp1].add(tmp2);
				adj[tmp2].add(tmp1);
			}
			left = new int[n];
			right = new int[n];
			parent = new int[n];
			chosen = new boolean[n];
			leaves = new IntArray();
			index = 0;
			st = new LazyMaxAddSegmentTree(n);
			dfs(0, -1, 1);
			int mayChose = 0, red = 0;
			for (int i = 0; i < k; i++) {
				long[] maxAndPos = st.getMaxAndPos(0, index);
				long max = maxAndPos[0];
				int pos = (int) maxAndPos[1];
				if (max <= 0) break;
				mayChose += max;
				red++;
				int node = leaves.get(pos);
				while (node != -1 && !chosen[node]) {
					chosen[node] = true;
					st.add(left[node], right[node], -1);
					node = parent[node];
				}
			}
			if (red == leaves.size()) {
				long optimus = Math.max(red, Math.min(k, n / 2));
				out.println(optimus * (n - optimus));
				return;
			}
			int possibleBlue = n - mayChose;
			long w = n - red - possibleBlue;
			if (possibleBlue <= red) {
				out.println(w * (red - possibleBlue));
				return;
			}
			long nTotal = n - 2L * red;
			possibleBlue -= red;
			long optimus = Math.min(possibleBlue, nTotal / 2);
			out.println(-optimus * (nTotal - optimus));
		}

		void dfs(int node, int par, int depth) {
			parent[node] = par;
			left[node] = index;
			boolean leaf = true;
			for (int i = 0; i < adj[node].size(); i++) {
				int next = adj[node].get(i);
				if (next != par) {
					leaf = false;
					dfs(next, node, depth + 1);
				}
			}
			if (leaf) {
				st.add(index, index + 1, depth);
				leaves.add(node);
				index++;
			}
			right[node] = index;
		}

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

		public int size() {
			return size;
		}

		public int[] toArray() {
			return Arrays.copyOf(arr, size);
		}

		public String toString() {
			return "IntArray " + Arrays.toString(toArray());
		}

	}

	static class LazyMaxAddSegmentTree {
		public int size;
		public long[] values;
		public int[] maxPosition;
		public long[] lazyAdd;

		public LazyMaxAddSegmentTree(int capacity) {
			size = 1;
			while (size < capacity) size *= 2;
			values = new long[2 * size];
			maxPosition = new int[2 * size];
			init(1, 0, size);
			lazyAdd = new long[size];
		}

		private void init(int idx, int idxFrom, int idxTo) {
			if (idxFrom + 1 == idxTo) {
				maxPosition[idx] = idxFrom;
				return;
			}
			int med = (idxFrom + idxTo) / 2;
			init(2 * idx, idxFrom, med);
			init(2 * idx + 1, med, idxTo);
		}

		private void propagateToChildren(int idx) {
			if (lazyAdd[idx] == 0) return;
			propagateToChild(idx, 2 * idx);
			propagateToChild(idx, 2 * idx + 1);
			lazyAdd[idx] = 0;
		}

		private void propagateToChild(int idx, int childIdx) {
			if (childIdx < size) { // child really exists
				lazyAdd[childIdx] += lazyAdd[idx];
			}
			values[childIdx] += lazyAdd[idx];
		}

		public void add(int fromInclusive, int toExclusive, long value) {
			add(fromInclusive, toExclusive, 1, 0, size, value);
		}

		private void add(int fromInclusive, int toExclusive, int idx, int idxFrom, int idxTo, long value) {
			if (idxTo <= fromInclusive || toExclusive <= idxFrom) return;
			if (fromInclusive <= idxFrom && idxTo <= toExclusive) {
				if (idx < size) {
					lazyAdd[idx] += value;
				}
				values[idx] += value;
				return;
			}
			int med = (idxFrom + idxTo) / 2;
			propagateToChildren(idx);
			add(fromInclusive, toExclusive, 2 * idx, idxFrom, med, value);
			add(fromInclusive, toExclusive, 2 * idx + 1, med, idxTo, value);
			values[idx] = Math.max(values[2 * idx], values[2 * idx + 1]);
			if (values[idx] == values[2 * idx]) {
				maxPosition[idx] = maxPosition[2 * idx];
			} else {
				maxPosition[idx] = maxPosition[2 * idx + 1];
			}
		}

		public long[] getMaxAndPos(int fromInclusive, int toExclusive) {
			int maxIdx = getMaxIdx(fromInclusive, toExclusive, 1, 0, size);
			return new long[]{values[maxIdx], maxPosition[maxIdx]};
		}

		private int getMaxIdx(int fromInclusive, int toExclusive, int idx, int idxFrom, int idxTo) {
			if (idxTo <= fromInclusive || toExclusive <= idxFrom) return -1;
			if (fromInclusive <= idxFrom && idxTo <= toExclusive) {
				return idx;
			}
			// Previous conditions => not a leaf
			int med = (idxFrom + idxTo) / 2;
			propagateToChildren(idx);
			int ret1 = getMaxIdx(fromInclusive, toExclusive, 2 * idx, idxFrom, med);
			int ret2 = getMaxIdx(fromInclusive, toExclusive, 2 * idx + 1, med, idxTo);
			if (ret2 == -1 || ret1 != -1 && values[ret1] >= values[ret2]) return ret1;
			return ret2;
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