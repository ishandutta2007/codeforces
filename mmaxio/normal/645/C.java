import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();

		String s = nextToken();

		List<Integer> f = new ArrayList<>();

		for (int i = 0; i < n; i++) {
			if (s.charAt(i) == '0') {
				f.add(i);
			}
		}

		int ans = Integer.MAX_VALUE;

		for (int i = 0; i + k + 1 <= f.size(); i++) {
			int fst = f.get(i);
			int lst = f.get(i + k);
			int mid = (fst + lst) >> 1;
			int posMid = Collections.binarySearch(f, mid);
			if (posMid < 0) {
				posMid = -posMid - 2;
			}

			if (posMid >= 0 && posMid < f.size()) {
				int where = f.get(posMid);
				if (fst <= where && where <= lst) {
					ans = Math.min(ans, Math.max(where - fst, lst - where));
				}
			}

			if (posMid + 1 >= 0 && posMid + 1 < f.size()) {
				int where = f.get(posMid + 1);
				if (fst <= where && where <= lst) {
					ans = Math.min(ans, Math.max(where - fst, lst - where));
				}
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