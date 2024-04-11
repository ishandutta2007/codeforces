import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class B {
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		Map<Integer, Integer> map = new HashMap<>();
		int N = sc.nextInt(), key, value;
		long ans = 0;
		for (int i = 0; i < N; i++) {
			key = sc.nextInt();
			value = sc.nextInt();
			ans += value;
			map.put(key, value);
		}
		N = sc.nextInt();
		for (int i = 0; i < N; i++) {
			key = sc.nextInt();
			value = sc.nextInt();
			Integer oldVal = map.get(key);
			if (oldVal == null) oldVal = 0;
			if (value > oldVal) ans += value - oldVal;
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