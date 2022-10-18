import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	static final int INF = 1_000_000_000;

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int[] add = new int[n];
		int[] max = new int[n];
		
		Arrays.fill(max, INF);
		int[][] inp = new int[m][4];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < 4; j++) {
				inp[i][j] = nextInt();
			}
			inp[i][1]--;
			inp[i][2]--;
			
			if (inp[i][0] == 1) {
				for (int j = inp[i][1]; j <= inp[i][2]; j++) {
					add[j] += inp[i][3];
				}
			} else {
				for (int j = inp[i][1]; j <= inp[i][2]; j++) {
					max[j] = Math.min(max[j], inp[i][3] - add[j]);
				}
			}
			
		}
		
		Arrays.fill(add, 0);
		for (int i = 0; i < m; i++) {
			
			if (inp[i][0] == 1) {
				for (int j = inp[i][1]; j <= inp[i][2]; j++) {
					add[j] += inp[i][3];
				}
			} else {
				int curMax = Integer.MIN_VALUE;
				for (int j = inp[i][1]; j <= inp[i][2]; j++) {
					curMax = Math.max(curMax, max[j] + add[j]);
				}
				if (curMax != inp[i][3]) {
					out.println("NO");
					return;
				}
			}
			
		}
		
		out.println("YES");
		for (int i = 0; i < n; i++) {
			out.print(max[i] + " " );
		}
		out.println();
		
		
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