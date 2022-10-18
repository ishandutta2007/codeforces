import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class MultiTreeSet<T extends Comparable<T>> {
		private TreeMap<T, Integer> map = new TreeMap<>();
		private int size = 0;

		public int count(T x) {
			Integer ret = map.get(x);
			return ret == null ? 0 : ret;
		}

		void add(T x) {
			map.put(x, count(x) + 1);
			size++;
		}

		T first() {
			return map.firstKey();
		}

		T last() {
			return map.lastKey();
		}

		T floor(T key) {
			return map.floorKey(key);
		}

		boolean remove(T x) {
			int prev = count(x);
			if (prev == 0) {
				return false;
			}
			if (prev == 1) {
				map.remove(x);
			} else {
				map.put(x, prev - 1);
			}
			size--;
			return true;
		}

		boolean isEmpty() {
			return map.isEmpty();
		}

		@Override
		public String toString() {
			return map.toString();
		}
		
		int size() {
			return size;
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int[] arr = new int[3];
		for (int i = 0; i < 3; i++) {
			arr[i] = nextInt();
		}
		Arrays.sort(arr);

		int a = arr[0];
		int b = arr[1];
		int c = arr[2];

		MultiTreeSet<Integer> set = new MultiTreeSet<>();
		for (int i = 0; i < n; i++) {
			set.add(nextInt());
		}

		int ret = 0;

		if (set.last() > a + b + c) {
			out.println(-1);
			return;
		}

		// abc
		while (!set.isEmpty() && set.last() > b + c) {
			set.remove(set.last());
			ret++;
		}

		// bc + a
		while (!set.isEmpty() && set.last() > a + c) {
			set.remove(set.last());
			Integer free = set.floor(a);
			if (free != null) {
				set.remove(free);
			}
			ret++;
		}

		// ac + b
		while (!set.isEmpty() && set.last() > Math.max(a + b, c)) {
			set.remove(set.last());
			Integer free = set.floor(b);
			if (free != null) {
				set.remove(free);
			}
			ret++;
		}

		// a/b/c or ab/c
		int big = Math.max(a + b, c);
		int small = Math.min(a + b, c);

		int tooBig = 0;
		int onlyBig = 0;
		int both = 0;

		for (Map.Entry<Integer, Integer> x : set.map.entrySet()) {
			if (x.getKey() > big) {
				tooBig += x.getValue();
			} else if (x.getKey() > small) {
				onlyBig += x.getValue();
			} else {
				both += x.getValue();
			}
		}

		int ans = Integer.MAX_VALUE;

		for (int two = 0;; two++) {
			if (tooBig == 0) {
				ans = Math
						.min(ans,
								ret
										+ two
										+ Math.max(onlyBig,
												(onlyBig + both + 1) / 2));
			}
			
			if (set.isEmpty()) {
				break;
			}
			
			int oldSz = set.size();

			Integer rem = set.floor(c);
			if (rem != null) {
				set.remove(rem);
				if (rem > big) {
					tooBig--;
				} else if (rem > small) {
					onlyBig--;
				} else {
					both--;
				}
			}

			rem = set.floor(b);
			if (rem != null) {
				set.remove(rem);
				if (rem > big) {
					tooBig--;
				} else if (rem > small) {
					onlyBig--;
				} else {
					both--;
				}
			}

			rem = set.floor(a);
			if (rem != null) {
				set.remove(rem);
				if (rem > big) {
					tooBig--;
				} else if (rem > small) {
					onlyBig--;
				} else {
					both--;
				}
			}
			
			if (set.size() == oldSz) {
				break;
			}
		}

		out.println(ans);
	}

	E() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		// for (int x = 0; x <= 30; x++)
		// for (int y = 0; y <= 30; y++) {
		// f(x, y);
		// }
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new E();
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