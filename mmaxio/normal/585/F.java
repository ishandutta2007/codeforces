import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class F {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int P = 1_000_000_007;
	static final BigInteger BIG_P = BigInteger.valueOf(P);

	static class Trie {

		int size = 0;

		/** [low; high] **/
		char low, high;
		int alph;
		List<Node> nodes = new ArrayList<>();
		Node root = new Node();
		
		public Trie(char low, char high) {
			this.low = low;
			this.high = high;
			alph = high - low + 1;
		}
		
		int[][] to;
		boolean[] bad;

		class Node {

			Node child, sibling;
			Node sufLink;
			char parSymb;
			boolean bad;
			int id;

			Node goChild(char symb) {
				Node res = child;
				while (res != null && res.parSymb != symb)
					res = res.sibling;
				return res;
			}

			Node go(char symb) {
				if (to[id][symb - low] != -1) {
					return nodes.get(to[id][symb - low]);
				}
				Node ret = null;
				for (Node v = this; v != null; v = v.sufLink) {
					Node res = v.goChild(symb);
					if (res != null) {
						ret = res;
						break;
					}
				}
				if (ret == null) {
					ret = root;
				}
				to[id][symb - low] = ret.id;
				return ret;
			}

			public Node(Node sibling, char parSymb) {
				this();
				this.sibling = sibling;
				this.parSymb = parSymb;
			}

			public Node() {
				id = size++;
				nodes.add(this);
			}
		}


		void addString(String s) {
			Node cur = root;
			for (int i = 0; i < s.length(); i++) {
				char symb = s.charAt(i);
				Node next = cur.goChild(symb);
				if (next == null) {
					next = new Node(cur.child, symb);
					cur.child = next;
				}
				cur = next;
			}
			cur.bad = true;
		}

		void buildAutomaton() {
			
			to = new int[size][alph];
			for (int i = 0; i < size; i++) {
				Arrays.fill(to[i], -1);
			}
			bad = new boolean[size];
			
			Queue<Node> q = new ArrayDeque<>();
			for (Node to = root.child; to != null; to = to.sibling) {
				to.sufLink = root;
				q.add(to);
			}

			while (!q.isEmpty()) {
				Node v = q.poll();
				for (Node to = v.child; to != null; to = to.sibling) {
					to.sufLink = v.sufLink.go(to.parSymb);
					to.bad |= to.sufLink.bad;
					q.add(to);
				}
			}
			
			for (Node v : nodes) {
				bad[v.id] = v.bad;
				for (char c = low; c <= high; c++) {
					v.go(c);
				}
			}
		}
		
		boolean check(String s) {
			Node v = root;
			for (char c : s.toCharArray()) {
				v = v.go(c);
				if (v.bad) {
					return true;
				}
			}
			return false;
		}
	}
	
	int[][] to;
	boolean[] bad;
	int size;
	
	int go(String s) {
		int[][] dp = new int[2][size];
		dp[0][0] = 1;
		for (char c : s.toCharArray()) {
			int dig = c - '0';
			int[][] next = new int[2][size];
			for (int i = 0; i < 2; i++)
				for (int j = 0; j < size; j++) {
					if (dp[i][j] == 0) {
						continue;
					}
					for (int k = 0; k < 10; k++) {
						if (i == 0 && k > dig) {
							continue;
						}
						int newI = (i == 0 && k == dig) ? 0 : 1;
						int newJ = to[j][k];
						if (bad[newJ]) {
							continue;
						}
						next[newI][newJ] += dp[i][j];
						if (next[newI][newJ] >= P) {
							next[newI][newJ] -= P;
						}
					}
				}
			dp = next;
		}
		int good = 0;
		for (int i = 0; i < size; i++) {
			good += dp[1][i];
			if (good >= P) {
				good -= P;
			}
		}
		
//		System.err.println(s + " " + good);
		
		return Math.floorMod(new BigInteger(s).mod(BIG_P).intValue() - good, P);
	}

	void solve() throws IOException {
		String s = nextToken();
		String x = nextToken();
		String y = nextToken();

		int d = x.length() / 2;
		
		Trie t = new Trie('0', '9');

		for (int i = 0; i + d <= s.length(); i++) {
			t.addString(s.substring(i, i + d));
		}
		
		t.buildAutomaton();
		
		to = t.to;
		bad = t.bad;
		size = t.size;

		
		boolean add1 = t.check(y);

		out.println(Math.floorMod(go(y) - go(x) + (add1 ? 1 : 0), P));
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