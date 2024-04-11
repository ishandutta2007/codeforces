import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	class Item implements Comparable<Item>{
		int ind;
		int profit;
		public Item(int ind, int profit) {
			this.ind = ind;
			this.profit = profit;
		}
		
		@Override
		public int compareTo(Item o) {
			return Integer.compare(o.profit, profit);
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int sz = nextInt();
		
		ArrayList<Item> s1 = new ArrayList<Item>();
		ArrayList<Item> s2 = new ArrayList<Item>();
		
		for (int i = 0; i < n; i++) {
			int type = nextInt();
			Item cur = new Item(i + 1, nextInt());
			(type == 1 ? s1 : s2).add(cur);
		}
		
		Collections.sort(s1);
		Collections.sort(s2);
		
		int[] prof1 = new int[s1.size() + 1];
		int[] prof2 = new int[s2.size() + 1];
		
		for (int i = 0; i < s1.size(); i++)
			prof1[i + 1] = prof1[i] + s1.get(i).profit;
		
		for (int i = 0; i < s2.size(); i++)
			prof2[i + 1] = prof2[i] + s2.get(i).profit;
		
		int ans = -1;
		int ansTake1 = -1;
		int ansTake2 = -1;
		
		for (int take2 = 0; take2 <= s2.size() && 2 * take2 <= sz; take2++) {
			int take1 = Math.min(s1.size(), sz - 2 * take2);
			if (prof1[take1] + prof2[take2] > ans) {
				ans = prof1[take1] + prof2[take2];
				ansTake1 = take1;
				ansTake2 = take2;
			}
		}
		
		out.println(ans);
		for (int i = 0; i < ansTake1; i++)
			out.print(s1.get(i).ind + " ");
		for (int i = 0; i < ansTake2; i++)
			out.print(s2.get(i).ind + " ");
		out.println();
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B().inp();
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