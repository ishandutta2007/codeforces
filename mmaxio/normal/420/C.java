import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int p = nextInt();
		int[] v1 = new int[n];
		int[] v2 = new int[n];
		int[] deg = new int[n];
		for (int i = 0; i < n; i++) {
			v1[i] = nextInt() - 1;
			v2[i] = nextInt() - 1;
			if (v1[i] > v2[i]) {
				int tmp = v1[i];
				v1[i] = v2[i];
				v2[i] = tmp;
			}
			deg[v1[i]]++;
			deg[v2[i]]++;
		}

		Random rng = new Random();
		int[] tmpDeg = new int[n];
		for (int i = 0; i < n; i++) {
			int j = rng.nextInt(i + 1);
			tmpDeg[i] = tmpDeg[j];
			tmpDeg[j] = deg[i];
		}

		Arrays.sort(tmpDeg);
		long ans = 0;
		for (int i = 0, j = n; i < n; i++) {
			while (j > 0 && tmpDeg[i] + tmpDeg[j - 1] >= p) {
				j--;
			}
			ans += n - j;
			if (i > j) {
				ans--;
			}
		}

		ans /= 2;
		Map<Long, Integer> map = new HashMap<>();
		for (int i = 0; i < n; i++) {
			Long key = (long) n * v1[i] + v2[i];
			Integer prev = map.get(key);
			if (prev == null) {
				prev = 0;
			}
			map.put(key, prev + 1);
		}
		
		for (int i = 0; i < n; i++) {
			Long key = (long) n * v1[i] + v2[i];
			if (map.containsKey(key)) {
				if (deg[v1[i]] + deg[v2[i]] >= p && deg[v1[i]] + deg[v2[i]] - map.get(key) < p) {
					ans--;
				}
				map.remove(key);
			}
		}
		
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