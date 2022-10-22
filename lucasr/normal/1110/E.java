import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class E {
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = sc.nextInt();
		int[] c = new int[n], t = new int[n];
		for (int i = 0; i < n; i++) {
			c[i] = sc.nextInt();
		}
		for (int i = 0; i < n; i++) {
			t[i] = sc.nextInt();
		}
		boolean can = true;
		if (c[0] != t[0] || c[n-1] != t[n-1]) can = false;
		if (can) {
			Map<Integer, Integer> counter = new HashMap<>();
			for (int i = 0; i + 1 < n; i++) {
				int val = c[i+1] - c[i];
				counter.put(val, counter.getOrDefault(val, 0) + 1);
			}
			
			Map<Integer, Integer> counter2 = new HashMap<>();
			for (int i = 0; i + 1 < n; i++) {
				int val = t[i+1] - t[i];
				counter2.put(val, counter2.getOrDefault(val, 0) + 1);
			}
			
			for (Map.Entry<Integer, Integer> entry : counter.entrySet()) {
				int c2 = counter2.getOrDefault(entry.getKey(), 0);
				if (c2 != entry.getValue()) {
					can = false;
					break;
				}
			}
		}
		out.println(can ? "Yes" : "No");
		
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