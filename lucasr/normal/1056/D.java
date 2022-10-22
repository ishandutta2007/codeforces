import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class D {
	
	static int[] leaves;
	static List<Integer>[] children;
	
	static void calc(int node) {
		leaves[node] = children[node].isEmpty() ? 1 : 0;
		for (Integer child : children[node]) {
			calc(child);
			leaves[node] += leaves[child];
		}
	}
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = sc.nextInt();
		int[] parent = new int[n];
		children = new List[n];
		for (int i = 0; i < n; i++) {
			children[i] = new ArrayList<>();
		}
		parent[0] = -1;
		for (int i = 1; i < n; i++) {
			int c = sc.nextInt() - 1;
			parent[i] = c;
			children[c].add(i);
		}
		leaves = new int[n];
		calc(0);
		List<Integer> values = new ArrayList<>(leaves.length);
		for (int i = 0; i < leaves.length; i++) {
			values.add(leaves[i]);
		}
		Collections.sort(values);
		for (int i = 1; i <= n; i++) {
			if (i > 1) out.print(" ");
			out.print(values.get(i-1));
		}
		out.println();
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