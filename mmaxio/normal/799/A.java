import java.io.*;
import java.util.*;

public class A {

	void submit() {
		int need = nextInt();
		int time = nextInt();
		int batch = nextInt();
		int build = nextInt();
		
		int n = (need + batch - 1) / batch;
		
		int stupid = n * time;
		
		int low = 0;
		int high = 1_000_000;
		while (high - low > 1) {
			int mid = (low + high) >> 1;
			
			int canPrepare = mid / time;
			if (mid >= build) {
				canPrepare += (mid - build) / time;
			}
			if (canPrepare >= n) {
				high = mid;
			} else {
				low = mid;
			}
		}
		
		int smart = high;
		out.println(stupid > smart ? "YES" : "NO");
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