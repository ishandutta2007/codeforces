import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int N = sc.nextInt();
		int[] vals = new int[N];
		int[] ret = new int[N];
		int sum = 0;
		for (int i = 0; i < N; i++) {
			vals[i] = sc.nextInt();
			if (vals[i] % 2 != 0) {
				ret[i] = (vals[i] - 1) / 2;
			} else {
				ret[i] = vals[i] / 2;
			}
			sum += ret[i];
		}
		
		for (int i = 0; i < N && sum < 0; i++) {
			if (2 * ret[i] != vals[i]) {
				ret[i]++;
				sum++;
			}
		}
		
		for (int i = 0; i < N; i++) {
			out.println(ret[i]);
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