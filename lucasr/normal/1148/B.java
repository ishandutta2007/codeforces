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
		int ta = sc.nextInt();
		int tb = sc.nextInt();
		int k = sc.nextInt();
		int[] first = new int[n];
		for (int i = 0; i < n; i++) {
			first[i] = sc.nextInt() + ta;
		}
		int[] second = new int[m];
		for (int i = 0; i < m; i++) {
			second[i] = sc.nextInt();
		}
		
		int ans = 0;
		int idx = 0;
		if (k >= n) {
			ans = Integer.MAX_VALUE;
		}
		for (int i = 0; i <= k && i < n; i++) {
			while (idx < m && second[idx] < first[i]) idx++;
			if (idx + k - i < m) ans = Math.max(ans, second[idx + k - i] + tb);
			else ans = Integer.MAX_VALUE;
		}
		
		out.println(ans == Integer.MAX_VALUE ? -1 : ans);
		
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