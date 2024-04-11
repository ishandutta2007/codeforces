import java.io.*;
import java.util.*;

public class F_tad_faster {

	long solve(int n, int m, int[] ls, int[] rs) {
		if (m == 1) {
			return 1;
		}

		long ans = 0;

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				ans += solve(ls, rs, i, j, m);
				// System.err.println("CURRENT ANSWER: " + ans);
			}
		}

		int[] add = new int[m + 1];
		for (int i = 0; i < n; i++) {
			add[ls[i]]++;
			add[rs[i] + 1]--;
		}

		long noFountain = 0;
		int streak = 0;

		for (int i = 0; i < m; i++) {
			if (i > 0) {
				add[i] += add[i - 1];
			}
			if (add[i] == 0) {
				streak++;
			} else {
				streak = 0;
			}
			noFountain += (long) streak * (streak + 1) / 2;
		}

		return ans - noFountain;
	}

	static final int B = 15;

	void stress() {
		for (int tst = 0;; tst++) {
			int n = rand(1, B);
			int m = rand(1, B);

			int[] ls = new int[n];
			int[] rs = new int[n];

			for (int i = 0; i < n; i++) {
				ls[i] = rand(0, m - 1);
				rs[i] = rand(0, m - 1);
				if (ls[i] > rs[i]) {
					int tmp = ls[i];
					ls[i] = rs[i];
					rs[i] = tmp;
				}
			}

			long slow = slow(n, m, ls, rs);
			long fast = solve(n, m, ls, rs);
			if (slow != fast) {
				System.err.println(n + " " + m);
				System.err.println(Arrays.toString(ls) + " "
						+ Arrays.toString(rs));
				System.err.println("slow " + slow);
				System.err.println("fast " + fast);
				throw new AssertionError();
			}

			System.err.println(tst);
		}
	}

	long slow(int n, int m, int[] ls, int[] rs) {
		long ans = 0;
		for (int l = 0; l < m; l++) {
			for (int r = l; r < m; r++) {
				boolean allOk = true;
				boolean hadNonEmpty = false;
				for (int i = 0; i < n; i++) {
					int low = Math.max(ls[i], l);
					int high = Math.min(rs[i], r);
					if (low <= high && (high - low) % 2 == 1) {
						allOk = false;
					}
					if (low <= high) {
						hadNonEmpty = true;
					}
				}

				if (allOk && hadNonEmpty) {
					// System.err.println(l + " " +r);
					ans += r - l + 1;
				}

			}
		}
		return ans;
	}

	void submit() {
		int n = nextInt();
		int m = nextInt();
		int[] ls = new int[n];
		int[] rs = new int[n];
		for (int i = 0; i < n; i++) {
			ls[i] = nextInt() - 1;
			rs[i] = nextInt() - 1;
		}

		out.println(solve(n, m, ls, rs));
		// out.println(slow(n, m, ls, rs));
	}

	static final int INF = Integer.MAX_VALUE / 10;

	static class GetResult {
		int max;
		int cntMax;
		long sumMax;
		
		public GetResult(int max, int cntMax, long sumMax) {
			this.max = max;
			this.cntMax = cntMax;
			this.sumMax = sumMax;
		}
	}
	static class Node {

		int l, r;

		Node left, right;

		int delta;
		int max;
		int cntMax;
		long sumMax;

		int getMax() {
			return max + delta;
		}

		void combine() {
			cntMax = left.cntMax;
			sumMax = left.sumMax;
			max = left.getMax();

			if (right.getMax() > left.getMax()) {
				cntMax = right.cntMax;
				sumMax = right.sumMax;
				max = right.getMax();
			} else if (right.getMax() == left.getMax()) {
				cntMax += right.cntMax;
				sumMax += right.sumMax;
			}
		}

		public Node(int l, int r, int odd) {
			this.l = l;
			this.r = r;
			if (r - l > 1) {
				int m = (l + r) >> 1;
				left = new Node(l, m, odd);
				right = new Node(m, r, odd);
				combine();
			} else {
				cntMax = 1;
				sumMax = 2 * l + odd;
				max = 0;
			}
		}

		void add(int ql, int qr, int deltaQ) {
			if (l >= qr || ql >= r) {
				return;
			}
			if (ql <= l && r <= qr) {
				delta += deltaQ;
				return;
			}
			left.add(ql, qr, deltaQ);
			right.add(ql, qr, deltaQ);
			combine();
		}

		GetResult getInfo(int ql, int qr) {
			if (l >= qr || ql >= r) {
				return null;
			}
			if (ql <= l && r <= qr) {
				return new GetResult(getMax(), cntMax, sumMax);
			}

			GetResult retL = left.getInfo(ql, qr);
			GetResult retR = right.getInfo(ql, qr);

			if (retL == null && retR == null) {
				return null;
			}
			if (retL == null) {
				retR.max += delta;
				return retR;
			}
			if (retR == null) {
				retL.max += delta;
				return retL;
			}
			retR.max += delta;
			retL.max += delta;
			if (retL.max > retR.max) {
				return retL;
			}
			if (retL.max < retR.max) {
				return retR;
			}
			retL.cntMax += retR.cntMax;
			retL.sumMax += retR.sumMax;
			return retL;
		}

	}
	
	int[] vis = new int[300000];
	int visVer = 0;
	int[] delta = new int[300000];
	
	int[] listPt = new int[30];
	int listSz = 0;

	long solve(int[] ls, int[] rs, int oddL, int oddR, int m) {

		// System.err.println("solve " + oddL + " " + oddR);

		int cntRs;
		if (oddR == 0) {
			cntRs = (m + 1) / 2;
		} else {
			cntRs = m / 2;
		}

		Node root = new Node(0, cntRs, oddR);

		int n = ls.length;

		// ArrayList<Event>[] evs = new ArrayList[m + 2];
		// for (int i = 0; i < evs.length; i++) {
		// evs[i] = new ArrayList<>();
		// }

		int[] head = new int[m + 2];
		int[] next = new int[6 * n];
		// Event[] what = new Event[6 * n];
		int[] whatPos = new int[6 * n];
		int[][] whatSegms = new int[6 * n][];
		int evPtr = 0;
		Arrays.fill(head, -1);

		int[] posEvs = new int[3];
		int[] posL = new int[3];
		int[] posR = new int[3];

		for (int i = 0; i < n; i++) {
			int low = ls[i];
			int high = rs[i];

			posEvs[0] = 0 + ((0 ^ oddL) & 1);
			posEvs[1] = low + ((low ^ oddL) & 1);
			posEvs[2] = high + (((high + 1) ^ oddL) & 1) + 1;

			posL[0] = -1;
			posL[1] = low + ((low ^ oddR) & 1);
			posL[2] = high + (((high + 1) ^ oddR) & 1) + 1;

			posR[0] = low - (((low - 1) ^ oddR) & 1) - 1;
			posR[1] = high - ((high ^ oddR) & 1);
			int pos = m - 1;
			posR[2] = pos - ((pos ^ oddR) & 1);

			for (int j = 0; j < 3; j++) {
				int whereEv = posEvs[j];
				int[] newSegms = new int[6];
				int ptr = 0;
				for (int k = j; k < 3; k++) {
					int pos1 = posEvs[j];
					int segL = Math.max(posL[k],
							pos1 + ((pos1 ^ oddR) & 1));
					int segR = posR[k];

					if (segL > segR) {
						continue;
					}

					if (!isOk(whereEv, segL, low, high)) {
						continue;
					}

					segL /= 2;
					segR /= 2;

					newSegms[ptr++] = segL;
					newSegms[ptr++] = segR + 1;
				}

				newSegms = Arrays.copyOf(newSegms, ptr);
				// Event newEvent = new Event(i, newSegms);

				next[evPtr] = head[whereEv];
				head[whereEv] = evPtr;
				// what[evPtr++] = newEvent;
				whatPos[evPtr] = i;
				whatSegms[evPtr++] = newSegms;

				// evs[whereEv].add(new Event(i, newSegms));

				// System.err.println(i + " " + whereEv + " " +
				// Arrays.toString(newSegms));
			}

		}

		int[][] segms = new int[n][0];

		long ans = 0;

		for (int l = oddL; l < m; l += 2) {
			for (int e = head[l]; e >= 0; e = next[e]) {
				int idx = whatPos[e];

				int[] newSegms = whatSegms[e];

				int[] oldSegms = segms[idx];

				++visVer;
				listSz = 0;
				for (int i = 0; i < oldSegms.length; i++) {
					int where = oldSegms[i];
					int what = 1 - (i & 1) * 2;
					if (vis[where] != visVer) {
						vis[where] = visVer;
						listPt[listSz++] = where;
						delta[where] = 0;
					}
					delta[where] += what;
				}
				
				for (int i = 0; i < newSegms.length; i++) {
					int where = newSegms[i];
					int what = -1 + (i & 1) * 2;
					if (vis[where] != visVer) {
						vis[where] = visVer;
						listPt[listSz++] = where;
						delta[where] = 0;
					}
					delta[where] += what;
				}
				
				for (int i = 0; i < listSz; i++) {
					int where = listPt[i];
					int what = delta[where];
					if (where > 0 && what != 0) {
						root.add(0, where, what);
					}
				}
				
//				int markOld = 0;
//				int markNew = 0;

//				for (int i = 0; i < oldSegms.length; i += 2) {
//					if (((markOld >> (i >> 1)) & 1) != 0) {
//						continue;
//					}
//					for (int j = 0; j < newSegms.length; j += 2) {
//
//						if (((markNew >> (j >> 1)) & 1) != 0) {
//							continue;
//						}
//
//						int from1 = oldSegms[i];
//						int to1 = oldSegms[i + 1];
//						int from2 = newSegms[j];
//						int to2 = newSegms[j + 1];
//						if (from1 == from2 && to1 == to2) {
//							// System.err.println("?");
//							markOld |= 1 << (i >> 1);
//							markNew |= 1 << (j >> 1);
//							continue;
//						}
//						if (from1 == from2 && to1 < to2) {
//							// System.err.println("?");
//							root.add(to1, to2, 1);
//							markOld |= 1 << (i >> 1);
//							markNew |= 1 << (j >> 1);
//							continue;
//						}
//						if (from1 == from2 && to1 > to2) {
//							// System.err.println("?");
//							root.add(to2, to1, -1);
//							markOld |= 1 << (i >> 1);
//							markNew |= 1 << (j >> 1);
//							continue;
//						}
//						if (from1 < from2 && to1 == to2) {
//							// System.err.println("?");
//							root.add(from1, from2, -1);
//							markOld |= 1 << (i >> 1);
//							markNew |= 1 << (j >> 1);
//							continue;
//						}
//						if (from1 > from2 && to1 == to2) {
//							// System.err.println("?");
//							root.add(from2, from1, 1);
//							markOld |= 1 << (i >> 1);
//							markNew |= 1 << (j >> 1);
//							continue;
//						}
//					}
//				}
//
//				for (int i = 0; i < oldSegms.length; i += 2) {
//					if (((markOld >> (i >> 1)) & 1) != 0) {
//						continue;
//					}
//					int from = oldSegms[i];
//					int to = oldSegms[i + 1];
//					// System.err.println(from + " " + to + " -1");
//					root.add(from, to, -1);
//				}
//
//				for (int i = 0; i < newSegms.length; i += 2) {
//					if (((markNew >> (i >> 1)) & 1) != 0) {
//						continue;
//					}
//					int from = newSegms[i];
//					int to = newSegms[i + 1];
//					// System.err.println(from + " " + to + " 1");
//					root.add(from, to, 1);
//				}
				
				

				segms[idx] = newSegms;
			}

			int justFirstR = l + ((l ^ oddR) & 1);

			// System.err.println("calcualting from " + justFirstR);

			justFirstR /= 2;

			if (justFirstR < cntRs && root.getMax() == n) {
//				long[] get = root.getInfo(justFirstR, cntRs);
				GetResult get = root.getInfo(justFirstR, cntRs);

				int max = get.max;
				if (max == n) {
					int cntMax = get.cntMax;
					long sumMax = get.sumMax;

					long delta = sumMax - (long) cntMax * l + cntMax;
					ans += delta;
				}
			}

		}

		return ans;
	}

	boolean isOk(int a, int b, int c, int d) {
		a = Math.max(a, c);
		b = Math.min(b, d);
		if (a <= b && (b - a) % 2 == 0) {
			return true;
		}
		if (a > b) {
			return true;
		}
		return false;
	}

	static class Event {
		int whichIdx;
		int[] newSegms;

		public Event(int whichIdx, int[] newSegms) {
			this.whichIdx = whichIdx;
			this.newSegms = newSegms;
		}
	}

	void preCalc() {

	}

	void test() {
		int n = 200000;
		int m = 200000;

		int[] ls = new int[n];
		int[] rs = new int[n];

		for (int i = 0; i < n; i++) {
			ls[i] = rand(0, m - 1);
			rs[i] = rand(0, m - 1);
			if (ls[i] > rs[i]) {
				int tmp = ls[i];
				ls[i] = rs[i];
				rs[i] = tmp;
			}
		}

		long start = System.currentTimeMillis();
		long fast = solve(n, m, ls, rs);
		System.err.println(System.currentTimeMillis() - start + " ms");
		System.err.println(fast);
	}

	F_tad_faster() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		 submit();
//		stress();
//		 test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new F_tad_faster();
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