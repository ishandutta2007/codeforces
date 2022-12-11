import java.io.*;
import java.util.*;
import java.lang.Math;
 
public class lakefill {
	static int lakesize = 0;
	static char[][]  b;
	static int[][] b1;
	static int n;
	static int m;
	static int c = 0;
	static void fill(int x, int y) {
		b1[x][y] = c;
		b[x][y] = '*';
		lakesize += 1;
		if (x != 1) {
			if (b[x-1][y] == '.') {
				fill(x-1, y);
			}
		}
		if (x != n-2) {
			if (b[x+1][y] == '.') {
				fill(x+1, y);
			}
		}
		if (y != 1) {
			if (b[x][y-1] == '.') {
				fill(x, y-1);
			}
		}
		if (y != m-2) {
			if (b[x][y+1] == '.') {
				fill(x, y+1);
			}
		}
	}
	static void edgefill(int x, int y) {
		b[x][y] = 'O';
		b1[x][y] = -1;
		if (x != 0) {
			if (b[x-1][y] == '.') {
				edgefill(x-1, y);
			}
		}
		if (x != n-1) {
			if (b[x+1][y] == '.') {
				edgefill(x+1, y);
			}
		}
		if (y != 0) {
			if (b[x][y-1] == '.') {
				edgefill(x, y-1);
			}
		}
		if (y != m-1) {
			if (b[x][y+1] == '.') {
				edgefill(x, y+1);
			}
		}
	}
	public static void main(String[] args) throws IOException {
		int answer = 0;
		Scanner sc = new Scanner(System.in);
		StringTokenizer st = new StringTokenizer(sc.nextLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		b = new char[n][m];
		b1 = new int[n][m];
		char[][] b2 = new char[n][m];
		ArrayList<Integer> lakesizes = new ArrayList<Integer>();
		ArrayList<Integer> lakesizes2 = new ArrayList<Integer>();
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(sc.nextLine());
			String teststring = st.nextToken();
			for (int j = 0; j < m; j++) {
				b[i][j] = teststring.charAt(j);
				b2[i][j] = teststring.charAt(j);
				b1[i][j] = -1;
			}
		}
		for (int i = 0; i < n; i++)
		{
		  for (int j = 0; j < m; j++)
		  {
		    if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
		    {
		       if (b[i][j] == '.')
		       {
		          edgefill(i, j);
		       }
		    }
		  }
		}
		for (int i = 1; i < m-1; i++) {
			for (int j = 1; j < n-1; j++) {
				lakesize = 0;
				if (b[j][i] == '.') {
					fill(j, i);
					c += 1;
					lakesizes.add(lakesize);
					lakesizes2.add(lakesize);
				}
			}
		}
		Collections.sort(lakesizes);
		for (int i = 0; i < lakesizes.size() - k; i++) {
			int idx = -1;
			answer = answer + lakesizes.get(i);
			for (int j = 0; j < lakesizes2.size(); j++) {
				if (lakesizes2.get(j).equals(lakesizes.get(i))) {
					idx = j;
					lakesizes2.set(j, -1);
					break;
				}
			}
			for (int j = 0; j < n; j++) {
				for (int l = 0; l < m; l++) {
					if (b1[j][l] == idx) {
						b2[j][l] = '*';
					}
				}
			}
		}
		System.out.println(answer);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				System.out.print(b2[i][j]);
			}
			System.out.println();
		}
		sc.close();
	}
}