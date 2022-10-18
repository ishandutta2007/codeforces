import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int d = nextInt();
		int[] cost= new int[n];
		int sum = 0;
		for (int i = 0; i < n; i++) {
			cost[i] = nextInt();
			sum += cost[i];
		}
		
		boolean[] can = new boolean[sum + 1];
		can[0] = true;
		for (int i = 0; i < n; i++) {
			int x = cost[i];
			for (int j = sum; j >= x; j--) {
				can[j] |= can[j - x];
			}
		}
		
		int ans1 = 0;
		int ans2 = 0;
		
		int canGo = d;
		int canGoAns = 1;
		
		for (int i = 1; i <= sum; i++) {
			if (can[i]) {
				// System.err.println(i + " " + canGo + " " + canGoAns + ", " + ans1 + " " + ans2);
				if (i <= canGo) {
					ans1 = i;
					ans2 = canGoAns;
				} else {
					canGo = ans1 + d;
					canGoAns++;
					// System.err.println("!!! at " + i + ", now " + canGo + " " + canGoAns);
					if (i <= canGo) {
						ans1 = i;
						ans2 = canGoAns;
					} else {
						break;
					}
				}
			}
		}
		
		out.println(ans1 + " " + ans2);
	}

	B() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B();
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