import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class C {
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int N = sc.nextInt();
		int[] degree = new int[N];
		int a, b;
		for (int i = 0; i < N-1; i++) {
			a = sc.nextInt() - 1;
			b = sc.nextInt() - 1;
			degree[a]++;
			degree[b]++;
		}
		boolean can = true;
		int moreIdx = -1;
		List<Integer> one = new ArrayList<>();
		for (int i = 0; i < N; i++) {
			if (degree[i] > 2) {
				if (moreIdx != -1) can = false;
				moreIdx = i+1;
			}
			if (degree[i] == 1) one.add(i+1);
		}
		if (can) {
			out.println("Yes");
			if (moreIdx == -1) {
				out.println(1);
				out.println(one.get(0) + " " + one.get(1));
			} else {
				out.println(one.size());
				for (int val : one) {
					out.println(moreIdx + " " + val);
				}
			}
		} else {
			out.println("No");
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