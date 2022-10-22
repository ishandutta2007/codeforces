import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class C {
	
	static int N;
	static List<Integer>[] adj;
	static int[] parent;
	static boolean[] black;
	static int[] to;
	
	static void calcCycles() {
		to = new int[N];
		Arrays.fill(to, -1);
		black = new boolean[N];
		parent = new int[N];
		Arrays.fill(parent, -2);
		for (int i = 0; i < N; i++) if (parent[i] == -2) {
			parent[i] = -1;
			visit(i);
		}
	}
	
	static void visit(int node) {
		for (int vec : adj[node]) if (vec != parent[node] && (parent[node] != -1 || parent[vec] == -2)) {
			if (parent[vec] == -2) {
				parent[vec] = node;
				visit(vec);
			} else if (!black[vec]) {
				int mini = Math.min(vec, node), maxi = Math.max(vec, node);
				int tmp = node;
				while (parent[tmp] != vec) {
					tmp = parent[tmp];
					mini = Math.min(mini, tmp);
					maxi = Math.max(maxi, tmp);
				}
				to[mini] = maxi;
			}
		}
		black[node] = true;
	}
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
//		PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		PrintWriter out = new PrintWriter(System.out);
		N = sc.nextInt();
		int M = sc.nextInt();
		adj = new List[N];
		for (int i = 0; i < adj.length; i++) {
			adj[i] = new ArrayList<>();
		}
		int a, b;
		for (int i = 0; i < M; i++) {
			a = sc.nextInt() - 1;
			b = sc.nextInt() - 1;
			adj[a].add(b);
			adj[b].add(a);
		}
		calcCycles();
		int[] right = new int[N];
		right[N-1] = 1;
		for (int i = right.length - 2; i >= 0; i--) {
			right[i] = 1 + right[i+1];
			if (to[i] != -1) right[i] = Math.min(right[i], to[i] - i);
		}
		long[] acum = new long[N];
		acum[0] = right[0];
		for (int i = 1; i < N; i++) {
			acum[i] = acum[i-1] + right[i];
		}
		int q = sc.nextInt();
		int l, r, ll, rr, med;
		for (int i = 0; i < q; i++) {
			l = sc.nextInt() - 1;
			r = sc.nextInt();
			ll = l - 1;
			rr = r;
			while (ll + 1 < rr) {
				med = (ll + rr) / 2;
				if (med + right[med] >= r) rr = med;
				else ll = med;
			}
			long ans = (r - rr) * (long)(r - rr + 1) / 2;
			ans += (rr > 0 ? acum[rr-1] : 0) - (l > 0 ? acum[l-1] : 0);
			out.println(ans);
		}
		out.close();
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