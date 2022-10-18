import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int[] diff;
	static final int MOD = 1_000_000_007;

	class SuffixTree {
		class Node {
			Node par;
			Node child, sibling;
			Node sufLink;
			int l, r;

			int val1, val2, val3;
			int depth;

			int len() {
				return getR() - l;
			}

			int getR() {
				return r == -1 ? s.length() : r;
			}

			Node() {
			}

			Node(Node par, Node child, Node sibling, Node sufLink, int l, int r) {
				this.par = par;
				this.child = child;
				this.sibling = sibling;
				this.sufLink = sufLink;
				this.l = l;
				this.r = r;
			}

			Node go(char c) {
				for (Node to = child; to != null; to = to.sibling) {
					if (s.charAt(to.l) == c)
						return to;
				}
				return null;
			}

			void dfs(int len1, int len2, int len3, int curDepth) {
				depth = curDepth;
				if (child == null) {
					if (depth >= 2 && depth <= len3 + 1) {
						val3 = 1;
					}
					if (depth >= len3 + 3 && depth <= len2 + len3 + 2) {
						val2 = 1;
					}
					if (depth >= len2 + len3 + 4
							&& depth <= len1 + len2 + len3 + 3) {
						val1 = 1;
					}
					return;
				}
				for (Node to = child; to != null; to = to.sibling) {
					to.dfs(len1, len2, len3, curDepth + to.len());
					val1 += to.val1;
					val2 += to.val2;
					val3 += to.val3;
				}

				if (par != null) {
					int delta = (int) ((long) val1 * val2 % MOD * val3 % MOD);
					if (delta != 0) {
						int from = depth - this.len() + 1;
						int to = depth;
						// [from; to]
						diff[from] = (diff[from] + delta) % MOD;
						diff[to + 1] = (diff[to + 1] + MOD - delta) % MOD;
					}
				}

			}
		}

		void splitEdge() {
			Node v = new Node(curNode.par, curNode, curNode.sibling, null,
					curNode.l, curNode.l + curPos);
			curNode.sibling = null;
			curNode.par = v;
			curNode.l = curNode.l + curPos;

			for (Node to = v.par.child; to != null; to = to.sibling) {
				if (to.sibling == curNode) {
					to.sibling = v;
					break;
				}
			}

			if (v.par.child == curNode) {
				v.par.child = v;
			}

			curNode = v;

		}

		private boolean addChar(char c) {

			if (curPos < curNode.len()) {
				if (s.charAt(curNode.l + curPos) == c) {
					curPos++;
					return false;
				}
				splitEdge();
			}

			if (curPos != curNode.len()) {
				throw new AssertionError("Bug in edge splitting");
			}

			Node tmp = curNode.go(c);
			if (tmp != null) {
				curNode = tmp;
				curPos = 1;
				return false;
			}

			// add child
			Node add = new Node(curNode, null, curNode.child, null, curExt
					+ curDepth, -1);
			curNode.child = add;

			return true;

		}

		void add(char c) {
			s.append(c);

			Node needSufLink = null;

			while (curExt < s.length()) {

				// Already have sufLink
				if (curPos == curNode.len() && needSufLink != null) {
					needSufLink.sufLink = curNode;
					needSufLink = null;
				}

				if (!addChar(c)) {
					// type 3 extension
					curDepth++;
					break;
				}

				// Just created sufLink
				if (needSufLink != null) {
					needSufLink.sufLink = curNode;
					needSufLink = null;
				}

				if (curExt == s.length() - 1) {
					curExt++;
					break;
				}

				if (curNode.sufLink == null) {

					needSufLink = curNode;

					// up to parent
					int downL = curNode.l;
					int downR = curNode.l + curPos;
					curDepth -= curNode.len();
					curNode = curNode.par;

					if (curNode == root) {
						downL = curExt + 1;
						downR = s.length() - 1;
					} else {
						// use sufLink
						curNode = curNode.sufLink;
						curDepth--;
					}

					curDepth += downR - downL;

					// go down
					outer: while (true) {
						if (downL == downR) {
							// stopped in node
							curPos = curNode.len();
							break;
						}

						curNode = curNode.go(s.charAt(downL));

						if (curNode == null) {
							throw new AssertionError("Skip/count bug");
						}

						if (downL + curNode.len() > downR) {
							// stopped in edge
							curPos = downR - downL;
							break outer;
						} else {
							downL += curNode.len();
							continue outer;
						}

					}
				} else {
					curNode = curNode.sufLink;
					curDepth--;
					curPos = curNode.len();
				}

				curExt++;
			}
		}

		void dfs(int len1, int len2, int len3) {
			root.dfs(len1, len2, len3, 0);
		}

		Node root = new Node();
		StringBuilder s = new StringBuilder();

		int curExt;
		Node curNode = root;
		int curPos;
		int curDepth;
	}

	void solve() throws IOException {
		String s1 = nextToken();
		String s2 = nextToken();
		String s3 = nextToken();
		SuffixTree t = new SuffixTree();
		for (char c : s1.toCharArray()) {
			t.add(c);
		}
		t.add((char) 0);

		for (char c : s2.toCharArray()) {
			t.add(c);
		}
		t.add((char) 1);

		for (char c : s3.toCharArray()) {
			t.add(c);
		}
		t.add((char) 2);

		diff = new int[Math
				.min(s1.length(), Math.min(s2.length(), s3.length())) + 2];
		t.dfs(s1.length(), s2.length(), s3.length());

		int[] ans = new int[diff.length - 1];
		ans[0] = diff[0];
		for (int i = 1; i < ans.length; i++) {
			ans[i] = (ans[i - 1] + diff[i]) % MOD;
		}
		for (int i = 1; i < ans.length; i++) {
			out.print(ans[i] + " ");
		}
	}

	E() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new E();
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