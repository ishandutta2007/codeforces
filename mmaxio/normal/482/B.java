import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int[] low = new int[m];
		int[] high = new int[m];
		int[] val = new int[m];
		for (int i = 0; i < m; i++) {
			low[i] = nextInt() - 1;
			high[i] = nextInt() - 1;
			val[i] = nextInt();
		}

		int[] ans = new int[n];

		for (int bit = 0; bit < 30; bit++) {
			int[] arr = new int[n + 1];
			for (int i = 0; i < m; i++) {
				if ((val[i] & 1) == 1) {
//					System.err.println(bit + " " + i);
					arr[low[i]]++;
					arr[high[i] + 1]--;
				}
			}
			
			
			
			for (int i = 1; i <= n; i++) {
				arr[i] += arr[i - 1];
			}
			for (int i = 0; i <= n; i++) {
				arr[i] = Math.min(arr[i], 1);
			}
			
			
			
			int[] sums = new int[n + 1];
			sums[0] = arr[0];
			for (int i = 1; i <= n; i++) {
				sums[i] = sums[i - 1] + arr[i];
			}
			for (int i = 0; i < m; i++) {
				if ((val[i] & 1) == 0) {
					int sum = sums[high[i]];
					if (low[i] > 0) {
						sum -= sums[low[i] - 1];
					}
					if (sum == high[i] - low[i] + 1) {
						out.println("NO");
						return;
					}
				}
			}
			
			
			
			for (int i = 0; i < n; i++) {
				
				ans[i] |= arr[i] << bit;
			}
			
			for (int i = 0; i < m; i++) {
				val[i] >>= 1;
			}
			
		}
		
		out.println("YES");
		for (int i = 0; i < n; i++) {
			out.print(ans[i] + " ");
		}
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