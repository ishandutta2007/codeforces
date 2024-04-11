import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final String[] SYMBS = { "8<", "[]", "()" };
	static {
		Arrays.sort(SYMBS);
	}

	void solve() throws IOException {
		String s1 = nextToken();
		String s2 = nextToken();

		int sc1 = 0, sc2 = 0;

		for (int i = 0; i < s1.length(); i += 2) {
			String v1 = s1.substring(i, i + 2);
			String v2 = s2.substring(i, i + 2);
			int p1 = Arrays.binarySearch(SYMBS, v1);
			int p2 = Arrays.binarySearch(SYMBS, v2);
			if ((p1 - p2 + 3) % 3 == 2) {
				sc1++;
			} else if ((p1 - p2 + 3) % 3 == 1) {
				sc2++;
			}
		}

		if (sc1 > sc2) {
			out.println("TEAM 1 WINS");
		} else if (sc1 < sc2) {
			out.println("TEAM 2 WINS");
		} else {
			out.println("TIE");
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