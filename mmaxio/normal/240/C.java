import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
	
	void solve(int l, int r, int level) {
		if (l == r - 1)
			return;
		int mid = (l + r) >> 1;
		if (ans.size() <= level)
			ans.add(new ArrayList<Integer>());
		for (int i = l; i < mid; i++)
			ans.get(level).add(i);
		solve(l, mid, level + 1);
		solve(mid, r, level + 1);
	}

	void solve() throws IOException {
		int n = nextInt();
		solve(1, n + 1, 0);
		out.println(ans.size());
		for (int i = 0; i < ans.size(); i++) {
			ArrayList<Integer> p = ans.get(i);
			out.print(p.size() + " ");
			for (int j = 0; j < p.size(); j++)
				out.print(p.get(j) + " ");
			out.println();
		}
	}

	C() throws IOException {
		br = new BufferedReader(new FileReader("input.txt"));
		out = new PrintWriter("output.txt");
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