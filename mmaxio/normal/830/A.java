import java.io.*;
import java.util.*;

public class A {

	static class Segment implements Comparable<Segment> {
		long l, r;

		public Segment(long l, long r) {
			this.l = l;
			this.r = r;
		}

		@Override
		public int compareTo(Segment o) {
			return Long.compare(r, o.r);
		}
		
	}
	
	void submit() {
		int n = nextInt();
		int k = nextInt();
		long p = nextLong();
		long[] a = new long[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextLong() - p;
		}
		
		long[] b = new long[k];
		for (int i = 0; i < k; i++) {
			b[i] = nextLong() - p;
		}
		
		long maxD = 0;
		for (int i = 0; i < n; i++) {
			maxD = Math.max(maxD, Math.abs(a[i]));
		}
		
		long low = maxD - 1; // can't
		long high = 2_000_000_000; // can
		
		Arrays.sort(b);
		
		Segment[] segms = new Segment[n];
		
		binS: while (high - low > 1) {
			long mid = (low + high) >> 1;
			for (int i = 0; i < n; i++) {
				long extra = (mid - Math.abs(a[i])) / 2;
				long from = Math.min(a[i], 0) - extra;
				long to = Math.max(a[i], 0) + extra;
				
				if (from > to) {
					low = mid;
					continue binS;
				}
				
				segms[i] = new Segment(from, to);
			}
			
			Arrays.sort(segms);
			TreeSet<Long> keys = new TreeSet<>();
			for (int i = 0; i < k; i++) {
				keys.add(b[i]);
			}
			
			for (Segment s : segms) {
				Long pick = keys.ceiling(s.l);
				if (pick == null) {
					low = mid;
					continue binS;
				}
				if (pick > s.r) {
					low = mid;
					continue binS;
				}
				keys.remove(pick);
			}
			
			high = mid;
		}
		
		out.println(high);
	}

	void preCalc() {

	}

	void stress() {

	}

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