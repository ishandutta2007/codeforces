import java.io.*;
import java.util.*;

public class E {

	static final double EPS = 1e-8;
	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		long start = System.currentTimeMillis();

		int n = nextInt();
		final double[] d = new double[n];

		double[][] p = new double[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				p[i][j] = nextInt() * 0.01;
			}
			d[i] = p[i][n - 1] == 0 ? 100 * (n - 1) : 1 / p[i][n - 1];
		}
		d[n - 1] = 0;

		Integer[] order = new Integer[n];
		for (int i = 0; i < n; i++) {
			order[i] = i;
		}

		Comparator<Integer> byExp = (Integer a, Integer b) -> Double.compare(
				d[a], d[b]);

		boolean stop = false;
		while (true) {
			Arrays.sort(order, byExp);
			for (int i = n - 1; i >= 1; i--) {
				int v = order[i];
				double prob = 1;
				double exp = 1;
				for (int j = 0; j < i; j++) {
					int u = order[j];
					exp += prob * p[v][u] * d[u];
					prob *= 1 - p[v][u];
					if (prob == 0) {
						break;
					}
				}
				
				// x = exp + prob * x
				if (prob != 1) {
					double tmp = exp / (1 - prob);
					if (d[v] > tmp) {
						d[v] = tmp;
						stop = false;
					}
				}
			}
			if (stop) {
				break;
			}
			stop = true;
		}
		out.println(d[0]);
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