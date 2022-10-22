import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		char[] elems = sc.next().toCharArray();
		int N = elems.length;
		char[] nn = new char[2*N];
		for (int i = 0; i < N; i++) {
			nn[i] = nn[N+i] = elems[i];
		}
		int ans = 0;
		int i = 0;
		while (i < nn.length){
			int tot = 1;
			while (i + 1 < nn.length && nn[i] != nn[i+1]) {
				i++;
				tot++;
			}
			ans = Math.max(ans, tot);
			i++;
		}
		out.println(Math.min(ans, N));
		
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