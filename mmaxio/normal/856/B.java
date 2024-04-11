import java.io.*;
import java.util.*;

public class B {

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
		int[] depth;
		int[] toSuf;
		
		class Node {

			Node child, sibling;
			Node sufLink;
			char parSymb;
			int id;
			
			int depth;

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
				cur.depth = i + 1;
			}
		}

		void buildAutomaton() {

			to = new int[size][alph];
			depth = new int[size];
			toSuf = new int[size];
			
			for (int i = 0; i < size; i++) {
				Arrays.fill(to[i], -1);
			}

			depth[0] = 0;
			toSuf[0] = 0;
			
			Queue<Node> q = new ArrayDeque<>();
			for (Node to = root.child; to != null; to = to.sibling) {
				to.sufLink = root;
				q.add(to);
			}

			while (!q.isEmpty()) {
				Node v = q.poll();
				
				depth[v.id] = v.depth;
				if (v.sufLink.depth == v.depth - 1 && v.sufLink != root) {
					toSuf[v.id] = v.sufLink.id; 
				}
				
				for (Node to = v.child; to != null; to = to.sibling) {
					to.sufLink = v.sufLink.go(to.parSymb);
					q.add(to);
				}
			}

//			for (Node v : nodes) {
//				for (char c = low; c <= high; c++) {
//					v.go(c);
//				}
//			}
		}
	}

	int[] head;
	int[] next;
	int[] to;
	int m;
	
	int[] dpTake;
	int[] dpSkip;
	
	int solve(String[] a) {
		Trie t = new Trie('a', 'z');
		
		for (String s : a) {
			t.addString(s);
		}
		
		t.buildAutomaton();
		
		int n = t.size;
		
		head = new int[n];
		Arrays.fill(head, -1);
		next = new int[n];
		to = new int[n];
		m = 0;
		
		boolean[] isRoot = new boolean[n];
		Arrays.fill(isRoot, true);
		
		for (int i = 1; i < n; i++) {
			if (t.toSuf[i] != 0) {
				
//				System.err.println(t.toSuf[i] + " -> " + i);
				
				addEdge(t.toSuf[i], i);
				isRoot[i] = false;
			}
		}	
		
		int ret = 0;
		
		dpTake = new int[n];
		dpSkip = new int[n];
		
		for (int i = 1; i < n; i++) {
			if (isRoot[i]) {
//				System.err.println(i);
				dfsMatch(i);
				ret += Math.max(dpTake[i], dpSkip[i]);
			}
		}
		return ret;
	}
	
	void dfsMatch(int v) {
		dpTake[v] = 1;
		dpSkip[v] = 0;
		
		for (int e = head[v]; e >= 0; e = next[e]) {
			int u = to[e];
			dfsMatch(u);
			dpTake[v] += dpSkip[u];
			dpSkip[v] += Math.max(dpTake[u], dpSkip[u]);
		}
	}
	
	void addEdge(int v, int u) {
		to[m] = u;
		next[m] = head[v];
		head[v] = m;
		m++;
	}
	
	void submit() {
		int t = nextInt();
		while (t-- > 0) {
			int n = nextInt();
			String[] a = new String[n];
			for (int i = 0; i < n; i++) {
				a[i] = nextToken();
			}
			out.println(solve(a));
		}
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	B() throws IOException {
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
		new B();
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