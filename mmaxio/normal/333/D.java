import java.io.*;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static class Cell implements Comparable<Cell> {
		int x, y, val;

		public Cell(int x, int y, int val) {
			this.x = x;
			this.y = y;
			this.val = val;
		}

		@Override
		public int compareTo(Cell o) {
			return -Integer.compare(val, o.val);
		}

	}

	int SIZE;
	static final int MASK = 31;

	void solve() throws IOException {
				
		int n = nextInt();
		int m = nextInt();

		Cell[] a = new Cell[n * m];
		for (int i = 0, k = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				a[k++] = new Cell(i, j, nextInt());
			}
		}

		Arrays.sort(a);
		SIZE = (Math.max(m, n) + 31) >> 5;
			
		int[][] setRow = new int[n][SIZE];
		List<Integer>[] whichRows = new List[m];
		for (int i = 0; i < m; i++) {
			whichRows[i] = new ArrayList<>();
		}
		
		for (int i = 0; i < n * m; i++) {
			int x = a[i].x;
			int y = a[i].y;
			
			int[] set2 = setRow[x];
			
			List<Integer> cur = whichRows[y];
			
			for (int j = 0; j < cur.size(); j++) {
				int row = cur.get(j);
				
				int[] set1 = setRow[row];
				for (int k = 0; k < SIZE; k++) {
					if ((set1[k] & set2[k]) != 0) {
						out.println(a[i].val);
						return;
					}
				}
			}
			
			setBit(set2, y);
			cur.add(x);
		}
		
		throw new AssertionError();
	}
	
	static void setBit(int[] bitSet, int pos) {
		bitSet[pos >> 5] |= 1 << (pos & MASK);
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