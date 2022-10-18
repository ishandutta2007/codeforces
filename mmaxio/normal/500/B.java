import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		int[] p = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = i;
		}
		for (int i = 0; i < n; i++) {
			char[] tmp = nextToken().toCharArray();
			for (int j = i + 1; j < n; j++)
				if (tmp[j] == '1') {
					int v1 = get(p, i);
					int v2 = get(p, j);
					if (v1 != v2) {
						p[v1] = v2;
					}
				}
		}
		
		int[] ans = new int[n];
		boolean[] used = new boolean[n];
		for (int i = 0; i < n; i++) {
			if (!used[i]) {
				List<Integer> pos = new ArrayList<>();
				List<Integer> nums = new ArrayList<>();
				for (int j = i; j < n; j++) {
					if (get(p, j) == get(p, i)) {
						pos.add(j);
						nums.add(a[j]);
						used[j] = true;
					}
				}
				Collections.sort(nums);
				for (int j = 0; j < pos.size(); j++) {
					ans[pos.get(j)] = nums.get(j);
				}
			}
		}
		
		for (int x : ans) {
			out.print(x + " ");
		}
		out.println();

	}

	int get(int[] p, int i) {
		return (p[i] == i) ? i : (p[i] = get(p, p[i]));
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