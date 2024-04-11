import java.io.*;
import java.util.*;

public class D {

	HashMap<Integer, Integer>[] createLayer(int n) {
		HashMap<Integer, Integer>[] hm = new HashMap[n + 1];
		for (int i = 0; i <= n; i++) {
			hm[i] = new HashMap<>();
		}
		return hm;
	}
	
	ArrayList<Integer> getDegs(int[] a) {
		
		int n = a.length;
		
		ArrayList<HashMap<Integer, Integer>[]> dp = new ArrayList<>();
		
		HashMap<Integer, Integer>[] init = createLayer(n);
		init[0].put(0, -1);
		dp.add(init);
		
		outer: for (int ans = 1;; ans++) {
//			System.err.println(ans);
			
			int need = ans * (ans - 1) / 2;
			
			HashMap<Integer, Integer>[] prev = dp.get(ans - 1);
			
			HashMap<Integer, Integer>[] now = createLayer(n);
			dp.add(now);
			
			for (int state = 0; state <= n; state++) {
				HashMap<Integer, Integer> map = prev[state];
				
				for (Integer val : map.keySet()) {
					
					for (int what = state - 1; what <= state; what++) {
						if (what < 0 || what >= n) {
							continue;
						}
						
						int newVal = val + a[what];
						if (newVal < need) {
							continue;
						}
						
						now[what + 1].put(newVal, state);
						if (what == n - 1 && newVal == need) {
							break outer;
						}
					}
					
					
				}
			}
		}
		
		int ansSz = dp.size() - 1;
		
		ArrayList<Integer> ans = new ArrayList<>();
		int layer = dp.size() - 1;
		int state = n;
		int sum = ansSz * (ansSz - 1) / 2;
		while (layer > 0) {
			HashMap<Integer, Integer> map = dp.get(layer)[state];
			
			int prevState = map.get(sum);
			
			ans.add(a[state - 1]);
			
			sum -= a[state - 1];
			state = prevState;
			layer--;
		}
		
		return ans;
	}
	
	static class Player implements Comparable<Player> {
		int idx;
		int wins;
		
		@Override
		public int compareTo(Player o) {
			return Integer.compare(wins, o.wins);
		}

		public Player(int idx, int wins) {
			this.idx = idx;
			this.wins = wins;
		}
		
	}
	
	void makeAnswer(ArrayList<Integer> degs) {
		int n = degs.size();
		Player[] a = new Player[n];
		for (int i = 0; i < n; i++) {
			a[i] = new Player(i, degs.get(i));
		}
		
		char[][] ans = new char[n][n];
		for (int i = 0; i < n; i++) {
			Arrays.fill(ans[i], '0');
		}
		
		for (int i = n; i > 0; i--) {
			Arrays.sort(a, 0, i);
			Player now = a[i - 1];
			
			for (int j = 0; j < now.wins; j++) {
				ans[now.idx][a[j].idx] = '1';
			}
			for (int j = now.wins; j < i - 1; j++) {
				ans[a[j].idx][now.idx] = '1';
				a[j].wins--;
			}
			
		}
		
		out.println(n);
		for (char[] row : ans) {
			out.println(row);
		}
	}
	
	void submit() {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		Arrays.sort(a);
		ArrayList<Integer> degs = getDegs(a);
		makeAnswer(degs);
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {
		for (int tst = 0; tst < 10; tst++) {
//			int mask = rand(0, 1_000_000_000);
//			int mask = (1 << rand(0, 30)) | (1 << rand(0, 30)) | (1 << rand(0, 30)) | (1 << rand(0, 30));
			
//			int mask = (1 << 31) - 1 - tst;
			int mask = tst + 1;
			int[] a = new int[Integer.bitCount(mask)];
			
			int ptr = 0;
			for (int i = mask, j = 0; i > 0; i >>= 1, j++) {
				if ((i & 1) == 1) {
					a[ptr++] = j;
				}
			}
			
			System.err.println(Arrays.toString(a) + " " + getDegs(a));
		}
	}

	D() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
//		stress();
//		test();
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