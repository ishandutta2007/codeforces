import java.io.*;
import java.util.*;

import com.sun.corba.se.spi.ior.MakeImmutable;

public class cfRockethon2015C {

	static final String CANT = "IMPOSSIBLE";
	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	List<Integer>[] g;
	List<Integer> log;

	int n;

	int go(int root, int need) {
		if (root == n) {
			return n;
		}
		int minL = n;
		int maxL = -1;
		int minR = n;
		int maxR = -1;
		for (int to : g[root]) {
			if (to >= 0) {
				minR = Math.min(minR, to);
				maxR = Math.max(maxR, to);
			} else {
				to = ~to;
				minL = Math.min(minL, to);
				maxL = Math.max(maxL, to);
			}
		}
		if (maxL == -1 && maxR == -1) {
			if (need == root) {
				log.add(root);
				return root;
			}
			log.add(root);
			int tmp = go(root + 1, need);
			if (tmp == -1) {
				return -1;
			}
			return tmp;
		}
		if (maxL == -1) {
			// all right
			log.add(root);
			int tmp = go(root + 1, Math.max(need, maxR));
			if (tmp == -1) {
				return -1;
			}
			return tmp;
		}
		if (maxR == -1) {
			// all left
			int tmp = go(root + 1, Math.max(need, maxL));
			log.add(root);
			if (tmp == -1) {
				return -1;
			}
			return tmp;
		}
		if (maxL >= minR) {
			return -1;
		}
		int tmp = go(root + 1, maxL);
		if (tmp == -1 || tmp >= minR) {
			return -1;
		}
		log.add(root);
		int tmp2 = go(tmp + 1, Math.max(need, maxR));
		return tmp2;
	}
	
	void solve() throws IOException {
		n = nextInt();
		int c = nextInt();

		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>(0);
		}

		for (int i = 0; i < c; i++) {
			int v1 = nextInt() - 1;
			int v2 = nextInt() - 1;
			String dir = nextToken();
			if (v1 >= v2) {
				out.println(CANT);
				return;
			}
			g[v1].add(dir.equals("LEFT") ? ~v2 : v2);
		}

		log = new ArrayList<>(n);
		if (go(0, n - 1) == -1) {
			out.println(CANT);
		} else {
			for (int x : log) {
				out.print((x + 1) + " ");
			}
		}
		out.println();
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new cfRockethon2015C().inp();
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