import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
//	int X1, Y1, X2, Y2;
//	int X3, Y3, X4, Y4;
//	{
//		X1 = 1;
//		Y1 = 2;
//		X2 = 3;
//		Y2 = 4;
//		
//		X3 = 5;
//		Y3 = 1;
//		X4 = 5;
//		Y4 = 5;
//	}

	int ask(int x1, int y1, int x2, int y2) throws IOException {
		out.println("? " + x1 + " " + y1 + " " + x2 + " " + y2);
		out.flush();
		return nextInt();
	}
	
	int inside(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
		return inside(x1, x2, x3, x4) & inside(y1, y2, y3, y4);
	}
	
	int inside(int x1, int x2, int y1, int y2) {
		return (x1 <= y1 && y2 <= x2) ? 1 : 0;
	}
	
//	int ask(int x1, int y1, int x2, int y2) throws IOException {
//		return inside(x1, y1, x2, y2, X1, Y1, X2, Y2) + inside(x1, y1, x2, y2, X3, Y3, X4, Y4); 
//	}

	int askFlipped(int x1, int y1, int x2, int y2) throws IOException {
		return ask(y1, x1, y2, x2);
	}
	
	boolean check(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) throws IOException {
		if (x1 > x2 || y1 > y2 || x3 > x4 || y3 > y4) {
			return false;
		}
		
		if (Math.max(x1, x3) <= Math.min(x2, x4) && Math.max(y1, y3) <= Math.min(y2, y4)) {
			return false;
		}
		
		return check(x1, y1, x2, y2) && check(x3, y3, x4, y4);
	}
	
	boolean check(int x1, int y1, int x2, int y2) throws IOException {
		if (ask(x1, y1, x2, y2) != 1) {
			return false;
		}
		if (x1 != x2) {
			if (ask(x1 + 1, y1, x2, y2) != 0 || ask(x1, y1, x2 - 1, y2) != 0) {
				return false;
			}
		}
		
		if (y1 != y2) {
			if (ask(x1, y1 + 1, x2, y2) != 0 || ask(x1, y1, x2, y2 - 1) != 0) {
				return false;
			}
		}
		return true;
	}

	void solve() throws IOException {
		int n = nextInt();

		int low = 0; // 0
		int high = n; // >0
		while (high - low > 1) {
			int mid = (low + high) >> 1;
			int ret = ask(1, 1, mid, n);
			if (ret == 0) {
				low = mid;
			} else {
				high = mid;
			}
		}

		int minX2 = high;

		low = 0; // <2
		high = n; // 2
		while (high - low > 1) {
			int mid = (low + high) >> 1;
			int ret = ask(1, 1, mid, n);
			if (ret == 2) {
				high = mid;
			} else {
				low = mid;
			}
		}

		int maxX2 = high;

		low = 1; // >0
		high = n + 1; // 0
		while (high - low > 1) {
			int mid = (low + high) >> 1;
			int ret = ask(mid, 1, n, n);
			if (ret == 0) {
				high = mid;
			} else {
				low = mid;
			}
		}

		int maxX1 = low;

		low = 1; // 2
		high = n + 1; // <2
		while (high - low > 1) {
			int mid = (low + high) >> 1;
			int ret = ask(mid, 1, n, n);
			if (ret == 2) {
				low = mid;
			} else {
				high = mid;
			}
		}
		int minX1 = low;

		// / NOW Y

		low = 0; // 0
		high = n; // >0
		while (high - low > 1) {
			int mid = (low + high) >> 1;
			int ret = askFlipped(1, 1, mid, n);
			if (ret == 0) {
				low = mid;
			} else {
				high = mid;
			}
		}

		int minY2 = high;

		low = 0; // <2
		high = n; // 2
		while (high - low > 1) {
			int mid = (low + high) >> 1;
			int ret = askFlipped(1, 1, mid, n);
			if (ret == 2) {
				high = mid;
			} else {
				low = mid;
			}
		}

		int maxY2 = high;

		low = 1; // >0
		high = n + 1; // 0
		while (high - low > 1) {
			int mid = (low + high) >> 1;
			int ret = askFlipped(mid, 1, n, n);
			if (ret == 0) {
				high = mid;
			} else {
				low = mid;
			}
		}

		int maxY1 = low;

		low = 1; // 2
		high = n + 1; // <2
		while (high - low > 1) {
			int mid = (low + high) >> 1;
			int ret = askFlipped(mid, 1, n, n);
			if (ret == 2) {
				low = mid;
			} else {
				high = mid;
			}
		}
		int minY1 = low;

		int[] x1s = { minX1, maxX1 };
		int[] x2s = { minX2, maxX2 };
		int[] y1s = { minY1, maxY1 };
		int[] y2s = { minY2, maxY2 };
		
		for (int mask = 0; mask < 8; mask++) {
			int x1 = x1s[0];
			int x3 = x1s[1];
			
			int x2 = x2s[get(mask, 0)];
			int x4 = x2s[get(mask, 0) ^ 1];
			
			int y1 = y1s[get(mask, 1)];
			int y3 = y1s[get(mask, 1) ^ 1];
			
			int y2 = y2s[get(mask, 2)];
			int y4 = y2s[get(mask, 2) ^ 1];
			
			if (check(x1, y1, x2, y2, x3, y3, x4, y4)) {
				out.printf("! %d %d %d %d %d %d %d %d\n", x1, y1, x2, y2, x3, y3, x4, y4);
				out.flush();
				return;
			}
		}
	}
	
	int get(int mask, int i) {
		return (mask >> i) & 1;
	}

	B() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B();
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