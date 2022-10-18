import java.io.*;
import java.util.*;

public class A {

	void submit() {
		int r = nextInt();
		int c = nextInt();
		int[][] a = new int[r][c];
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				a[i][j] = nextInt();
			}
		}
		
		int[] ansR = null;
		int[] ansC = null;
		int ansTot = Integer.MAX_VALUE;
		
		outer: for (int r0 = 0; r0 <= 500; r0++) {
			int[] nowR = new int[r];
			int[] nowC = new int[c];
			nowR[0] = r0;
			for (int j = 0; j < c; j++) {
				nowC[j] = a[0][j] - nowR[0];
			}
			for (int i = 1; i < r; i++) {
				nowR[i] = a[i][0] - nowC[0];
			}
			
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (nowR[i] < 0 || nowC[j] < 0 || a[i][j] != nowR[i] + nowC[j]) {
						continue outer;
					}
				}
			}
			
			int nowTot = 0;
			for (int x : nowR) {
				nowTot += x;
			}
			
			for (int y : nowC) {
				nowTot += y;
			}
			
			if (nowTot < ansTot) {
				ansTot = nowTot;
				ansR = nowR;
				ansC = nowC;
			}
		}
		
		if (ansTot == Integer.MAX_VALUE) {
			out.println(-1);
		} else {
			out.println(ansTot);
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < ansR[i]; j++) {
					out.println("row " + (i + 1));
				}
			}
			
			for (int i = 0; i < c; i++) {
				for (int j = 0; j < ansC[i]; j++) {
					out.println("col " + (i + 1));
				}
			}
		}
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	A() throws IOException {
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
		new A();
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