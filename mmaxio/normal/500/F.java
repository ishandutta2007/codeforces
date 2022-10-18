import java.io.*;
import java.util.*;

public class F {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Item {
		int cost, profit, id;

		public Item(int cost, int profit, int id) {
			this.cost = cost;
			this.profit = profit;
			this.id = id;
		}
	}

	static class ItemEvent implements Comparable<ItemEvent> {
		int time;
		boolean add;
		Item it;

		public ItemEvent(int time, boolean add, Item it) {
			this.time = time;
			this.add = add;
			this.it = it;
		}

		@Override
		public int compareTo(ItemEvent o) {
			if (time != o.time) {
				return time < o.time ? -1 : 1;
			}
			return Integer.compare(it.id, o.it.id);
		}

	}

	static class KnapsackQueue {
		KnapsackStack head, tail;

		public KnapsackQueue(int knapsackSize) {
			head = new KnapsackStack(knapsackSize);
			tail = new KnapsackStack(knapsackSize);
		}

		void push(Item it) {
			tail.push(it);
		}

		Item pop() {
			if (!head.isEmpty()) {
				return head.pop();
			}
			while (!tail.isEmpty()) {
				head.push(tail.pop());
			}
			if (head.isEmpty()) {
				throw new AssertionError("Empty queue");
			}
			return head.pop();
		}

		int getProfit(int have) {
			int[] dp1 = head.getDp();
			int[] dp2 = tail.getDp();
			int ret = 0;
			for (int i = 0; i <= have; i++) {
				ret = Math.max(ret, dp1[i] + dp2[have - i]);
			}
			return ret;
		}
	}

	static class KnapsackStack {

		List<int[]> dp = new ArrayList<>();
		List<Item> items = new ArrayList<>();
		int size;

		public KnapsackStack(int knapsackSize) {
			this.size = knapsackSize;
			dp.add(new int[knapsackSize + 1]);
		}

		int[] getDp() {
			return dp.get(dp.size() - 1);
		}

		boolean isEmpty() {
			return items.isEmpty();
		}

		void push(Item it) {
			items.add(it);
			int cost = it.cost;
			int profit = it.profit;
			int[] newDp = dp.get(dp.size() - 1).clone();
			for (int i = size - cost; i >= 0; i--) {
				newDp[i + cost] = Math.max(newDp[i + cost], newDp[i] + profit);
			}
//			System.err.println(Arrays.toString(newDp));
			for (int i = 1; i <= size; i++) {
				newDp[i] = Math.max(newDp[i], newDp[i - 1]);
			}
			dp.add(newDp);
		}

		Item pop() {
			if (items.isEmpty()) {
				throw new AssertionError("Empty stack");
			}
			dp.remove(dp.size() - 1);
			return items.remove(items.size() - 1);
		}
	}

	static class Query implements Comparable<Query> {
		int time, have, id;

		public Query(int time, int have, int id) {
			this.time = time;
			this.have = have;
			this.id = id;
		}

		@Override
		public int compareTo(Query o) {
			return Integer.compare(time, o.time);
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int p = nextInt();
		ItemEvent[] itEvs = new ItemEvent[2 * n];
		for (int i = 0; i < n; i++) {
			int cost = nextInt();
			int profit = nextInt();
			int start = nextInt();
			Item it = new Item(cost, profit, i);
			itEvs[2 * i] = new ItemEvent(start, true, it);
			itEvs[2 * i + 1] = new ItemEvent(start + p, false, it);
		}
		Arrays.sort(itEvs);

		int maxHave = 0;

		int nq = nextInt();
		Query[] qs = new Query[nq];
		for (int i = 0; i < nq; i++) {
			int time = nextInt();
			int have = nextInt();
			maxHave = Math.max(maxHave, have);
			qs[i] = new Query(time, have, i);
		}
		Arrays.sort(qs);

		KnapsackQueue queue = new KnapsackQueue(maxHave);
		int[] outp = new int[nq];
		for (int i = 0, j = 0; i < nq; i++) {
			while (j < 2 * n && itEvs[j].time <= qs[i].time) {
				ItemEvent curEv = itEvs[j++];
				if (curEv.add) {
					queue.push(curEv.it);
				} else {
					Item popped = queue.pop();
					if (popped != curEv.it) {
						throw new AssertionError();
					}
				}
			}
			outp[qs[i].id] = queue.getProfit(qs[i].have);
		}
		for (int x : outp) {
			out.println(x);
		}
	}

	F() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new F();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return null;
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			eof = true;
			return null;
		}
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}