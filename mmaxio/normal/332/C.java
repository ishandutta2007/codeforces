import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Thing {
		int a;
		int b;
		int id;
		int byBPos;

		public Thing(int a, int b, int id) {
			this.a = a;
			this.b = b;
			this.id = id;
		}

		static Comparator<Thing> byB = new Comparator<Thing>() {

			@Override
			public int compare(Thing o1, Thing o2) {
				if (o1.b != o2.b)
					return Integer.compare(o1.b, o2.b);
				return -Integer.compare(o1.a, o2.a);
			}
		};

		static Comparator<Thing> byA = new Comparator<Thing>() {

			@Override
			public int compare(Thing o1, Thing o2) {
				return -Integer.compare(o1.a, o2.a);
			}
		};

		@Override
		public String toString() {
			return "(" + a + ", " + b + ")";
		}

	}

	void solve() throws IOException {
		int n = nextInt();
		int p = nextInt();
		int k = nextInt();

		Thing[] a = new Thing[n];
		for (int i = 0; i < n; i++) {
			a[i] = new Thing(nextInt(), nextInt(), i);
		}

		Arrays.sort(a, Thing.byB);

		Thing[] b = a.clone();
		
		for (int i = p - k; i < n; i++) {
			b[i].byBPos = i;
		}
		for (int l = p - k, r = n - 1; l < r; l++, r--) {
			Thing tmp = b[l];
			b[l] = b[r];
			b[r] = tmp;
		}
		
		Arrays.sort(b, p - k, n, Thing.byA);

		int borderInd = n;
		for (int i = p - k; i < p; i++) {
			borderInd = Math.min(borderInd, b[i].byBPos);
		}

		for (int i = borderInd - (p - k); i < borderInd; i++) {
			out.print(a[i].id + 1 + " ");
		}

		for (int i = p - k; i < p; i++) {
			out.print(b[i].id + 1 + " ");
		}
		out.println();

	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return null;
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			eof = true;
			return null;
		}
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}