import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {
	
	static class Parallel {
		int minx, maxx, miny, maxy;
		
		public Parallel(MyScanner sc) {
			minx = Integer.MAX_VALUE;
			miny = Integer.MAX_VALUE;
			maxx = Integer.MIN_VALUE;
			maxy = Integer.MIN_VALUE;
			for (int i = 0; i < 4; i++) {
				int x = sc.nextInt();
				minx = Math.min(minx, x);
				maxx = Math.max(maxx, x);
				int y = sc.nextInt();
				miny = Math.min(miny, y);
				maxy = Math.max(maxy, y);
			}
		}
		
		boolean contains(int x, int y) {
			return minx <= x && x <= maxx && miny <= y && y <= maxy;
		}
	}
	
	static class Rombo {
		int cx, cy, dist;
		
		public Rombo(MyScanner sc) {
			int x = -1, y = -1, sx = 0, sy = 0;
			for (int i = 0; i < 4; i++) {
				x = sc.nextInt();
				y = sc.nextInt();
				sx += x;
				sy += y;
			}
			cx = sx / 4;
			cy = sy / 4;
			dist = Math.abs(x - cx) + Math.abs(y - cy);
		}
		
		boolean contains(int x, int y) {
			return Math.abs(x - cx) + Math.abs(y - cy) <= dist;
		}
	}
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		Parallel parallel = new Parallel(sc);
		Rombo rombo = new Rombo(sc);
		boolean inter = false;
		for (int i = -100; i <= 100 && !inter; i++) {
			for (int j = -100; j <= 100 && !inter; j++) {
				if (parallel.contains(i,j) && rombo.contains(i,j)) inter = true;
			}
		}
		out.println(inter ? "Yes" : "No");
		
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