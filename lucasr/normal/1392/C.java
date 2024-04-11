import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {
	static final PrintWriter out = new PrintWriter(System.out);
	static final MyScanner sc = new MyScanner();

	public static void main(String[] args) {
		int numberOfCases = sc.nextInt();
		for (int caze = 1; caze <= numberOfCases; caze++) {
			int n = sc.nextInt();
			long[] vals = new long[n];
			for (int i = 0; i < n; i++) {
				vals[i] = sc.nextLong();
			}
			long ans = 0, last = vals[0], nextSmall = -1;
			for (int i = 1; i < n; i++) {
				if (nextSmall == -1) {
					if (vals[i] < last) {
						nextSmall = vals[i];
					} else {
						last = vals[i];
					}
				} else {
					if (vals[i] <= nextSmall) nextSmall = vals[i];
					else if (vals[i] < last) {
						ans += vals[i] - nextSmall;
						nextSmall = vals[i];
					} else {
						ans += last - nextSmall;
						nextSmall = -1;
						last = vals[i];
					}
				}
			}
			if (nextSmall != -1) {
				ans += last - nextSmall;
			}
			out.println(ans);
			
			out.flush();
		}
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