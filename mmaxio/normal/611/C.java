import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int h = nextInt();
		int w = nextInt();
		char[][] f = new char[h][];
		for (int i = 0; i < h; i++) {
			f[i] = nextToken().toCharArray();
		}

		int[][] hor = new int[h + 1][w];
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w - 1; j++) {
				hor[i + 1][j + 1] = (f[i][j] == '.' && f[i][j + 1] == '.') ? 1 : 0;
			}

		int[][] ver = new int[h][w + 1];
		for (int i = 0; i < h - 1; i++)
			for (int j = 0; j < w; j++) {
				ver[i + 1][j + 1] = (f[i][j] == '.' && f[i + 1][j] == '.') ? 1 : 0;
			}
		
//		System.err.println(Arrays.deepToString(hor));
//		System.err.println(Arrays.deepToString(ver));

		for (int i = 1; i < h + 1; i++)
			for (int j = 1; j < w; j++) {
				hor[i][j] += hor[i - 1][j] + hor[i][j - 1] - hor[i - 1][j - 1];
			}

		for (int i = 1; i < h; i++)
			for (int j = 1; j < w + 1; j++) {
				ver[i][j] += ver[i - 1][j] + ver[i][j - 1] - ver[i - 1][j - 1];
			}
		
		
		
		int q = nextInt();
		for (int i = 0; i < q; i++) {
			int x1 = nextInt() - 1;
			int y1 = nextInt() - 1;
			int x2 = nextInt() - 1;
			int y2 = nextInt() - 1;
			
			int ret = hor[x2 + 1][y2] - hor[x1][y2] - hor[x2 + 1][y1] + hor[x1][y1];
			ret += ver[x2][y2 + 1] - ver[x1][y2 + 1] - ver[x2][y1] + ver[x1][y1];
			out.println(ret);
		}
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