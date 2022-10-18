import java.io.*;
import java.util.*;

public class A {
	
	static final String F0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
	static final String F1_BEG =  "What are you doing while sending \"";
	static final String F1_MID = "\"? Are you busy? Will you send \"";
	static final String F1_END = "\"?";

	long[] len;
	
	long getLen(int n) {
		return n < len.length ? len[n] : Long.MAX_VALUE / 3;
	}
	
	char solve(int n, long k) {
		if (k >= getLen(n)) {
			return '.';
		}
		if (n == 0) {
			return F0.charAt((int) k);
		}
		
		if (k < F1_BEG.length()) {
			return F1_BEG.charAt((int) k);
		}
		k -= F1_BEG.length();
		
		if (k < getLen(n - 1)) {
			return solve(n - 1, k);
		}
		k -= getLen(n - 1);
		
		if (k < F1_MID.length()) {
			return F1_MID.charAt((int) k);
		}
		k -= F1_MID.length();
		
		if (k < getLen(n - 1)) {
			return solve(n - 1, k);
		}
		k -= getLen(n - 1);
		
		if (k < F1_END.length()) {
			return F1_END.charAt((int) k);
		}
		k -= F1_END.length();
		
		throw new AssertionError();
	}
	
	void submit() {
		len = new long[55];
		len[0] = F0.length();
		
		for (int i = 1; i < len.length; i++) {
			len[i] = F1_BEG.length() + F1_MID.length() + F1_END.length() + 2 * len[i - 1];
//			System.err.println(i + " " + len[i]);
		}
		
		int q = nextInt();
		while (q-- > 0) {
			int n = nextInt();
			long k = nextLong() - 1;
			out.print(solve(n, k));
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