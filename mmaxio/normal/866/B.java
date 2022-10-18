import java.io.*;
import java.util.*;

public class B {

	static class Player implements Comparable<Player> {
		int cost;
		int cnt;
		
		@Override
		public int compareTo(Player o) {
			return Integer.compare(cost, o.cost);
		}

		public Player(int cost, int cnt) {
			this.cost = cost;
			this.cnt = cnt;
		}
	}
	
	void submit() {
		int n = nextInt();
		int pizza = nextInt();
		
		List<Player>[] lst = new List[2];
		lst[0] = new ArrayList<>();
		lst[1] = new ArrayList<>();
		
		long base = 0;
		
		long c1 = 0;
		long c2 = 0;
		
		for (int i = 0; i < n; i++) {
			int x = nextInt();
			int costA = nextInt();
			int costB = nextInt();
			base += (long)x * Math.max(costA, costB);
			if (costA >= costB) {
				lst[0].add(new Player(costA - costB, x));
				c1 += x;
			} else {
				lst[1].add(new Player(costB - costA, x));
				c2 += x;
			}
		}
		
		for (List<Player> l : lst) {
			Collections.sort(l);
		}
		
		long ret = Math.min(go(lst[0], c1, c2, pizza), go(lst[1], c2, c1, pizza));
		out.println(base - ret);
	}
	
	long go(List<Player> lst, long c1, long c2, int pizza) {
		long opt = ceil(c1 + c2, pizza);
		if (ceil(c1, pizza) + ceil(c2, pizza) == opt) {
			return 0;
		}
		long ret = 0;
		for (Player p : lst) {
			for (int i = 0; i < p.cnt; i++) {
				ret += p.cost;
				c1 -= 1;
				c2 += 1;
				if (ceil(c1, pizza) + ceil(c2, pizza) == opt) {
					return ret;
				}
			}
		}
		throw new AssertionError();
	}
	
	long ceil(long a, long b) {
		return (a + b - 1) / b;
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	B() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
		//stress();
		//test();
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