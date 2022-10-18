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

		int[] init = new int[n];
		int[] log = new int[m];
		
		int[] there = new int[n];

		for (int i = 0; i < m; i++) {
			char c = nextToken().charAt(0);
			int x = nextInt() - 1;
			if (c == '+') {
				log[i] = x;
				if (init[x] == 0) {
					init[x] = -1;
				}
				there[x] = 1;
			} else {
				log[i] = ~x;
				if (init[x] == 0) {
					init[x] = 1;
				}
				there[x] = -1;
			}
		}
		int curTot = 0;
		
		boolean hasInit = false;

		for (int i = 0; i < n; i++) {
			if (init[i] > 0) {
				curTot++;
				hasInit = true;
			}
		}

		boolean[] ans = new boolean[n];
		Arrays.fill(ans, true);
		
		if (hasInit) {
			for (int i = 0; i < n; i++) {
				if (init[i] == -1) {
					ans[i] = false;
				}
			}
		}
		
		Set<Integer> last = new HashSet<>();
		
		for (int i = 0; i < m; i++) {
			if (log[i] >= 0) {
				int x = log[i];
				curTot++;
				if (curTot == 1) {
					last.add(x);
				}
			} else {
				int x = ~log[i];
				curTot--;
				if (curTot > 0) {
					ans[x] = false;
				} else {
					last.add(x);
				}
			}
		}
		
		if (last.size() > 1) {
			for (int i = 0; i < n; i++) {
				ans[i] = init[i] == 0;
			}
		} else if (last.size() == 1) {
			for (int i = 0; i < n; i++) {
				if (init[i] != 0) {
					if (!(hasInit && init[i] == -1) && last.contains(i)) {
						ans[i] = true;
					} else {
						ans[i] = false;
					}
				}
			}
		}
		
		if (curTot > 0) {
			for (int i = 0; i < n; i++) {
				ans[i] &= there[i] != -1;
			}
		}
		
		int ansCnt = 0;
		for (int i = 0; i < n; i++) {
			if (ans[i]) {
				ansCnt++;
			}
		}
		out.println(ansCnt);
		for (int i = 0; i< n; i++) {
			if (ans[i]) {
				out.print((i + 1) + " ");
			}
		}
		out.println();
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