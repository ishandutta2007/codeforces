import java.io.*;
import java.util.*;

public class B {

	interface Interactor {
		int[] ask(int idx);

		void answer(int ans);

		int[] readInput();
	}

	static final int B = 1_000_000_000;

	static final int MAX_QUERIES = 1999;

	class SubmitInteractor implements Interactor {

		@Override
		public int[] ask(int idx) {
			out.println("? " + (idx + 1));
			out.flush();
			int[] ret = new int[2];
			ret[0] = nextInt();
			ret[1] = nextInt() - 1;
			if (ret[1] == -2) {
				ret[1] = -1;
			}
			return ret;
		}

		@Override
		public void answer(int ans) {
			out.println("! " + ans);
			out.flush();
		}

		@Override
		public int[] readInput() {
			int[] ret = new int[3];
			ret[0] = nextInt();
			ret[1] = nextInt() - 1;
			ret[2] = nextInt();
			return ret;
		}
		
	}
	
	class LocalInteractor implements Interactor {

		int n;
		int x;
		int[] arr;
		int qry;

		public LocalInteractor(int n) {
			this.n = n;
			arr = new int[n];
			HashSet<Integer> used = new HashSet<>();
			for (int i = 0; i < n; i++) {
				while (true) {
					arr[i] = rand(0, B);
					if (!used.contains(arr[i])) {
						used.add(arr[i]);
						break;
					}
				}
			}
			Arrays.sort(arr);
			x = -1;
			while (true) {
				x = rand(0, B);
				if (!used.contains(x)) {
					break;
				}
			}
			
			int[] perm = new int[n];
			for (int i = 0; i < n; i++) {
				int j = rand(0, i);
				perm[i] = perm[j];
				perm[j] = i;
			}
			
			
			
		}

		@Override
		public int[] ask(int idx) {
			if (idx < 0 || idx >= n) {
				throw new AssertionError("Bad query");
			}
			if (++qry > MAX_QUERIES) {
				throw new AssertionError("Too many queries");
			}
			return new int[] { arr[idx], idx == n - 1 ? -1 : idx + 1 };
		}

		@Override
		public void answer(int ans) {
			if (++qry > MAX_QUERIES) {
				throw new AssertionError("Too many queries");
			}
			int realAns = -1;
			for (int i = 0; i < n; i++) {
				if (arr[i] >= x) {
					realAns = arr[i];
					break;
				}
			}
			if (ans != realAns) {
				throw new AssertionError("WA");
			}
			System.err.println("OK " + qry + " queries");
		}

		@Override
		public int[] readInput() {
			return new int[] { n, 0, x };
		}

	}

	static final int K = 1500;

	static class Number implements Comparable<Number> {
		int val, pos, next;

		public Number(int val, int pos, int next) {
			this.val = val;
			this.pos = pos;
			this.next = next;
		}

		@Override
		public int compareTo(Number o) {
			return Integer.compare(val, o.val);
		}

	}

	void submit(Interactor it) {
		int[] tmp = it.readInput();
		int n = tmp[0];
		int start = tmp[1];
		int x = tmp[2];

		int[] left = new int[n];
		for (int i = 0; i < n; i++) {
			left[i] = i;
		}

		Number[] a = new Number[Math.min(K, n)];
		tmp = it.ask(start);
		if (tmp[0] >= x) {
			it.answer(tmp[0]);
			return;
		}
		a[0] = new Number(tmp[0], start, tmp[1]);

		left[start] = n - 1;

		for (int i = 1; i < a.length; i++) {

			int leftIdx = rng.nextInt(n - i);
			int idx = left[leftIdx];

			left[leftIdx] = left[n - i - 1];

			tmp = it.ask(idx);
			a[i] = new Number(tmp[0], idx, tmp[1]);
		}

		Arrays.sort(a);

		int begin = 0;
		while (begin + 1 < a.length && a[begin + 1].val < x) {
			begin++;
		}

		int until;
		if (begin == a.length - 1) {
			until = -1;
		} else {
			until = a[begin + 1].pos;
		}

		int cur = a[begin].next;
		while (cur != until) {
			tmp = it.ask(cur);
			if (tmp[0] >= x) {
				it.answer(tmp[0]);
				return;
			}
			cur = tmp[1];
		}

		if (until != -1) {
			it.answer(a[begin + 1].val);
		} else {
			it.answer(-1);
		}
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {
//		for (int i = 0; i < 10000; i++) {
//			submit(new LocalInteractor(50000));
//		}
		 submit(new LocalInteractor(50000));
	}

	B() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		// preCalc();
		submit(new SubmitInteractor());
		// stress();
//		test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new B();
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