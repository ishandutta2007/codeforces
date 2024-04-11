import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class B {
	
	static class Pair {
		int a, b;
		
		public Pair(int a, int b) {
			this.a = a;
			this.b = b;
		}
		
		int common(Pair o) {
			if (a == o.a && b != o.b) return a;
			if (a == o.b && b != o.a) return a;
			if (a != o.a && b == o.b) return b;
			if (a != o.b && b == o.a) return b;
			return -1;
		}
	}
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = sc.nextInt();
		int m = sc.nextInt();
		List<Pair> first = new ArrayList<>(), second = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			first.add(new Pair(sc.nextInt(), sc.nextInt()));
		}
		for (int i = 0; i < m; i++) {
			second.add(new Pair(sc.nextInt(), sc.nextInt()));
		}
		boolean[] can = new boolean[10];
		int total = 0;
		boolean[][] firstKnow = new boolean[n][10];
		boolean[][] secondKnow = new boolean[m][10];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int c = first.get(i).common(second.get(j));
				if (c != -1) {
					if (!can[c]) {
						can[c] = true;
						total++;
					}
					firstKnow[i][c] = true;
					secondKnow[j][c] = true;
				}
			}
		}
		if (total == 1) {
			for (int i = 0; i < 10; i++) {
				if (can[i]) {
					out.println(i);
					break;
				}
			}
		} else {
			boolean bothKnow = true;
			for (int i = 0; i < n; i++) {
				int c = 0;
				for (int j = 0; j < 10; j++) {
					if (firstKnow[i][j]) c++;
				}
				if (c > 1) bothKnow = false;
			}
			for (int i = 0; i < m; i++) {
				int c = 0;
				for (int j = 0; j < 10; j++) {
					if (secondKnow[i][j]) c++;
				}
				if (c > 1) bothKnow = false;
			}
			out.println(bothKnow ? 0 : -1);
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