import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	static final Random rng = new Random();
	
	void sort(int[] a) {
		for (int i = 0; i < a.length; i++) {
			int j = rng.nextInt(i + 1);
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
		Arrays.sort(a);
	}

	void solve() throws IOException {
		int n = nextInt();
		int q = nextInt();
		
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = nextInt();
		
		int[] d = new int[n];
		for (int i = 0; i < q; i++) {
			int l = nextInt() - 1;
			int r = nextInt() - 1;
			d[l]++;
			if (r != n - 1)
				d[r + 1]--;
		}
		
		for (int i = 1; i < n; i++)
			d[i] += d[i - 1];
		
		sort(d);
		sort(a);
		
		long ans = 0;
		for (int i = 0; i < n; i++)
			ans += (long)a[i] * d[i];
		
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