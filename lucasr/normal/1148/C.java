import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {
	
	static int[] a, b, where, p;
	static int tot, n, uptTo;
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		n = sc.nextInt();
		uptTo = n / 2 - 1;
		p = new int[n];
		where = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = sc.nextInt() - 1;
			where[p[i]] = i;
		}
		a = new int[5 * n];
		b = new int[5 * n];
		tot = 0;
		for (int i = 0; i < n; i++) {
			if (where[i] != i) {
				change(i, where[i]);
			}
		}
		out.println(tot);
		for (int i = 0; i < tot; i++) {
			out.println((a[i] + 1) + " " + (b[i] + 1));
		}
		
		out.flush();
	}
	
	static void change(int p1, int p2) {
		if (p2 - p1 >= n / 2) {
			swap(p1, p2);
		} else if (p2 <= uptTo) {
			swap(p1, n - 1);
			swap(p2, n - 1);
			swap(p1, n - 1);
		} else if (p1 > uptTo) {
			swap(p1, 0);
			swap(p2, 0);
			swap(p1, 0);
		} else {
			swap(p1, n - 1);
			swap(p2, 0);
			swap(0, n - 1);
			swap(p1, n - 1);
			swap(p2, 0);
		}
	}
	
	static void swap(int first, int second) {
		if (first == second) return;
		if (first > second) {
			swap(second, first);
			return;
		}
		int tmp = p[first];
		p[first] = p[second];
		p[second] = tmp;
		where[p[first]] = first;
		where[p[second]] = second;
		a[tot] = first;
		b[tot] = second;
		tot++;
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