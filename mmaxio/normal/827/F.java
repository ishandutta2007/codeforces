import java.io.*;
import java.util.*;

import sun.security.pkcs11.Secmod.DbMode;

public class F {

	static class Edge {
		int from, to;
		int idx;

		public Edge(int from, int to, int idx) {
			this.from = from;
			this.to = to;
			this.idx = idx;
		}
	}

	static class Event implements Comparable<Event> {
		int time;
		int type;
		Edge edge;

		public Event(int time, int type, Edge edge) {
			this.time = time;
			this.type = type;
			this.edge = edge;
		}

		@Override
		public int compareTo(Event o) {
			if (time != o.time) {
				return time < o.time ? -1 : 1;
			}
			return -Integer.compare(type, o.type);
//			return Integer.compare(time, o.time);
		}

	}

	int slow(int n, int m, int[] vs, int[] us, int[] ls, int[] rs) {
		boolean[] can = new boolean[n];
		can[0] = true;
		for (int time = 0;; time++) {
			if (can[n - 1]) {
				return time;
			}
			boolean canSmth = false;
			for (int i = 0; i < n; i++) {
				canSmth |= can[i];
			}
			if (!canSmth) {
				return -1;
			}
			boolean[] nxt = new boolean[n];
			for (int i = 0; i < m; i++) {
				nxt[us[i]] |= can[vs[i]] && ls[i] <= time && time < rs[i];
				nxt[vs[i]] |= can[us[i]] && ls[i] <= time && time < rs[i];
			}
			can = nxt;
		}
	}

	int solve(int n, int m, int[] vs, int[] us, int[] ls, int[] rs) {

		if (n == 1) {
			return 0;
		}

		PriorityQueue<Event> pq = new PriorityQueue<>(12 * m + 1);

		for (int i = 0; i < m; i++) {
			int v = vs[i];
			int u = us[i];
			int l = ls[i];
			int r = rs[i];

			for (int par = 0; par < 2; par++) {
				int start = firstAfter(l, par);
				int end = firstAfter(r, par);
				if (start >= end) {
					continue;
				}

				Edge eVU = new Edge((2 * v) ^ par, (2 * u) ^ 1 ^ par, 4 * i + 2
						* par);
				Edge eUV = new Edge((2 * u) ^ par, (2 * v) ^ 1 ^ par, 4 * i + 2
						* par + 1);

				pq.add(new Event(start, 1, eVU));
				pq.add(new Event(end, 3, eVU));
				pq.add(new Event(start, 1, eUV));
				pq.add(new Event(end, 3, eUV));
			}
		}

		int[] counter = new int[2 * n];

		int[] head = new int[2 * n];
		int[] next = new int[4 * m];
		Edge[] key = new Edge[4 * m];
		int ptr = 0;
		Arrays.fill(head, -1);

		boolean[] everActive = new boolean[4 * m];
		boolean[] isDead = new boolean[4 * m];

		while (!pq.isEmpty()) {
			Event ev = pq.poll();
			Edge e = ev.edge;

			if (ev.type == 1) {
				if (counter[e.from] != 0 || (e.from == 0 && ev.time == 0)) {
					pq.add(new Event(ev.time + 1, 2, e));
				} else {
					key[ptr] = e;
					next[ptr] = head[e.from];
					head[e.from] = ptr;
					ptr++;
				}
			} else if (ev.type == 2) {
				everActive[e.idx] = true;
				counter[e.to]++;
				if ((e.to >> 1) == n - 1) {
					return ev.time;
				}
				for (int i = head[e.to]; i >= 0; i = next[i]) {
					Edge oldEdge = key[i];
					if (isDead[oldEdge.idx]) {
						continue;
					}
					pq.add(new Event(ev.time + 1, 2, oldEdge));
				}
				head[e.to] = -1;
			} else {
				isDead[e.idx] = true;
				if (everActive[e.idx]) {
					counter[e.to]--;
				}
			}
		}

		return -1;
	}

	void submit() {
		int n = nextInt();
		int m = nextInt();

		int[] vs = new int[m];
		int[] us = new int[m];
		int[] ls = new int[m];
		int[] rs = new int[m];

		for (int i = 0; i < m; i++) {
			vs[i] = nextInt() - 1;
			us[i] = nextInt() - 1;
			ls[i] = nextInt();
			rs[i] = nextInt();
		}

		out.println(solve(n, m, vs, us, ls, rs));
//		out.println(slow(n, m, vs, us, ls, rs));
	}

	int firstAfter(int time, int parity) {
		return time + ((time & 1) ^ parity);
	}

	void preCalc() {

	}

	static final int B = 4;
	
	void stress() {
		for (int tst = 0;; tst++) {
			int n = rand(2, B);
			int m = rand(0, 3);
			int[] vs = new int[m];
			int[] us = new int[m];
			int[] ls = new int[m];
			int[] rs = new int[m];
			
			for (int i = 0; i < m; i++) {
				vs[i] = rand(0, n - 1);
				us[i] = (vs[i] + rand(1, n - 1)) % n;
				ls[i] = rand(0, B);
				rs[i] = rand(0, B) + rand(1, B);
			}
			
			int fast = solve(n, m, vs, us, ls, rs);
			int slow = slow(n, m, vs, us, ls, rs);
			
			if (fast != slow) {
				
				System.err.println(fast + " vs " + slow);
				
				System.err.println(n + " " + m);
				System.err.println(Arrays.toString(vs));
				System.err.println(Arrays.toString(us));
				System.err.println(Arrays.toString(ls));
				System.err.println(Arrays.toString(rs));
				throw new AssertionError();
			}
			
			System.err.println(tst++);
		}
	}

	void test() {

	}

	F() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
//		 stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new F();
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