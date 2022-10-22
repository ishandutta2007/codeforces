import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {
	
	static char[][] parse(MyScanner sc) {
		char[][] ret = new char[2][];
		for (int i = 0; i < 2; i++) {
			ret[i] = sc.next().toCharArray();
		}
		return ret;
	}
	
	static int[] x = {0, 0, 1, 1};
	static int[] y = {0, 1, 1, 0};
	static String getValue(char[][] a) {
		String ret = "";
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 4; j++) {
				if (a[x[j]][y[j]] == 'A' || !ret.isEmpty()) {
					ret += a[x[j]][y[j]];
				}
			}
		}
		return ret.substring(0, 4).replace("X", "");
	}
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		String first = getValue(parse(sc));
		String second = getValue(parse(sc));
		out.println(first.equals(second) ? "YES" : "NO");
		
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