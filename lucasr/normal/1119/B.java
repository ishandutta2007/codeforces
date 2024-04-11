import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class B {
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = sc.nextInt();
		long h = sc.nextInt();
		int[] vals = new int[n];
		for (int i = 0; i < vals.length; i++) {
			vals[i] = sc.nextInt();
		}
		int ans = 1;
		for (int i = 0; i < n; i++) {
			Arrays.sort(vals, 0, i + 1);
			long totH = 0;
			for (int j = i; j >= 0 ; j-= 2) {
				totH += vals[j];
			}
			if (totH > h) {
				break;
			} else {
				ans = i + 1;
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