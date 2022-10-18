import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	static class Node {
		int l, r;
		Node left, right;
		
		long value;
		
		int output, posPref, negSuff, prefOutput, suffOutput;
		
		public Node(int l, int r, int[] a) {
			this.l = l;
			this.r = r;
			if (r - l > 1) {
				int mid = (l + r) >> 1;
				left = new Node(l, mid, a);
				right = new Node(mid, r, a);
				
				combine();
			} else {
				value = a[l];
				makeLeaf();
			}
		}
		
		void makeLeaf() {
			output = value != 0 ? 1 : 0;
			posPref = value > 0 ? 1 : 0;
			negSuff = value < 0 ? 1 : 0;
			prefOutput = value != 0 ? 1 : 0;
			suffOutput = value != 0 ? 1 : 0;
		}
		
		void combine() {
			output = Math.max(left.output, right.output);
			output = Math.max(output, left.negSuff + right.prefOutput);
			output = Math.max(output, left.suffOutput + right.posPref);
			
			if (left.negSuff == left.r - left.l) {
				prefOutput = left.r - left.l + right.prefOutput;
			} else if (left.prefOutput == left.r - left.l) {
				prefOutput = left.r - left.l + right.posPref;
			} else {
				prefOutput = left.prefOutput;
			}
			
			// suffOutput
			if (right.posPref == right.r - right.l) {
				suffOutput = right.r - right.l + left.suffOutput;
			} else if (right.suffOutput == right.r - right.l) {
				suffOutput = right.r - right.l + left.negSuff;
			} else {
				suffOutput = right.suffOutput;
			}
			
			//posPref
			if (left.posPref == left.r - left.l) {
				posPref = left.r - left.l + right.posPref;
			} else {
				posPref = left.posPref;
			}
			
			// negSuff
			if (right.negSuff == right.r - right.l) {
				negSuff = right.r - right.l + left.negSuff;
			} else {
				negSuff = right.negSuff;
			}
		}
		
		void change(int pos, int delta) {
			if (r - l == 1) {
				value += delta;
				makeLeaf();
				return;
			}
			(pos < left.r ? left : right).change(pos, delta);
			combine();
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		
		int[] b = new int[n - 1];
		for (int i = 0; i < n - 1; i++) {
			b[i] = a[i] - a[i + 1];
		}
		
		int m = nextInt();
		if (n == 1) {
			for (int i = 0; i < m; i++) {
				out.println(1);
			}
			return;
		}
		
		Node root = new Node(0, n - 1, b);
		
		for (int i = 0; i < m; i++) {
			int l = nextInt() - 1;
			int r = nextInt() - 1;
			int d = nextInt();
			
			if (l != 0) {
				
//				System.err.println(l - 1 + " " + -d);
				
				root.change(l - 1, -d);
			}
			
			if (r != n - 1) {
				
//				System.err.println(r + " " + d);
				
				root.change(r, d);
			}
			
			out.println(root.output + 1);
		}
		
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