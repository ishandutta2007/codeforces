import java.io.*;
import java.util.*;

public class F {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int[] buildSuffixArray(char[] s, int alphSize) {
		// sorts cyclic shifs, append a sentinel to the end if suffix array is
		// needed
		int n = s.length;
		int[] cnt = new int[Math.max(alphSize, n)];

		for (int i = 0; i < n; i++) {
			cnt[s[i]]++;
		}
		for (int i = 1; i < alphSize; i++) {
			cnt[i] += cnt[i - 1];
		}

		int[] arr = new int[n];
		for (int i = n - 1; i >= 0; i--) {
			arr[--cnt[s[i]]] = i;
		}

		int[] cls = new int[n];
		int nCl = 1;

		for (int i = 1; i < n; i++) {
			int curSuff = arr[i];
			if (s[curSuff] != s[arr[i - 1]]) {
				nCl++;
			}
			cls[curSuff] = nCl - 1;
		}

		int[] aux = new int[n];

		for (int h = 1; h < n && nCl < n; h <<= 1) {

			// aux - suffixes ordered by second halves
			for (int i = 0; i < n; i++) {
				int tmp = arr[i] - h;
				if (tmp < 0)
					tmp += n;
				aux[i] = tmp;
			}

			Arrays.fill(cnt, 0, nCl, 0);
			for (int i = 0; i < n; i++) {
				cnt[cls[i]]++;
			}
			for (int i = 1; i < nCl; i++) {
				cnt[i] += cnt[i - 1];
			}

			for (int i = n - 1; i >= 0; i--) {
				int curSuff = aux[i];
				arr[--cnt[cls[curSuff]]] = curSuff;
			}

			// aux - new classes
			aux[arr[0]] = 0;
			nCl = 1;
			for (int i = 1; i < n; i++) {
				int curPos = arr[i];
				int prevPos = arr[i - 1];
				if (cls[curPos] == cls[prevPos]) {
					int tmpCurPos = curPos + h;
					if (tmpCurPos >= n)
						tmpCurPos -= n;
					prevPos += h;
					if (prevPos >= n)
						prevPos -= n;
					if (cls[tmpCurPos] != cls[prevPos])
						nCl++;
				} else {
					nCl++;
				}
				aux[curPos] = nCl - 1;
			}

			int[] tmp = aux;
			aux = cls;
			cls = tmp;
		}

		return arr;
	}

	int[] buildLCP(char[] s, int[] arr, int[] inv) {

		int n = s.length;

		int[] lcp = new int[n - 1];
		for (int i = 0, x = 0; i < n; i++) {
			if (x != 0)
				x--;
			int pos = inv[i];
			if (pos == n - 1)
				continue;
			int j = arr[pos + 1];
			while (i + x < n && j + x < n && s[i + x] == s[j + x])
				x++;
			lcp[pos] = x;
		}
		return lcp;
	}

	static class Index implements Comparable<Index> {
		int bal, pos;

		@Override
		public int compareTo(Index o) {
			if (bal != o.bal) {
				return bal < o.bal ? -1 : 1;
			}
			return Integer.compare(pos, o.pos);
		}

		public Index(int bal, int pos) {
			this.bal = bal;
			this.pos = pos;
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		char[] f = nextToken().toCharArray();

		f = Arrays.copyOf(f, n + 1);

		for (int i = 0; i < n; i++) {
			f[i] = (char) (f[i] == '(' ? 1 : 2);
		}
		f[n] = 0;

		int[] sa = buildSuffixArray(f, 3);
		int[] inv = new int[n + 1];
		for (int i = 0; i <= n; i++) {
			inv[sa[i]] = i;
		}
		int[] lcp = buildLCP(f, sa, inv);

//		System.err.println(Arrays.toString(sa));
//		System.err.println(Arrays.toString(lcp));

		Index[] a = new Index[n + 1];
		int balance = 0;
		for (int i = 0; i < n; i++) {
			a[i] = new Index(balance, i);
			balance += (f[i] == 1 ? 1 : -1);
		}
		a[n] = new Index(balance, n);

		Arrays.sort(a);

		TreeSet<Integer> big = new TreeSet<>();

		long ret = 0;

		for (int i = 0; i <= n;) {
			int j = i;
			while (j <= n && a[i].bal == a[j].bal) {
				j++;
			}

			int[] arr = new int[j - i];
			for (int k = i; k < j; k++) {
				arr[k - i] = a[k].pos;
			}

//			System.err.println(Arrays.toString(arr));

			for (int k = arr.length - 1; k >= 0; k--) {
				int suff = arr[k];
				Integer tmp = big.higher(suff);
				int to = (tmp == null ? n + 1 : tmp);

				int same = inv[suff] == 0 ? 0 : lcp[inv[suff] - 1];
				int from = suff + same + 1;

//				System.err.println(suff + " " + from + " " + to);
				if (from <= to)
					ret += count(arr, from, to);
//				System.err.println(suff + " " + from + " " + to);
			}

			for (int k = 0; k < arr.length; k++) {
				big.add(arr[k]);
			}

			i = j;
		}

		out.println(ret);
	}

	int count(int[] arr, int from, int to) {
		// #x: from <= x < to
		to = Arrays.binarySearch(arr, to);
		if (to < 0) {
			to = -to - 1;
		}

		from = Arrays.binarySearch(arr, from);
		if (from < 0) {
			from = -from - 1;
		}
		return to - from;
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