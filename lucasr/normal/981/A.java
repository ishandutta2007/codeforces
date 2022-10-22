import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class A {
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		String S = sc.next();
		int ans = 0;
		for (int i = 0; i < S.length(); i++) {
			for (int j = i; j <= S.length(); j++) {
				if (!pal(S.substring(i, j).toCharArray())) {
					ans = Math.max(ans, j - i);
				}
			}
		}
		out.println(ans);
		
		out.flush();
	}
	
	private static boolean pal(char[] s) {
		int i = 0, j = s.length - 1;
		while (i < j) {
			if (s[i] != s[j]) return false;
			i++;
			j--;
		}
		return true;
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