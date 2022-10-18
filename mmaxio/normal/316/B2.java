import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int x = nextInt() - 1;

		int[] next = new int[n];
		Arrays.fill(next, -1);

		boolean[] hasIn = new boolean[n];

		for (int i = 0; i < n; i++) {
			int prev = nextInt() - 1;
			if (prev != -1) {
				next[prev] = i;
				hasIn[i] = true;
			}
		}
		
//		System.err.println(Arrays.toString(next));
		
		int[] pos = new int[n];
		
		boolean[] can = new boolean[n + 1];
		can[0] = true;
		
		for (int i = 0; i < n; i++) {
			if (!hasIn[i]) {
				
				boolean hasBeaver = false;
				int sz = 0;
				
				for (int j = i; j != -1; j = next[j], sz++) {
					hasBeaver |= (j == x);
					pos[j] = sz;
				}
				
				if (!hasBeaver) {
					for (int j = n; j >= sz; j--)
						can[j] |= can[j - sz];
				}
			}
		}
		
		for (int i = 0; i < n; i++)
			if (can[i]) {
				out.println(i + pos[x] + 1);
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