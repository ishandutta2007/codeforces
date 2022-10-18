import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	static class Pair {
		int x, y;

		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + x;
			result = prime * result + y;
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Pair other = (Pair) obj;
			if (x != other.x)
				return false;
			if (y != other.y)
				return false;
			return true;
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		HashMap<Integer, Integer> xs = new HashMap<>();
		HashMap<Integer, Integer> ys = new HashMap<>();
		HashMap<Pair, Integer> both = new HashMap<>();
		
		for (int i = 0; i < n; i++) {
			int x = nextInt();
			int y = nextInt();
			Pair p = new Pair(x, y);
			xs.put(x, xs.getOrDefault(x, 0) + 1);
			ys.put(y, ys.getOrDefault(y, 0) + 1);
			both.put(p, both.getOrDefault(p, 0) + 1);
		}
		
		long ans = 0;
		for (int v : xs.values()) {
			ans += (long)v * (v - 1) / 2;
		}
		
		for (int v : ys.values()) {
			ans += (long)v * (v - 1) / 2;
		}
		
		for (int v : both.values()) {
			ans -= (long)v * (v - 1) / 2;
		}
		
		out.println(ans);
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