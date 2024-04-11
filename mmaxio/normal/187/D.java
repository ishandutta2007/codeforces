import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int n;
	int gr, mod;

	int[] compress(int[] a) {

		Arrays.sort(a);

		int n = a.length;
		int newLen = 1;
		for (int i = 1; i < n; i++) {
			if (a[i] != a[i - 1])
				a[newLen++] = a[i];
		}

		return Arrays.copyOf(a, newLen);
	}

	class Node {
		int l, r;
		Node left, right;

		int min; // minimum

		public Node(int l, int r) {
			this.l = l;
			this.r = r;
			if (l != r) {
				left = new Node(l, (l + r) >> 1);
				right = new Node(((l + r) >> 1) + 1, r);
			}
			min = Integer.MAX_VALUE;
		}
		
		int get(int l, int r) {
			if (l <= this.l && this.r <= r)
				return min;
			if (l > this.r || this.l > r)
				return Integer.MAX_VALUE;
			return Math.min(left.get(l, r), right.get(l, r));
		}
		
		void put(int ind, int val) {
			if (l == r) {
				min = Math.min(min, val);
				return;
			}
			(ind <= left.r ? left : right).put(ind, val);
			min = Math.min(left.min, right.min);
		}
	}
	
	Node root;
	int[] comp;
	
	int findNext(int l, int r) {
		l = Arrays.binarySearch(comp, l);
		if (l < 0)
			l = ~l;
		
		r = Arrays.binarySearch(comp, r);
		if (r < 0)
			r = ~r - 1;
		
		if (l == comp.length || r == -1)
			return Integer.MAX_VALUE;
		
		return root.get(l, r);
	}

	void solve() throws IOException {
		n = nextInt();
		gr = nextInt();
		mod = gr + nextInt();

		int[] d = new int[n + 1];
		for (int i = 0; i < n + 1; i++)
			d[i] = nextInt();

		long[] s = new long[n + 1];
		for (int i = 1; i < n + 1; i++)
			s[i] = s[i - 1] + d[i];
		
		int[] pos = new int[n];
		for (int i = 0; i < n; i++)
			pos[i] = (int)(s[i] % mod);
		
		comp = compress(pos.clone());
		
		root = new Node(0, comp.length - 1);
		
		long[] t = new long[n];
		
		for (int i = n - 1; i >= 0; i--) {
			int left = (int) ((s[i] + gr) % mod);
			int right = (int) ((s[i] + mod - 1) % mod);
			
			int nextStop;
			
			if (left <= right)
				nextStop = findNext(left, right);
			else
				nextStop = Math.min(findNext(left, mod - 1), findNext(0, right));
			
			if (nextStop == Integer.MAX_VALUE)
				t[i] = s[n] - s[i];
			else {
				long arrive = s[nextStop] - s[i];
				if (arrive % mod < gr)
					throw new AssertionError();
				t[i] =  (arrive / mod + 1) * mod + t[nextStop];
			}
			
			root.put(Arrays.binarySearch(comp, (int)(s[i] % mod)), i);
				
		}
		
		int q = nextInt();
		while (q-- > 0) {
			int initTime = d[0] + nextInt();
			int left = (gr - initTime) % mod;
			if (left < 0)
				left += mod;
			
			int right = (-1 - initTime) % mod;
			if (right < 0)
				right += mod;
			
			int stop;
			if (left <= right)
				stop = findNext(left, right);
			else
				stop = Math.min(findNext(left, mod - 1), findNext(0, right));
			
			if (stop == Integer.MAX_VALUE)
				out.println(s[n] + initTime);
			else {
				long arrive = s[stop] + initTime;
				if (arrive % mod < gr)
					throw new AssertionError();
				out.println((arrive / mod + 1) * mod + t[stop]);
			}
		}
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