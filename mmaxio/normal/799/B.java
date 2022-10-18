import java.io.*;
import java.util.*;

public class B {
	void submit() {
		int n = nextInt();
		int[] costs = new int[n];
		int[] a = new int[n];
		int[] b = new int[n];

		TreeSet<Integer>[][] c = new TreeSet[3][3];
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				c[i][j] = new TreeSet<Integer>();
			}
		}

		for (int i = 0; i < n; i++) {
			costs[i] = nextInt();
		}

		for (int i = 0; i < n; i++) {
			a[i] = nextInt() - 1;
		}

		for (int i = 0; i < n; i++) {
			b[i] = nextInt() - 1;
		}

		for (int i = 0; i < n; i++) {
			c[a[i]][b[i]].add(costs[i]);
		}

		int q = nextInt();
		while (q-- > 0) {
			int best = nextInt() - 1;
			int ix = -1, iy = -1;
			int bestP = Integer.MAX_VALUE;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if ((i == best) || (j == best)) {
						if (!c[i][j].isEmpty()) {
							int here = c[i][j].first();
							if (here < bestP) {
								bestP = here;
								ix = i;
								iy = j;
							}
						}
					}
				}
			}
			if (ix == -1) {
				out.print(-1 + " ");
			} else {
				out.print(bestP + " ");
				c[ix][iy].remove(bestP);
			}
		}
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	B() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
		// stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new B();
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