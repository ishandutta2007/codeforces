import java.io.*;
import java.util.*;

public class B {

	static final int N = 100_000;
	
	void add(int[] fen, int pos, int delta) {
		for (int i = pos; i < fen.length; i |= i + 1) {
			fen[i] += delta;
		}
	}

	int get(int[] fen, int l, int r) {
		return get(fen, r) - get(fen, l - 1);
	}

	int get(int[] fen, int pos) {
		int ret = 0;
		for (int i = pos; i >= 0; i = (i & (i + 1)) - 1) {
			ret += fen[i];
		}
		return ret;
	}
	
	void submit() {
		int n = nextInt();
		int[] a = new int[n];
		int[] cnt = new int[N];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt() - 1;
			cnt[a[i]]++;
		}
		
		int[][] where = new int[N][];
		for (int i = 0; i < N; i++) {
			where[i] = new int[cnt[i]];
		}
		
		for (int i = n - 1; i >= 0; i--) {
			int x = a[i];
			where[x][--cnt[x]] = i;
		}
		
		int[] fen = new int[n];
		for (int i = 0; i < n; i++) {
			add(fen, i, 1);
		}
		
		int pos = 0;
		
		long ans = 0;
		
		for (int[] lst : where) {
			if (lst.length == 0) {
				continue;
			}
			
			int lastSeen = getLastSeen(lst, pos);
			// blah-blah fenwick stuff
			
			if (pos <= lastSeen) {
				ans += get(fen, pos, lastSeen);
			} else {
				ans += get(fen, pos, n - 1) + get(fen, 0, lastSeen);
			}
			
			for (int x : lst) {
				add(fen, x, -1);
			}
			
			pos = (lastSeen + 1) % n;
		}
		
		out.println(ans);
		
	}
	
	int getLastSeen(int[] arr, int after) {
		int tmp = Arrays.binarySearch(arr, after);
		int posLess;
		if (tmp >= 0) {
			posLess = tmp - 1;
		} else {
			posLess = -tmp - 2;
		}
		if (posLess < 0) {
			return arr[arr.length - 1];
		} else {
			return arr[posLess];
		}
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