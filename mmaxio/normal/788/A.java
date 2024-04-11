import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	long slow(long[] a) {
		long ret = 0;
		
		for (int i = 0; i < a.length; i++) {
			long sum = 0;
			for (int j = i + 1; j < a.length; j++) {
				long diff = a[j] - a[j - 1];
				if ((j - i) % 2 == 0) {
					diff = -diff;
				}
				sum += diff;
				ret = Math.max(ret, sum);
			}
		}
		return ret;
	}
	
	long go(long[] a) {
		long ret = 0;
		long minEven = 0;
		long pref = 0;
		for (int i = 0; i < a.length; i++) {
			pref += (i % 2 == 0 ? a[i] : -a[i]);
			ret = Math.max(ret, pref - minEven);
			if (i % 2 == 1) {
				minEven = Math.min(minEven, pref);
			}
		}
		return ret;
	}
	
	long solve(long[] a) throws IOException {
		int n = a.length;
		
		
		long[] b = new long[n - 1];
		for (int i = 0; i < n - 1; i++) {
			b[i] = Math.abs(a[i] - a[i + 1]);
		}
		
		return Math.max(go(b), go(Arrays.copyOfRange(b, 1, n - 1)));
	}

	void submit() throws IOException {
		int n = nextInt();
		
		long[] a = new long[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		out.println(solve(a));
	}
	
	A() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		submit();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new A();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return null;
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			eof = true;
			return null;
		}
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}