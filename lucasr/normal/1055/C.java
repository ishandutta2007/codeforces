import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {
	
	
	static int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a%b);
	}
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int la = sc.nextInt();
		int ra = sc.nextInt();
		int ta = sc.nextInt();
		int lb = sc.nextInt();
		int rb = sc.nextInt();
		int tb = sc.nextInt();
		int g = gcd(ta, tb);
		if (la < lb) {
			int tmp = la;
			la = lb;
			lb = tmp;
			tmp = ra;
			ra = rb;
			rb = tmp;
		}
		int k = (la - lb) / g;
		int ans = inter(la, ra, lb + k * g, rb + k * g);
		k++;
		ans = Math.max(ans, inter(la, ra, lb + k * g, rb + k * g));
		out.println(ans);
		
		out.flush();
	}
	
	static int inter(int la, int ra, int lb, int rb) {
		return Math.max(0, Math.min(ra, rb) - Math.max(la, lb) + 1);
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