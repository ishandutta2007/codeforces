import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	static final double rad(double a, double h) {
		a *= 0.5;
		double area = a * h;
		double hypot = Math.sqrt(a * a + h * h);
		return area / hypot;
	}

	void solve() throws IOException {
		double res = nextDouble();
		for (int i = 1; i <= 10; i++){
			for (int j = 1; j <= 10; j++) {
				double val = rad(i, j);
				if (Math.abs(val - res) < 1e-6) {
					out.println(i + " " + j);
					return;
				}
			}
		}
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