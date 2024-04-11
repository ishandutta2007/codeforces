import java.io.*;
import java.util.*;

public class B {

	int[][] head = new int[26][];
	int[][] next = new int[26][];
	int[][] to = new int[26][];
	int[] ptr = new int[26];
	
	void add(int v, int u, int symb) {
		int i = ptr[symb]++;
		
		to[symb][i] = u;
		next[symb][i] = head[symb][v];
		head[symb][v] = i;
	}
	
	int[][][] winner;
	
	void submit() {
		int n = nextInt();
		int m = nextInt();
		
		for (int i = 0; i < 26; i++) {
			head[i] = new int[n];
			Arrays.fill(head[i], -1);
			next[i] = new int[m];
			to[i] = new int[m];
		}
		
		for (int i = 0; i < m; i++) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;
			int symb = nextToken().charAt(0) - 'a';
			
			add(v, u, symb);
		}
		
		winner = new int[26][n][n];
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (go(i, j, 0) == 1) {
					out.print('A');
				} else {
					out.print('B');
				}
			}
			out.println();
		}
	}
	
	int go(int v, int u, int let) {
		if (winner[let][v][u] != 0) {
			return winner[let][v][u];
		}
		
		if (let < 25 && go(v, u, let + 1) == 1) {
			return winner[let][v][u] = 1;
		}
		
		int[] nowTo = to[let];
		int[] nowNext = next[let];
		
		for (int e = head[let][v]; e >= 0; e = nowNext[e]) {
			int newV = nowTo[e];
			if (go(u, newV, let) == -1) {
				return winner[let][v][u] = 1;
			}
		}
		
		return winner[let][v][u] = -1;
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