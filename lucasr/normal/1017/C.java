import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int N = sc.nextInt();
		int a = -1, b = -1, best = N + 5;
		for (int i = 1; i <= N; i++) {
			int cur = i + ((N + i - 1) / i);
			if (cur < best) {
				a = i;
				b = (N + i - 1) / i;
				best = cur;
			}
		}
		boolean first = true;
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				int val = b * (a - 1 - i) + j + 1;
				if (val <= N) {
					if (first) first = false;
					else out.print(" ");
					out.print(val);
				}
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