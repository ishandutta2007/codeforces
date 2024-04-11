import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class D {
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[] count = new int[m];
		for (int i = 0; i < n; i++) {
			count[sc.nextInt() - 1]++;
		}
		int[][][] table = new int[m][5][3];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 3; k++) {
					table[i][j][k] = -n;
				}
			}
		}
		int max;
		for (int i = m - 1; i >= 0 ; i--) {
			for (int j = 0; j < 5; j++) if (j <= count[i]) {
				for (int k = 0; k < 3; k++) if (i + 1 < m && k <= count[i+1] || k == 0) {
					table[i][j][k] = 0;
					int rem = count[i] - j;
					max = Math.min(rem, (i + 1 < m ? count[i+1] : 0) - k);
					max = Math.min(max, 2);
					for (int l = 0; l <= max; l++) {
						table[i][j][k] = Math.max(table[i][j][k], (i+1 < m ? table[i+1][k+l][l] : 0) + l + (rem-l)/3);
					}
				}
			}
		}
		out.println(table[0][0][0]);
		
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