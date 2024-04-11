import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Node {
		static final int P = 2 * 2 * 3 * 5;

		static void fillLeafData(int[] data, int freq) {
			for (int i = 0; i < P; i++) {
				data[i] = i % freq == 0 ? 2 : 1;
			}
		}

		static void combineData(int[] dataRes, int[] dL, int[] dR) {
			for (int i = 0; i < P; i++) {
				dataRes[i] = dL[i] + dR[(i + dL[i]) % P];
			}
		}

		int l, r;
		Node left, right;
		int[] data = new int[P];

		public Node(int l, int r, int[] freqs) {
			this.l = l;
			this.r = r;
			if (r - l == 1) {
				fillLeafData(data, freqs[l]);
			} else {
				int mid = (l + r) >> 1;
				left = new Node(l, mid, freqs);
				right = new Node(mid, r, freqs);
				combineData(data, left.data, right.data);
			}
		}
//		10
//		2 5 4 2 3 5 3 4 2 6
//		1
//			A 3 11
		

		void set(int pos, int newFreq) {
			if (l == pos && pos + 1 == r) {
				fillLeafData(data, newFreq);
				return;
			}
			(pos < left.r ? left : right).set(pos, newFreq);
			combineData(data, left.data, right.data);
		}

		int get(int ql, int qr, int stRem) {
			if (ql >= r || l >= qr) {
				return 0;
			}
			if (ql <= l && r <= qr) {
				return data[stRem];
			}
			int lTime = left.get(ql, qr, stRem);
			int rTime = right.get(ql, qr, (stRem + lTime) % P);
			return lTime + rTime;
		}

	}

	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		Node root = new Node(0, n, a);
		
		
		int q = nextInt();
		while (q-- > 0) {
			char type = nextToken().charAt(0);
			int x = nextInt();
			int y = nextInt();
			if (type == 'A') {
				out.println(root.get(x - 1, y - 1, 0));
			} else {
				root.set(x - 1, y);
			}
		}
	}

	D() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D();
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