import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int sum = nextInt();
		
		int[] low = new int[n];
		int[] high = new int[n];
		
		int sumLow = 0;
		int sumHigh = 0;
		
		for (int i = 0; i < n; i++) {
			low[i] = nextInt();
			sumLow += low[i];
			high[i] = nextInt();
			sumHigh += high[i];
		}
		
		if (sum < sumLow || sum > sumHigh) {
			out.println("NO");
			return;
		}
		
		out.println("YES");
		int left = sum - sumLow;
		for (int i = 0; i < n; i++) {
			int cur = Math.min(left, high[i] - low[i]);
			out.print(low[i] + cur + " ");
			left -= cur;
		}
		
		out.println();
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B().inp();
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