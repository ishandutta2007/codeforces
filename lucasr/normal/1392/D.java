import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class D {
	static final PrintWriter out = new PrintWriter(System.out);
	static final MyScanner sc = new MyScanner();

	public static void main(String[] args) {
		int numberOfCases = sc.nextInt();
		for (int caze = 1; caze <= numberOfCases; caze++) {
			int N = sc.nextInt();
			char[] vals = sc.next().toCharArray();
			List<Integer> groups = new ArrayList<>();
			int cur = 1;
			for (int i = 1; i < N; i++) {
				if (vals[i] != vals[i-1]) {
					groups.add(cur);
					cur = 1;
				} else {
					cur++;
				}
			}
			groups.add(cur);
			int ans = 0;
			if (groups.size() == 1) {
				int val = groups.get(0);
				if (val >= 3) {
					ans = 1 + (val - 1) / 3;
				}
			} else {
				int size = groups.size();
				if (size % 2 == 1) {
					groups.set(0, groups.get(0) + groups.get(size - 1));
					size--;
				}
				for (int i = 0; i < size; i++) {
					ans += groups.get(i) / 3;
				}
			}
			out.println(ans);
			
			out.flush();
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