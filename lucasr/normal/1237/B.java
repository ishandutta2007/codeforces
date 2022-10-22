import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int N = sc.nextInt();
		int[] a = new int[N], b = new int[N], id = new int[N];
		for (int i = 0; i < N; i++) {
			a[i] = sc.nextInt() - 1;
		}
		for (int i = 0; i < N; i++) {
			b[i] = sc.nextInt() - 1;
		}
		for (int i = 0; i < N; i++) {
			id[a[i]] = N - i - 1;
		}
		int ans = 0, max = -1;
		for (int i = N - 1; i >= 0; i--) {
			if (id[b[i]] > max) ans++;
			max = Math.max(max, id[b[i]]);
		}
		out.println(N - ans);
		
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