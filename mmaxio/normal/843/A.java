import java.io.*;
import java.util.*;

public class A {

	static class Number implements Comparable<Number> {
		int val, pos;

		public Number(int val, int pos) {
			this.val = val;
			this.pos = pos;
		}

		@Override
		public int compareTo(Number o) {
			return Integer.compare(val, o.val);
		}
		
	}
	
	void submit() {
		int n = nextInt();
		Number[] a = new Number[n];
		for (int i = 0; i < n; i++) {
			int x = nextInt();
			a[i] = new Number(x, i);
		}
		
		Arrays.sort(a);
		
		int[] perm = new int[n];
		for (int i = 0; i < n; i++) {
			perm[a[i].pos] = i;
		}
		
		boolean[] vis = new boolean[n];
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (!vis[i]) {
				ans++;
				for (int j = i; !vis[j]; j = perm[j]) {
					vis[j] = true;
				}
			}
		}
		
		out.println(ans);
		Arrays.fill(vis, false);
		for (int i = 0; i < n; i++) {
			if (!vis[i]) {
				int size = 0;
				for (int j = i; !vis[j]; j = perm[j]) {
					vis[j] = true;
					size++;
				}
				
				out.print(size + " " + (i + 1) + " ");
				for (int j = perm[i]; j != i; j = perm[j]) {
					out.print((j + 1) + " ");
				}
				out.println();
			}
		}
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	A() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
		//stress();
		//test();
		out.close();
	}

	static final Random rng = new Random();

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new A();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}