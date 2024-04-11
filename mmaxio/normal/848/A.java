import java.io.*;
import java.util.*;

public class A {

	String solve(int x) {
		if(x == 0) {
			return "a";
		}
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < 26; i++) {
			if (x == 0) {
				break;
			}
			int cur = 0;
			while (cur * (cur + 1) / 2 <= x) {
				cur++;
			}
			x -= cur * (cur - 1) / 2;
			char c = (char)('a' + i);
			for (int z = 0; z < cur; z++) {
				sb.append(c);
			}
		}
//		System.err.println(sb.length());
		return sb.toString();
	}
	
	void submit() {
		out.print(solve(nextInt()));
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