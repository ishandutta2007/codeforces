import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Voter implements Comparable<Voter> {
		int id, vote, cost;

		public Voter(int id, int vote, int cost) {
			this.id = id;
			this.vote = vote;
			this.cost = cost;
		}

		@Override
		public int compareTo(Voter o) {
			return Integer.compare(cost, o.cost);
		}
	}

	class Node {
		Node left, right;
		int l, r;
		int count, sum;

		public Node(int l, int r) {
			this.l = l;
			this.r = r;
			if (r - l > 1) {
				int mid = (l + r) >> 1;
				left = new Node(l, mid);
				right = new Node(mid, r);
			}
		}

		void add(int pos, int cost) {
			if (l == pos && pos + 1 == r) {
				count = 1;
				sum = cost;
				return;
			}
			(pos < left.r ? left : right).add(pos, cost);
			count = left.count + right.count;
			sum = left.sum + right.sum;
		}

		int get(int k) {
			if (k <= 0) {
				return 0;
			}
			if (count == k) {
				return sum;
			}
			if (k <= left.count) {
				return left.get(k);
			} else {
				return left.sum + right.get(k - left.count);
			}
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		List<Voter> all = new ArrayList<Voter>(n);
		List<Voter>[] byWho = new List[100000];
		for (int i = 0; i < 100000; i++) {
			byWho[i] = new ArrayList<>(0);
		}
		int have = 0;
		for (int i = 0; i < n; i++) {
			int who = nextInt();
			int cost = nextInt();
			if (who == 0) {
				have++;
			} else {
				Voter tmp = new Voter(all.size(), who - 1, cost);
				all.add(tmp);
				byWho[who - 1].add(tmp);
			}
		}
		Collections.sort(all);
		int[] sortOrd = new int[n];
		for (int i = 0; i < all.size(); i++) {
			sortOrd[all.get(i).id] = i;
		}
		Arrays.sort(byWho, new Comparator<List<Voter>>() {

			@Override
			public int compare(List<Voter> o1, List<Voter> o2) {
				return -Integer.compare(o1.size(), o2.size());
			}

		});
		for (int i = 0; i < 100000; i++) {
			Collections.sort(byWho[i]);
		}

		Node root = new Node(0, all.size());
		int needPay = 0;
		int countNeedPay = 0;
		for (int i = 0; i < 100000; i++) {
			int from = Math.max(byWho[i].size() - Math.max(have - 1, 0), 0);
			for (int j = from; j < byWho[i].size(); j++) {
				Voter v = byWho[i].get(j);
				root.add(sortOrd[v.id], v.cost);
			}
			// System.err.println(byWho[i].size() + " " + from);
			for (int j = 0; j < from; j++) {
				needPay += byWho[i].get(j).cost;
				countNeedPay++;
			}
		}
		int ans;
		if (have == 0) {
			ans = Integer.MAX_VALUE;
		} else {
			ans = needPay;
		}
		for (int res = have + 1; res <= n; res++) {
			if (res != 1) {
				for (int j = 0; j < 100000; j++) {
					if (byWho[j].size() < res - 1) {
						break;
					}
					// System.err.println(res);
					Voter v = byWho[j].get(byWho[j].size() - res + 1);
					needPay -= v.cost;
					countNeedPay--;
					root.add(sortOrd[v.id], v.cost);
				}
			}
			// System.err.println(res + " " + countNeedPay);
			// System.err.println(root.count);
			ans = Math.min(ans, needPay + root.get(res - have - countNeedPay));
		}
		out.println(ans);
	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C();
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