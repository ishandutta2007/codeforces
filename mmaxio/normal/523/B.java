import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * Created by Aksenov239 on 08.03.2015.
 */
public class B {
	public static void main(String[] args) {
		new B().run();
	}

	BufferedReader br;
	StringTokenizer in;
	PrintWriter out;

	public String nextToken() throws IOException {
		while (in == null || !in.hasMoreTokens()) {
			in = new StringTokenizer(br.readLine());
		}
		return in.nextToken();
	}

	public int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	public double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	public void solve() throws IOException {
		int n = nextInt();
		int T = nextInt();
		double c = nextDouble();

		double[][] ans = new double[n][2];

		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}

		long sum = 0;
		double mean = 0;
		for (int i = 0; i < n; i++) {
			mean = (mean + 1. * a[i] / T) / c;

			sum += a[i];
			if (i >= T) {
				sum -= a[i - T];
			}

			ans[i][0] = 1. * sum / T;
			ans[i][1] = mean;
		}

		int m = nextInt();
		for (int i = 0; i < m; i++) {
			int t = nextInt() - 1;
			out.println(ans[t][0] + " " + ans[t][1] + " "
					+ Math.abs(ans[t][0] - ans[t][1]) / ans[t][0]);
		}
	}

	public void run() {
		try {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);

			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
}