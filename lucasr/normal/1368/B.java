import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		char[] CF = "codeforces".toCharArray();
		long k = sc.nextLong();
		long a;
		for (a = 1; true; a++) {
			long tmp = a;
			boolean can = false;
			for (int i = 1; i < CF.length; i++) {
				tmp *= a + 1;
				if (tmp >= k) {
					can = true;
					break;
				}
			}
			if (can) break;
		}
		long val = 1;
		for (int i = 0; i < CF.length; i++) {
			val *= a + 1;
		}
		int b = 0;
		for (int i = 0; i < CF.length; i++) {
			if (val / (a + 1) * a >= k) {
				val /= a + 1;
				val *= a;
				b++;
			} else break;
		}
		for (int i = 0; i < CF.length; i++) {
			for (int j = 0; j < a; j++) {
				out.print(CF[i]);
			}
			if (i >= b) {
				out.print(CF[i]);
			}
		}
		out.println();
		
		out.flush();
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