import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	boolean[] can;

	void solve() throws IOException {
		int n = nextInt();
		 
//		can = new boolean[2 * n];
//		can[0] = true;
//		Queue<Integer> q = new ArrayDeque<>();
//		q.add(0);
//		
//		while (!q.isEmpty()) {
//			int same = q.poll();
//			int neg = 2 * n - 1 - same;
//			
//			for (int chSame = 0; chSame <= same; chSame++) {
//				int chNeg = n - chSame;
//				if (chNeg < 0 || chNeg > neg)
//					continue;
//				
//				int newSame = same - chSame + chNeg;
//				if (!can[newSame]) {
//					can[newSame] = true;
//					q.add(newSame);
//				}
//			}
//		}
//		
//		System.err.println(Arrays.toString(can));
		
		int[] a = new int[2 * n - 1];
		for (int i = 0; i < a.length; i++)
			a[i] = nextInt();
		Arrays.sort(a);
		
		if (n % 2 == 1) {
			int res = 0;
			for (int i = 0; i < a.length; i++)
				res += Math.abs(a[i]);
			out.println(res);
			return;
		}
		
		Arrays.sort(a);
		int sumPos = 0;
		for (int i = 0; i < a.length; i++)
			sumPos += a[i];
		
		int sumNeg = 0;
		int ans = sumPos - sumNeg;
		
		for (int i = 0; i < 2 * n - 2; i += 2) {
			sumPos -= a[i] + a[i + 1];
			sumNeg += a[i] + a[i + 1];
			ans = Math.max(ans, sumPos - sumNeg);
		}
		
		out.println(ans);
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