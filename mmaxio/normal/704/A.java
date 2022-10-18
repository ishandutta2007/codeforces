import java.io.*;
import java.util.*;

public class A_new {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int q = nextInt();
		
		List<Integer> cur = new ArrayList<Integer>();
		int ptr = 0;
		
		int outp = 0;
		
		int[] last = new int[n];
		int[] prev = new int[q];
		boolean[] read = new boolean[q];
		Arrays.fill(last, -1);
		
		for (int i = 0; i < q; i++) {
			int type = nextInt();
			if (type == 1) {
				int app = nextInt() - 1;
				
				prev[cur.size()] = last[app];
				last[app] = cur.size();
				
				cur.add(app);
				outp++;
			}
			if (type == 2) {
				int app = nextInt() - 1;
				
				for (int j = last[app]; j >= 0 && !read[j]; j = prev[j]) {
					read[j] = true;
					outp--;
				}
			}
			if (type == 3) {
				int cnt = nextInt();
				while (ptr < cnt) {
					if (!read[ptr]) {
						read[ptr] = true;
						outp--;
					}
					ptr++;
				}
			}
			
			out.println(outp);
		}
	}

	A_new() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new A_new();
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