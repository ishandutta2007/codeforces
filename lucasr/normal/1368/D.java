import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class D {
	static final int MAX = 20;
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int[] got = new int[MAX];
		int N = sc.nextInt();
		for (int i = 0; i < N; i++) {
			int tmp = sc.nextInt();
			for (int j = 0; j < MAX; j++) {
				if (contains(tmp, j)) got[j]++;
			}
		}
		long ans = 0;
		for (int mask = (1 << MAX) - 1; mask > 0; mask--) {
			int tot = Integer.MAX_VALUE;
			for (int i = 0; i < MAX; i++) if (contains(mask, i)) {
				tot = Math.min(tot, got[i]);
			}
			if (tot > 0) {
				long sum = mask;
				sum *= mask;
				sum *= tot;
				ans += sum;
				for (int i = 0; i < MAX; i++) if (contains(mask, i)) {
					got[i] -= tot;
				}
			}
		}
		out.println(ans);
		
		out.flush();
	}
	
	static boolean contains(int mask, int i) {
		return (mask & (1 << i)) != 0;
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