import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class D {
	
	static int N, K;
	static long[] values;
	static long target;
	static int[][] posible;
	
	
	static boolean can(long t) {
		target = t;
		for (int i = 0; i < posible.length; i++) {
			Arrays.fill(posible[i], -1);
		}
		return calc(0,K) > 0;
	}
	
	static int calc(int pos, int rem) {
		int ret = posible[pos][rem];
		if (ret != -1) return ret;
		if (pos == N) return posible[pos][rem] = rem == 0 ? 1 : 0;
		if (rem == 0) return posible[pos][rem] = 0;
		ret = 0;
		long sum = 0;
		for (int i = pos; i < N && ret == 0; i++) {
			sum += values[i];
			if ((sum & target) == target && calc(i + 1, rem - 1) > 0) ret = 1;
		}
		return posible[pos][rem] = ret;
	}
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		N = sc.nextInt();
		K = sc.nextInt();
		values = new long[N];
		for (int i = 0; i < values.length; i++) {
			values[i] = sc.nextLong();
		}
		posible = new int[N + 1][K+1];
		long ans = 0;
		long curbit = 1L << 60;
		while (curbit > 0) {
			long newAns = ans | curbit;
			if (can(newAns)) {
				ans = newAns;
			}
			curbit /= 2;
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