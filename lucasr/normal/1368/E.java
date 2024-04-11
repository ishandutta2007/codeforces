import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class E {
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int T = sc.nextInt();
		for (int caze = 0; caze < T; caze++) {
			int N = sc.nextInt();
			int M = sc.nextInt();
			List<Integer>[] next = new List[N];
			for (int i = 0; i < N; i++) {
				next[i] = new ArrayList<>();
			}
			for (int i = 0; i < M; i++) {
				int x = sc.nextInt() - 1;
				int y = sc.nextInt() - 1;
				next[x].add(y);
			}
			List<Integer> ans = new ArrayList<>();
			int[] val = new int[N];
			for (int i = 0; i < N; i++) {
				if (val[i] == 2) {
					ans.add(i);
				} else {
					for (int j = 0; j < next[i].size(); j++) {
						int nn = next[i].get(j);
						val[nn] = Math.max(val[nn], val[i]+1);
					}
				}
			}
			out.println(ans.size());
			for (Integer integer : ans) {
				out.print((integer + 1) + " ");
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