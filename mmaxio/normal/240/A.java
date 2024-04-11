import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int m = nextInt();
		int k = nextInt();
		boolean[] isFav = new boolean[m];
		for (int i = 0; i < k; i++)
			isFav[nextInt() - 1] = true;
		int n = nextInt();
		
		int[] minFav = new int[n];
		int[] maxFav = new int[n];
		for (int i = 0; i < n; i++) {
			nextToken();
			int d = nextInt();
			int unknFav = k;
			int unknNotFav = m - k;
			int totalUnknown = 0;
			for (int j = 0; j < d; j++) {
				int x = nextInt();
				if (x != 0) {
					if (isFav[x - 1]) {
						unknFav--;
						minFav[i]++;
						maxFav[i]++;
					} else
						unknNotFav--;
				} else
					totalUnknown++;
			}
			
			minFav[i] += totalUnknown - Math.min(unknNotFav, totalUnknown);
			maxFav[i] += Math.min(unknFav, totalUnknown);
		}
		
		for (int i = 0; i < n; i++) {
			boolean canBeFav = true;
			boolean canBeNotFav = false;
			for (int j = 0; j < n; j++)
				if (i != j) {
					if (maxFav[i] < minFav[j])
						canBeFav = false;
					if (minFav[i] < maxFav[j])
						canBeNotFav = true;
				}
			if (canBeFav && canBeNotFav)
				out.println(2);
			else if (canBeFav)
				out.println(0);
			else
				out.println(1);
		}
		
	}

	A() throws IOException {
		br = new BufferedReader(new FileReader("input.txt"));
		out = new PrintWriter("output.txt");
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