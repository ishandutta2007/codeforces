import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	int n, m;
	
	long f(int x, int y) {
		return (long)x * m + y;
	}
	
	boolean test(int mask, int i) {
		return ((mask >> i) & 1) == 1;
	}
	
	int getD(int dx, int dy) {
		return (dx == -1 ? 2 : 0) + (dy == -1 ? 1 : 0);
	}
	
	int getMove(int cur, int delta, int size) {
		return delta == 1 ? (size - 1 - cur) : (cur);
	}

	void solve() throws IOException {
		n = nextInt();
		m = nextInt();
		
		int x0 = nextInt() - 1;
		int y0 = nextInt() - 1;
		
		int totalBorder = n + m - 2;
		
		HashMap<Long, Integer> mask = new HashMap<>();
		
		long ans = 1;
		String dir = nextToken();
		int dx = dir.charAt(0) == 'D' ? 1 : -1;
		int dy = dir.charAt(1) == 'R' ? 1 : -1;
		

		
		while (true) {
			if (x0 == 0 && dx == -1)
				dx = 1;
			if (x0 == n - 1 && dx == 1)
				dx = -1;
			if (y0 == 0 && dy == -1)
				dy = 1;
			if (y0 == m - 1 && dy == 1)
				dy = -1;
			
			long curCell = f(x0, y0);
			int curDir = getD(dx, dy);
			
			Integer tmp = mask.get(curCell);
//			out.println(x0 + " " + y0 + " " + dx + " " + dy + " " + tmp + " " + curDir);
			if (tmp == null) {
				tmp = 0;
				totalBorder--;
				if (totalBorder == 0) {
					break;
				}
			}
			if (test(tmp, curDir)) {
				out.println(-1);
				return;
			}
			tmp ^= (1 << curDir);
			mask.put(curCell, tmp);
			
			int moveX = getMove(x0, dx, n);
			int moveY = getMove(y0, dy, m);
			
			int move = Math.min(moveX, moveY);
			ans += move;
			x0 += move * dx;
			y0 += move * dy;
		}
		
		out.println(ans);
	}

	D() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D();
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