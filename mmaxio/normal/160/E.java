import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void makeUnique(ArrayList<Integer> ls) {
		Collections.sort(ls);

		int uk = 0;

		for (int i = 0; i < ls.size(); i++)
			if (ls.get(i).compareTo(ls.get(uk)) != 0)
				ls.set(++uk, ls.get(i));

		for (int i = ls.size() - 1; i > uk; i--)
			ls.remove(i);
	}

	class Query implements Comparable<Query> {
		int type;// 0 - bus, 1 - passenger
		int l, r, time;
		int id;

		@Override
		public int compareTo(Query o) {
			if (l != o.l)
				return l < o.l ? -1 : 1;
			if (type != o.type)
				return type < o.type ? -1 : 1;
			return 0;
		}

		public Query(int type, int l, int r, int time, int id) {
			this.type = type;
			this.l = l;
			this.r = r;
			this.time = time;
			this.id = id;
		}

		@Override
		public String toString() {
			return "[type=" + type + ", l=" + l + ", r=" + r + ", time=" + time
					+ ", id=" + id + "]";
		}

	}

	class Node {
		int l, r;
		Node left, right;

		int val;

		public Node(int l, int r) {
			this.l = l;
			this.r = r;
			if (l < r) {
				left = new Node(l, (l + r) >> 1);
				right = new Node(((l + r) >> 1) + 1, r);
			}
			val = -1;
		}

	}

	void upd(Node v, int ind, int val) {
		if (v.l == v.r) {
			v.val = val;
			return;
		}

		if (v.left.r >= ind)
			upd(v.left, ind, val);
		else
			upd(v.right, ind, val);

		v.val = Math.max(v.left.val, v.right.val);
	}

	int find(Node v, int ind, int val) {
		if (v.r < ind || v.val < val)
			return -1;
		if (v.l == v.r)
			return v.l;
		int res = find(v.left, ind, val);
		return res == -1 ? find(v.right, ind, val) : res;
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();

		int[] s = new int[n];
		int[] f = new int[n];
		int[] t = new int[n];

		int[] l = new int[m];
		int[] r = new int[m];
		int[] b = new int[m];
		
		for (int i = 0; i < n; i++) {
			s[i] = nextInt();
			f[i] = nextInt();
			t[i] = nextInt();
		}
		
		for (int i = 0; i < m; i++) {
			l[i] = nextInt();
			r[i] = nextInt();
			b[i] = nextInt();
		}

		ArrayList<Integer> all = new ArrayList<Integer>();
		for (int i = 0; i < n; i++) {
			all.add(s[i]);
			all.add(f[i]);
		}
		for (int i = 0; i < m; i++) {
			all.add(l[i]);
			all.add(r[i]);
		}

		makeUnique(all);
		for (int i = 0; i < n; i++) {
			s[i] = Collections.binarySearch(all, s[i]);
			f[i] = Collections.binarySearch(all, f[i]);
		}
		for (int i = 0; i < m; i++) {
			l[i] = Collections.binarySearch(all, l[i]);
			r[i] = Collections.binarySearch(all, r[i]);
		}

		all.clear();
		for (int i = 0; i < n; i++)
			all.add(t[i]);
		for (int i = 0; i < m; i++)
			all.add(b[i]);

		makeUnique(all);
		for (int i = 0; i < n; i++)
			t[i] = Collections.binarySearch(all, t[i]);
		for (int i = 0; i < m; i++)
			b[i] = Collections.binarySearch(all, b[i]);

		int maxTime = all.size();

		int[] timeToBus = new int[maxTime];

		Query[] qs = new Query[n + m];
		for (int i = 0; i < n; i++) {
			qs[i] = new Query(0, s[i], f[i], t[i], i);
			timeToBus[t[i]] = i;
		}
		for (int i = 0; i < m; i++)
			qs[i + n] = new Query(1, l[i], r[i], b[i], i);

		Node root = new Node(0, maxTime - 1);

		int[] ans = new int[m];

		Arrays.sort(qs);
		for (Query q : qs) {

//			System.err.println(q);

			if (q.type == 0)
				upd(root, q.time, q.r);
			else {
				int tmp = find(root, q.time, q.r);
				ans[q.id] = (tmp == -1) ? -1 : (timeToBus[tmp] + 1);
			}
		}

		for (int x : ans)
			out.print(x + " ");
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new E().inp();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	String nextString() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken("\n");
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