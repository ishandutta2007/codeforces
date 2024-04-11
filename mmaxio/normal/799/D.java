import java.io.*;
import java.util.*;

public class D {

	static final int INF = Integer.MAX_VALUE;
	static final int C = 34;

	static class State {
		int x, y;

		@Override
		public int hashCode() {
			return x * 100001 + y;
		}

		@Override
		public boolean equals(Object obj) {
			State other = (State) obj;
			return x == other.x && y == other.y;
		}

		public State(int x, int y) {
			if (x > y) {
				int tmp = x;
				x = y;
				y = tmp;
			}
			this.x = x;
			this.y = y;
		}

		@Override
		public String toString() {
			return "(" + x + ", " + y + ")";
		}
	}
	
	int ceilDiv(int a, int b) {
		return (a + b - 1) / b;
	}

	int go(int x0, int y0, int x1, int y1, int[] arr) {
		HashMap<State, Integer> dp = new HashMap<>();
		dp.put(new State(x0, y0), 0);

		for (int x : arr) {
			HashMap<State, Integer> nxt = new HashMap<>();
			for (Map.Entry<State, Integer> e : dp.entrySet()) {

				State s = e.getKey();
				int val = e.getValue();
				
				{
					Integer prev = nxt.get(s);
					if (prev == null || prev > val) {
						nxt.put(s, val);
					}
				}
				
				{
					State toS = new State(ceilDiv(s.x, x), s.y);
					Integer prev = nxt.get(toS);
					if (prev == null || prev > val + 1) {
						nxt.put(toS, val + 1);
					}
				}

				{
					State toS = new State(s.x, ceilDiv(s.y, x));
					Integer prev = nxt.get(toS);
					if (prev == null || prev > val + 1) {
						nxt.put(toS, val + 1);
					}
				}

			}
			dp = nxt;
			
//			System.err.println(x + " " + dp);
		}
		
		int ret = INF;

		for (Map.Entry<State, Integer> e : dp.entrySet()) {
			State s = e.getKey();
			int val = e.getValue();
			if ((s.x <= x1 && s.y <= y1) || (s.x <= y1 && s.y <= x1)) {
				ret = Math.min(ret, val);
			}
		}
		
		return ret;
	}

	void submit() {
		int a = nextInt();
		int b = nextInt();
		int w = nextInt();
		int h = nextInt();
		int n = nextInt();
		int[] arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = nextInt();
		}

		Arrays.sort(arr);
		if (n > C) {
			arr = Arrays.copyOfRange(arr, n - C, n);
		}

		int ret = go(a, b, h, w, arr);
		if (ret == INF) {
			out.println(-1);
		} else {
			out.println(ret);
		}
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	D() throws IOException {
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
		new D();
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