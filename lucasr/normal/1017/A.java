import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class A {
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int N = sc.nextInt();
		List<Pair> elems = new ArrayList<>(N);
		int a, b,c,d;
		for (int i = 0; i < N; i++) {
			a = sc.nextInt();
			b = sc.nextInt();
			c = sc.nextInt();
			d = sc.nextInt();
			elems.add(new Pair(a+b+c+d, i));
		}
		int ans = 0;
		Collections.sort(elems);
		for (int i = 0; i < N; i++) {
			if (elems.get(i).id == 0) {
				ans = i + 1;
				break;
			}
		}
		out.println(ans);
		
		out.flush();
	}
	
	static class Pair implements Comparable<Pair> {
		int sum, id;
		
		public Pair(int sum, int id) {
			this.sum = sum;
			this.id = id;
		}
		
		@Override
		public int compareTo(Pair o) {
			int cmp = Integer.compare(o.sum, sum);
			if (cmp != 0) return cmp;
			return Integer.compare(id, o.id);
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