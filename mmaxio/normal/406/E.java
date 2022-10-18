import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int ansVal = -1;
	long ansCnt = 0;

	void updateAns(int val, long count) {
		if (count == 0) {
			return;
		}
		if (val > ansVal) {
			ansVal = val;
			ansCnt = count;
		} else if (val == ansVal) {
			ansCnt += count;
		}
	}

	static class Group {
		int val;
		int rep;

		public Group(int val, int rep) {
			this.val = val;
			this.rep = rep;
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();

		List<Integer> aList = new ArrayList<>();
		List<Integer> bList = new ArrayList<>();

		int na, nb;

		for (int i = 0; i < m; i++) {
			int type = nextInt();
			int val = nextInt();
			(type == 0 ? aList : bList).add(val);
		}

		na = aList.size();
		nb = bList.size();

		Group[] a = makeGroups(aList);
		Group[] b = makeGroups(bList);

		solve1(a, na);
		solve1(b, nb);
		solve2(a, b, n, na, nb);
		solve2(b, a, n, nb, na);
		
		// System.err.println(ansVal);
		out.println(ansCnt);
	}

	Group[] makeGroups(List<Integer> a) {
		Collections.sort(a);
		List<Group> b = new ArrayList<>();
		for (int i = 0, j = -1; i < a.size(); i = j) {
			j = i;
			int st = a.get(i);
			while (j < a.size() && a.get(j).intValue() == st) {
				j++;
			}
			b.add(new Group(st, j - i));
		}
		return b.toArray(new Group[b.size()]);
	}

	void solve1(Group[] a, int realLen) {
		if (a.length == 0) {
			return;
		}
		int n = a.length;
		int val = 2 * (a[n - 1].val - a[0].val);
		long count;
		if (a.length == 1) {
			count = (long) realLen * (realLen - 1) * (realLen - 2) / 6;
		} else {
			int pref = a[0].rep;
			int suff = a[n - 1].rep;

			count = (long) pref * (realLen - pref - suff) * suff + (long) pref
					* (pref - 1) / 2 * suff + (long) pref * suff * (suff - 1)
					/ 2;
		}
		updateAns(val, count);
	}

	long C2(int x) {
		return (long) x * (x - 1) / 2;
	}

	void solve2(Group[] a, Group[] b, int n, int realLenA, int realLenB) {
		int na = a.length;
		int nb = b.length;

		if (na == 0 || nb == 0) {
			return;
		}
		// j is last in b <= a[i]

		int totBNotMore = 0;
		int totBMore = realLenB;

		for (int i = 0, j = -1; i < na; i++) {
			while (j < nb - 1 && b[j + 1].val <= a[i].val) {
				j++;
				totBNotMore += b[j].rep;
				totBMore -= b[j].rep;
			}

			// both <=
			if (j >= 0) {
				int val = 2 * (b[j].val + n - a[i].val);
				long count = (long) a[i].rep
						* (C2(totBNotMore) - C2(totBNotMore - b[j].rep));
				updateAns(val, count);
			}

			// <= and >
			if (j >= 0 && j < nb - 1) {
				int val = 2 * n;
				long count = (long) a[i].rep * totBNotMore * totBMore;
				System.err.println(a[i].val + " " + count);
				updateAns(val, count);
			}

			// both >
			if (j < nb - 1) {
				// System.err.println("?");
				int val = 2 * (-b[j + 1].val + n + a[i].val);
				long count = (long) a[i].rep
						* (C2(totBMore) - C2(totBMore - b[j + 1].rep));
				updateAns(val, count);
			}
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