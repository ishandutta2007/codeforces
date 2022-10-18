import java.io.*;
import java.util.*;

public class D_faster {

	static final int K = 4;

	static class Node {
		int l, r;
		Node left, right;

		int[] info;

		public Node(int l, int r, int[] a) {
			this.l = l;
			this.r = r;
			if (r - l == 1) {
				info = new int[] { a[l], 1 };
			} else {
				int m = (l + r) >> 1;
				left = new Node(l, m, a);
				right = new Node(m, r, a);
				info = merge(left.info, right.info);
			}
		}
		
		int[] getInfo(int ql, int qr) {
			if (ql >= r || l >= qr) {
				return null;
			}
			
			if (ql <= l && r <= qr) {
				return info;
			}
			
			int[] infoL = left.getInfo(ql, qr);
			int[] infoR = right.getInfo(ql, qr);
			return merge(infoL, infoR);
		}

	}

	static int[] merge(int[] a, int[] b) {
		
		if (a == null) {
			return b;
		}
		
		if (b == null) {
			return a;
		}

		int[] all = Arrays.copyOf(a, a.length + b.length);

		int ptr = a.length;

		outer: for (int i = 0; i < b.length; i += 2) {

			int val = b[i];
			int cnt = b[i + 1];

			for (int j = 0; j < ptr; j += 2) {
				if (val == all[j]) {
					all[j + 1] += cnt;
					continue outer;
				}
			}

			all[ptr++] = val;
			all[ptr++] = cnt;
		}

		while (ptr > 2 * K) {
			int idx = -1;
			int leastCnt = Integer.MAX_VALUE;
			for (int i = 0; i < ptr; i += 2) {
				if (all[i + 1] < leastCnt) {
					idx = i;
					leastCnt = all[i + 1];
				}
			}

			all[idx] = all[ptr - 2];
			all[idx + 1] = all[ptr - 1];
			
			ptr -= 2;
			
			for (int i = 0; i < ptr; i += 2) {
				all[i + 1] -= leastCnt;
			}

		}

		all = Arrays.copyOf(all, ptr);
		
//		System.err.println(Arrays.toString(a));
//		System.err.println(Arrays.toString(b));
//		System.err.println(Arrays.toString(all));
//		System.err.println("-----------");
		return all;
	}
	
	void submit() {
		int n = nextInt();
		int q = nextInt();
		
		int[] a = new int[n];
		int[] occ = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt() - 1;
			occ[a[i]]++;
		}
		
		int[][] arr = new int[n][];
		for (int i = 0; i < n; i++) {
			arr[i] = new int[occ[i]];
		}
		
		for (int i = n - 1; i >= 0; i--) {
			
			int x = a[i];
			
			arr[x][--occ[x]] = i;
		}
		
		Node root = new Node(0, n, a);
		
		while (q-- > 0) {
			int l = nextInt() - 1;
			int r = nextInt();
			int k = nextInt();
			
			int need = (r - l) / k + 1;
			
			int[] info = root.getInfo(l, r);
			
			int cand = n;
			
			for (int i = 0; i < info.length; i += 2) {
				int x = info[i];
//				System.err.println(count(arr[x], r));
//				System.err.println(count(arr[x], l));
				if (count(arr[x], r) - count(arr[x], l) >= need) {
					cand = Math.min(cand, x);
				}
			}
			
			out.println(cand == n ? -1 : (cand + 1));
		}
	}
	
	int count(int[] arr, int x) {
		int tmp = Arrays.binarySearch(arr, x);
		if (tmp < 0) {
			return -tmp - 1;
		}
		return tmp;
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	D_faster() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
		// stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new D_faster();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}