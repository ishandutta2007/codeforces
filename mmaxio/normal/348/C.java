import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int ROOT = 316;

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int q = nextInt();

		long[] a = new long[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}

		List<HashSet<Integer>> bigSetsList = new ArrayList<>();
		List<HashSet<Integer>> smallSetsList = new ArrayList<>();

		HashSet<Integer>[] sets = new HashSet[m];
		boolean[] isBig = new boolean[m];
		int[] index = new int[m];

		List<Long> bigSumsList = new ArrayList<>();

		int[][] arrSets = new int[m][];
		for (int i = 0; i < m; i++) {
			int sz = nextInt();
			sets[i] = new HashSet<>(sz);
			arrSets[i] = new int[sz];
			long curSum = 0;
			for (int j = 0; j < sz; j++) {

				arrSets[i][j] = nextInt() - 1;
				sets[i].add(arrSets[i][j]);
				curSum += a[arrSets[i][j]];
			}
			if (sz >= ROOT) {
				isBig[i] = true;
				index[i] = bigSetsList.size();
				bigSetsList.add(sets[i]);
				bigSumsList.add(curSum);
			} else {
				isBig[i] = false;
				index[i] = smallSetsList.size();
				smallSetsList.add(sets[i]);
			}
		}

		HashSet<Integer>[] bigSets = new HashSet[bigSetsList.size()];
		for (int i = 0; i < bigSetsList.size(); i++) {
			bigSets[i] = bigSetsList.get(i);
		}

		HashSet<Integer>[] smallSets = new HashSet[smallSetsList.size()];
		for (int i = 0; i < smallSetsList.size(); i++) {
			smallSets[i] = smallSetsList.get(i);
		}

		long[] bigSums = new long[bigSumsList.size()];
		for (int i = 0; i < bigSumsList.size(); i++) {
			bigSums[i] = bigSumsList.get(i);
		}

		int nBig = bigSets.length;
		int nSmall = smallSets.length;

		int[][] bigBigInter = new int[nBig][nBig];
		for (int i = 0; i < nBig; i++) {
			bigBigInter[i][i] = bigSets[i].size();
			for (int j = i + 1; j < nBig; j++) {
				bigBigInter[i][j] = bigBigInter[j][i] = interSize(bigSets[i],
						bigSets[j]);
			}
		}

		int[][] smallBigInter = new int[nSmall][nBig];
		for (int i = 0; i < nSmall; i++)
			for (int j = 0; j < nBig; j++) {
				smallBigInter[i][j] = interSize(smallSets[i], bigSets[j]);
			}

		long[] bigTotalAdd = new long[nBig];

		while (q-- > 0) {
			char type = nextToken().charAt(0);
			if (type == '?') {
				int ind = nextInt() - 1;
				if (isBig[ind]) {
					int bigInd = index[ind];
					out.println(bigSums[bigInd]);
				} else {
					int smallInd = index[ind];
					int[] cache = smallBigInter[smallInd];
					long ans = 0;
					for (int i = 0; i < nBig; i++) {
						ans += cache[i] * bigTotalAdd[i];
					}
					cache = arrSets[ind];
					for (int i = 0; i < cache.length; i++) {
						ans += a[cache[i]];
					}

					out.println(ans);
				}
			} else {
				int ind = nextInt() - 1;
				long delta = nextInt();
				if (isBig[ind]) {
					int bigInd = index[ind];
					bigTotalAdd[bigInd] += delta;

					int[] cache = bigBigInter[bigInd];
					for (int i = 0; i < cache.length; i++) {
						bigSums[i] += cache[i] * delta;
					}
				} else {
					int smallInd = index[ind];
					int[] cache = smallBigInter[smallInd];
					for (int i = 0; i < cache.length; i++) {
						bigSums[i] += cache[i] * delta;
					}

					cache = arrSets[ind];
					for (int i = 0; i < cache.length; i++) {
						a[cache[i]] += delta;
					}
				}
			}
		}

	}

	static int interSize(HashSet<Integer> a, HashSet<Integer> b) {
		if (a.size() > b.size()) {
			HashSet<Integer> tmp = a;
			a = b;
			b = tmp;
		}
		int ret = 0;
		for (Integer x : a) {
			if (b.contains(x))
				ret++;
		}
		return ret;
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