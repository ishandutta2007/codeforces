import java.io.*;
import java.util.*;

public class E {
	
	static class Cost implements Comparable<Cost> {
		int cost;
		int id;
		int sortedId;
		public Cost(int cost, int id) {
			this.cost = cost;
			this.id = id;
		}
		@Override
		public int compareTo(Cost o) {
			return Integer.compare(cost, o.cost);
		}
		@Override
		public String toString() {
			return "Cost [cost=" + cost + ", id=" + id + ", sortedId="
					+ sortedId + "]";
		}
	}
	
	static class Node {
		int l, r;
		Node left, right;
		
		long sum;
		int cnt;
		public Node(int l, int r) {
			this.l = l;
			this.r = r;
			if (r - l > 1) {
				int m = (l + r) >> 1;
				left = new Node(l, m);
				right = new Node(m, r);
			}
		}
		
		void set(int pos, int setVal, int setCnt) {
			if (r - l == 1) {
				sum = setVal;
				cnt = setCnt;
				return;
			}
			(pos < left.r ? left : right).set(pos, setVal, setCnt);
			sum = left.sum + right.sum;
			cnt = left.cnt + right.cnt;
		}
		
		long getSumFirst(int howMuch) {
			if (howMuch < 0 || howMuch > cnt) {
				throw new AssertionError();
			}
			if (howMuch == 0) {
				return 0;
			}
			if (howMuch == cnt) {
				return sum;
			}
			if (howMuch >= left.cnt) {
				return left.sum + right.getSumFirst(howMuch - left.cnt);
			} else {
				return left.getSumFirst(howMuch);
			}
		}
	}

	long solve(int n, int m, int k, int[] c, int[] mask) {
		
		Cost[] cs = new Cost[n];
		for (int i = 0; i < n; i++) {
			cs[i] = new Cost(c[i], i);
		}
		
		ArrayList<Cost>[] byMask = new ArrayList[4];
		for (int i = 0; i < 4; i++) {
			byMask[i] = new ArrayList<>();
		}
		
		for (int i = 0; i < n; i++) {
			byMask[mask[i]].add(cs[i]);
		}
		
		Arrays.sort(cs);
		for (int i = 0; i < n; i++) {
			cs[i].sortedId = i;
		}
		
		Node root = new Node(0, n);
		for (int i = 0; i < 4; i++) {
			Collections.sort(byMask[i]);
//			System.err.println(byMask[i]);
		}
		
		for (int i = 0; i < 3; i++) {
			for (Cost cst : byMask[i]) {
				root.set(cst.sortedId, cst.cost, 1);
			}
		}

		long[] pref1 = new long[byMask[1].size() + 1];
		long[] pref2 = new long[byMask[2].size() + 1];
		
		for (int i = 1; i < 3; i++) {
			for (int j = 0; j < k && j < byMask[i].size(); j++) {
				Cost cst = byMask[i].get(j);
				root.set(cst.sortedId, 0, 0);
			}
			
			long[] pref = i == 1 ? pref1 : pref2;
			
			for (int j = 0; j < byMask[i].size(); j++) {
				pref[j + 1] = pref[j] + byMask[i].get(j).cost;
			}
		}
		
		long ans = Long.MAX_VALUE;
		long sumPick3 = 0;
		for (int pick3 = 0; pick3 <= m && pick3 <= byMask[3].size(); pick3++) {
			if (pick3 > 0) {
				sumPick3 += byMask[3].get(pick3 - 1).cost;
			}
			
			int need12 = k - pick3;
			
			int realNeed12 = Math.max(need12, 0);
			int needRest = m - pick3 - 2 * realNeed12;
			
			if (realNeed12 <= byMask[1].size() && realNeed12 <= byMask[2].size() && needRest >= 0) {
				long sumPick12 = pref1[realNeed12] + pref2[realNeed12];
				
				if (root.cnt >= needRest) {
					long sumPickRest = root.getSumFirst(needRest);
					
					ans = Math.min(ans, sumPick3 + sumPick12 + sumPickRest);
				}
			}
			
			if (need12 > 0) {
				if (need12 <= byMask[1].size()) {
					Cost cst = byMask[1].get(need12 - 1);
					root.set(cst.sortedId, cst.cost, 1);
				}
				if (need12 <= byMask[2].size()) {
					Cost cst = byMask[2].get(need12 - 1);
					root.set(cst.sortedId, cst.cost, 1);
				}
			}
		}
		if (ans == Long.MAX_VALUE) {
			ans = -1;
		}
		return ans;
	}
	
	void submit() {
		int n = nextInt();
		int m = nextInt();
		int k = nextInt();
		int[] c = new int[n];
		for (int i = 0; i < n; i++) {
			c[i] = nextInt();
		}
		
		int[] mask = new int[n];
		for (int x = 1; x <= 2; x++) {
			int cnt = nextInt();
			for (int i = 0; i < cnt; i++) {
				int idx = nextInt() - 1;
				mask[idx] |= x;
			}
		}
		
		out.println(solve(n, m, k, c, mask));
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	E() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
		// stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new E();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}