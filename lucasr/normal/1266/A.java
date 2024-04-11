import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int N = sc.nextInt();
		for (int i = 0; i < N; i++) {
			char[] digs = sc.next().toCharArray();
			
			boolean zero = false;
			boolean par = false;
			int sum = 0;
			for (int j = 0; j < digs.length; j++) {
				int digit = digs[j] - '0';
				if (digit == 0 && !zero) {
					zero = true;
				} else if (digit % 2 == 0 && !par) {
					par = true;
				}
				sum += digit;
			}
			out.println(zero && par && sum % 3 == 0 ? "red" : "cyan");
		}
		
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