import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class E {
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int N = sc.nextInt();
		int[] vals = new int[N];
		Point[] pp = new Point[N];
		
		for (int i = 0; i < N; i++) {
			vals[i] = sc.nextInt();
			pp[i] = new Point(vals[i], i + 1);
		}
		Arrays.sort(pp);
		List<int[]> ret = new ArrayList<>();
		while (true) {
			boolean change = false;
			for (int i = 0; i + 1 < N; i++) {
				if (pp[i].pos > pp[i+1].pos) {
					ret.add(new int[] {pp[i+1].pos, pp[i].pos});
					change = true;
					int tmp = pp[i].pos;
					pp[i].pos = pp[i+1].pos;
					pp[i+1].pos = tmp;
				}
			}
			if (!change) break;
		}
		
		out.println(ret.size());
		for (int[] a : ret) {
			out.println(a[0] + " " + a[1]);
		}
		
		out.flush();
	}
	
	static class Point implements Comparable<Point> {
		int val, pos, id;
		
		public Point(int val, int pos) {
			this.val = val;
			this.id = pos;
			this.pos = pos;
		}
		
		@Override
		public int compareTo(Point o) {
			int cmp = Integer.compare(val, o.val);
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