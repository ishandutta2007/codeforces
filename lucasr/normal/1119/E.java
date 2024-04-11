import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class E {
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = sc.nextInt();
		long[] cant = new long[n];
		long total = 0;
		for (int i = 0; i < cant.length; i++) {
			cant[i] = sc.nextLong();
			total += cant[i];
		}
		long needed = 0;
		long ans = 0;
		for (int i = n - 1; i >= 0; i--) if (cant[i] > 0) {
			total -= cant[i];
			if (cant[i] % 2 == 1 && needed > 0) {
				needed--;
				cant[i]--;
			}
			long max = cant[i] / 2;
			max = Math.min(max, (cant[i] + total - needed) / 3);
			ans += max;
			cant[i] -= 2 * max;
			needed += max;
			needed -= Math.min(cant[i], needed);
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