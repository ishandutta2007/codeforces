import java.io.*;
import java.util.*;

public class A {

	int f(int x) {
		return x == 0 ? 0 : (x % 10) + f(x / 10);
	}
	
	void submit() {
		int n = nextInt();
		ArrayList<Integer> ans = new ArrayList<>();
		for (int x = n; x >= n - 100 && x > 0; x--) {
			if (x + f(x) == n) {
				ans.add(x);
			}
		}
		Collections.sort(ans);
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