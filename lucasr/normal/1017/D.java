import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class D {
	
	final static int MAX = 101;
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int q = sc.nextInt();
		int tot = 1 <<n;
		int[] cant = new int[tot];
		int[] values = new int[n];
		for (int i = 0; i < n; i++) {
			values[i] = sc.nextInt();
		}
		char[] tmp;
		for (int i = 0; i < m; i++) {
			tmp = sc.next().toCharArray();
			int val = 0;
			for (int j = 0; j < n; j++) {
				if (tmp[j] == '1') val |= 1 << j;
			}
			cant[val]++;
		}
		int[] sum = new int[tot];
		for (int mask = 0; mask < tot; mask++) {
			sum[mask] = 0;
			for (int i = 0; i < n; i++) {
				if ((mask & (1<<i)) == 0) {
					sum[mask] += values[i];
				}
			}
		}
		int[][] ans = new int[tot][MAX];
		for (int i = 0; i < tot; i++) {
			for (int j = 0; j < tot; j++) {
				int sumVal = sum[i ^ j];
				if (sumVal < MAX) {
					ans[i][sumVal] += cant[j];
				}
			}
		}
		
		for (int i = 0; i < tot; i++) {
			for (int j = 1; j < MAX; j++) {
				ans[i][j] += ans[i][j-1];
			}
		}
		
		int k;
		for (int i = 0; i < q; i++) {
			tmp = sc.next().toCharArray();
			k = sc.nextInt();
			int val = 0;
			for (int j = 0; j < n; j++) {
				if (tmp[j] == '1') val |= 1 << j;
			}
			
			out.println(ans[val][k]);
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