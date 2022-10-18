import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		List<Integer> pos = new ArrayList<>();
		List<Integer> zero = new ArrayList<>();
		List<Integer> neg = new ArrayList<>();
		int n = nextInt();
		for (int i = 0; i < n; i++) {
			int x = nextInt();
			if (x > 0)
				pos.add(x);
			if (x == 0)
				zero.add(x);
			if (x < 0)
				neg.add(x);
		}
		
		if (neg.size() % 2 == 0) {
			zero.add(neg.remove(neg.size() - 1));
		}
		
		out.println("1 " + neg.remove(neg.size() - 1));
		out.print(neg.size() + pos.size() + " ");
		for (int x : neg)
			out.print(x + " ");
		for (int x : pos)
			out.print(x + " ");
		out.println();
		out.print(zero.size() + " ");
		for (int x : zero)
			out.print(x + " ");
		out.println();
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