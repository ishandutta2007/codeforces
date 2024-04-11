import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int[] p = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = nextInt() - 1;
		}
		
		List<List<Integer>> cycles = new ArrayList<>();
		boolean[] used = new boolean[n];
		for (int i = 0; i < n; i++) {
			if (!used[i]) {
				List<Integer> cur = new ArrayList<>();
				cur.add(i);
				used[i] = true;
				for (int j = p[i]; j != i; j = p[j]) {
					cur.add(j);
					used[j] = true;
				}
				cycles.add(cur);
			}
		}
		
		Collections.sort(cycles, new Comparator<List<Integer>>() {

			@Override
			public int compare(List<Integer> o1, List<Integer> o2) {
				return Integer.compare(o1.size(), o2.size());
			}
			
		});
		
		if (cycles.get(0).size() == 1) {
			out.println("YES");
			int root = cycles.get(0).get(0);
			for (int i = 0; i < n; i++) {
				if (i != root) {
					out.println((root + 1) + " " + (i + 1));
				}
			}
			return;
		}
		if (cycles.get(0).size() == 2) {
			
			for (List<Integer> lst : cycles) {
				if (lst.size() % 2 != 0) {
					out.println("NO");
					return;
				}
			}
			
			out.println("YES");
			int v1 = cycles.get(0).get(0);
			int v2 = cycles.get(0).get(1);
			for (int i = 1; i < cycles.size(); i++) {
				List<Integer> c = cycles.get(i);
				for (int j = 0; j < c.size(); j++) {
					out.println((j % 2 == 0 ? v1 : v2) + 1 + " " + (c.get(j) + 1));
				}
			}
			out.println((v1 + 1) + " " + (v2 + 1));
			return;
		}
		
		out.println("NO");
		
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