import java.io.*;
import java.util.*;

public class D {

	static class Card {
		int x, y, z;

		public Card(int x, int y, int z) {
			this.x = x;
			this.y = y;
			this.z = z;
		}
	}
	
	long solve(int n, int p, int q, int r, int[] xs, int[] ys, int[] zs) {
		Card[] vals = new Card[n];
		int[] head = new int[r];
		int[] next = new int[n];
		Arrays.fill(head, -1);
		
		for (int i = 0; i < n; i++) {
			int x = p - xs[i];
			int y = q - ys[i];
			int z = r - zs[i];
			vals[i] = new Card(x, y, z);
			next[i] = head[z];
			head[z] = i;
		}
		
		int[] h = new int[p];
		Arrays.fill(h, q);
		
		for (Card c : vals){ 
			h[c.x] = Math.min(h[c.x], c.y);
		}
		
		for (int i = 1; i < p; i++) {
			h[i] = Math.min(h[i], h[i - 1]);
		}
		
		long[] pref = new long[p + 1];
		for (int i = 0; i < p; i++) {
			pref[i + 1] = pref[i] + h[i];
		}
		
		int szX = p;
		int szY = q;
		
		long ans = 0;
		
		for (int i = 0; i < r; i++) {
			for (int idx = head[i]; idx >= 0; idx = next[idx]) {
				Card c = vals[idx];
				szX = Math.min(szX, c.x);
				szY = Math.min(szY, c.y);
			}
			
			int low = -1; // >= szY
			int high = szX; // < szY
			
			while (high - low > 1) {
				int mid = (low + high) >> 1;
				if (h[mid] >= szY) {
					low = mid;
				} else {
					high = mid;
				}
			}
			
			ans += (long)high * szY;
			ans += pref[szX] - pref[high];
		}
		
		return ans;
	}
	
	void submit() {
		int n = nextInt();
		int p = nextInt();
		int q = nextInt();
		int r = nextInt();
		
		int[] xs = new int[n];
		int[] ys = new int[n];
		int[] zs = new int[n];
		
		for (int i = 0; i < n; i++) {
			xs[i] = nextInt();
			ys[i] = nextInt();
			zs[i] = nextInt();
		}
		
		out.println(solve(n, p, q, r, xs, ys, zs));
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
		//stress();
		//test();
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