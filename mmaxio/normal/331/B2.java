import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static void add(int[] f, int pos, int delta) {
		for (int i = pos; i < f.length; i |= i + 1) {
			f[i] += delta;
		}
	}

	static int get(int[] f, int pos) {
		int ret = 0;
		for (int i = pos; i >= 0; i = (i & (i + 1)) - 1) {
			ret += f[i];
		}
		return ret;
	}
	
	int n;
	int[] beaver2Pos;
	int[] val, fen;

	void solve() throws IOException {
		n = nextInt();

		int[] pos2Beaver = new int[n];
		beaver2Pos = new int[n];

		for (int i = 0; i < n; i++) {
			pos2Beaver[i] = nextInt() - 1;
			beaver2Pos[pos2Beaver[i]] = i;
		}

		fen = new int[n - 1];
		val = new int[n - 1];
		for (int i = 0; i < n - 1; i++) {
			if (beaver2Pos[i] > beaver2Pos[i + 1]) {
				val[i] = 1;
				add(fen, i, 1);
			}
		}

		int q = nextInt();
		while (q-- > 0) {
			int type = nextInt();
			if (type == 1) {
				int fromBeaver = nextInt() - 1;
				int toBeaver = nextInt() - 1;
				out.println(get(fen, toBeaver - 1) - get(fen, fromBeaver - 1) + 1);
			} else {
				int pos1 = nextInt() - 1;
				int pos2 = nextInt() - 1;
				
				int beaver1 = pos2Beaver[pos1];
				int beaver2 = pos2Beaver[pos2];
				
				pos2Beaver[pos1] = beaver2;
				pos2Beaver[pos2] = beaver1;
				
				beaver2Pos[beaver1] = pos2;
				beaver2Pos[beaver2] = pos1;
				
				update(beaver1 - 1);
				update(beaver1);
				update(beaver2 - 1);
				update(beaver2);
			}
		}
	}
	
	void update(int beaver) {
		if (beaver < 0 || beaver + 1 >= n)
			return;
		int newVal = comp(beaver2Pos[beaver], beaver2Pos[beaver + 1]);
		int delta = newVal - val[beaver];
		add(fen, beaver, delta);
		val[beaver] = newVal;
	}
	
	static int comp(int a, int b) {
		if (a == b)
			throw new AssertionError();
		return a < b ? 0 : 1;
	}

	B() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B();
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