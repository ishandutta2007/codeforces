import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();

		long sum = 0;

		ArrayList<Integer> diff = new ArrayList<>();
		int last = 0;

		for (int i = 0; i < n; i++) {
			int type = nextInt();
			if (type == 1) {
				int len = nextInt();
				int delta = nextInt();

				sum += (long) len * delta;

				if (len - 1 < diff.size()) {
					diff.set(len - 1, diff.get(len - 1) - delta);
				} else {
					last += delta;
				}
			}
			if (type == 2) {
				int k = nextInt();
				sum += k;
				diff.add(k - last);
				last = k;
			}
			if (type == 3) {
				sum -= last;
				int lastDiff = diff.remove(diff.size() - 1);
				last -= lastDiff;
			}
			
			//System.err.println(diff + " " + last);

			double ans = 1.0 * sum / (diff.size() + 1);
			out.println(ans);
		}
	}

	A() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new A();
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