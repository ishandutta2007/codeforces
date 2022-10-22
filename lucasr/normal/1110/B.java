import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class B {
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int k = sc.nextInt();
		int[] broken = new int[n];
		for (int i = 0; i < broken.length; i++) {
			broken[i] = sc.nextInt();
		}
		List<Integer> tops = new ArrayList<>();
		for (int i = 0; i + 1 < broken.length; i++) {
			tops.add(broken[i + 1] - broken[i] - 1);
		}
		Collections.sort(tops);
		Collections.reverse(tops);
		int ans = broken[n-1] - broken[0] + 1;
		for (int i = 0; i < Math.min(tops.size(), k - 1); i++) {
			ans -= tops.get(i);
		}
		out.println(ans);
		
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