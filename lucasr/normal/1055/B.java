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
		int l = sc.nextInt();
		long[] values = new long[n];
		for (int i = 0; i < values.length; i++) {
			values[i] = sc.nextInt();
		}
		int ans = values[0] > l ? 1 : 0;
		for (int i = 1; i < n; i++) {
			if (values[i] > l && values[i-1] <= l) ans++;
		}
		for (int i = 0; i < m; i++) {
			int t = sc.nextInt();
			if (t == 0) {
				out.println(ans);
			} else {
				int p = sc.nextInt() - 1;
				int d = sc.nextInt();
				if (values[p] <= l && values[p] + d > l) {
					int cc = 0, ll = 0;
					if (p > 0) {
						if (values[p-1] > l) ll++;
						else cc++;
					}
					if (p + 1 < n) {
						if (values[p+1] > l) ll++;
						else cc++;
					}
					if (ll == 0) ans++;
					else if (ll == 2) ans--;
				}
				values[p] += d;
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