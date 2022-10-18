import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {
	FastScanner in;
	PrintWriter out;

	public void solve() throws IOException {
		int n = in.nextInt();
		int[] w = new int[n];
		int[] h = new int[n];

		for (int i = 0; i < n; i++) {
			w[i] = in.nextInt();
			h[i] = in.nextInt();
			if (w[i] >= h[i]) {
				int q = w[i];
				w[i] = h[i];
				h[i] = q;
			}
		}

		long ans = Integer.MAX_VALUE;
		for (int i = 1; i < 1001; i++) {
			int W = 0;
			boolean good = true;
			for (int j = 0; j < w.length; j++) {
				if (h[j] <= i) {
					W += w[j];
				} else if (w[j] <= i) {
					W += h[j];
				} else {
					good = false;
				}
			}
			if (good) {
				ans = Math.min(ans, 1L * W * i);
			}
		}

		out.println(ans);
	}

	public void run() {
		try {
			in = new FastScanner();
			out = new PrintWriter(System.out);

			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}
	}

	public static void main(String[] arg) {
		new B().run();
	}
}