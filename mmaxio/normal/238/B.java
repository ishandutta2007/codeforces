import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	class Number implements Comparable<Number>{
		int val, pos;

		public Number(int val, int pos) {
			this.val = val;
			this.pos = pos;
		}

		@Override
		public int compareTo(Number o) {
			return Integer.compare(val, o.val);
		}

	}

	static final int INF = Integer.MAX_VALUE / 3;

	void solve() throws IOException {
		int n = nextInt();
		int h = nextInt();
		Number[] a = new Number[n];
		for (int i = 0; i < n; i++)
			a[i] = new Number(nextInt(), i);

		Arrays.sort(a);
//		for (int i =0 ; i < n; i++)
//			System.err.println(a[i].val + " ");

		int ansCase = 0;
		int ansNum = -1;
		int ans = a[n - 2].val + a[n - 1].val - a[0].val - a[1].val;

		for (int i = 0; i < n; i++) {

			int maxDiff = a[i == n - 1 ? n - 2 : n - 1].val + a[i].val + h;
			int maxSame;
			if (n == 2)
				maxSame = -INF;
			else {
				if (i == n - 1)
					maxSame = a[n - 2].val + a[n - 3].val;
				else if (i == n - 2)
					maxSame = a[n - 1].val + a[n - 3].val;
				else
					maxSame = a[n - 1].val + a[n - 2].val;
			}

			int minDiff = a[i == 0 ? 1 : 0].val + a[0].val + h;
			int minSame;
			if (n == 2)
				minSame = INF;
			else {
				if (i == 0)
					minSame = a[1].val + a[2].val;
				else if (i == 1)
					minSame = a[0].val + a[2].val;
				else
					minSame = a[0].val + a[1].val;
			}

			int curAns = Math.max(maxDiff, maxSame)
					- Math.min(minDiff, minSame);
			if (curAns < ans) {
				
//				System.err.println(maxDiff + " " + maxSame + " " + minDiff + " " + minSame);
				
				ans = curAns;
				ansCase = 1;
				ansNum = i;
			}
		}

		if (n > 2) {

			for (int i = 2; i < n - 1; i++) {

				int maxSame = i == n - 2 ? Math.max(a[0].val + a[n - 1].val,
						a[n - 2].val + a[n - 3].val) : a[n - 1].val
						+ a[n - 2].val;
				int maxDiff = a[n - 1].val + a[i].val + h;
				int minSame = Math.min(a[0].val + a[i + 1].val, a[1].val + a[2].val);
				int minDiff = a[0].val + a[1].val + h;
				
				int curAns = Math.max(maxDiff, maxSame)
						- Math.min(minDiff, minSame);
				if (curAns < ans) {
					ans = curAns;
					ansCase = 2;
					ansNum = i;
				}
			}

		}
		
		out.println(ans);
		int[] outp = new int[n];
		Arrays.fill(outp, 1);
		if (ansCase == 0) {
		} else if (ansCase == 1) {
			
			outp[a[ansNum].pos] = 2;
		} else {
			
			for (int i = 1; i <= ansNum; i++)
				outp[a[i].pos]= 2; 
		}
		
		for (int i = 0; i < n; i++)
			out.print(outp[i] + " ");
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