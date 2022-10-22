import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class C {
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[] values = new int[2*n + 1];
		boolean[] chosen = new boolean[2*n + 1];
		int[] match = new int[2*n + 1];
		Arrays.fill(match, -1);
		for (int i = 1; i <= 2 * n; i++) {
			values[i] = sc.nextInt();
		}
		for (int i = 0; i < m; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			match[a] = b;
			match[b] = a;
		}
		int turn = sc.nextInt();
		int total = 0;
		int forced = -1;
		while (total < 2 * n) {
			total++;
			if (turn % 2 == total % 2) {
				if (forced != -1) {
					out.println(forced);
					chosen[forced] = true;
//					System.err.println("Elijo forzado: " + forced + " => " + values[forced]);
				} else {
					int best = -1;
					for (int i = 1; i <= 2*n; i++) if (!chosen[i]) {
						if (match[i] != -1) {
							best = values[i] >= values[match[i]] ? i : match[i];
							break;
						} else {
							if (best == -1 || values[best] < values[i]) {
								best = i;
							}
						}
					}
//					System.err.println("Elijo: " + best + " => " + values[best]);
					out.println(best);
					chosen[best] = true;
				}
				out.flush();
			} else {
				int pos = sc.nextInt();
				if (pos == -1) return;
				chosen[pos] = true;
//				System.err.println("Elijio " + pos  + " => " + values[pos]);
				if (match[pos] != -1 && !chosen[match[pos]]) {
					forced = match[pos];
				} else forced = -1;
			}
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