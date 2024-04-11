import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	class Event implements Comparable<Event>{
		int l, r;
		int val;
		int sign;
		int id;
		public Event(int l, int r, int val, int sign, int id) {
			this.l = l;
			this.r = r;
			this.val = val;
			this.sign = sign;
			this.id = id;
		}
		@Override
		public int compareTo(Event o) {
			return Integer.compare(val, o.val);
		}
		
	}

	void solve() throws IOException {
		int n = nextInt();
		int q = nextInt();
		
		int[] p = new int[n];
		int[] inv = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = nextInt() - 1;
			inv[p[i]] = i;
		}
		
		Event[] evs = new Event[2 * q];
		for (int i = 0; i < q; i++) {
			int l = nextInt() - 1;
			int r = nextInt() - 1;
			evs[2 * i] = new Event(l, r, l - 1, -1, i);
			evs[2 * i + 1] = new Event(l, r, r, 1, i);
		}
		
		Arrays.sort(evs);
		long[] f = new long[n];
		long[] res = new long[q];
		int lastX = 0;
		for (int i = 0; i < evs.length; i++) {
			Event e = evs[i];
			while (lastX <= e.val) {
				int num = p[lastX];
				for (int j = num; j < n; j += num + 1)
					add(f, inv[j]);
				lastX++;
			}
			long delta = get(f, e.l, e.r) * e.sign;
			res[e.id] += delta;
		}
		
		for (int i = 0; i < q; i++)
			out.println(res[i]);
	}

	void add(long[] f, int pos) {
		for (int i = pos; i < f.length; i |= i + 1)
			f[i]++;
	}
	
	long get(long[] f, int l, int r) {
		return get(f, r) - get(f, l - 1);
	}
	
	long get(long[] f, int pos) {
		long ret = 0;
		for (int i = pos; i >= 0; i = (i & (i + 1)) - 1)
			ret += f[i];
		return ret;
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