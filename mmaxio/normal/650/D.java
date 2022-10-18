import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Query implements Comparable<Query> {
		int pos, val, id;

		public Query(int pos, int val, int id) {
			this.pos = pos;
			this.val = val;
			this.id = id;
		}

		@Override
		public int compareTo(Query o) {
			return Integer.compare(val, o.val);
		}
		
		int asLast, asFirst;
	}
	
	void set(int[] f, int pos, int val) {
		for (int i = pos; i < f.length; i |= i + 1) {
			f[i] = Math.max(f[i], val);
		}
	}
	
	int get(int[] f, int pos) {
		int ret = 0;
		for (int i = pos; i >= 0; i = (i & (i + 1)) - 1) {
			ret = Math.max(ret, f[i]);
		}
		return ret;
	}

	void solve() throws IOException {
		int n = nextInt();
		int qq = nextInt();

		final int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		
		Query[] qs = new Query[qq];
		for (int i = 0; i < qq; i++) {
			qs[i] = new Query(nextInt() - 1, nextInt(), i);
		}
		
		Integer[] order = new Integer[n];
		for (int i = 0; i < n; i++) {
			order[i] = i;
		}
		
		Arrays.sort(order, new Comparator<Integer>() {

			@Override
			public int compare(Integer o1, Integer o2) {
				if (a[o1] != a[o2]) {
					return a[o1] < a[o2] ? -1 : 1;
				}
				return -o1.compareTo(o2);
			}
		});
		
		int[] fen = new int[n];
		
		Arrays.sort(qs);
		
		int[] asFirst = new int[n];
		int[] asLast = new int[n];
		
		int j = 0;
		
		for (int i = 0; i < qq; i++) {
			while (j < n && a[order[j]] < qs[i].val) {
				int prev = get(fen, order[j] - 1);
				set(fen, order[j], prev + 1);
				asLast[order[j]] = prev + 1;
				j++;
			}
			qs[i].asFirst = get(fen, qs[i].pos - 1) + 1;
		}
		
		while (j < n) {
			int prev = get(fen, order[j] - 1);
			set(fen, order[j], prev + 1);
			asLast[order[j]] = prev + 1;
			j++;
		}
		
		
		Arrays.fill(fen, 0);
		
		j = n - 1;
		for (int i = qq - 1; i >= 0; i--) {
			while (j >= 0 && a[order[j]] > qs[i].val) {
				int prev = get(fen, n - 1 - order[j] - 1);
				set(fen, n - 1 - order[j], prev + 1);
				asFirst[order[j]] = prev + 1;
				j--;
			}
			qs[i].asLast = get(fen, n - 1 - qs[i].pos - 1) + 1;
		}
		
		while (j >= 0) {
			int prev = get(fen, n - 1 - order[j] - 1);
			set(fen, n - 1 - order[j], prev + 1);
			asFirst[order[j]] = prev + 1;
			j--;
		}
		
		int justBest = 0;
		for (int i = 0; i < n; i++) {
			justBest = Math.max(justBest, asFirst[i] + asLast[i] - 1);
		}
		
		HashMap<Integer, Integer> map = new HashMap<>();
		
		int[] ansWithout = new int[n];
		Arrays.fill(ansWithout, justBest);
		
		for (int i = 0; i < n; i++) {
			if (asFirst[i] + asLast[i] - 1 != justBest) {
				continue;
			}
			if (!map.containsKey(asFirst[i])) {
				map.put(asFirst[i], i);
			} else {
				map.put(asFirst[i], -1);
			}
		}
		
//		System.err.println(Arrays.toString(asFirst));
//		System.err.println(Arrays.toString(asLast));
		
		
		for (Map.Entry<Integer, Integer> e : map.entrySet()) {
			if (e.getValue().intValue() != -1) {
				ansWithout[e.getValue()] = justBest - 1;
			}
		}
		
		int[] outp = new int[qq];
		for (int i = 0; i < qq; i++) {
			outp[qs[i].id] = Math.max(qs[i].asFirst + qs[i].asLast - 1, ansWithout[qs[i].pos]); 
		}
		
		for (int x : outp) {
			out.println(x);
		}
	}

	D() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
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