import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	int[] go(int[] a, int high) {
		HashSet<Integer> set = new HashSet<>();
		int[] b = new int[a.length];
		for (int i = a.length - 1; i >= 0; i--) {
			int x = a[i];
			while (x >= 1 && (x > high || set.contains(x))) {
				x >>= 1;
			}
			if (x == 0) {
				return null;
			}
			b[i] = x;
			set.add(x);
		}
		return b;
	}

	void solve() throws IOException {
		int n = nextInt();
		Random rng = new Random();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			int j = rng.nextInt(i + 1);
			a[i] = a[j];
			a[j] = nextInt();
		}
		Arrays.sort(a);
		int low = n - 1; // can't
		int high = a[n - 1]; // can
		
		while (high - low > 1) {
			int mid = (low + high) >> 1;
			int[] tmp = go(a, mid);
			if (tmp == null) {
				low = mid;
			} else {
				high = mid;
			}
		}
		
		int[] ans = go(a, high);
		for (int x : ans) {
			out.print(x + " ");
		}
		out.println();
	}

	D() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D();
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