import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	int[] unique(int[] inp) {
		int[] a = inp.clone();
		Arrays.sort(a);
		int sz = 1;
		for (int i = 1; i < a.length; i++) {
			if (a[i] != a[sz - 1]) {
				a[sz++] = a[i];
			}
		}
		return Arrays.copyOf(a, sz);
	}

	void solve() throws IOException {
		int n = nextInt();
		int[] x1 = new int[n];
		int[] y1 = new int[n];
		int[] x2 = new int[n];
		int[] y2 = new int[n];
		
		for (int i = 0; i < n; i++) {
			x1[i] = nextInt();
			y1[i] = nextInt();
			x2[i] = nextInt();
			y2[i] = nextInt();
		}
		
		int[] allX = Arrays.copyOf(x1, 2 * n);
		System.arraycopy(x2, 0, allX, n, n);
		
		int[] allY = Arrays.copyOf(y1, 2 * n);
		System.arraycopy(y2, 0, allY, n, n);
		
		allX = unique(allX);
		allY = unique(allY);
		
		int minX = allX[0];
		int maxX = allX[allX.length - 1];
		
		int minY = allY[0];
		int maxY = allY[allY.length - 1];
		
		if (maxX - minX != maxY - minY) {
			out.println("NO");
			return;
		}
		
		boolean[][] f = new boolean[allX.length - 1][allY.length - 1];
		
		for (int i = 0; i < n; i++) {
			x1[i] = Arrays.binarySearch(allX, x1[i]);
			y1[i] = Arrays.binarySearch(allY, y1[i]);
			x2[i] = Arrays.binarySearch(allX, x2[i]);
			y2[i] = Arrays.binarySearch(allY, y2[i]);
			
			for (int x = x1[i]; x < x2[i]; x++)
				for (int y = y1[i]; y < y2[i]; y++) {
					f[x][y] = true;
				}
		}
		
		for (int i = 0; i < f.length; i++)
			for (int j = 0; j < f[i].length; j++) {
				if (!f[i][j]) {
					out.println("NO");
					return;
				}
			}
		
		out.println("YES");
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