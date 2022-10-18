import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		Random rng = new Random();
		for (int i = 0; i < n; i++) {
			int j = rng.nextInt(i + 1);
			a[i] = a[j];
			a[j] = nextInt();
		}
		
		Arrays.sort(a);
		
		long ans = 0;
		long sum = 0;
		
		for (int i = 0, j = n - 1; i < n; i++, j--) {
			if (Integer.bitCount(i) == 1 && (Integer.numberOfTrailingZeros(i) & 1) == 0)
				ans += sum;
			sum += a[j];
		}
		
		ans += sum;
		out.println(ans);
	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C();
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