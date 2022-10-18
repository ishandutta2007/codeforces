import java.io.*;
import java.util.*;

public class C_new {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	long solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		int[] cnt = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt() - 1;
			cnt[a[i]]++;
		}

		int oddVal = -1;
		for (int i = 0; i < n; i++) {
			if (cnt[i] % 2 == 1) {
				if (oddVal == -1) {
					oddVal = i;
				} else {
					return 0;
				}
			}
		}

		int same = 0;
		while (same < n / 2 && a[same] == a[n - 1 - same]) {
			same++;
		}

		if (same == n / 2) {
			return pairs(n);
		}

		long ret = (long) (same + 1) * (same + 1);
		int[] tmp = Arrays.copyOfRange(a, same, n - same);
		ret += (long) (same + 1) * go(tmp, n, oddVal);
		for (int i = 0, j = tmp.length - 1; i < j; i++, j--) {
			int z = tmp[i];
			tmp[i] = tmp[j];
			tmp[j] = z;
		}
		ret += (long) (same + 1) * go(tmp, n, oddVal);
		return ret;
	}

	static long go(int[] a, int alph, int oddVal) {
		int[] right = new int[alph];
		for (int x : a) {
			right[x]++;
		}
		if (oddVal != -1) {
			right[oddVal]--;
		}
		int[] left = new int[alph];
		int ret = 0;
		for (int i = 0; i < a.length / 2; i++) {
			int x = a[i];
			left[x]++;
			right[x]--;
			if (left[x] > right[x]) {
				return ret;
			}
			ret++;
		}
		if (a.length % 2 == 1) {
			if (a[a.length / 2] != oddVal) {
				return ret;
			}
			ret++;
		}

		for (int i = (a.length + 1) / 2; i < a.length - 1; i++) {
			if (a[i] != a[a.length - 1 - i]) {
				return ret;
			}
			ret++;
		}
		throw new AssertionError();
	}

	static long pairs(int n) {
		return (long) n * (n + 1) / 2;
	}

	C_new() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		out.println(solve());
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C_new();
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