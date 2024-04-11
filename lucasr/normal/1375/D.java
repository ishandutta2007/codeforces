import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class D {
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int T = sc.nextInt();
		for (int caze = 0; caze < T; caze++) {
			int n = sc.nextInt();
			int[] cant = new int[n + 1];
			int[] vals = new int[n];
			for (int i = 0; i < n; i++) {
				vals[i] = sc.nextInt();
				cant[vals[i]]++;
			}
			List<Integer> ans = new ArrayList<>();
			while (true) {
				for (int i = 0; i <= n; i++) {
					if (cant[i] == 0) {
						if (i < n) {
							ans.add(i);
							cant[vals[i]]--;
							cant[i]++;
							vals[i] = i;
						} else {
							for (int j = 0; j < n; j++) {
								if (vals[j] != j) {
									ans.add(j);
									cant[vals[j]]--;
									cant[n]++;
									vals[j] = n;
									break;
								}
							}
						}
						break;
					}
				}
				boolean end = true;
				for (int i = 0; i + 1 < n; i++) {
					if (vals[i] > vals[i+1]) {
						end = false;
						break;
					}
				}
				if (end) break;
			}
			
			out.println(ans.size());
			for (Integer an : ans) {
				out.print((an + 1) + " ");
			}
			out.println();
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