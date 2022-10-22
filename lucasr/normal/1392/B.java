import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {
	static final PrintWriter out = new PrintWriter(System.out);
	static final MyScanner sc = new MyScanner();

	public static void main(String[] args) {
		int numberOfCases = sc.nextInt();
		for (int caze = 1; caze <= numberOfCases; caze++) {
			int n = sc.nextInt();
			long k = sc.nextLong();
			if (k % 2 == 0) k = Math.min(k, 2);
			else k = 1;
			long[] vals = new long[n];
			for (int i = 0; i < n; i++) {
				vals[i] = sc.nextLong();
			}
			for (int i = 0; i < k; i++) {
				vals = apply(vals);
			}
			for (int i = 0; i < n; i++) {
				out.print(vals[i] + " ");
			}
			out.println();
			
			out.flush();
		}
	}

	static long[] apply(long[] vals) {
		long[] ret = new long[vals.length];
		long max = Long.MIN_VALUE;
		for (int i = 0; i < vals.length; i++) {
			max = Math.max(max, vals[i]);
		}
		for (int i = 0; i < vals.length; i++) {
			ret[i] = max - vals[i];
		}
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