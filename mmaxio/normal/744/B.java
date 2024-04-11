import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		
		int[][][] ret = new int[10][2][n];
		
		for (int bit = 0; bit < 10; bit++) {
			for (int set = 0; set < 2; set++) {
				List<Integer> query = new ArrayList<>();
				for (int i = 0; i < n; i++) {
					if (get(i, bit) == set) {
						query.add(i);
					}
				}
				if (query.isEmpty()) {
					Arrays.fill(ret[bit][set], Integer.MAX_VALUE);
					continue;
				}
				out.println(query.size());
				for (int x : query) {
					out.print((x + 1) + " ");
				}
				out.println();
				out.flush();
				
				for (int i = 0; i < n; i++) {
					ret[bit][set][i] = nextInt();
				}
			}
		}
		
		
		out.println(-1);
		for (int row = 0; row < n; row++) {
			int outp = Integer.MAX_VALUE;
			for (int bit = 0; bit < 10; bit++) {
				int which = get(row, bit) ^ 1;
				
				outp = Math.min(outp, ret[bit][which][row]);
				
			}
			out.print(outp + " ");
		}
		
		out.println();
		out.flush();
	}
	
	int get(int mask, int pos) {
		return ((mask >> pos) & 1);
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