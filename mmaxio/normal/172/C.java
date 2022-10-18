import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	class Man implements Comparable<Man>{
		int time;
		int x;
		int id;
		public Man(int time, int x, int id) {
			this.time = time;
			this.x = x;
			this.id = id;
		}
		
		@Override
		public int compareTo(Man o) {
			return Integer.compare(x, o.x);
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		
		Man[] a = new Man[n];
		for (int i = 0; i < n; i++)
			a[i] = new Man(nextInt(), nextInt(), i);
		
		long time = 0;
		
		long[] ans = new long[n];
		
		for (int st = 0; st < n; st += m) {
			int en = Math.min(st + m, n);
			time = Math.max(time, a[en - 1].time);
			
			Arrays.sort(a, st, en);
			
			for (int i = st; i < en;) {
				time += a[i].x;
				if (i != st)
					time -= a[i - 1].x;
				int j = i;
				while (j < en && a[j].x == a[i].x)
					ans[a[j++].id] = time;
				time += 1 + (j - i) / 2;
				i = j;
			}
			
			time += a[en - 1].x;
		}
		
		for (long x : ans)
			out.print(x + " ");
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C().inp();
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