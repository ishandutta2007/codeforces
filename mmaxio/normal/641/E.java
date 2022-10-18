import java.io.*;
import java.util.*;

public class E {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	static class Query implements Comparable<Query>{
		int number, type, time, id;

		@Override
		public int compareTo(Query o) {
			if (number != o.number) {
				return number < o.number ? -1 : 1;
			}
			return Integer.compare(id, o.id);
		}

		public Query(int number, int type, int time, int id) {
			this.number = number;
			this.type = type;
			this.time = time;
			this.id = id;
		}
	}
	
	void add(int[] f, int pos, int delta) {
		for (int i = pos; i < f.length; i |= i + 1) {
			f[i] += delta;
		}
	}
	
	int get(int[] f, int pos) {
		int ret = 0;
		for (int i = pos; i >= 0; i = (i & (i + 1)) - 1) {
			ret += f[i];
		}
		return ret;
	}

	void solve() throws IOException {
		int n = nextInt();
		Query[] a = new Query[n];
		for (int i = 0; i < n; i++) {
			int type = nextInt();
			int time = nextInt();
			int number = nextInt();
			a[i] = new Query(number, type, time, i);
		}
		
		int[] ans = new int[n];
		Arrays.fill(ans, -1);
		
		Arrays.sort(a);
		for (int i = 0; i < n;) {
			int j = i;
			while (j < n && a[i].number == a[j].number) {
				j++;
			}
			
			int len = j - i;
			int[] times = new int[len];
			for (int k = i; k < j; k++) {
				times[k - i] = a[k].time;
			}
			
			Arrays.sort(times);
			
			int[] fen = new int[len];
			for (int k = i; k < j; k++) {
				int compPos = Arrays.binarySearch(times, a[k].time); 
				if (a[k].type == 1) {
					add(fen, compPos, 1);
				} else if (a[k].type == 2) {
					add(fen, compPos, -1);
				} else {
					ans[a[k].id] = get(fen, compPos);
				}
			}
				
			i = j;
		}
		
		for (int i = 0; i < n; i++) {
			if (ans[i] != -1) {
				out.println(ans[i]);
			}
		}
	}

	E() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new E();
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