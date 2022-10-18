import java.io.*;
import java.util.*;

public class A {

	void submit() {
		int n = nextInt();
		int[] a = new int[n];
		int c1 = 0;
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
			if (a[i] == 1) {
				c1++;
			}
		}
		
		if (c1 > 0) {
			out.println(n - c1);
			return;
		}
		
		int ans = Integer.MAX_VALUE;
		
		for (int i = 0; i < n; i++) {
			int g = 0;
			int j = i;
			while (j < n) {
				g = gcd(g, a[j]);
				if (g == 1) {
					ans = Math.min(ans, j - i + n - 1);
					break;
				}
				j++;
			}
			if (i == 0 && j == n) {
				out.println(-1);
				return;
			}
		}
		
		out.println(ans);
	}
	
	int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
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