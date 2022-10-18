import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int c2 = nextInt();
		int c3 = nextInt();
		int low = 0;
		int high = Integer.MAX_VALUE / 5;
		while (high - low > 1) {
			int mid = (low + high) >> 1;
			int has2 = mid / 2;
			int has3 = mid / 3;
			int has6 = mid / 6;
			if (has2 + has3 - has6 >= c2 + c3 && has2 >= c2 && has3 >= c3) {
				high = mid;
			} else {
				low = mid;
			}
		}
		
		out.println(high);
	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C();
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