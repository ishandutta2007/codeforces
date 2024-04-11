import java.io.*;
import java.util.*;

public class A {

	static class Number implements Comparable<Number> {
		int val;
		int pos;

		@Override
		public int compareTo(Number o) {
			if (val != o.val) {
				return val < o.val ? -1 : 1;
			}
			return Integer.compare(pos, o.pos);
		}

		public Number(int val, int pos) {
			this.val = val;
			this.pos = pos;
		}

	}

	int[] slow(int[] as, int[] bs) {
		int n = as.length;

		as = as.clone();
		Arrays.sort(as);

		long best = 0;
		int[] ret = null;

		do {
			long sum = 0;
			for (int i = 0; i < n; i++) {
				sum += choose(as[i], bs[i]);
			}
			if (Arrays.equals(as, new int[]{5, 8, 4, 6, 4})) {
				System.err.println(sum);
			}
			if (sum == 107) {
				System.err.println(Arrays.toString(as));
			}
			if (sum > best) {
				best = sum;
				ret = as.clone();
			}
		} while (nextPermutation(as));
		System.err.println(best);
		return ret;
	}
	
	int[] fast(int[] as, int[] bs) {
		int n = bs.length;
		Number[] nbs = new Number[n];
		for (int i = 0; i < n; i++) {
			nbs[i] = new Number(bs[i], i);
		}
		
		Arrays.sort(nbs);
		for (int i = 0; i < n; i++) {
			int j = rand(0, i);
			int tmp = as[j];
			as[j] = as[i];
			as[i] = tmp;
		}
		Arrays.sort(as);
		
		int[] ret = new int[n];
		for (int i = n - 1; i >= 0; i--) {
			ret[nbs[i].pos] = as[n - 1 - i];
		}
		
		return ret;
	}

	void submit() {
		int n = nextInt();
		int[] as = new int[n];
		int[] bs = new int[n];
		
		for (int i = 0; i < n; i++) {
			as[i] = nextInt();
		}
		
		for (int i = 0; i < n; i++) {
			bs[i] = nextInt();
		}
		
		int[] ret = fast(as, bs);
		for (int x : ret) {
			out.print(x + " ");
		}
	}

	long choose(int n, int k) {
		long ret = 1;
		for (int i = 1; i <= k; i++) {
			ret = ret * (n - i + 1) / i;
		}
		return ret;
	}

	static boolean nextPermutation(int[] a) {
		int n = a.length;
		int ptr = n - 1;
		while (ptr > 0 && a[ptr - 1] >= a[ptr]) {
			ptr--;
		}

		for (int i = ptr, j = n - 1; i < j; i++, j--) {
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}

		if (ptr == 0) {
			return false;
		}

		for (int i = ptr;; i++) {
			if (a[ptr - 1] < a[i]) {
				int tmp = a[ptr - 1];
				a[ptr - 1] = a[i];
				a[i] = tmp;
				return true;
			}
		}
	}

	void preCalc() {

	}

	void stress() {
		for (int tst = 0;; tst++) {
			
			int n = rand(1, B);
			
			int mid = rand(1, B);
			
			int[] as = new int[n];
			int[] bs = new int[n];
			for (int i = 0; i < n; i++) {
				as[i] = rand(mid, B);
				bs[i] = rand(1, mid);
			}
			
			int[] fArr = fast(as, bs);
			int[] sArr = slow(as, bs);
			
			long valF = 0;
			long valS = 0;
			for (int i = 0; i < n; i++) {
				valF += choose(fArr[i], bs[i]);
				valS += choose(sArr[i], bs[i]);
			}
			
			if (valF != valS) {
				throw new AssertionError();
			}
			
			System.err.println(tst);
		}
	}
	
	static final int B = 4;

	void test() {

	}

	A() throws IOException {
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
		new A();
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