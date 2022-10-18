import java.io.*;
import java.util.*;

public class C {

	static final int K = 300_000;

	static class Delta implements Comparable<Delta>{
		int where;
		long dC0;
		long dC1;
		
		@Override
		public int compareTo(Delta o) {
			return Integer.compare(where, o.where);
		}

		public Delta(int where, long dC0, long dC1) {
			this.where = where;
			this.dC0 = dC0;
			this.dC1 = dC1;
		}
	}
	
	void submit() {
		int n = nextInt();
		long k = nextLong();

		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}

		long[] c0 = new long[K];
		long[] c1 = new long[K];

//		HashMap<Integer, Long> mapC0 = new HashMap<>();
//		HashMap<Integer, Long> mapC1 = new HashMap<>();
		
		Delta[] big = new Delta[1_000_000];
		int ptr = 0;
		big[ptr++] = new Delta(K, 0, 0);

		for (int x : a) {

			int ceil = 1;
			for (; ceil * ceil <= x; ceil++) {

				// ceil of (x/d)
				int low = ceilDiv(x, ceil);
				int valAtLow = getVal(x, low);

				long nowC0 = valAtLow - (long) ceil * low;

				if (low < K) {
					c1[low] += ceil;
					c0[low] += nowC0;
				} else {
					big[ptr++] = new Delta(low, nowC0, ceil);
				}

				if (ceil != 1) {
					int high = ceilDiv(x, ceil - 1);

					if (high < K) {
						c1[high] -= ceil;
						c0[high] -= nowC0;
					} else {
						big[ptr++] = new Delta(high, -nowC0, -ceil);
					}
				}

			}

			int smallD = ceilDiv(x, ceil - 1) - 1;
			for (int d = 1; d <= smallD; d++) {
				int delta = getVal(x, d);
				c0[d] += delta;
				c0[d + 1] -= delta;
			}
		}
		
		Arrays.sort(big, 0, ptr);
		
//		System.err.println(ptr);
		
		long ans = -1;

		for (int i = 1; i < K; i++) {
			c0[i] += c0[i - 1];
			c1[i] += c1[i - 1];
			long here = c0[i] + c1[i] * i;
			if (here <= k) {
				ans = i;
			}
		}
		
		long nowC0 = c0[K - 1];
		long nowC1 = c1[K - 1];
		
		for (int i = 0; i < ptr; ) {
			int j = i;
			int start = big[i].where;
			
			while (j < ptr && big[j].where == start) {
				nowC0 += big[j].dC0;
				nowC1 += big[j].dC1;
				j++;
			}
			
			int finish = (j == ptr) ? -1 : big[j].where - 1;
			
			
			if (nowC1 <= 0) {
				if (finish == -1) {
					throw new AssertionError();
				}
				
				long atLast = nowC0 + nowC1 * finish;
				if (atLast <= k) {
					ans = finish;
				}
			} else {
				// nowC0 + nowC1 * x <= k
				// x <= (k - nowC0) / nowC1
				
				long num = k - nowC0;
				long denom = nowC1;
				
				// x <= num / denom
				if (num >= 0) {
					long lastX = num / denom;
					if (lastX < start) {
						// nothing
					} else if (finish == -1 || lastX <= finish) {
						ans = lastX;
					} else {
						ans = finish;
					}
				}
				
			}
			
			i = j;
		}
		
		out.println(ans);
	}
	
	int ceilDiv(int a, int b) {
		return (a + b - 1) / b;
	}

	int getVal(int x, int mod) {
		x %= mod;
		return x == 0 ? 0 : mod - x;
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	C() throws IOException {
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
		new C();
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