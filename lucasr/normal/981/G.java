import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Iterator;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class G {
	static final long MOD = 998244353;
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int N = sc.nextInt();
		int Q = sc.nextInt();
		TreeSet<Interval>[] set = new TreeSet[N];
		LazySegmentTree segmentTree = new LazySegmentTree(N);
		int type, l, r, number;
		for (int i = 0; i < Q; i++) {
			type = sc.nextInt();
			l = sc.nextInt() - 1;
			r = sc.nextInt();
			if (type == 1) {
				number = sc.nextInt() - 1;
				Interval e = new Interval(l, r);
				if (set[number] == null) {
					set[number] = new TreeSet<>();
				}
				TreeSet<Interval> tree = set[number];
				Interval floor = tree.floor(e);
				if (floor == null) floor = e;
				Iterator<Interval> it = tree.tailSet(floor).iterator();
				Interval intersection, union = e;
				segmentTree.increment(l, r, 1, 1);
				int notValid = 0;
				while (it.hasNext()) {
					Interval current = it.next();
					intersection = e.intersect(current);
					if (intersection.isValid()) {
						it.remove();
						if (!intersection.isEmpty()) {
							segmentTree.increment(intersection.from, intersection.to, 1, (int)MOD -1);
							segmentTree.increment(intersection.from, intersection.to, 2, 0);
						}
						union = union.union(current);
					} else {
						notValid++;
						if (notValid >= 2) break;
					}
				}
				tree.add(union);
			} else {
				out.println(segmentTree.getSum(l, r));
			}
		}
		
		out.flush();
	}
	
	static class Interval implements Comparable<Interval> {
		public int from, to;
		
		public Interval(int from, int to) {
			this.from = from;
			this.to = to;
		}
		
		@Override
		public int compareTo(Interval o) {
			return Integer.compare(from, o.from);
		}
		
		public Interval intersect(Interval o) {
			return new Interval(Math.max(from, o.from), Math.min(to, o.to));
		}
		
		/**
		 * Assumes they intersect
		 */
		public Interval union(Interval o) {
			return new Interval(Math.min(from, o.from), Math.max(to, o.to));
		}
		
		public boolean isValid() {
			return from <= to;
		}
		
		public boolean isEmpty() {
			return from >= to;
		}
	}
	
	static class LazySegmentTree {
		public int size;
		public long[] values;
		public long[] opTimes, opAdd;
		
		/**
		 * @param capacity for queries in range [0, capacity)
		 */
		public LazySegmentTree(int capacity) {
			size = 1;
			while (size < capacity) size *= 2;
			values = new long[2 * size];
			opTimes = new long[size];
			Arrays.fill(opTimes, 1);
			opAdd = new long[size];
		}
		
		public void propagateToChildren(int idx, int length) {
			if (opTimes[idx] == 1 && opAdd[idx] == 0) return;
			propagateToChild(idx, 2*idx, length);
			propagateToChild(idx, 2*idx + 1, length);
			opTimes[idx] = 1;
			opAdd[idx] = 0;
		}
			
		public void propagateToChild(int idx, int childIdx, int length) {
			if (childIdx < size) {
				opTimes[childIdx] *= opTimes[idx];
				opTimes[childIdx] %= MOD;
				opAdd[childIdx] *= opTimes[idx];
				opAdd[childIdx] += opAdd[idx];
				opAdd[childIdx] %= MOD;
			}
			values[childIdx] *= opTimes[idx];
			values[childIdx] += opAdd[idx] * length;
			values[childIdx] %= MOD;
		}
		
		public void increment(int fromInclusive, int toExclusive, int times, int add) {
			increment(fromInclusive, toExclusive, 1, 0, size, times, add);
		}
		
		public void increment(int fromInclusive, int toExclusive, int idx, int idxFrom, int idxTo, int times, int add) {
			if (idxTo <= fromInclusive || toExclusive <= idxFrom) return;
			if (fromInclusive <= idxFrom && idxTo <= toExclusive) {
				if (idx < size) {
					opTimes[idx] *= times;
					opTimes[idx] %= MOD;
					opAdd[idx] *= times;
					opAdd[idx] += add;
					opAdd[idx] %= MOD;
				}
				values[idx] *= times;
				values[idx] += add * (long)(idxTo - idxFrom);
				values[idx] %= MOD;
				return;
			}
			int med = (idxFrom + idxTo) / 2;
			propagateToChildren(idx, med - idxFrom);
			increment(fromInclusive, toExclusive, 2*idx, idxFrom, med, times, add);
			increment(fromInclusive, toExclusive, 2*idx+1, med, idxTo, times, add);
			values[idx] = (values[2*idx] + values[2*idx+1]) % MOD;
		}
		
		public long getSum(int fromInclusive, int toExclusive) {
			return getSum(fromInclusive, toExclusive, 1, 0, size);
		}
		
		public long getSum(int fromInclusive, int toExclusive, int idx, int idxFrom, int idxTo) {
			if (idxTo <= fromInclusive || toExclusive <= idxFrom) return 0;
			if (fromInclusive <= idxFrom && idxTo <= toExclusive) {
				return values[idx];
			}
			// Previous conditions => not a leaf
			int med = (idxFrom + idxTo) / 2;
			propagateToChildren(idx, med - idxFrom);
			long ret = getSum(fromInclusive, toExclusive, 2*idx, idxFrom, med);
			ret += getSum(fromInclusive, toExclusive, 2*idx+1, med, idxTo);
			ret %= MOD;
			return ret;
		}
	}
	
	static class MyScanner {
		private BufferedReader br;
		private StringTokenizer tokenizer;
		
		public MyScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
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
		
		public long nextLong() {
			return Long.parseLong(next());
		}
	}
}