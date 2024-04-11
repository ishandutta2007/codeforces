import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Candy {
		int need;
		int bonus;
		int id;

		public Candy(int need, int bonus, int id) {
			this.need = need;
			this.bonus = bonus;
			this.id = id;
		}
	}

	Comparator<Candy> byNeed = new Comparator<Candy>() {

		@Override
		public int compare(Candy o1, Candy o2) {
			if (o1.need != o2.need) {
				return o1.need < o2.need ? -1 : 1;
			}
			return Integer.compare(o1.id, o2.id);
		}
	};

	Comparator<Candy> byBonus = new Comparator<Candy>() {

		@Override
		public int compare(Candy o1, Candy o2) {
			if (o1.bonus != o2.bonus) {
				return o1.bonus < o2.bonus ? -1 : 1;
			}
			return Integer.compare(o1.id, o2.id);
		}
	};

	int go(int init, List<Candy> h1, List<Candy> h2) {
		int ret = 0;
		TreeSet<Candy> can1 = new TreeSet<>(byBonus);
		TreeSet<Candy> can2 = new TreeSet<>(byBonus);

		int i1 = 0;
		int i2 = 0;
		while (i1 < h1.size() && h1.get(i1).need <= init) {
			can1.add(h1.get(i1++));
		}
		while (i2 < h2.size() && h2.get(i2).need <= init) {
			can2.add(h2.get(i2++));
		}

		while (true) {
			if (can1.isEmpty()) {
				return ret;
			}
			Candy tmp = can1.pollLast();
			init += tmp.bonus;
			ret++;
			while (i1 < h1.size() && h1.get(i1).need <= init) {
				can1.add(h1.get(i1++));
			}
			while (i2 < h2.size() && h2.get(i2).need <= init) {
				can2.add(h2.get(i2++));
			}
			
			if (can2.isEmpty()) {
				return ret;
			}
			tmp = can2.pollLast();
			init += tmp.bonus;
			ret++;
			while (i1 < h1.size() && h1.get(i1).need <= init) {
				can1.add(h1.get(i1++));
			}
			while (i2 < h2.size() && h2.get(i2).need <= init) {
				can2.add(h2.get(i2++));
			}
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int x = nextInt();
		List<Candy> t0 = new ArrayList<>();
		List<Candy> t1 = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			int type = nextInt();
			int need = nextInt();
			int bonus = nextInt();
			Candy tmp = new Candy(need, bonus, i);
			(type == 0 ? t0 : t1).add(tmp);
		}
		Collections.sort(t0, byNeed);
		Collections.sort(t1, byNeed);
		int ans = Math.max(go(x, t0, t1), go(x, t1, t0));
		out.println(ans);
	}

	A() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new A();
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