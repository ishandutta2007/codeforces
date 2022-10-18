import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int ROOT;
	int K;

	void update(int part) {
		long curSum = 0;
		int curMax = -1;
		for (int i = part * ROOT; i < (part + 1) * ROOT; i++) {
			curSum += arr[i];
			curMax = Math.max(curMax, arr[i]);
		}
		max[part] = curMax;
		sum[part] = curSum;
	}

	int[] arr, max;
	long[] sum;

	void solve() throws IOException {
		int n = nextInt();
		int qq = nextInt();

		ROOT = (int) (Math.sqrt(n) + 1);
		K = n / ROOT + 1;

		arr = new int[ROOT * K];
		max = new int[K];
		sum = new long[K];

		for (int i = 0; i < n; i++) {
			arr[i] = nextInt();
		}

		for (int i = 0; i < K; i++) {
			update(i);
		}

		while (qq-- > 0) {
			int type = nextInt();
			if (type == 1) {
				int l = nextInt() - 1;
				int r = nextInt() - 1;

				int partL = l / ROOT;
				int partR = r / ROOT;
				long outp = 0;
				if (partL == partR) {
					for (int i = l; i <= r; i++) {
						outp += arr[i];
					}
				} else {

					for (int i = l; i < (partL + 1) * ROOT; i++) {
						outp += arr[i];
					}
					for (int i = partR * ROOT; i <= r; i++) {
						outp += arr[i];
					}
					for (int i = partL + 1; i < partR; i++) {
						outp += sum[i];
					}
				}
				out.println(outp);

			} else if (type == 2) {
				int l = nextInt() - 1;
				int r = nextInt() - 1;
				int x = nextInt();

				int partL = l / ROOT;
				int partR = r / ROOT;

				// System.err.println(partL + " " + partR);

				if (partL == partR) {
					if (max[partL] >= x) {
						for (int i = l; i <= r; i++) {
							arr[i] %= x;
						}
						update(partL);
					}
				} else {

					if (max[partL] >= x) {

						for (int i = l; i < (partL + 1) * ROOT; i++) {
							arr[i] %= x;
						}
						update(partL);
					}
					if (max[partR] >= x) {
						for (int i = partR * ROOT; i <= r; i++) {
							arr[i] %= x;
						}
						update(partR);
					}
					for (int i = partL + 1; i < partR; i++) {
						if (max[i] >= x) {
							for (int j = i * ROOT; j < (i + 1) * ROOT; j++) {
								arr[j] %= x;
							}
							update(i);
						}
					}
				}
			} else if (type == 3) {
				int k = nextInt() - 1;
				int x = nextInt();
				arr[k] = x;
				int part = k / ROOT;
				update(part);
			}
			// System.err.println(Arrays.toString(arr));
		}
	}

	D() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D();
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