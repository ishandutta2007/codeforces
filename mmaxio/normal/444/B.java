import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	long x;

	long getNextX() {
		x = (x * 37 + 10007) % 1000000007;
		return x;
	}

	void solve() throws IOException {
		int n = nextInt();
		int d = nextInt();
		x = nextLong();

		int[] a = new int[n];
		int[] b = new int[n];

		for (int i = 0; i < n; i++) {
			a[i] = i;
		}
		for (int i = 0; i < n; i = i + 1) {
			int j = (int) (getNextX() % (i + 1));
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
		for (int i = 0; i < n; i++) {
			if (i < d)
				b[i] = 1;
			else
				b[i] = 0;
		}
		for (int i = 0; i < n; i = i + 1) {
			int j = (int) (getNextX() % (i + 1));
			int tmp = b[i];
			b[i] = b[j];
			b[j] = tmp;
		}

		int[] inv = new int[n];
		for (int i = 0; i < n; i++) {
			inv[a[i]] = i;
		}

		int[] ans = new int[n];
		Arrays.fill(ans, -1);
		int[] put = new int[d];
		for (int i = 0, j = 0; i < n; i++) {
			if (b[i] == 1) {
				put[j++] = i;
			}
		}
		TreeSet<Integer> left = new TreeSet<>();
		for (int i = 0; i < n; i++) {
			left.add(i);
		}

		List<Integer> rem = new ArrayList<Integer>(n);

		for (int val = n - 1; val >= 0; val--) {
			int pos = inv[val];
			int szPut = Arrays.binarySearch(put, n - pos);
			if (szPut < 0) {
				szPut = -szPut - 2;
			}
			if (szPut < left.size()) {
				for (int i = 0; i < d; i++) {
					if (pos + put[i] >= n) {
						break;
					}
					if (ans[pos + put[i]] == -1) {
						ans[pos + put[i]] = val;
						left.remove(pos + put[i]);
					}
				}
			} else {
				rem.clear();
				for (Integer p : left.tailSet(pos)) {
					if (b[p - pos] == 1) {
						rem.add(p);
						ans[p] = val;
					}
				}
				for (Integer x : rem) {
					left.remove(x);
				}
			}
		}

		for (int i = 0; i < n; i++) {
			out.println(ans[i] + 1);
		}
	}

	B() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B();
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