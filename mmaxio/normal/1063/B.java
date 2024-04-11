import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class B {

	void submit() {
		int n = nextInt();
		int m = nextInt();
		int x0 = nextInt() - 1;
		int y0 = nextInt() - 1;

		int maxL = nextInt();
		int maxR = nextInt();

		char[][] f = new char[n][];
		for (int i = 0; i < n; i++) {
			f[i] = nextToken().toCharArray();
		}

		ArrayDeque<Integer> q = new ArrayDeque<>();

		int[][] dist = new int[n][m];
		for (int i = 0; i < n; i++) {
			Arrays.fill(dist[i], INF);
		}
		dist[x0][y0] = 0;

		q.add(x0);
		q.add(y0);

		while (!q.isEmpty()) {
			int x = q.pollFirst();
			int y = q.pollFirst();
			
			for (int dir = 0; dir < 4; dir++) {
				int cx = x + DX[dir];
				int cy = y + DY[dir];
				int cost = dir == 0 ? 1 : 0;
				
				if (cx < 0 || cx >= n || cy < 0 || cy >= m || f[cx][cy] == '*') {
					continue;
				}
				
				if (dist[cx][cy] > dist[x][y] + cost) {
					dist[cx][cy] = dist[x][y] + cost;
					if (cost == 0) {
						q.addFirst(cy);
						q.addFirst(cx);
					} else {
						q.addLast(cx);
						q.addLast(cy);
					}
				}
			}
		}
		
		int ret = 0;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (dist[i][j] == INF) {
					continue;
				}
				
				int needL = dist[i][j];
				int needR = needL + j - y0;
				
				if (needL <= maxL && needR <= maxR) {
					ret++;
				}
 			}
		}
		
		out.println(ret);
	}

	static final int[] DX = { 0, -1, 0, 1 };
	static final int[] DY = { -1, 0, 1, 0 };

	static final int INF = Integer.MAX_VALUE / 3;

	void test() {

	}

	void stress() {
		for (int tst = 0;; tst++) {
			if (false) {
				throw new AssertionError();
			}
			System.err.println(tst);
		}
	}

	B() throws IOException {
		is = System.in;
		out = new PrintWriter(System.out);
		submit();
		// stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();
	static final int C = 5;

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new B();
	}

	private InputStream is;
	PrintWriter out;

	private byte[] buf = new byte[1 << 14];
	private int bufSz = 0, bufPtr = 0;

	private int readByte() {
		if (bufSz == -1)
			throw new RuntimeException("Reading past EOF");
		if (bufPtr >= bufSz) {
			bufPtr = 0;
			try {
				bufSz = is.read(buf);
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
			if (bufSz <= 0)
				return -1;
		}
		return buf[bufPtr++];
	}

	private boolean isTrash(int c) {
		return c < 33 || c > 126;
	}

	private int skip() {
		int b;
		while ((b = readByte()) != -1 && isTrash(b))
			;
		return b;
	}

	String nextToken() {
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while (!isTrash(b)) {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	String nextString() {
		int b = readByte();
		StringBuilder sb = new StringBuilder();
		while (!isTrash(b) || b == ' ') {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	char nextChar() {
		return (char) skip();
	}

	int nextInt() {
		int ret = 0;
		int b = skip();
		if (b != '-' && (b < '0' || b > '9')) {
			throw new InputMismatchException();
		}
		boolean neg = false;
		if (b == '-') {
			neg = true;
			b = readByte();
		}
		while (true) {
			if (b >= '0' && b <= '9') {
				ret = ret * 10 + (b - '0');
			} else {
				if (b != -1 && !isTrash(b)) {
					throw new InputMismatchException();
				}
				return neg ? -ret : ret;
			}
			b = readByte();
		}
	}

	long nextLong() {
		long ret = 0;
		int b = skip();
		if (b != '-' && (b < '0' || b > '9')) {
			throw new InputMismatchException();
		}
		boolean neg = false;
		if (b == '-') {
			neg = true;
			b = readByte();
		}
		while (true) {
			if (b >= '0' && b <= '9') {
				ret = ret * 10 + (b - '0');
			} else {
				if (b != -1 && !isTrash(b)) {
					throw new InputMismatchException();
				}
				return neg ? -ret : ret;
			}
			b = readByte();
		}
	}
}