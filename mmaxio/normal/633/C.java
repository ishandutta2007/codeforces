import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int N = 1_000_001;

	int[][] to = new int[N][26];
	int size = 1;
	int[] word = new int[N];
	{
		for (int i = 0; i < N; i++) {
			Arrays.fill(to[i], -1);
		}
		Arrays.fill(word, -1);
	}

	void solve() throws IOException {
		int n = nextInt();
		String s = nextToken();
		int m = nextInt();

		String[] dict = new String[m];

		for (int i = 0; i < m; i++) {
			dict[i] = nextToken();
			String t = dict[i].toLowerCase();
			int v = 0;
			for (int j = 0; j < t.length(); j++) {
				int jj = t.charAt(j) - 'a';
				if (to[v][jj] == -1) {
					to[v][jj] = size++;
				}
				v = to[v][jj];
			}
			word[v] = i;
		}

		int[] last = new int[n + 1];
		last[0] = 0;
		for (int i = 0; i < n; i++) {
			last[i + 1] = -1;
			int v = 0;
			for (int j = i; j >= 0; j--) {
				v = to[v][s.charAt(j) - 'a'];
				if (v == -1) {
					break;
				}
				if (word[v] != -1 && last[j] != -1) {
					last[i + 1] = word[v];
					break;
				}
			}
		}
		
		List<String> outp = new ArrayList<>();
		
		for (int i = n; i > 0; i -= dict[last[i]].length()) {
			outp.add(dict[last[i]]);
		}
		Collections.reverse(outp);
		for (String x : outp) {
			out.print(x + " ");
		}
		out.println();
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