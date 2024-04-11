import java.io.*;
import java.util.*;

public class D {

	static final long INF = Long.MAX_VALUE / 10;

	long slow2(int[] a) {
		PriorityQueue<Integer> pq = new PriorityQueue<>();
		pq.add(Integer.MAX_VALUE);
		
		long ret = 0;
		
		for (int x : a) {
			int ez = pq.peek();
			if (ez < x) {
				ret += x - ez;
				pq.poll();
				pq.add(x);
			}
			pq.add(x);
		}
		return ret;
	}
	
	int getBest(int signLook, int[] sign, int[] a, int resSign, int from, int to) {
		int ret = Integer.MAX_VALUE;
		int idxRet = -1;
		for (int i = from; i < to; i++) {
			if (sign[i] == signLook && a[i] * resSign < ret) {
				ret = a[i] * resSign;
				idxRet = i;
			}
		}
		return idxRet;
	}

	long slow(int[] a) {
		long[] dp = new long[a.length + 1];
		Arrays.fill(dp, -INF);
		dp[0] = 0;

		for (int x : a) {
			long[] nxt = dp.clone();
			for (int i = 0; i < nxt.length; i++) {
				if (i > 0) {
					nxt[i] = Math.max(nxt[i], dp[i - 1] - x);
				}
				if (i < nxt.length - 1) {
					nxt[i] = Math.max(nxt[i], dp[i + 1] + x);
				}
			}
			dp = nxt;
			// System.err.println(Arrays.toString(dp));
		}
		return dp[0];
	}

	void submit() {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		out.println(slow2(a));
	}

	void preCalc() {

	}

	void stress() {
		for (int tst = 0;; tst++) {
			int n = rand(1, 5);
			int[] a = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = rand(1, 5);
			}
			long slow = slow(a);
			long slow2 = slow2(a);

			if (slow != slow2) {
				System.err.println(slow);
				System.err.println(slow2);
				System.err.println(Arrays.toString(a));
				throw new AssertionError();
			}
			System.err.println("tst " + tst);
		}
	}

	void test() {

	}

	D() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		 submit();
//		stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new D();
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