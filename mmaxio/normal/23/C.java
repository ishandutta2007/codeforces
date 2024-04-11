import java.io.*;
import java.util.*;

public class cfRound23C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	class Box implements Comparable<Box>{
		int c1, c2;
		int id;
		
		public Box(int c1, int c2, int id) {
			this.c1 = c1;
			this.c2 = c2;
			this.id = id;
		}

		@Override
		public int compareTo(Box o) {
			return Integer.compare(c1, o.c1);
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		Box[] a = new Box[2 * n - 1];
		for (int i = 0; i < 2 * n - 1; i++) {
			a[i] = new Box(nextInt(), nextInt(), i + 1);
		}
		
		Arrays.sort(a);
		
		long sumEven = 0;
		long sumOdd = 0;
		for (int i = 0; i < 2 * n - 2; i += 2) {
			sumEven += a[i].c2;
			sumOdd += a[i + 1].c2;
		}
		
		out.println("YES");
		if (sumEven > sumOdd) {
			for (int i = 0; i < 2 * n - 2; i += 2) {
				out.print(a[i].id + " ");
			}
		} else {
			for (int i = 1; i < 2 * n - 2; i += 2) {
				out.print(a[i].id + " ");
			}
		}
		out.println(a[2 * n - 2].id);
	}

	cfRound23C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		int t = nextInt();
		while (t-- > 0) {
			solve();
		}
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new cfRound23C();
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