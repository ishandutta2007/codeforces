import java.io.*;
import java.util.*;

public class F {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	static final int[] DAYS = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	int decodeTime(String p) {
		int month = Integer.parseInt(p.substring(5, 7)) - 1;
		int day = Integer.parseInt(p.substring(8, 10)) - 1;
		int h = Integer.parseInt(p.substring(11, 13));
		int m = Integer.parseInt(p.substring(14, 16));
		int s = Integer.parseInt(p.substring(17, 19));
		
		//System.err.println(month + " " + day + " " + h + " " + m + " " + s);
		
		for (int i = 0; i < month; i++)
			day += DAYS[i];
		return day * 24 * 60 * 60 + h * 60 * 60 + m * 60 + s;
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		ArrayDeque<Integer> q = new ArrayDeque<>();
		while (true) {
			String s = br.readLine();
			if (s == null)
				break;
			int time = decodeTime(s);
			System.err.println(time);
			while (!q.isEmpty() && q.peek() <= time - n)
				q.poll();
			q.add(time);
			if (q.size() >= m) {
				out.println(s.substring(0, 19));
				return;
			}
		}
		out.println(-1);
	}

	F() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new F();
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