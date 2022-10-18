import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static void canonize(int[] a) {
		int n = a.length;
		for (int size = 2; size <= n; size *= 2) {
			for (int i = 0; i < n / size; i++) {
				
				int p = i * size;
				int q = i * size + size / 2;
				int r = (i + 1) * size;
				
				boolean less = true;
				for (int i1 = p, i2 = q; i1 < q; i1++, i2++) {
					if (a[i1] < a[i2]) {
						less = true;
						break;
					} else if (a[i1] > a[i2]) {
						less = false;
						break;
					}
				}
				if (!less) {
					for (int i1 = p, i2 = q; i1 < q; i1++, i2++) {
						int tmp = a[i1];
						a[i1] = a[i2];
						a[i2] = tmp;
					}
				}
			}
		}
	}

	static boolean eq(int[] a, int[] b) {
		canonize(a);
		canonize(b);
		return Arrays.equals(a, b);
	}

	void solve() throws IOException {
		String a = nextToken();
		String b = nextToken();
		int n = a.length();
		int block = n;
		int m = 1;
		while (block % 2 == 0) {
			m *= 2;
			block /= 2;
		}
		int[] c = new int[m];
		int[] d = new int[m];
		HashMap<String, Integer> set = new HashMap<>();
		for (int i = 0; i < m; i++) {
			Integer prev = set.get(a.substring(i * block, (i + 1) * block));
			String tmp = a.substring(i * block, (i + 1) * block);
			if (prev == null) {
				prev = set.size();
				set.put(tmp, prev);
			}
			c[i] = prev;
		}

		for (int i = 0; i < m; i++) {
			Integer prev = set.get(b.substring(i * block, (i + 1) * block));
			String tmp = a.substring(i * block, (i + 1) * block);
			if (prev == null) {
				prev = set.size();
				set.put(tmp, prev);
			}
			d[i] = prev;
		}

//		System.err.println(Arrays.toString(c));
//		System.err.println(Arrays.toString(d));

		out.println(eq(c, d) ? "YES" : "NO");
	}

	B() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B();
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