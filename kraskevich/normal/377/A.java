import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {

        boolean[][] used;
        boolean[][] colored;
        String[] field;
        int n, m, k;

        public void dfs(int row, int col) {
                used[row][col] = true;
                for (int dir = 0; dir < 4; dir++) {
                        int x = row + GridUtils.dx4[dir];
                        int y = col + GridUtils.dy4[dir];
                        if (GridUtils.isValid(x, y, n, m) && !used[x][y] && field[x].charAt(y) == '.')
                                dfs(x, y);
                }
                if (k > 0) {
                        colored[row][col] = true;
                        k--;
                }
        }

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
                n = in.nextInt();
                m = in.nextInt();
                k = in.nextInt();
                field = new String[n];
                used = new boolean[n][m];
                colored = new boolean[n][m];
                for (int i = 0; i < n; i++)
                        field[i] = in.nextToken();
                for (int i = 0; i < n; i++)
                        for (int j = 0; j < m; j++)
                                if (field[i].charAt(j) != '#' && !used[i][j])
                                        dfs(i, j);
                for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++)
                                if (!colored[i][j])
                                        out.print(field[i].charAt(j));
                                else
                                        out.print("X");
                        out.println();
                }
        }
}

class GridUtils {
        public final static int[] dx4 = {0, 0, -1, 1};
        public final static int[] dy4 = {-1, 1, 0, 0};

        public static boolean isValid(int row, int col, int rowCount, int colCount) {
                return 0 <= row && row < rowCount && 0 <= col && col < colCount;
        }
}

class FastScanner {
        BufferedReader reader;
        StringTokenizer tokenizer;

        public FastScanner(InputStream inputStream)  {
                reader = new BufferedReader(new InputStreamReader(inputStream));
        }

        public String nextToken() {
                while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                        String line;
                        try {
                                line = reader.readLine();
                        } catch (IOException e) {
                                return null;
                        }
                        tokenizer = new StringTokenizer(line);
                }
                return tokenizer.nextToken();
        }

        public int nextInt() {
                return Integer.parseInt(nextToken());
        }
}