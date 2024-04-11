import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class D {
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = sc.nextInt();
		int r = sc.nextInt();
		int[] elems = new int[1<<n];
		long sum = 0;
		double total = 1<<n;
		for (int i = 0; i < 1<<n; i++) {
			elems[i] = sc.nextInt();
			sum += elems[i];
		}
		out.println(sum / total);
		int pos;
		for (int i = 0; i < r; i++) {
			pos = sc.nextInt();
			sum -= elems[pos];
			sum += elems[pos] = sc.nextInt();
			out.println(sum / total);
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