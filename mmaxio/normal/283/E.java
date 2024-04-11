import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	class Event implements Comparable<Event> {
		int x;
		int l, r;

		public Event(int x, int l, int r) {
			this.x = x;
			this.l = l;
			this.r = r;
		}

		@Override
		public int compareTo(Event o) {
			return Integer.compare(x, o.x);
		}
	}
	
	static class Node {
		Node left, right;
		int l, r;
		
		boolean flip;
		int val;
		
		public Node(int l, int r) {
			this.l = l;
			this.r = r;
			
			if (r - l > 1) {
				int mid = (l + r) >> 1;
				left = new Node(l, mid);
				right = new Node(mid, r);
			}
		}
		
		int getVal() {
			return flip ? r - l - val : val;
		}
		
		void flip(int l, int r) {
			if (l >= this.r || this.l >= r)
				return;
			if (l <= this.l && this.r <= r) {
				flip ^= true;
				return;
			}
			
			left.flip(l, r);
			right.flip(l, r);
			val = left.getVal() + right.getVal();
		}
		
		int get(int l, int r) {
			if (l >= this.r || this.l >= r)
				return 0;
			if (l <= this.l && this.r <= r) {
				return getVal();
			}
			int res = left.get(l, r) + right.get(l, r);
			
			int len = Math.min(this.r, r) - Math.max(this.l, l);
			
			return flip ? len - res : res;
		}

		
	}

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();

		int[] s = new int[n];
		for (int i = 0; i < n; i++) {
			s[i] = nextInt();
		}

		Arrays.sort(s);

		ArrayList<Event> evs = new ArrayList<>();

		for (int i = 0; i < k; i++) {
			int low = nextInt();
			int high = nextInt();

			low = Arrays.binarySearch(s, low);
			if (low < 0)
				low = -low - 1;

			high = Arrays.binarySearch(s, high);
			if (high < 0)
				high = -high - 2;
			
			if (low <= high) {
				evs.add(new Event(low, low, high + 1));
				evs.add(new Event(high + 1, low, high + 1));
			}
		}
		
		Collections.sort(evs);
		
		Node root = new Node(0, n);
		
		long bad = 0;
		for (int i = 0, j = 0; i < n; i++) {
			while (j < evs.size() && evs.get(j).x <= i) {
				Event e = evs.get(j++);
				root.flip(e.l, e.r);
			}
			int deg = (i - root.get(0, i)) + root.get(i + 1, n);
			
			bad += (long)deg * (deg - 1) / 2;
		}
		
		out.println((long)n * (n - 1) * (n - 2) / 6 - bad);
		
	}

	E() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new E();
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