import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		ArrayList<Integer> t1 = new ArrayList<>();
		ArrayList<Integer> t2 = new ArrayList<>();
		
		for (int i = 0; i < n; i++) {
			int t = nextInt();
			int w = nextInt();
			(t == 1 ? t1 : t2).add(w);
		}
		
		Collections.sort(t1);
		Collections.sort(t2);
		
		int ans = Integer.MAX_VALUE;
		
		for (int i = 0; i <= t1.size(); i++)
			for (int j = 0; j <= t2.size(); j++) {
				
				int val1 = 0;
				int val2 = 0;
				for (int k = 0; k < i; k++)
					val1 += t1.get(k);
				for (int k = 0; k < j; k++)
					val1 += t2.get(k);
				
				val2 = (t1.size() - i) + 2 * (t2.size() - j);
				if (val1 <= val2)
					ans = Math.min(ans, val2);
				
				
			}
		
		out.println(ans);
		
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