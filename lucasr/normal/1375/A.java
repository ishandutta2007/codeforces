import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int T = sc.nextInt();
		for (int i = 0; i < T; i++) {
			int N = sc.nextInt();
			long[] vals = new long[N];
			for (int j = 0; j < N; j++) {
				vals[j] = sc.nextInt();
			}
			out.print(vals[0]);
			for (int j = 1; j + 1 < N; j+=2) {
				boolean got = false;
				for (int k = -1; k <= 1 && !got; k+=2) {
					for (int l = -1; l <= 1 && !got; l+=2) {
						if ((vals[j]*k - vals[j-1]) * (vals[j+1]*l - vals[j]*k) <= 0) {
							got = true;
							vals[j] *= k;
							vals[j+1] *= l;
							out.print(" " + vals[j]);
							out.print(" " + vals[j + 1]);
						}
					}
				}
			}
			out.println();
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