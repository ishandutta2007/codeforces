import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = sc.nextInt();
		int m = sc.nextInt();
		long ans = 0;
		long tot = n / m;
		int mod = n % m;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				if ((i * i + j * j) % m == 0) ans += tot * tot;
			}
		}
		for (int i = 1; i <= mod ; i++) {
			for (int j = 1; j <= mod; j++) {
				if ((i * i + j * j) % m == 0) ans++;
			}
		}
		for (int i = 1; i <= mod ; i++) {
			for (int j = 0; j < m; j++) {
				if ((i * i + j * j) % m == 0) ans += 2*tot;
			}
		}
		out.println(ans);
		
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