import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final int[][] row = { { 0, 1, 2 }, { 3, 4, 5 }, { 6, 7, 8 },
			{ 0, 3, 6 }, { 1, 4, 7 }, { 2, 5, 8 }, { 0, 4, 8 }, { 2, 4, 6 } };

	static final int N = 9;

	boolean isWin(char[] f, char p) {
		for (int i = 0; i < row.length; i++) {
			boolean ok = true;
			for (int j = 0; j < row[i].length; j++)
				if (f[row[i][j]] != p) {
					ok = false;
					break;
				}
			if (ok)
				return true;
		}
		return false;
	}

	void solve() throws IOException {
		String s = nextToken() + nextToken() + nextToken();
		char[] f = s.toCharArray();

		int cntX = 0;
		int cnt0 = 0;
		for (int i = 0; i < N; i++)
			if (f[i] == 'X')
				cntX++;
			else if (f[i] == '0')
				cnt0++;

		int diff = cntX - cnt0;
		if (diff != 0 && diff != 1) {
			out.println("illegal");
			return;
		}

		char lastMove = diff == 0 ? '0' : 'X';
		char nextMove = diff == 0 ? 'X' : '0';

		if (isWin(f, nextMove)) {
			out.println("illegal");
			return;
		}
		
		if (!isWin(f, lastMove)) {
			if (cntX + cnt0 == 9)
				out.println("draw");
			else
				out.println(nextMove == 'X' ? "first" : "second");
			return;
		}
		
		for (int i = 0; i < N; i++) {
			if (f[i] == lastMove) {
				f[i] = '.';
				if (!isWin(f, lastMove)) {
					out.println("the " + (lastMove == 'X' ? "first" : "second") + " player won");
					return;
				}
				f[i] = lastMove;
			}
		}
		
		out.println("illegal");

	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C().inp();
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