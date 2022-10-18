import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int p = nextInt();

		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}

		int gcd = p - 1;
		for (int i = 0; i < m; i++) {
			int x = nextInt();
			gcd = gcd(gcd, x);
		}

		for (int i = 0; i < n; i++) {
			a[i] = pow(a[i], gcd, p);
		}
		
		int[] div = getDivs(p - 1);
		
		boolean[] good = new boolean[div.length];
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < div.length; j++) {
				if (pow(a[i], div[j], p) == 1) {
					good[div.length - 1 - j] = true;
					break;
				}
			}
		}
		
		outer: for (int i = 0; i < div.length; i++) {
			if (good[i]) {
				continue;
			}
			for (int j = 0; j < i; j++) {
				if (div[i] % div[j] == 0 && good[j]) {
					good[i] = true;
					continue outer;
				}
			}
		}
		
		int ans = 0;
		int[] cnt = new int[div.length];
		for (int i = div.length - 1; i >= 0; i--) {
			cnt[i] = (p - 1) / div[i];
			for (int j = i + 1; j < div.length; j++) {
				if (div[j] % div[i] == 0) {
					cnt[i] -= cnt[j];
				}
			}
			if (good[i]) {
				ans += cnt[i];
			}
		}
		
		out.println(ans);
	}

	static int[] getDivs(int x) {
		List<Integer> ret = new ArrayList<>();
		for (int i = 1; i * i <= x; i++) {
			if (x % i == 0) {
				ret.add(i);
				if (i * i != x) {
					ret.add(x / i);
				}
			}
		}
		Collections.sort(ret);
		int[] arr = new int[ret.size()];
		for (int i = 0; i < ret.size(); i++) {
			arr[i] = ret.get(i);
		}
		return arr;
	}

	int pow(int a, int b, int p) {
		int ret = 1;
		while (b != 0) {
			if ((b & 1) == 1) {
				ret = (int) ((long) ret * a % p);
			}
			a = (int) ((long) a * a % p);
			b >>= 1;
		}
		return ret;
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