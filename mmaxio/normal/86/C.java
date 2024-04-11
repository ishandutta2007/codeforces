import java.io.*;
import java.util.*;

public class C_new {

	int[] charToNumber;
	final int alphabetSize = 4;
	final int MAXLENGTH = 10;
	final int MOD = 1000000009;

	int getSymbNumber(char c) {
		return charToNumber[c];
	}

	class Trie {
		class Node {
			boolean isFinal;
			Node sufLink;
			Node[] child;
			Node[] go;
			Node parent;
			int parSymb;
			int index;
			int longestWord;

			public Node() {
				child = new Node[alphabetSize];
				go = new Node[alphabetSize];
				index = ls.size();
			}
		}

		ArrayList<Node> ls = new ArrayList<Node>();

		Node root;

		public Trie() {
			root = new Node();
			ls.add(root);
		}

		void addString(String s) {
			Node v = root;
			for (int i = 0; i < s.length(); i++) {
				Node prev = v;
				int symb = getSymbNumber(s.charAt(i));
				if (v.child[symb] == null) {
					v.child[symb] = new Node();
					ls.add(v.child[symb]);
				}
				v = v.child[symb];
				v.parent = prev;
				v.parSymb = symb;
			}
			v.isFinal = true;
			v.longestWord = Math.max(v.longestWord, s.length());
		}

		void buildAutomaton() {
			ArrayDeque<Node> q = new ArrayDeque<Node>();
			root.sufLink = root;
			for (int i = 0; i < alphabetSize; i++) {
				if (root.child[i] != null) {
					root.go[i] = root.child[i];
					q.addLast(root.child[i]);
				} else
					root.go[i] = root;
			}
			while (!q.isEmpty()) {
				Node v = q.pollFirst();
				v.sufLink = v.parent == root ? root
						: v.parent.sufLink.go[v.parSymb];
				v.isFinal |= v.sufLink.isFinal;
				v.longestWord = Math.max(v.longestWord, v.sufLink.longestWord);
				for (int i = 0; i < alphabetSize; i++)
					if (v.child[i] != null) {
						v.go[i] = v.child[i];
						q.addLast(v.child[i]);
					} else
						v.go[i] = v.sufLink.go[i];
			}
		}
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();

		charToNumber = new int[256];
		Arrays.fill(charToNumber, -1);
		charToNumber['A'] = 0;
		charToNumber['C'] = 1;
		charToNumber['G'] = 2;
		charToNumber['T'] = 3;	

		Trie t = new Trie();	

		for (int i = 0; i < m; i++) {
			String s = nextToken();
			if (s.length() <= n)
				t.addString(s);
		}

		t.buildAutomaton();

		int[][][] dp = new int[n + 1][t.ls.size()][MAXLENGTH + 1];
		dp[0][t.root.index][0] = 1;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < t.ls.size(); j++)
				for (int k = 0; k < MAXLENGTH; k++)
					if (dp[i][j][k] != 0) {
						Trie.Node v = t.ls.get(j);
						for (Trie.Node to : v.go)
							if (to != null && to != t.root) {
								int newK = k + 1;
								if (newK > MAXLENGTH)
									continue;
								if (to.isFinal && to.longestWord >= newK)
									newK = 0;
								dp[i + 1][to.index][newK] += dp[i][j][k];
								if (dp[i + 1][to.index][newK] >= MOD)
									dp[i + 1][to.index][newK] -= MOD;
							}
					}
		
		int ans = 0;
		
		for (int j = 0; j < t.ls.size(); j++) {
			ans += dp[n][j][0];
			if (ans >= MOD)
				ans -= MOD;
		}
		
		out.print(ans);

	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C_new().inp();
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