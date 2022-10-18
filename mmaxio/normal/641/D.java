import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		double[] min = new double[n];
		double[] max = new double[n];
		for (int i = 0; i < n; i++) {
			min[i] = nextDouble();
		}
		for (int i = 0; i < n; i++) {
			max[i] = nextDouble();
		}
		
		for (int i = 1; i < n; i++) {
			min[i] += min[i - 1];
		}
		
		for (int i = n - 2; i >= 0; i--) {
			max[i] += max[i + 1];
		}
		
		double[] xs = new double[n];
		double[] ys = new double[n];
		
		for (int i = 0; i < n - 1; i++) {
			
			double a = min[i];
			double b = max[i + 1];
			
			double base = a - b + 1;
			double diff = Math.sqrt(Math.max(base * base - 4 * a, 0));
			xs[i] = 0.5 * (base - diff);
			ys[i] = 0.5 * (base + diff);
		}
		
		xs[n - 1] = ys[n - 1] = 1;
		
		for (int i = 0; i < n; i++) {
			out.print(xs[i] - (i == 0 ? 0 : xs[i - 1]) + " ");
		}
		out.println();
		
		for (int i = 0; i < n; i++) {
			out.print(ys[i] - (i == 0 ? 0 : ys[i - 1]) + " ");
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