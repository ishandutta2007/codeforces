import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int T = sc.nextInt();
		for (int caze = 0; caze < T; caze++) {
			int n = sc.nextInt();
			int m = sc.nextInt();
			boolean can = true;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					int tmp = sc.nextInt();
					if (tmp > max(i, j, n, m)) can = false;
				}
			}
			out.println(can ? "YES" : "NO");
			if (can) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						out.print(max(i, j, n, m) + " ");
					}
					out.println();
				}
			}
			
		}
		
		out.flush();
	}
	
	static int max(int i, int j, int n, int m){
		int ret = 0;
		if (i > 0) ret++;
		if (i + 1 < n) ret++;
		if (j > 0) ret++;
		if (j + 1 < m) ret++;
		return ret;
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