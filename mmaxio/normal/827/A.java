import java.io.*;
import java.util.*;

public class A {

	void submit() {
		int n = nextInt();
		String[] a = new String[n];
		
		int[] startAt = new int[2_000_000];
		Arrays.fill(startAt, -1);
		
		int length = 0;
		
		for (int i = 0; i < n; i++) {
			a[i] = nextToken();
			int k = nextInt();
			for (int j = 0; j < k; j++) {
				int pos = nextInt() - 1;
				length = Math.max(length, pos + a[i].length());
				int was = startAt[pos];
				if (was == -1 || a[was].length() < a[i].length()) {
					startAt[pos] = i;
				}
			}
		}
		
		char[] ans = new char[length];
		
		String now = null;
		int left = 0;
		
		for (int i = 0; i < length; i++) {
			int here = startAt[i];
			if (here != -1 && a[here].length() > left){
				now = a[here];
				left = a[here].length();
			}
			if (left == 0) {
				ans[i] = 'a';
			} else {
				ans[i] = now.charAt(now.length() - left);
				left--;
			}
		}
		
		out.println(new String(ans));
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