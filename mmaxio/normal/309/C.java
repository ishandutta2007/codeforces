import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		
		int[] a = new int[n];
		
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		
		int[] cnt = new int[30];
		for (int i = 0; i < m; i++) {
			cnt[nextInt()]++;
		}
		
		Queue<Integer> q = new ArrayDeque<>();
		
		int ans = 0;
		for (int sz = 0; sz < 30; sz++) {
			int cur = cnt[sz];
			for (int i = 0; i < cur; i++)
				q.add(1);
			
			for (int i = 0; i < n; i++) {
				if ((a[i] & 1) == 1 && !q.isEmpty()) {
					a[i]--;
					ans += q.poll();
				}
				a[i] >>= 1;
			}
			int curSz = q.size();
			for (int i = 0; i < curSz; ) {
				int sum = q.poll();
				i++;
				if (i != curSz) {
					sum += q.poll();
					i++;
				}
				q.add(sum);
			}
		}
		
		out.println(ans);
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