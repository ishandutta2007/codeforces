import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	int diff(String a, String b) {
		int ret = 0;
		for (int i = 0; i < a.length(); i++) {
			if (a.charAt(i) != b.charAt(i)) {
				ret++;
			}
		}
		return ret;
	}
	
	String toStr(int x, int len) {
		String ret = "" + x;
		while (ret.length() < len) {
			ret = "0" + ret;
		}
		return ret;
	}

	void solve() throws IOException {
		int n = nextInt();
		String s = nextToken();
		String h = s.substring(0, 2);
		String m = s.substring(3, 5);
		
		int ansH = -1, ansM = -1, ans = 100;
		
		for (int i = (n == 12 ? 1 : 0); i <= (n == 12 ? 12 : 23); i++)
			for (int j = 0; j < 60; j++) {
				int tmp = diff(h, toStr(i, 2)) + diff(m, toStr(j, 2));
				if (tmp < ans) {
					ans = tmp;
					ansH = i;
					ansM = j;
				}
			}
		
		out.println(toStr(ansH, 2) + ":" + toStr(ansM, 2));
	}

	A() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new A();
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