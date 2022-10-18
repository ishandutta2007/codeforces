import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void add(TreeMap<Integer, TreeSet<Integer>> map, int v1, int v2) {
		TreeSet<Integer> lst = map.get(v1);
		if (lst == null) {
			lst = new TreeSet<Integer>();
			map.put(v1, lst);
		}
		lst.add(v2);
	}

	void solve() throws IOException {
		int m = nextInt();
		int k = nextInt();
		TreeMap<Integer, TreeSet<Integer>> map = new TreeMap<>();
		for (int i = 0; i < m; i++) {
			int v1 = nextInt();
			int v2 = nextInt();
			add(map, v1, v2);
			add(map, v2, v1);
		}
		for (int v : map.keySet()) {
			TreeSet<Integer> adjV = map.get(v);
			List<Integer> outp = new ArrayList<>();
			for (int u : map.keySet()) {
				if (u != v && !adjV.contains(u)) {
					TreeSet<Integer> adjU = map.get(u);
					int cnt = 0;
					int total = 0;
					for (int vv : adjV) {
						total++;
						if (adjU.contains(vv)) {
							cnt++;
						}
					}
					if (cnt * 100 >= total * k) {
						outp.add(u);
					}
				}
			}
			out.print(v + ": " + outp.size() + " ");
			for (int x : outp) {
				out.print(x + " ");
			}
			out.println();
		}
	}

	A() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new A();
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