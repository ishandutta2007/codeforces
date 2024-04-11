import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	static class Edge implements Comparable<Edge>{
		int id, len, inMST; // 1 - in MST, 0 - out of MST

		@Override
		public int compareTo(Edge o) {
			if (len != o.len) {
				return len < o.len ? -1 : 1;
			}
			return -Integer.compare(inMST, o.inMST);
		}

		public Edge(int id, int len, int inMST) {
			this.id = id;
			this.len = len;
			this.inMST = inMST;
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		Edge[] es = new Edge[m];
		for (int i = 0; i < m; i++) {
			int len = nextInt();
			int inMST = nextInt();
			es[i] = new Edge(i, len, inMST);
		}
		
		
		int[] v1 = new int[m];
		int[] v2 = new int[m];
		int[] freeStack = new int[2 * m];
		int ptr = 0;
		Arrays.sort(es);
		
		int last = 0;
		
		for (Edge e : es) {
			if (e.inMST == 1) {
				if (last == n - 1) {
					out.println(-1);
					return;
				}
				v1[e.id] = last;
				v2[e.id] = last + 1;
				last++;
				for (int j = last - 2; j >= 0 && ptr < 2 * m; j--) {
					freeStack[ptr++] = j;
					freeStack[ptr++] = last;
				}
			} else {
				if (ptr == 0) {
					out.println(-1);
					return;
				}
				v1[e.id] = freeStack[ptr - 2];
				v2[e.id] = freeStack[ptr - 1];
				ptr -= 2;
			}
		}
		
		if (last != n - 1) {
			out.println(-1);
			return;
		}
		
		for (int i = 0; i < m; i++) {
			out.println((v1[i] + 1) + " " + (v2[i] + 1));
		}
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