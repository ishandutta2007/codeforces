import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class D {
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = sc.nextInt();
		List<Pair> up = new ArrayList<>();
		List<Pair> down = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			Pair p = new Pair(i + 1, a, b);
			if (a < b) {
				up.add(p);
			} else {
				down.add(p);
			}
		}
		if (up.size() >= down.size()) {
			Collections.sort(up, (p1, p2) -> -Integer.compare(p1.a, p2.a));
			out.println(up.size());
			for (int i = 0; i < up.size(); i++) {
				if (i > 0) {
					out.print(" ");
				}
				out.print(up.get(i).id);
			}
		} else {
			Collections.sort(down, (p1, p2) -> Integer.compare(p1.a, p2.a));
			out.println(down.size());
			for (int i = 0; i < down.size(); i++) {
				if (i > 0) {
					out.print(" ");
				}
				out.print(down.get(i).id);
			}
		}
		out.println();
		out.flush();
	}
	
	static class Pair {
		int id, a, b;
		
		public Pair(int id, int a, int b) {
			this.id = id;
			this.a = a;
			this.b = b;
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