import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int[] w = new int[n];
		for (int i = 0; i < n; i++) {
			w[i] = nextInt();
		}
		
		long ret = 0;
		
		List<Integer> stack = new ArrayList<>();
		for (int j = 0; j < m; j++) {
			int id = nextInt() - 1;
			int where = stack.indexOf(id);
			if (where == -1) {
				where = stack.size();
				stack.add(id);
			}
			for (int i = 0; i < where; i++) {
				ret += w[stack.get(i)];
			}
			stack.remove(where);
			stack.add(0, id);
		}
		out.println(ret);
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