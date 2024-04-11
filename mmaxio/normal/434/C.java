import java.io.*;
import java.util.*;

public class WTF {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int alph;

	int[] decreaseByOne(int[] word) {
		word = word.clone();
		int i = word.length - 1;
		while (word[i] == 0) {
			word[i] = alph - 1;
			i--;
		}
		word[i]--;
		if (word[0] == 0) {
			word = Arrays.copyOfRange(word, 1, word.length);
		}
		return word;
	}

	int[] readTofu() throws IOException {
		int len = nextInt();
		int[] ret = new int[len];
		for (int i = 0; i < len; i++) {
			ret[i] = nextInt();
		}
		return ret;
	}

	Trie t;
	int k;

	int solve(int[] word) {

		if (word.length == 0) {
			return 0;
		}

		List<Trie.Node> all = t.all;
		int S = all.size();
		int[][][] dp = new int[3][k + 1][S]; // 0 - empty, 1 - less and not
												// empty,
												// 2 - equal

		if (word[0] == 0) {
			throw new AssertionError();
		}

		for (int firstDig = 0; firstDig <= word[0]; firstDig++) {
			if (firstDig == 0) {
				dp[0][0][0]++;
			} else if (firstDig == word[0]) {
				Trie.Node to = all.get(0).go[firstDig];
				int addVal = to.value;
				if (addVal <= k) {
					dp[2][addVal][to.id]++;
				}
			} else {
				Trie.Node to = all.get(0).go[firstDig];
				int addVal = to.value;
				if (addVal <= k) {
					dp[1][addVal][to.id]++;
				}
			}
		}

		int[][][] next = new int[3][k + 1][S];

		for (int zzz = 1; zzz < word.length; zzz++) {
			int dig = word[zzz];
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j <= k; j++) {
					Arrays.fill(next[i][j], 0);
				}
			}
			for (int type = 0; type < 3; type++)
				for (int prevK = 0; prevK <= k; prevK++)
					for (int prevStateId = 0; prevStateId < S; prevStateId++) {
						int prevVal = dp[type][prevK][prevStateId];
						if (prevVal == 0) {
							continue;
						}

//						System.err.println(zzz + " " + type + " " + prevK + " "
//								+ prevStateId + " " + prevVal);

						Trie.Node prevState = all.get(prevStateId);
						// System.err.println("?");
						for (int here = 0; here < alph; here++) {
							// System.err.println("??");
							Trie.Node newState = prevState.go[here];
							int newStateId = newState.id;
							int newK = prevK + newState.value;
							if (type == 0 && here == 0) {
								next[0][0][0] = (next[0][0][0] + prevVal) % MOD;
							}
							if (newK > k) {
								continue;
							}
							if (type == 0) {
								if (here != 0) {
									next[1][newK][newStateId] = (next[1][newK][newStateId] + prevVal)
											% MOD;
								}
							} else if (type == 1) {
								next[1][newK][newStateId] = (next[1][newK][newStateId] + prevVal)
										% MOD;
							} else if (type == 2) {
								if (here > dig) {
									continue;
								}
								if (here == dig) {
									next[2][newK][newStateId] = (next[2][newK][newStateId] + prevVal)
											% MOD;
								} else {
									next[1][newK][newStateId] = (next[1][newK][newStateId] + prevVal)
											% MOD;
								}
							}
						}
					}

			int[][][] tmp = next;
			next = dp;
			dp = tmp;
		}

		int ret = 0;
		for (int type = 1; type < 3; type++) {
			for (int val = 0; val <= k; val++) {
				for (int stateId = 0; stateId < S; stateId++) {
					ret += dp[type][val][stateId];
					ret %= MOD;
				}
			}
		}

		return ret;
	}

	void solve() throws IOException {
		int n = nextInt();
		alph = nextInt();
		k = nextInt();

		// if (n == 20 && alph == 12 && k == 12) {
		// out.println(133064129);
		// return;
		// }

		int[] low = readTofu();
		int[] high = readTofu();

		low = decreaseByOne(low);

		t = new Trie();

		for (int i = 0; i < n; i++) {
			int[] word = readTofu();
			int value = nextInt();
			t.addString(word, value);
		}

		t.buildAutomaton(alph);

		int ans = solve(high) - solve(low);
		if (ans < 0) {
			ans += MOD;
		}
		out.println(ans);
	}

	static class Trie {

		List<Node> all = new ArrayList<>();

		class Node {

			Node child, sibling;
			Node sufLink;
			int parSymb;

			int value;
			int id;

			Node[] go;

			Node goChild(int symb) {
				Node res = child;
				while (res != null && res.parSymb != symb)
					res = res.sibling;
				return res;
			}

			Node go(int symb) {
				for (Node v = this; v != null; v = v.sufLink) {
					Node res = v.goChild(symb);
					if (res != null)
						return res;
				}
				return root;
			}

			public Node(Node sibling, int parSymb) {
				this();
				this.sibling = sibling;
				this.parSymb = parSymb;
			}

			public Node() {
				this.id = all.size();
				all.add(this);
			}
		}

		Node root = new Node();

		Node addString(int[] s, int value) {
			Node cur = root;
			for (int i = 0; i < s.length; i++) {
				int symb = s[i];
				Node next = cur.goChild(symb);
				if (next == null) {
					next = new Node(cur.child, symb);
					cur.child = next;
				}
				cur = next;
			}
			cur.value += value;
			return cur;
		}

		void buildAutomaton(int alph) {
			Queue<Node> q = new ArrayDeque<>();
			for (Node to = root.child; to != null; to = to.sibling) {
				to.sufLink = root;
				to.value += to.sufLink.value;
				q.add(to);
			}

			while (!q.isEmpty()) {
				Node v = q.poll();
				for (Node to = v.child; to != null; to = to.sibling) {
					to.sufLink = v.sufLink.go(to.parSymb);
					to.value += to.sufLink.value;
					q.add(to);
				}
			}

			for (Node v : all) {
				v.go = new Node[alph];
				for (int i = 0; i < alph; i++) {
					v.go[i] = v.go(i);
				}
			}
		}
	}

	static final int MOD = 1_000_000_007;

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new WTF().inp();
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