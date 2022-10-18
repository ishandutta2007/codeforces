import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		
		int max = n - 1;
		if (max > (1 << k))
			throw new AssertionError();
		
		int[] cur = new int[n];
		Arrays.fill(cur, 1);
		cur[n - 1] = 0;
		
		int[] need = new int[n];
		for (int i = 0; i < n; i++)
			need[i] = n - 1 - i;
		
		for (int step = 0; step < k; step++) {
			for (int i = 0; i < n; i++) {
				int j;
				if (cur[i] == need[i]) {
					j = n - 1;
				} else if (cur[i] * 2 <= need[i]) {
					j = i;
				} else {
					int add = need[i] - cur[i];
					j = n - 1 - add;
				}
				out.print(j + 1 + " ");
				cur[i] += cur[j];
			}
			out.println();
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