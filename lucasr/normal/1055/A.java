import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = sc.nextInt();
		int s = sc.nextInt() - 1;
		int[][] vals = new int[n][2];
		for (int i = 0; i < vals.length; i++) {
			vals[i][0] = sc.nextInt();
		}
		for (int i = 0; i < vals.length; i++) {
			vals[i][1] = sc.nextInt();
		}
		boolean can = true;
		if (vals[0][0] != 1) can = false;
		else if (vals[s][0] != 1) {
			can = false;
			if (vals[s][1] == 1) {
				for (int i = s + 1; i < n; i++) {
					if (vals[i][0] == vals[i][1] && vals[i][1] == 1) can = true;
				}
			}
		}
		out.println(can ? "YES" :"NO");
		
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