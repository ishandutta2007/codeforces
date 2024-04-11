import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = nextInt();
		int m = nextInt();
		int[] b = new int[m];
		for (int i = 0; i < m; i++)
			b[i] = nextInt();

		ArrayList<Integer> res0 = new ArrayList<>();
		ArrayList<Integer> runs0 = new ArrayList<>();

		int last = -1;

		for (int i = 0, j = 0, c = 0; i < n || j < m; c ^= 1) {
			int run = 0;
			while (i < n && a[i] == c) {
				res0.add(++i);
				run++;
			}
			while (j < m && b[j] == c) {
				res0.add(n + ++j);
				run++;
			}
			if (run != 0)
				runs0.add(run);
			last = c;
		}
		
		if (last == 0)
			runs0.remove(runs0.size() - 1);
		
		ArrayList<Integer> res1 = new ArrayList<>();
		ArrayList<Integer> runs1 = new ArrayList<>();

		last = -1;

		for (int i = 0, j = 0, c = 1; i < n || j < m; c ^= 1) {
			int run = 0;
			while (i < n && a[i] == c) {
				res1.add(++i);
				run++;
			}
			while (j < m && b[j] == c) {
				res1.add(n + ++j);
				run++;
			}
			if (run != 0)
				runs1.add(run);
			last = c;
		}
		
		if (last == 0)
			runs1.remove(runs1.size() - 1);
		
		ArrayList<Integer> res, runs;
		
		if (runs0.size() <= runs1.size()) {
			res = res0;
			runs = runs0;
		} else {
			res = res1;
			runs = runs1;
		}
		

		for (int i = 0; i < res.size(); i++)
			out.print(res.get(i) + " ");
		out.println();
		out.println(runs.size());
		for (int i = 0, outp = 0; i < runs.size(); i++) {
			outp += runs.get(i);
			out.print(outp + " ");
		}
		out.println();
	}

	D() throws IOException {
		br = new BufferedReader(new FileReader("input.txt"));
		out = new PrintWriter("output.txt");
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