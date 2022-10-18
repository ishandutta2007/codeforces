import java.io.*;
import java.util.*;

public class D_new {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int k = nextInt();
		int n1 = nextInt();
		int n2 = nextInt();
		int n3 = nextInt();
		int t1 = nextInt();
		int t2 = nextInt();
		int t3 = nextInt();

		PriorityQueue<Integer> free1 = new PriorityQueue<>(n1);
		for (int i = 0; i < n1; i++) {
			free1.add(0);
		}
		PriorityQueue<Integer> free2 = new PriorityQueue<>(n2);
		for (int i = 0; i < n2; i++) {
			free2.add(0);
		}
		PriorityQueue<Integer> free3 = new PriorityQueue<>(n3);
		for (int i = 0; i < n3; i++) {
			free3.add(0);
		}

		int ans = -1;

		for (int i = 0; i < k; i++) {
			int next1 = free1.poll();
			int next2 = free2.poll();
			int next3 = free3.poll();
			int t = Math.max(next1, Math.max(next2 - t1, next3 - t1 - t2));
			t = Math.max(t, 0);
			free1.add(t + t1);
			free2.add(t + t1 + t2);
			free3.add(t + t1 + t2 + t3);
			if (i == k - 1) {
				ans = t + t1 + t2 + t3;
			}
		}
		out.println(ans);
	}

	D_new() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D_new();
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