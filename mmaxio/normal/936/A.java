import java.io.*;
import java.util.*;

public class A {

	void submit() {
		long k = nextLong();
		long d = nextLong();
		long baseT = nextLong();

		long full_ = (k + d - 1) / d * d;
		long on = k;
		long off = full_ - on;
		
		// on as baseT
		// off as 2 * baseT
		
		long cycle = 2 * on + off;
		
		long full = 2 * baseT / cycle;
		
		long ans = full * (on + off);
		
		long rem = 2 * baseT % cycle;
		
		if (rem < 2 * on) {
			out.println(ans + rem * 0.5);
		} else {
			rem -= 2 * on;
			ans += on;
			out.println(ans + rem);
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