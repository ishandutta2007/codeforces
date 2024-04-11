import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class F {
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int N = sc.nextInt();
		int max = 0, bestM = 2;
		for (int m = 2; m < N ; m++) {
			int tot = N - ((N + m - 1) / m) - m + 1;
			if (tot > max) {
				max = tot;
				bestM = m;
			}
		}
		boolean[] vals = new boolean[N];
		boolean[] need = new boolean[N];
		for (int i = 0; i < N; i++) {
			need[i] = (i % bestM) != 0;
		}
		while(true) {
			List<Integer> cc = new ArrayList<>();
			for (int i = 0; i < N; i++) if (need[i] && !vals[i]) {
				cc.add(i);
			}
			if (cc.size() >= bestM) {
				for (int i = 0; i < bestM; i++) {
					vals[cc.get(i)] = true;
				}
				out.print(bestM);
				for (int i = 0; i < bestM; i++) {
					out.print(" " + (cc.get(i) + 1));
				}
				out.println();
				out.flush();
				
				int x = sc.nextInt() - 1;
				for (int i = 0; i < bestM; i++) {
					vals[(x + i) % N] = false;
				}
			} else {
				out.println(0);
				out.flush();
				break;
			}
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