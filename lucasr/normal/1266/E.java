import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class F {
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int N = sc.nextInt();
		long[] vals = new long[N + 1];
		long[] got = new long[N + 1];
		long sum = 0;
		for (int i = 0; i < N; i++) {
			vals[i + 1] = sc.nextLong();
			sum += vals[i + 1];
		}
		Map<Integer, Integer>[] milestone = new Map[N + 1];
		long ans = sum;
		int q = sc.nextInt();
		for (int i = 0; i < q; i++) {
			int from = sc.nextInt();
			int cant = sc.nextInt();
			int to = sc.nextInt();
			if (milestone[from] == null) {
				milestone[from] = new HashMap<>();
			}
			Integer old = milestone[from].get(cant);
			if (old != null) {
				got[old]--;
				if (got[old] < vals[old]) {
					ans++;
				}
			}
			if (to == 0) {
				milestone[from].remove(cant);
			} else {
				milestone[from].put(cant, to);
				got[to]++;
				if (got[to] <= vals[to]) {
					ans--;
				}
			}
			
			out.println(ans);
		}
		
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