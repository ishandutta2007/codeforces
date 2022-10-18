import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int N = 500_000;
		int[] sign = new int[N + 1];
		Arrays.fill(sign, 1);
		for (int i = 2; i * i <= N; i++) {
			int i2 = i * i;
			for (int j = i2; j <= N; j += i2) {
				sign[j] = 0;
			}
		}

		boolean[] isPrime = new boolean[N + 1];
		Arrays.fill(isPrime, true);
		for (int i = 2; i * i <= N; i++) {
			if (isPrime[i]) {
				for (int j = i * i; j <= N; j += i) {
					isPrime[j] = false;
				}
			}
		}
		
		for (int i = 2; i <= N; i++) {
			if (isPrime[i]) {
				for (int j = i; j <= N; j += i) {
					sign[j] = -sign[j];
				}
			}
		}

		int[] cnt = new int[N + 1];
		List<Integer>[] divs = new List[N + 1];
		for (int i = 1; i <= N; i++) {
			divs[i] = new ArrayList<>();
		}
		for (int i = 1; i <= N; i++) {
			if (sign[i] != 0) {
				for (int j = i; j <= N; j += i) {
					divs[j].add(i);
				}
			}
		}

		int n = nextInt();
		int q = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		boolean[] here = new boolean[n];
		long ans = 0;
		while (q-- > 0) {
			int idx = nextInt() - 1;
			boolean flag = here[idx];
			here[idx] = !flag;
			List<Integer> lst = divs[a[idx]];
			for (int i = 0; i < lst.size(); i++) {
				int x = lst.get(i);
				if (!flag) {
					ans += sign[x] * cnt[x];
					cnt[x]++;
				} else {
					cnt[x]--;
					ans -= sign[x] * cnt[x];
				}
			}
			out.println(ans);
		}
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C().inp();
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