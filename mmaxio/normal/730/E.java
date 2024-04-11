// id, ans
//1 0
//0 2
//4 5
//3 7
//2 9
//12


import java.io.*;
import java.util.*;

public class Task_new {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	static class Team {
		int before, after, id;
		
		int cur;
		
		public Team(int before, int after, int id) {
			this.before = before;
			this.after = after;
			this.id = id;
			
			cur = before;
		}
	}
	
	Comparator<Team> byBefore = new Comparator<Task_new.Team>() {
		
		@Override
		public int compare(Team arg0, Team arg1) {
			if (arg0.before != arg1.before) {
				return arg0.before > arg1.before ? -1 : 1;
			}
			return Integer.compare(arg0.id, arg1.id);
		}
	};
	
	Comparator<Team> byAfter = new Comparator<Task_new.Team>() {
		
		@Override
		public int compare(Team arg0, Team arg1) {
			if (arg0.after != arg1.after) {
				return arg0.after > arg1.after ? -1 : 1;
			}
			return Integer.compare(arg0.id, arg1.id);
		}
	};
	
	Comparator<Team> byCur = new Comparator<Task_new.Team>() {
		
		@Override
		public int compare(Team arg0, Team arg1) {
			if (arg0.cur != arg1.cur) {
				return arg0.cur > arg1.cur ? -1 : 1;
			}
			return Integer.compare(arg0.id, arg1.id);
		}
	};
	
	
	void solve() throws IOException {
		int n = nextInt();
		Team[] a = new Team[n];
		for (int i = 0; i < n; i++) {
			int before = nextInt();
			int delta = nextInt();
			a[i] = new Team(before, before + delta, i);
		}
		
		Arrays.sort(a, byBefore);
		
		List<Team> lst = new ArrayList<>();
		
		for (int i = 0; i < n; i++) {
			if (a[i].before >= a[i].after) {
				lst.add(a[i]);
			}
		}
		
		for (int i = n - 1; i >= 0; i--) {
			if (a[i].before < a[i].after) {
				lst.add(a[i]);
			}
		}
		
//		for (Team t : a) {
//			System.err.println(t.id + " " + t.pos1 + " " + t.pos2);
//		}
		
		int ans = 0;
		for (int i = 0; i < n; i++) {
			Team t = lst.get(i);
			
//			System.err.println(t.id + " " + ans);
			
			for (int j = 0; j < n; j++) {
				if (i == j) {
					continue;
				}
				Team o = lst.get(j);
				
				int cmpNow = byCur.compare(t, o);
				
				t.cur = t.after;
				int cmpThen = byCur.compare(t, o);
				
				t.cur = t.before;
				if (cmpNow != cmpThen) {
					ans++;
				}
				
			}
			
			t.cur = t.after;
		}
		
		out.println(ans);
		
	}
	
	void run() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		
		solve();
		
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new Task_new().run();
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