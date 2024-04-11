import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	static class Pair {
		int r, b;

		public Pair(int r, int b) {
			this.r = r;
			this.b = b;
		}
	}
	
	static int max = 0;
	
	static class Options {
		List<Pair> lst = new ArrayList<>(60);
		// r increasing, b decreasing
		
		
		void add(Pair p) {
			
			int pr = p.r;
			int pb = p.b;
			
			for (int i = 0; i < lst.size(); i++) {
				Pair o = lst.get(i);
				if (pr >= o.r && pb >= o.b) {
					return;
				}
			}
			
			int idxL = 0;
			while (idxL < lst.size() && pb <= lst.get(idxL).b) {
				idxL++;
			}
			
			int idxR = lst.size() - 1;
			while (idxR >= 0 && pr <= lst.get(idxR).r) {
				idxR--;
			}
			
			// < idxL and > idxR must be removed
			for (int idx = idxL - 1; idx > idxR; idx--) {
				lst.remove(idx);
			}
			
			lst.add(idxR + 1, p);
			
			max = Math.max(max, lst.size());
		}
	}

	int solve(int n, char[] types, int[] rs, int[] bs) {
		Options[] dp = new Options[1 << n];
		for (int i = 0; i < 1 << n; i++) {
			dp[i] = new Options();
		}
		
		dp[0].add(new Pair(0, 0));
		
		int maskR = 0;
		int maskB = 0;
		for (int i = 0; i < n; i++) {
			if (types[i] == 'R') {
				maskR |= 1 << i;
			} else {
				maskB |= 1 << i;
			}
		}
		
		for (int mask = 0; mask < (1 << n); mask++) {
			
			int discR = Integer.bitCount(mask & maskR);
			int discB = Integer.bitCount(mask & maskB);
			
			for (Pair p : dp[mask].lst) {
				for (int nxt = 0; nxt < n; nxt++) {
					if (test(mask, nxt)) {
						continue;
					}
					int costR = Math.max(rs[nxt] - discR, 0);
					int costB = Math.max(bs[nxt] - discB, 0);
					
					dp[mask | (1 << nxt)].add(new Pair(p.r + costR, p.b + costB));
				}
			}
		}
		
		int ret = Integer.MAX_VALUE;
		for (Pair p : dp[(1 << n) - 1].lst) {
			ret = Math.min(ret, Math.max(p.r, p.b));
		}
		
		return ret + n;
	}
	
	boolean test(int mask, int i) {
		return ((mask >> i) & 1) == 1;
	}
	
	void submit() throws IOException {
		int n = nextInt();
		char[] types = new char[n];
		int[] rs = new int[n];
		int[] bs = new int[n];
		for (int i = 0; i < n; i++) {
			types[i] = nextToken().charAt(0);
			rs[i] = nextInt();
			bs[i] = nextInt();
		}
		out.println(solve(n, types, rs, bs));
//		out.println(max);
	}
	
	Random rng = new Random();
	
	void testTime() {
		int n = 16;
		char[] types = new char[n];
		int[] rs = new int[n];
		int[] bs = new int[n];
		
		for (int i = 0; i < n; i++) {
			types[i] = "RB".charAt(rng.nextInt(2));
			rs[i] = rng.nextInt(5);
			bs[i] = rng.nextInt(5);
		}
		
		out.println(solve(n, types, rs, bs));
	}
	
	void testCorrectness(int n, int bound) {
		char[] types = new char[n];
		int[] rs = new int[n];
		int[] bs = new int[n];
		
		for (int i = 0; i < n; i++) {
			types[i] = "RB".charAt(rng.nextInt(2));
			rs[i] = rng.nextInt(bound);
			bs[i] = rng.nextInt(bound);
		}
		
		if (solve(n, types, rs, bs) != brute(n, types, rs, bs)) {
			System.err.println(n);
			System.err.println(Arrays.toString(rs));
			System.err.println(Arrays.toString(bs));
			throw new AssertionError();
		}
	}
	
	int brute(int n, char[] types, int[] rs, int[] bs) {
		int ret = Integer.MAX_VALUE;
		int[] perm = new int[n];
		for (int i = 0; i < n; i++) {
			perm[i] = i;
		}
		
		do {
			int totR = 0;
			int totB = 0;
			int cR = 0;
			int cB = 0;
			for (int idx : perm) {
				totR += Math.max(rs[idx] - cR, 0);
				totB += Math.max(bs[idx] - cB, 0);
				if (types[idx] == 'R') {
					cR++;
				} else {
					cB++;
				}
			}
			ret = Math.min(ret, Math.max(totR, totB));
		} while (nextPermutation(perm));
		
		return ret + n;
	}
	
	static boolean nextPermutation(int[] a) {
		int n = a.length;
		int ptr = n - 2;
		while (ptr >= 0 && a[ptr] > a[ptr + 1]) {
			ptr--;
		}
		if (ptr < 0) {
			return false;
		}

		for (int i = ptr + 1, j = n - 1; i < j; i++, j--) {
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}

		for (int i = ptr + 1;; i++) {
			if (a[ptr] < a[i]) {
				int tmp = a[ptr];
				a[ptr] = a[i];
				a[i] = tmp;
				return true;
			}
		}
	}


	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
//		testTime();
//		for (int tst = 0; tst < 10000; tst++) {
//			testCorrectness(5, 5);
//			System.err.println(tst);
//		}
		submit();
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
	} // lul
}