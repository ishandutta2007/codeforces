import java.io.*;
import java.util.*;

public class A {

	static final int C = 100;
	
	boolean isAcute(int[] a, int[] b, int[] c) {
		int sum = 0;
		for (int i = 0; i < a.length; i++) {
			sum += (b[i] - a[i]) * (c[i] - a[i]);
		}
		return sum > 0;
	}
	
	void submit() {
		int n = nextInt();
		int[][] a = new int[n][5];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 5; j++) {
				a[i][j] = nextInt();
			}
		}
		
		if (n > C) {
			out.println(0);
			return;
		}
		
		ArrayList<Integer> ans = new ArrayList<>();
		outer: for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = j + 1; k < n; k++) {
					if (k != i && k != j) {
						if (isAcute(a[i], a[j], a[k])) {
							continue outer;
						}
					}
				}
			}
			ans.add(i + 1);
		}
		out.println(ans.size());
		for (int x : ans) {
			out.println(x);
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