import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static Random rng = new Random(System.currentTimeMillis() + 1280375817201L);
	static int[] hashMult = new int[3];
	static {
		for (int i = 0; i < hashMult.length; i++) {
			hashMult[i] = rng.nextInt();
		}
	}

	static class State {
		int[] arr;

		@Override
		public int hashCode() {
			int ret = 0;
			for (int i = 0; i < arr.length; i++) {
				ret += arr[i] * hashMult[i];
			}
			return ret;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			State other = (State) obj;
			if (!Arrays.equals(arr, other.arr))
				return false;
			return true;
		}

		public State(int[] arr) {
			this.arr = arr;
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();

		int[][] mult = new int[3][n];
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < n; j++) {
				mult[i][j] = rng.nextInt();
			}
		}

		int[][] hash = new int[3][m];

		for (int i = 0; i < n; i++) {
			int cnt = nextInt();
			for (int j = 0; j < cnt; j++) {
				int type = nextInt() - 1;
				for (int z = 0; z < 3; z++) {
					hash[z][type] += mult[z][i];
				}
			}
		}

		int ret = 1;

		HashMap<State, Integer> set = new HashMap<>();
		for (int i = 0; i < m; i++) {
			State s = new State(
					new int[] { hash[0][i], hash[1][i], hash[2][i] });
			Integer prev = set.get(s);
			if (prev == null) {
				prev = 0;
			}
			set.put(s, prev + 1);
			ret = (int) ((long) ret * (prev + 1) % 1_000_000_007);
		}

		out.println(ret);
	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C();
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