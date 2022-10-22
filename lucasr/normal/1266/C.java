import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int r = sc.nextInt();
		int c = sc.nextInt();
		if (r == 1 && c == 1) {
			out.println(0);
		} else {
			int iFrom = 1, jFrom = r + 1;
			if (c == 1) {
				iFrom = c + 1;
				jFrom = 1;
			}
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					out.print((iFrom + i) * (jFrom + j) + " ");
				}
				out.println();
			}
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