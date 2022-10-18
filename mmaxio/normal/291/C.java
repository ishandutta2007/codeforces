import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int decodeIP(String s) {
		int res = 0;
		while (true) {
			int id = s.indexOf('.');
			if (id == -1) {
				id = s.length();
			}
			int val = Integer.parseInt(s.substring(0, id));
			res = (res << 8) | val;
			if (id == s.length())
				break;
			s = s.substring(id + 1);
		}
		return res;
	}

	String encodeIP(int val) {
		StringBuilder sb = new StringBuilder();
		for (int i = 24; i >= 0; i -= 8) {
			int x = (val >> i) & 255;
			sb.append(x);
			if (i != 0)
				sb.append('.');
		}
		return sb.toString();
	}

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();

		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = decodeIP(nextToken());
		}

		Random rng = new Random();
		for (int i = 0; i < n; i++) {
			int j = rng.nextInt(i + 1);
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}

		Arrays.sort(a);

		for (int zeroes = 31; zeroes > 0; zeroes--) {
			int mask = ~((1 << zeroes) - 1);
//			System.err.println(encodeIP(mask));

			int cnt = 0;
			for (int i = 0; i < n; cnt++) {
				int val = a[i] & mask;

				int j = i + 1;
				while (j < n && ((a[j] & mask) == val))
					j++;

				i = j;
			}

			if (cnt == k) {
				out.println(encodeIP(mask));
				return;
			}
		}
		out.println("-1");
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