import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int[] vs = new int[n];
		int[] ds = new int[n];
		int[] ps = new int[n];
		for (int i = 0; i < n; i++) {
			vs[i] = nextInt();
			ds[i] = nextInt();
			ps[i] = nextInt();
		}
		
		int ret = 0;
		
		ArrayDeque<Integer> q = new ArrayDeque<>();
		ArrayList<Integer> ans = new ArrayList<>(n);
		
		for (int i = 0; i < n; i++) {
			if (ps[i] >= 0) {
				ans.add(i + 1);
				for (int j = i + 1, decr = vs[i]; j < n && decr > 0; j++) {
					if (ps[j] >= 0) {
						ps[j] -= decr;
						decr--;
						if (ps[j] < 0) {
							q.add(j);
						}
					}
				}
				while (!q.isEmpty()) {
					int pos = q.poll();
					for (int j = pos + 1; j < n; j++) {
						if (ps[j] >= 0) {
							ps[j] -= ds[pos];
							if (ps[j] < 0) {
								q.add(j);
							}
						}
					}
				}
			}
		}
		
		out.println(ans.size());
		for (int x : ans) {
			out.print(x + " ");
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