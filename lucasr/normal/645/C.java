import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {
	
	static int[] pos;
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = sc.nextInt();
		int k = sc.nextInt();
		char[] elems = sc.next().toCharArray();
		int total = 0;
		for (int i = 0; i < n; i++) {
			if (elems[i] == '0') total++;
		}
		pos = new int[total];
		int idx = 0;
		for (int i = 0; i < n; i++) {
			if (elems[i] == '0'){
				pos[idx] = i;
				idx++;
			}
		}
		int ans = n + 1, med = 0;
		for (int left = 0; left + k < pos.length; left++) {
			while (med < left) med++;
			int right = left + k;
			while (med < right && calc(left, med, right) > calc(left, med + 1, right)) med++;
			ans = Math.min(ans, calc(left, med, right));
		}
		out.println(ans);
		
		out.flush();
	}
	
	static int calc(int left, int med, int right) {
		return Math.max(pos[right] - pos[med], pos[med] - pos[left]);
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