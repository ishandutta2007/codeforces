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
		boolean[][] grid = new boolean[10][5 * (n + 5)];
		int par = n / 2;
		int last = 10 * (par + 2);
		make(grid, 0,0, 5, last);
		for (int i = 0; i < par; i++) {
			make(grid, 2, 5 + i * 10, 5, 3);
		}
		if (n % 2 == 1) {
			make(grid, 4, last-1, 3, 3);
		}
		int tot = 0;
		for (int i = 0; i < grid.length; i++) {
			for (int j = 0; j < grid[i].length; j++) {
				if (grid[i][j]) tot++;
			}
		}
		out.println(tot);
		for (int i = 0; i < grid.length; i++) {
			for (int j = 0; j < grid[i].length; j++) {
				if (grid[i][j]){
					out.println(i + " " + j);
				}
			}
		}
		
		out.flush();
	}
	
	static void make(boolean[][] grid, int iFrom, int jFrom, int sizeI, int sizeJ) {
		for (int i = 0; i < sizeI; i++) {
			grid[iFrom + i][jFrom] = grid[iFrom + i][jFrom + sizeJ - 1] = true;
		}
		for (int j = 0; j < sizeJ; j++) {
			grid[iFrom][jFrom + j] = grid[iFrom + sizeI - 1][jFrom + j] = true;
		}
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