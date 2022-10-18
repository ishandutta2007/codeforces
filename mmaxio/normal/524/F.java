import java.io.*;
import java.util.*;

public class Buffering {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int[] buildSuffixArray(int[] s, int alphSize) {
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

		for (int h = 1; h <= n; h <<= 1) {

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

	void solve() throws IOException {
		String ss = nextToken();
		int n = ss.length();
		int[] s = new int[n];
		int[] bal = new int[n + 1];
		for (int i = 0; i < n; i++) {
			s[i] = ss.charAt(i) == '(' ? 0 : 1;
			if (s[i] == 0) {
				bal[i + 1] = bal[i] + 1;
			} else {
				bal[i + 1] = bal[i] - 1;
			}
		}
		int[] sa = buildSuffixArray(s, 2);
		int[] order = new int[n];
		for (int i = 0; i < n; i++) {
			order[sa[i]] = i;
		}
		int minBal = 0;
		for (int i = 0; i <= n; i++) {
			minBal = Math.min(minBal, bal[i]);
		}

		int[] minSuff = new int[n + 1];
		int[] minPref = new int[n + 1];
		minPref[0] = bal[0];
		for (int i = 1; i <= n; i++) {
			minPref[i] = Math.min(minPref[i - 1], bal[i]);
		}
		minSuff[n] = bal[n];
		for (int i = n - 1; i >= 0; i--) {
			minSuff[i] = Math.min(minSuff[i + 1], bal[i]);
		}

		int pos = -1;
		// System.err.println(Arrays.toString(bal) + " " + minBal);
		for (int i = 0; i <= n; i++) {
			// if ((bal[n] <= 0 && bal[i] == minBal)
			// || (bal[n] > 0 && bal[i] <= minBal + bal[n])) {
			boolean cond;
			if (bal[n] >= 0) {
				cond = minSuff[i] - bal[i] >= 0;
				if (i > 0) {
					cond &= minPref[i - 1] + (bal[n] - bal[i]) >= 0;
				}
			} else {
				cond = (minSuff[i] - bal[i]) >= bal[n];
				if (i > 0) {
					cond &= minPref[i - 1] + (bal[n] - bal[i]) >= bal[n];
				}
			}
			if (cond) {

				if (pos == -1) {
					pos = i;
				} else {
					if (order[i % n] <= order[pos]) {
						pos = i;
					}
				}
			}
		}

		for (int i = 0; i < -bal[n]; i++) {
			out.print('(');
		}
		out.print(ss.substring(pos));
		out.print(ss.substring(0, pos));
		for (int i = 0; i < bal[n]; i++) {
			out.print(')');
		}
		out.println();
	}

	// ((()())

	Buffering() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new Buffering();
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