import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	char[] cur;

	ArrayList<String> ans = new ArrayList<>();
	
	boolean ok(String s) {
		if (s.charAt(0) == '0') {
			return s.length() == 1;
		}
		int x = Integer.parseInt(s);
		return x >= 1 && x < 256;
	}

	void checkAndAdd(String s) {
		for (int dot1 = 1; dot1 <= 3 && dot1 < s.length(); dot1++) {
			String s1 = s.substring(0, dot1);
			if (!ok(s1))
				continue;
			for (int dot2 = dot1 + 1; dot2 <= dot1 + 3 && dot2 < s.length(); dot2++) {
				String s2 = s.substring(dot1, dot2);
				if (!ok(s2))
					continue;
				for (int dot3 = dot2 + 1; dot3 <= dot2 + 3 && dot3 < s.length(); dot3++) {
					String s3 = s.substring(dot2, dot3);
					String s4 = s.substring(dot3);
					if (!ok(s3) || !ok(s4))
						continue;
					ans.add(s1 + "." + s2 + "." + s3 + "." + s4);
				}
			}
		}
	}
	
	boolean[] has = new boolean[10];

	void gen(int pos, int len) {
		int r = len - 1 - pos;
		if (pos > r) {
			
			Arrays.fill(has, false);
			for (int i = 0; i < len; i++) {
				has[cur[i] - '0'] = true;
			}
			
			for (int i = 0; i < 10; i++)
				if (!has[i] && ok[i]) {
					
					return;
				}
			
			checkAndAdd(new String(cur));
			return;
		}
		for (int i = 0; i < 10; i++) {
			if (ok[i]) {
				cur[pos] = cur[r] = (char) ('0' + i);
				gen(pos + 1, len);
			}
		}
	}

	boolean[] ok;

	void solve() throws IOException {
		int k = nextInt();
		ok = new boolean[10];
		for (int i = 0; i < k; i++) {
			int val = nextInt();
			ok[val] = true;
		}

		for (int len = 4; len <= 12; len++) {
			cur = new char[len];
			gen(0, len);
		}
		
		out.println(ans.size());
		for (int i = 0; i < ans.size(); i++) {
			out.println(ans.get(i));
		}
	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C();
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