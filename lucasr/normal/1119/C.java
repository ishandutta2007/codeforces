import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[][] mat1 = new int[n][m], mat2 = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				mat1[i][j] = sc.nextInt();
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				mat2[i][j] = sc.nextInt();
			}
		}
		boolean can = true;
		for (int i = 0; i < n; i++) {
			int a = 0, b = 0;
			for (int j = 0; j < m; j++) {
				if (mat1[i][j] == 1) a++;
				if (mat2[i][j] == 1) b++;
			}
			if (a % 2 != b % 2) can = false;
		}
		for (int j = 0; j < m; j++) {
			int a = 0, b = 0;
			for (int i = 0; i < n; i++) {
				if (mat1[i][j] == 1) a++;
				if (mat2[i][j] == 1) b++;
			}
			if (a % 2 != b % 2) can = false;
		}
		out.println(can ? "Yes" : "No");
		
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