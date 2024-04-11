import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int N = sc.nextInt();
		if (N / 2 % 2 == 1) {
			output(-1, out);
		} else {
			int half = N / 2;
			int l = 1, r = half;
			int first = query(half, out, sc);
			int next = query(2 * half, out, sc);
			if (first == next) {
				output(half, out);
				return;
			}
			boolean less = first < next;
			while (l + 1 < r) {
				int med = (l + r) / 2;
				first = query(med, out, sc);
				next = query(med + half, out, sc);
				if (first == next) {
					output(med, out);
					return;
				} else if (first < next == less) {
					r = med;
				} else {
					l = med + 1;
				}
			}
			output(l, out);
		}
	}
	
	static int query(int pos, PrintWriter out, MyScanner sc) {
		out.println("? " + pos);
		out.flush();
		return sc.nextInt();
	}
	
	static void output(int pos, PrintWriter out) {
		out.println("! " + pos);
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