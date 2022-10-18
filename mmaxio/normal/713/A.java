import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int q = nextInt();
		
		HashMap<String, Integer> map = new HashMap<>();
		
		while (q-- > 0) {
			char type = nextToken().charAt(0);
			if (type == '+' || type == '-' ) {
				int delta = type == '+' ? 1 : -1;
				String s = String.valueOf(nextLong());
				char[] t = new char[s.length()];
				for (int i = 0; i < s.length(); i++) {
					t[i] = (s.charAt(i)- '0') % 2 == 0 ? '0' : '1';
				}
				String tt = new String(t);
				String tt2 = tt;
				while (tt.length() < 20) {
					
					Integer prev = map.get(tt);
					if (prev == null) {
						prev = 0;
					}
					map.put(tt, prev + delta);
					
					tt = "0" + tt;
				}
				while (tt2.length() > 1 && tt2.charAt(0) == '0') {
					tt2 = tt2.substring(1);
					Integer prev = map.get(tt2);
					if (prev == null) {
						prev = 0;
					}
					map.put(tt2, prev + delta);
				}
			} else {
				String qq = nextToken();
				out.println(map.getOrDefault(qq, 0));
			}
		}
		
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