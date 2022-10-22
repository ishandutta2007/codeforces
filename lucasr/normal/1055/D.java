import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class D {
	
	public static class KMP {
		private final int R;       // the radix
		private int[][] dfa;       // the KMP automoton
		
		private char[] pattern;    // either the character array for the pattern
		
		public KMP(char[] pattern, int R) {
			this.R = R;
			this.pattern = new char[pattern.length];
			for (int j = 0; j < pattern.length; j++)
				this.pattern[j] = pattern[j];
			
			// build DFA from pattern
			int m = pattern.length;
			dfa = new int[R][m];
			dfa[pattern[0]][0] = 1;
			for (int x = 0, j = 1; j < m; j++) {
				for (int c = 0; c < R; c++)
					dfa[c][j] = dfa[c][x];     // Copy mismatch cases.
				dfa[pattern[j]][j] = j + 1;      // Set match case.
				x = dfa[pattern[j]][x];        // Update restart state.
			}
		}
		
		public int search(char[] text) {
			
			// simulate operation of DFA on text
			int m = pattern.length;
			int n = text.length;
			int i, j;
			for (i = 0, j = 0; i < n && j < m; i++) {
				j = dfa[text[i]][j];
			}
			if (j == m) return i - m;    // found
			return -1;                    // not found
		}
	}
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = sc.nextInt();
		char[][] from = new char[n][], to = new char[n][];
		for (int i = 0; i < from.length; i++) {
			from[i] = sc.next().toCharArray();
		}
		for (int i = 0; i < from.length; i++) {
			to[i] = sc.next().toCharArray();
		}
		boolean can = true;
		int ldiff = -1, first = -1;
		int[] different = new int[n];
		int sizeDif = 0;
		int[] ff = new int[n];
		for (int i = 0; i < n && can; i++) {
			ff[i] = ff(from[i], to[i]);
			if (ff[i] != -1) {
				int ll = ll(from[i], to[i]);
				if (ldiff == -1) ldiff = ll - ff[i];
				if (ldiff != ll - ff[i]) can = false;
				if (first == -1) first = i;
				different[sizeDif++] = i;
				int base = different[0];
				for (int j = 0; j <= ldiff; j++) {
					if (from[base][ff[base] + j] != from[i][ff[i] + j] ||
							to[base][ff[base] + j] != to[i][ff[i] + j]) can = false;
				}
			}
		}
		if (can) {
			boolean oneLess = true;
			while (oneLess) {
				char val = 'A';
				for (int i = 0; i < sizeDif; i++) {
					int cur = different[i];
					if (ff[cur] > 0) {
						if (val == 'A') val = from[cur][ff[cur] - 1];
						if (from[cur][ff[cur] - 1] != val) {
							oneLess = false;
						}
					} else oneLess = false;
				}
				if (oneLess) {
					ldiff++;
					for (int i = 0; i < sizeDif; i++) {
						int cur = different[i];
						ff[cur]--;
					}
				}
			}
			boolean oneMore = true;
			while (oneMore) {
				char val = 'A';
				for (int i = 0; i < sizeDif; i++) {
					int cur = different[i];
					if (ff[cur] + ldiff + 1 < from[cur].length) {
						if (val == 'A') val = from[cur][ff[cur] + ldiff + 1];
						if (from[cur][ff[cur] + ldiff + 1] != val) {
							oneMore = false;
						}
					} else oneMore = false;
				}
				if (oneMore) {
					ldiff++;
				}
			}
		}
		char[] ansFrom = new char[ldiff + 1];
		char[] ansTo = new char[ldiff + 1];
		if (can) {
			int tmp = different[0];
			for (int i = 0; i <= ldiff; i++) {
				ansFrom[i] = from[tmp][ff[tmp] + i];
				ansTo[i] = to[tmp][ff[tmp] + i];
			}
			KMP kmp = new KMP(ansFrom, 'z' + 1);
			for (int i = 0; i < n; i++) {
				int ans = kmp.search(from[i]);
				if (ans != ff[i]) can = false;
			}
		}
		out.println(can ? "YES" : "NO");
		if (can) {
			out.println(new String(ansFrom));
			out.println(new String(ansTo));
		}
		
		out.flush();
	}
	
	static int ff(char[] a, char[] b) {
		for (int i = 0; i < a.length; i++) {
			if (a[i] != b[i]) return i;
		}
		return -1;
	}
	
	static int ll(char[] a, char[] b) {
		for (int i = a.length - 1; i >= 0; i--) {
			if (a[i] != b[i]) return i;
		}
		return -1;
	}
	
	static class MyScanner {
		private BufferedReader br;
		private StringTokenizer tokenizer;
		
		public MyScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
		
		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
	}
}