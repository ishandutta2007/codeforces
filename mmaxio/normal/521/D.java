import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Item implements Comparable<Item> {
		int type, delta, id;

		@Override
		public int compareTo(Item o) {
			return -Integer.compare(delta, o.delta);
		}

		public Item(int type, int delta, int id) {
			this.type = type;
			this.delta = delta;
			this.id = id;
		}
	}

	static class Profit implements Comparable<Profit> {
		Item item;
		long num, denom;

		public Profit(Item item, long num, long denom) {
			this.item = item;
			this.num = num;
			this.denom = denom;
		}

		@Override
		public int compareTo(Profit o) {
			// num/denom > o.num/o.denom -> -1
			long v1 = num * o.denom;
			long v2 = o.num * denom;
			return -Long.compare(v1, v2);
		}
	}

	void solve() throws IOException {
		int k = nextInt();
		int n = nextInt();
		int take = nextInt();
		int[] a = new int[k];
		for (int i = 0; i < k; i++) {
			a[i] = nextInt();
		}

		List<Item>[][] b = new List[k][3];
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < 3; j++) {
				b[i][j] = new ArrayList<>(0);
			}
		}

		for (int i = 0; i < n; i++) {
			int type = nextInt() - 1;
			int where = nextInt() - 1;
			int delta = nextInt();
			b[where][type].add(new Item(type, delta, i));
		}

		List<Profit> pr = new ArrayList<>(n);

		for (int i = 0; i < k; i++) {
			List<Item>[] bi = b[i];
			for (int j = 0; j < 3; j++) {
				Collections.sort(bi[j]);
			}
			if (!bi[0].isEmpty()) {
				int add = bi[0].get(0).delta - a[i];
				if (add > 0) {
					bi[1].add(new Item(0, add, bi[0].get(0).id));
					Collections.sort(bi[1]);
				}
			}

			long curA = a[i];
			for (Item it : bi[1]) {
				pr.add(new Profit(it, curA + it.delta, curA));
				curA += it.delta;
			}
			for (Item it : bi[2]) {
				if (it.delta != 1) {
					pr.add(new Profit(it, it.delta, 1));
				}
			}

		}

		Collections.sort(pr);
		List<Item> answer = new ArrayList<>(take);
		for (int i = 0; i < take && i < pr.size(); i++) {
			answer.add(pr.get(i).item);
		}
		Collections.sort(answer, new Comparator<Item>() { // this shit better be
															// stable

					@Override
					public int compare(Item o1, Item o2) {
						return Integer.compare(o1.type, o2.type);
					}
				});
		out.println(answer.size());
		for (Item it : answer) {
			out.print(it.id + 1 + " ");
		}
		out.println();
	}

	D() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D();
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