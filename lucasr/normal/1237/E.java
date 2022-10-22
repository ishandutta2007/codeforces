import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class E {
	
	static int[] tree;
	
	static void fill(int idx) {
		if (idx >= tree.length) return;
		fill(2 * idx);
		fill(2 * idx + 1);
		tree[idx] = 1;
		if (2 * idx < tree.length) tree[idx] += tree[2 * idx];
		if (2 * idx + 1 < tree.length) tree[idx] += tree[2 * idx + 1];
	}
	
	static boolean shouldAdd(int idx) {
		if (idx % 2 == 1) return true;
		while (idx % 2 == 0) {
			idx /= 2;
		}
		return tree[2 * idx] % 2 == 0;
	}
	
	static void add(int idx) {
		while (idx >= 1) {
			tree[idx]++;
			idx /= 2;
		}
	}
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int N = sc.nextInt();
		int level = 0, got = 1;
		while (N >= got) {
			N -= got;
			level++;
			got *= 2;
		}
		tree = new int[1 << level];
		fill(1);
		for (int i = tree.length - 1; i > 1 << (level-1); i--) {
			if (shouldAdd(i)) {
				add(i);
				N--;
			}
		}
		
		out.println(N == 0 || N == 1 ? 1 : 0);
		
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