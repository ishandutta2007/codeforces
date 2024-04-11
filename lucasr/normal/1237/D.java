import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class D {
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int N = sc.nextInt();
		int[] vals = new int[N];
		int max = Integer.MIN_VALUE, min = Integer.MAX_VALUE;
		for (int i = 0; i < N; i++) {
			vals[i] = sc.nextInt();
			max = Math.max(max, vals[i]);
			min = Math.min(min, vals[i]);
		}
		int[] ret = new int[N];
		Arrays.fill(ret, -1);
		if (2 * min < max) {
			TreeMap<Integer, Integer> counter = new TreeMap<>();
			int total = 0, toPos = 0;
			for (int i = 0; i < N; i++) {
				while (counter.isEmpty() || 2 * vals[toPos] >= max(counter)) {
					total++;
					inc(counter, vals[toPos]);
					toPos++;
					toPos %= N;
				}
				ret[i] = total;
				total--;
				dec(counter, vals[i]);
			}
		}
		for (int i = 0; i < N; i++) {
			out.print(ret[i] + " ");
		}
		out.println();
		
		out.flush();
	}
	
	static void inc(TreeMap<Integer, Integer> counter, int val) {
		counter.put(val, counter.getOrDefault(val, 0) + 1);
	}
	
	static void dec(TreeMap<Integer, Integer> counter, int val) {
		int c = counter.get(val);
		if (c == 1) counter.remove(val);
		else {
			counter.put(val, c - 1);
		}
	}
	
	static int max(TreeMap<Integer, Integer> counter) {
		return counter.lastKey();
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