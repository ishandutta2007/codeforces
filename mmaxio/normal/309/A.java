import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	int dist(int a, int b, int l) {
		if (a <= b)
			return b - a;
		else
			return b - a + l;
	}

	void solve() throws IOException {
		int n = nextInt();
		int l = nextInt() * 2;
		int t = nextInt() * 2;
		
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt() * 2;
		}
		
		if (n == 1) {
			out.println(0);
			return;
		}
		
		int full = t / (l / 2);
		
		long fullAns = (long)full * n * (n - 1); // should divide by 4
		
		t %= l / 2;
		
		//System.err.println(dist(a[0], a[1], l) + " " + t);
		
		long pairs = 0;
		for (int i = 0, j = 1; i < n; i++) {
			if (j == i) {
				j++;
				if (j == n)
					j = 0;
			}
			while (j != i && dist(a[i], a[j], l) <= t * 2) {
				j++;
				if (j == n)
					j = 0;
			}
			int add = j - i;
			if (add <= 0)
				add += n;
			pairs += add - 1;
		}
		
		long ansTimes4 = fullAns + pairs;
		out.println(divideBy4(ansTimes4));
		
	}

	private String divideBy4(long x) {
		String ret = "" + (x >> 2);
		if ((x & 3) == 1)
			ret += ".25";
		if ((x & 3) == 2)
			ret += ".5";
		if ((x & 3) == 3)
			ret += ".75";
		return ret;
	}

	A() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new A();
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