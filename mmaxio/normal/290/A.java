import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	ArrayList<String> ans = new ArrayList<>();

	void solve() throws IOException {
		String[] ans = { "Washington", "Adams", "Jefferson", "Madison",
				"Monroe", "Adams", "Jackson", "Van Buren", "Harrison", "Tyler",
				"Polk", "Taylor", "Fillmore", "Pierce", "Buchanan", "Lincoln",
				"Johnson", "Grant", "Hayes", "Garfield", "Arthur", "Cleveland",
				"Harrison", "Cleveland", "McKinley", "Roosevelt", "Taft",
				"Wilson", "Harding", "Coolidge", "Hoover", "Roosevelt",
				"Truman", "Eisenhower", "Kennedy", "Johnson", "Nixon", "Ford",
				"Carter", "Reagan" };
		int n = nextInt();
		out.println(ans[n - 1]);
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