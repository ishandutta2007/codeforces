import java.io.*;
import java.util.*;

public class C_new {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}

		List<Integer> bad = new ArrayList<>();

		int[] arrBad = new int[n - 1];
		int totBad = 0;

		for (int i = 0; i < n - 1; i++) {
			if ((i % 2 == 0 && a[i] >= a[i + 1])
					|| (i % 2 == 1 && a[i] <= a[i + 1])) {
				bad.add(i);
				totBad++;
				arrBad[i] = 1;
			}
		}

		if (bad.size() > 4) {
			out.println(0);
			return;
		}
		
		HashSet<Long> set = new HashSet<>();

		int ret = 0;

		for (int i1 = 0; i1 < bad.size(); i1++) {
			for (int ii = 0; ii < 2; ii++) {

				int x = bad.get(i1) + ii;

				for (int y = 0; y < n; y++) {
					
					if (x == y) {
						continue;
					}
					
					int low = Math.min(x, y);
					int high = Math.max(x, y);
					
					long hash = (long)low * n + high;
					if (set.contains(hash)) {
						continue;
					}
					set.add(hash);
					
					
					int tmp = a[low];
					a[low] = a[high];
					a[high] = tmp;
					
					int nowBad = totBad;

					if (low != 0) {
						int i = low - 1;
						int here;
						if ((i % 2 == 0 && a[i] >= a[i + 1])
								|| (i % 2 == 1 && a[i] <= a[i + 1]))
							here = 1;
						else
							here = 0;
						nowBad += here - arrBad[i];
					}
					
					if (low != n - 1) {
						int i = low;
						int here;
						if ((i % 2 == 0 && a[i] >= a[i + 1])
								|| (i % 2 == 1 && a[i] <= a[i + 1]))
							here = 1;
						else
							here = 0;
						nowBad += here - arrBad[i];
					}
					
					
					if (high != low + 1) {
						int i = high - 1;
						int here;
						if ((i % 2 == 0 && a[i] >= a[i + 1])
								|| (i % 2 == 1 && a[i] <= a[i + 1]))
							here = 1;
						else
							here = 0;
						nowBad += here - arrBad[i];
					}
					
					if (high != n - 1) {
						int i = high;
						int here;
						if ((i % 2 == 0 && a[i] >= a[i + 1])
								|| (i % 2 == 1 && a[i] <= a[i + 1]))
							here = 1;
						else
							here = 0;
						nowBad += here - arrBad[i];
					}
					
					if (nowBad == 0) {
						ret++;
					}
					
					tmp = a[x];
					a[x] = a[y];
					a[y] = tmp;

				}
			}
		}

		out.println(ret);
	}

	C_new() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C_new();
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