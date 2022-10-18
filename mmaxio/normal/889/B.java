import java.io.*;
import java.util.*;

public class B {

	void submit() {
		int n = nextInt();
		char[] next = new char[256];
		char[] prev = new char[256];
		Arrays.fill(next, '?');
		Arrays.fill(prev, '?');
		
		boolean[] need = new boolean[256];
		
		for (int i = 0; i < n; i++) {
			String s = nextToken();
			if (s.length() > 26) {
				out.println("NO");
				return;
			}
			if (s.length() == 1) {
				need[s.charAt(0)] = true;
				continue;
			}
			for (int j = 0; j < s.length(); j++) {
				for (int k = j + 1; k < s.length(); k++) {
					if (s.charAt(j) == s.charAt(k)) {
						out.println("NO");
						return;
					}
				}
			}
			for (int j = 0; j < s.length() - 1; j++) {
				char from = s.charAt(j);
				char to = s.charAt(j + 1);
				if (next[from] != '?' && next[from] != to) {
					out.println("NO");
					return;
				}
				if (prev[to] != '?' && prev[to] != from) {
					out.println("NO");
					return;
				}
				
				for (char c = to; c != '?'; c = next[c]) {
					if (c == from) {
						out.println("NO");
						return;
					}
				}
				
				for (char c = from; c != '?'; c = prev[c]) {
					if (c == to) {
						out.println("NO");
						return;
					}
				}
				
				next[from] = to;
				prev[to] = from;
			}
		}
		
		for (char c = 'a'; c <= 'z'; c++) {
			if ((next[c] != '?' && prev[c] == '?') || (prev[c] == '?' && next[c] == '?' && need[c])) {
				for (char x = c; x != '?'; x = next[x]) {
					out.print(x);
				}
			}
		}
		out.println();
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	B() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
		// stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new B();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}