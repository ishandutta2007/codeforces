import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int MAX = 100000;
	static final int PR_CNT = 9592;

	static final int[] PRIMES = new int[PR_CNT];

	void solve() throws IOException {
		boolean[] isPrime = new boolean[MAX + 1];
		Arrays.fill(isPrime, true);
		int pr_ptr = 0;
		for (int i = 2; i <= MAX; i++) {
			if (isPrime[i]) {
				PRIMES[pr_ptr++] = i;
				if ((long) i * i <= MAX) {
					for (int j = i * i; j <= MAX; j += i)
						isPrime[j] = false;
				}
			}
		}

		int[] lastIndex = new int[PR_CNT];
		Arrays.fill(lastIndex, -1);

		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		
		int[] ans = new int[n];

		for (int i = 0; i < n; i++) {
			int x = a[i];
			
			ans[i] = 1;
			int maxAdd = 0;
			
			for (int j = 0; PRIMES[j] * PRIMES[j] <= x; j++) {
				int p = PRIMES[j];
				if (x % p == 0) {
					
					int prev = lastIndex[j];
					if (prev != -1)
						maxAdd = Math.max(maxAdd, ans[prev]);
					lastIndex[j] = i;
					
					x /= p;
					
					while (x % p == 0)
						x /= p;
				}
			}
			if (x != 1) {
				int prPos = Arrays.binarySearch(PRIMES, x);
				
				int prev = lastIndex[prPos];
				if (prev != -1)
					maxAdd = Math.max(maxAdd, ans[prev]);
				lastIndex[prPos] = i;
			}
			
			ans[i] += maxAdd;
		}
		
		int outp = 0;
		for (int i = 0; i < n; i++)
			outp = Math.max(outp, ans[i]);
		
		out.println(outp);
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