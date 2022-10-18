import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	static final int[] dx = {1, 0, -1, 0};
	static final int[] dy = {0, 1, 0, -1};
	static final String DIRS = "DRUL";
	
	static final Random rng = new Random();
	
	int[] compress(int[] a) {
		for (int i = 0; i < a.length; i++) {
			int j = rng.nextInt(i + 1);
			int tmp = a[j];
			a[j] = a[i];
			a[i] = tmp;
		}
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
		int[] x = new int[n + 1];
		int[] y = new int[n + 1];
		int[] dir = new int[n];
		for (int i = 0; i < n; i++) {
			char dc = nextToken().charAt(0);
			dir[i] = DIRS.indexOf(dc);
			int move = nextInt();
			x[i + 1] = x[i] + dx[dir[i]] * move;
			y[i + 1] = y[i] + dy[dir[i]] * move;
//			System.err.println(x[i + 1] + " " + y[i + 1]);
		}
		int[] allX = x.clone();
		int[] allY = y.clone();
		allX = compress(allX);
		allY = compress(allY);
		
//		System.err.println(Arrays.toString(allX));
//		System.err.println(Arrays.toString(allY));
		
		ArrayList<Integer> newAllX = new ArrayList<>();
		ArrayList<Integer> sizeX = new ArrayList<>();
		
		newAllX.add(allX[0]);
		sizeX.add(1);
		for (int i = 1; i < allX.length; i++) {
			if (allX[i] != allX[i - 1] + 1) {
				newAllX.add(allX[i - 1] + 1);
				sizeX.add(allX[i] - allX[i - 1] - 1);
			}
			newAllX.add(allX[i]);
			sizeX.add(1);
		}
		
//		System.err.println(Arrays.toString(allX));
//		System.err.println(newAllX);
//		System.err.println(sizeX);
		
		
		ArrayList<Integer> newAllY = new ArrayList<>();
		ArrayList<Integer> sizeY = new ArrayList<>();
		
		newAllY.add(allY[0]);
		sizeY.add(1);
		for (int i = 1; i < allY.length; i++) {
			if (allY[i] != allY[i - 1] + 1) {
				newAllY.add(allY[i - 1] + 1);
				sizeY.add(allY[i] - allY[i - 1] - 1);
			}
			newAllY.add(allY[i]);
			sizeY.add(1);
		}
		
//		System.err.println(Arrays.toString(allY));
//		System.err.println(newAllY);
//		System.err.println(sizeY);
		
		for (int i = 0; i <= n; i++) {
			x[i] = Collections.binarySearch(newAllX, x[i]);
			y[i] = Collections.binarySearch(newAllY, y[i]);
		}
		
		int fSizeX = newAllX.size() + 2;
		int fSizeY = newAllY.size() + 2;
		
		int[][] f = new int[fSizeX][fSizeY];
		for (int i = 0; i < n; i++) {
			int x1 = x[i] + 1;
			int y1 = y[i] + 1;
			int x2 = x[i + 1] + 1;
			int y2 = y[i + 1] + 1;
			while (x1 != x2 || y1 != y2) {
				f[x1][y1] = 1;
				x1 += dx[dir[i]];
				y1 += dy[dir[i]];
			}
			f[x2][y2] = 1;
		}
		
//		for (int i = 0; i < fSizeX; i++)
//			System.err.println(Arrays.toString(f[i]));
		
		ArrayDeque<Integer> q = new ArrayDeque<>();
		q.add(0);
		q.add(0);
		f[0][0] = 2;
		while (!q.isEmpty()) {
			int cx = q.poll();
			int cy = q.poll();
			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx >= 0 && nx < fSizeX && ny >= 0 && ny < fSizeY && f[nx][ny] == 0) {
					f[nx][ny] = 2;
					q.add(nx);
					q.add(ny);
				}
			}
		}
		
		long ans = 0;
		for (int i = 1; i < fSizeX - 1; i++) {
			long xSize = sizeX.get(i - 1);
			for (int j = 1; j < fSizeY - 1; j++) {
				long ySize = sizeY.get(j - 1);
				if (f[i][j] != 2)
					ans += xSize * ySize;
			}
		}
		
		out.println(ans);
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