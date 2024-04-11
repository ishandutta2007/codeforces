import java.io.*;
import java.util.*;

public class C {
	
	static class Item implements Comparable<Item> {
		int bonus;
		int cost;

		public Item(int bonus, int cost) {
			this.bonus = bonus;
			this.cost = cost;
		}

		@Override
		public int compareTo(Item o) {
			return Integer.compare(cost, o.cost);
		}
	}
	
	void submit() {
		int n = nextInt();
		int x = nextInt();
		int y = nextInt();
		
		ArrayList<Item> it[] = new ArrayList[2];
		it[0] = new ArrayList<>();
		it[1] = new ArrayList<>();
		
		int ans = 0;
		int b0 = 0, b1 = 0;
		for (int i = 0; i < n; i++) {
			int bonus = nextInt();
			int cost = nextInt();
			int type = nextToken().equals("C") ? 0 : 1;
			if (type == 0 && cost <= x) {
				b0 = Math.max(b0, bonus);
			}
			if (type == 1 && cost <= y) {
				b1 = Math.max(b1, bonus);
			}
			it[type].add(new Item(bonus, cost));
		}
		
		if (b0 != 0 && b1 != 0) {
			ans = b0 + b1;
		}
		
		ans = Math.max(ans, solve(it[0], x));
		ans = Math.max(ans, solve(it[1], y));
		
		out.println(ans);
	}
	
	int solve(ArrayList<Item> arr, int lim) {
		Collections.sort(arr);
		
		int b1 = -1;
		int b2 = -1;
		
		int ret = 0;
		
		int j = 0;
		for (int i = arr.size() - 1; i >= 0; i--) {
			while (j < arr.size() && arr.get(i).cost + arr.get(j).cost <= lim) {
				int here = arr.get(j).bonus;
				if (here > b1) {
					b2 = b1;
					b1 = here;
				} else if (here > b2) {
					b2 = here;
				}
				
				j++;
			}
			
			if (b1 == -1 && b2 == -1) {
				continue;
			}
			
			if (b1 != -1 && arr.get(i).bonus != b1) {
				ret = Math.max(ret, b1 + arr.get(i).bonus);
			} else {
				if (b2 != -1) {
					ret = Math.max(ret, b2 + arr.get(i).bonus);
				}
			}
			
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
		//stress();
		//test();
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