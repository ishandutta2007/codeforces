import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	class Item implements Comparable<Item> {
		int pos;
		int cost;

		public Item(int pos, int cost) {
			this.pos = pos;
			this.cost = cost;
		}

		@Override
		public int compareTo(Item o) {
			if (cost != o.cost)
				return cost < o.cost ? -1 : 1;
			return Integer.compare(pos, o.pos);
		}
	}

	void solve() throws IOException {
		char[] s = nextToken().toCharArray();
		int n = s.length;

		TreeSet<Item> q = new TreeSet<Item>();
		int balance = 0;
		long ans = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '(')
				balance++;
			if (s[i] == ')')
				balance--;
			if (s[i] == '?') {
				int open = nextInt();
				int close = nextInt();
				s[i] = ')';
				ans += close;
				q.add(new Item(i, open - close));
				balance--;
			}

			if (balance == -1) {
				if (q.isEmpty()) {
					out.println(-1);
					return;
				}
				Item cur = q.pollFirst();
				ans += cur.cost;
				s[cur.pos] = '(';
				balance = 1;
			}
		}
		
		if (balance != 0) {
			out.println(-1);
			return;
		}
		
		out.println(ans);
		out.println(new String(s));
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D().inp();
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