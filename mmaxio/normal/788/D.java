import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	interface Interactor {
		int ask(int x, int y);

		void answer(int[] xs, int[] ys);
	}

	class SubmitInteractor implements Interactor {

		@Override
		public int ask(int x, int y) {
			if (Math.abs(x) > B || Math.abs(y) > B) {
				return -1;
			}
			out.println("0 " + x + " " + y);
			out.flush();
			try {
				return nextInt();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return -1;
		}

		@Override
		public void answer(int[] xs, int[] ys) {
			out.println("1 " + xs.length + " " + ys.length);
			for (int x : xs) {
				out.print(x + " ");
			}
			out.println();
			for (int y : ys) {
				out.print(y + " ");
			}
			out.println();
		}

	}

	static final int B = 100_000_000;
	static final int MAX_QUERIES = 300_000;

	int ask1d(int[] xs, int x) {
		int pos = Arrays.binarySearch(xs, x);
		if (pos < 0) {
			pos = -pos - 2;
		}
		int ret = Integer.MAX_VALUE;
		if (pos != -1) {
			ret = Math.min(ret, x - xs[pos]);
		}
		if (pos + 1 < xs.length) {
			ret = Math.min(ret, xs[pos + 1] - x);
		}
		return ret;
	}

	class LocalInteractor implements Interactor {

		int[] xs;
		int[] ys;

		int qryCnt = 0;

		@Override
		public int ask(int x, int y) {
			if (Math.abs(x) > B && Math.abs(y) > B) {
				return -1;
			}
			if (x > B) {
				x = B;
			}
			if (x < -B) {
				x = -B;
			}
			if (y > B) {
				y = B;
			}
			if (y < -B) {
				y = -B;
			}
			if (++qryCnt > MAX_QUERIES) {
				throw new AssertionError("too many queries");
			}
			return Math.min(ask1d(xs, x), ask1d(ys, y));
		}

		@Override
		public void answer(int[] xs, int[] ys) {
			Arrays.sort(xs);
			Arrays.sort(ys);

			if (!Arrays.equals(xs, this.xs) || !Arrays.equals(ys, this.ys)) {
				throw new AssertionError("wa");
			} else {
				System.err.println("gg in " + qryCnt);
			}
		}

		public LocalInteractor(int[] xs, int[] ys) {
			Arrays.sort(xs);
			Arrays.sort(ys);
			this.xs = xs;
			this.ys = ys;
		}

	}
	static final Random rng = new Random();

	int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}
	
	void go(int low, int high, Interactor it, List<Integer> ans) {
		if (high - low <= 1) {
			return;
		}
		
		int mid = (low + high) >> 1;
		int dist = it.ask(mid, mid);
		
		if (mid - dist == low) {
			if (mid + dist != high && it.ask(mid + dist, mid + dist) == 0) {
				ans.add(mid + dist);
			}
			return;
		}
		
		int found = it.ask(mid - dist, mid - dist) == 0 ? mid - dist : mid + dist;
		
		ans.add(found);
		go(low, found, it, ans);
		go(found, high, it, ans);
	}
	
	void solve(Interactor it) {
		int low = -B + it.ask(-B, -B);
		int high = B - it.ask(B, B);
		
		List<Integer> ans = new ArrayList<>();
		if (low == high) {
			ans.add(low);
		} else {
			ans.add(low);
			ans.add(high);
			go(low, high, it, ans);
		}
		
		int z = rand(-B, B);
		
		int[] ansX = new int[ans.size()];
		int[] ansY = new int[ans.size()];
		int szX = 0, szY = 0;
		
		
		for (int x : ans) {
			if (it.ask(x, z) == 0) {
				ansX[szX++] = x;
			}
			if (it.ask(z, x) == 0) {
				ansY[szY++] = x;
			}
		}
		
		it.answer(Arrays.copyOf(ansX, szX), Arrays.copyOf(ansY, szY));
		
		
	}

	D() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		// solve(new SubmitInteractor());
		// solve(new LocalInteractor(new int[] { 2 }, new int[] { 0, -3 }));
//		int cnt = 10000;
//		int[] xs = new int[cnt];
//		int[] ys = new int[cnt];

//		int small = B / 1000 * 999;
		// int small = B;
//		int small = 113231512;

//		for (int i = 0; i < cnt; i++) {
//			xs[i] = rand(-B, B);
//			ys[i] = rand(-B, B);
//		}

//		solve(new LocalInteractor(xs, ys));
		solve(new SubmitInteractor());
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D();
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