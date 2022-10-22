import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Map;
import java.util.StringTokenizer;

public class D {
	
	static int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}
	
	static int N;
	static int[] elems;
	static boolean[][] mat;
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		N = sc.nextInt();
		elems = new int[N];
		for (int i = 0; i < N; i++) {
			elems[i] = sc.nextInt();
		}
		mat = new boolean[N][N];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) if (i != j) {
				mat[i][j] = gcd(elems[i], elems[j]) > 1;
			}
		}
		
		boolean[][] left = new boolean[N][N];
		boolean[][] right = new boolean[N][N];
		for (int i = 0; i < N; i++) {
			left[i][i] = right[i][i] = true;
		}
		for (int len = 2; len <= N; len++) {
			for (int from = 0; from + len - 1 < N; from++) {
				int to = from + len - 1;
				for (int i = from + 1; i <= to; i++) if (mat[from][i]) {
					if (right[from+1][i] && left[i][to]) {
						left[from][to] = true;
						break;
					}
				}
				for (int i = from; i < to; i++) if (mat[i][to]) {
					if (right[from][i] && left[i][to-1]) {
						right[from][to] = true;
						break;
					}
				}
			}
		}
		boolean ans = false;
		for (int i = 0; i < N; i++) {
			if (right[0][i] && left[i][N-1]) ans = true;
		}
		out.println(ans ? "Yes" : "No");
		
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