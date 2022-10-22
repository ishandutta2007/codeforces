import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class G {
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int s = sc.nextInt() - 1;
		long t = sc.nextLong();
		int[] next = new int[n];
		Arrays.fill(next, -1);
		while (t % n != 0) {
			if (s < m) s += t % n;
			else s += n - t % n;
			s %= n;
			t--;
		}
		long cant = t / n;
		int prevs = s;
		while (cant > 0 && next[s] == -1) {
			for (int i = n - 1; i > 0; i--) {
				if (s < m) s += i;
				else s += n - i;
				if (s >= n) s -= n;
			}
			next[prevs] = s;
			prevs = s;
			cant--;
		}
		if (cant > 0) {
			long cicle = 1;
			prevs = s;
			while (next[prevs] != s) {
				cicle++;
				prevs = next[prevs];
			}
			long total = cant % cicle;
			for (int i = 0; i < total; i++) {
				s = next[s];
			}
		}
		out.println(s+1);
		
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