import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	long[] f;
	long[] cnt;

	void add(long[] f, int pos, int delta) {
//		System.err.println(pos + " " + delta);
		for (int i = pos; i < f.length; i |= i + 1) {
			f[i] += delta;
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int q = nextInt();
		int[] a = new int[n];

		List<Integer> allList = new ArrayList<>(n);

		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
			allList.add(a[i]);
		}
		long[][] qs = new long[q][3];
		for (int i = 0; i < q; i++) {
			qs[i][0] = nextInt();
			if (qs[i][0] == 1) {
				qs[i][1] = nextInt() - 1;
				qs[i][2] = nextInt();
				allList.add((int) qs[i][2]);
			} else {
				qs[i][1] = nextLong();
			}
		}

		makeUnique(allList);
		int N = allList.size();
		int[] all = new int[N];
		for (int i = 0; i < N; i++) {
			all[i] = allList.get(i);
		}

		f = new long[N];
		cnt = new long[N];
		for (int i = 0; i < n; i++) {
			a[i] = Arrays.binarySearch(all, a[i]);
			add(f, a[i], all[a[i]]);
			add(cnt, a[i], 1);
		}

		for (int i = 0; i < q; i++) {
			if (qs[i][0] == 1) {
				int pos = (int) qs[i][1];
				int newVal = Arrays.binarySearch(all, (int) qs[i][2]);
				add(f, a[pos], -all[a[pos]]);
				add(cnt, a[pos], -1);

				a[pos] = newVal;
				add(f, newVal, all[newVal]);
				add(cnt, newVal, 1);
			} else {
				long add = qs[i][1];
				double low = 0;
				double high = 1_000_000_000.0 + 1.0 * add / n;
				// double low = 5.0 / 3, high = 5.0 / 3;
				for (int iter = 0; iter < 70; iter++) {
					// for (int iter = 0; iter < 1; iter++) {
					double mid = (low + high) * 0.5;
					int pos = binSearch(all, mid);
					// System.err.println(pos);
					long sum = get(f, pos);
					long curCnt = get(cnt, pos);
					// System.err.println(sum);
					if (pos == -1) {
						low = mid;
						continue;
					}
					double res = 1.0 * (sum + add) / curCnt;
					if (res < mid) {
						high = mid;
					} else {
						low = mid;
					}
				}
				out.println((low + high) * 0.5);
			}
		}

	}

	long get(long[] f, int pos) {
		long ret = 0;
		for (int i = pos; i >= 0; i = (i & (i + 1)) - 1) {
			ret += f[i];
		}
		return ret;
	}

	int binSearch(int[] all, double x) {
		int low = -1;
		int high = all.length;
		while (low + 1 < high) {
			int mid = (low + high) >> 1;
			if (all[mid] <= x) {
				low = mid;
			} else {
				high = mid;
			}
		}
		return low;
	}

	void makeUnique(List<Integer> a) {
		Collections.sort(a);
		int sz = 1;
		for (int i = 1; i < a.size(); i++) {
			if (!a.get(i).equals(a.get(sz - 1))) {
				a.set(sz++, a.get(i));
			}
		}
		for (int i = a.size() - 1; i >= sz; i--) {
			a.remove(i);
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