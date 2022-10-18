import java.io.*;
import java.util.*;

public class C {

	long seed;

	static final int P = 1_000_000_007;

	int rnd() {
		int ret = (int) seed;
		seed = (7L * seed + 13) % P;
		return ret;
	}

	static class Segment implements Comparable<Segment> {
		int l, r;
		long val;

		public Segment(int l, int r, long val) {
			this.l = l;
			this.r = r;
			this.val = val;
		}

		Segment nxt, prv;

		@Override
		public int compareTo(Segment o) {
			return Long.compare(val, o.val);
		}

		int eval(int x, int y) {
			int a = (int) (val % y);
			int ret = 1;
			for (; x > 0; x >>= 1) {
				if ((x & 1) == 1) {
					ret = (int) ((long) ret * a % y);
				}
				a = (int) ((long) a * a % y);
			}
			
			ret = (int)((long)ret * (r - l) % y);
			return ret;
		}
	}

	void split(Segment s, int m) {
		if (m <= s.l || m >= s.r) {
			throw new AssertionError();
		}
		// DOESN'T TOUCH LEFT PART
		Segment nxt = s.nxt;
		Segment add = new Segment(m, s.r, s.val);
		s.r = m;

		s.nxt = add;
		add.prv = s;

		add.nxt = nxt;
		nxt.prv = add;
	}

	void submit() {
		int n = nextInt();
		int m = nextInt();
		seed = nextInt();
		int vmax = nextInt();

		long[] a = new long[n];
		for (int i = 0; i < n; i++) {
			a[i] = rnd() % vmax + 1;
		}

		Segment head = new Segment(-1, 0, -1);
		Segment tmpTail = head;

		for (int i = 0; i < n; i++) {
			Segment seg = new Segment(i, i + 1, a[i]);
			tmpTail.nxt = seg;
			seg.prv = tmpTail;
			tmpTail = seg;
		}

		Segment tail = new Segment(n, n + 1, -1);
		tail.prv = tmpTail;
		tmpTail.nxt = tail;

		Segment[] arr = new Segment[n];
		int arrSz = 0;
		
//		System.err.println(Arrays.toString(a));

		while (m-- > 0) {
			int op = rnd() % 4;
			int l = rnd() % n;
			int r = rnd() % n;
			if (l > r) {
				int tmp = l;
				l = r;
				r = tmp;
			}

			int x = -1, y = -1;

			if (op == 2) {
				x = rnd() % (r - l + 1);
			} else {
				x = rnd() % vmax + 1;
			}

			if (op == 3) {
				y = rnd() % vmax + 1;
			}
			
//			System.err.println(op + ": " + l + "-" + r + " " + x + " " + y);

			r++;

			Segment bef, aft;

			{
				Segment ptr = head;
				while (ptr.r <= l) {
					ptr = ptr.nxt;
				}

				if (ptr.l != l) {
					split(ptr, l);
					bef = ptr;
					ptr = ptr.nxt;
				} else {
					bef = ptr.prv;
				}

				while (ptr.r < r) {
					ptr = ptr.nxt;
				}

				if (ptr.r != r) {
					split(ptr, r);
					aft = ptr.nxt;
				} else {
					aft = ptr.nxt;
				}
			}

			if (op == 0) {
				for (Segment seg = bef.nxt; seg != aft; seg = seg.nxt) {
					seg.val += x;
				}
				
//				for (int i = l; i < r; i++) {
//					a[i] += x;
//				}
				
				
			} else if (op == 1) {
				Segment blob = new Segment(l, r, x);
				bef.nxt = blob;
				blob.prv = bef;

				blob.nxt = aft;
				aft.prv = blob;
				
//				for (int i = l; i < r; i++) {
//					a[i] = x;
//				}
				
			} else if (op == 2) {
				arrSz = 0;
				for (Segment seg = bef.nxt; seg != aft; seg = seg.nxt) {
					arr[arrSz++] = seg;
				}
				Arrays.sort(arr, 0, arrSz);
				int i = 0;
				
				int realX = x;
				
				while (x >= arr[i].r - arr[i].l) {
					x -= arr[i].r - arr[i].l;
					i++;
				}
				out.println(arr[i].val);
				
				
//				long[] tmp = Arrays.copyOfRange(a, l, r);
//				Arrays.sort(tmp);
//				out.println("vs " + tmp[realX]);
				
			} else if (op == 3) {
				int ans = 0;
				for (Segment seg = bef.nxt; seg != aft; seg = seg.nxt) {
					ans += seg.eval(x, y);
					if (ans >= y) {
						ans -= y;
					}
				}
				out.println(ans);
				
				
				
				
//				int zzz = 0;
//				for (int i = l; i < r; i++) {
//					zzz += pow(a[i], x, y);
//					if (zzz >= y) {
//						zzz -= y;
//					}
//				}
//				out.println("vs " + zzz);
			}
			
//			System.err.println(Arrays.toString(a));
//			
//			for (Segment s = head; s != tail; s = s.nxt) {
//				System.err.println(s.l + " " + s.r + " " + s.val);
//			}
//			System.err.println("--------");
			
		}
	}
	
	int pow(long _a, int b, int m) {
		int a = (int) (_a % m);
		int ret = 1;
		for (; b > 0; b >>= 1) {
			if ((b & 1) == 1) {
				ret = (int)((long)ret * a % m);
			}
			a = (int)((long)a * a % m);
		}
		return ret;
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