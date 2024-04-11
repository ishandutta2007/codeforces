import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;
import java.lang.Thread;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main implements Runnable {
        public static void main(String[] args) {
                Thread th = new Thread(new ThreadGroup("Main"), new Main(), "solve", 200_000_000L);
                th.start();
                try {
                        th.join();
                } catch (InterruptedException e) {
                        e.printStackTrace();
                }
        }

        @Override
        public void run() {
                InputStream inputStream = System.in;
                OutputStream outputStream = System.out;
                FastScanner in = new FastScanner(inputStream);
                PrintWriter out = new PrintWriter(outputStream);
                TaskD solver = new TaskD();
                solver.solve(1, in, out);
                out.close();
        }
}

class TaskD {
        String[] field;
        short[][] color;
        int dp1[][];
        boolean cycle;
        int n, m;
        int res = 0;

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
                n = in.nextInt();
                m = in.nextInt();
                field = new String[n];
                for (int i = 0; i < n; i++)
                        field[i] = in.nextToken();
                color = new short[n][m];
                for (int i = n - 1; i >= 0; i--)
                        for (int j = m - 1; j >= 0; j--)
                                if (color[i][j] == 0)
                                        dfs1((short)i, (short)j);
                if (cycle) {
                        out.println(-1);
                        return;
                }
                for (int i = 0; i < n; i++)
                        Arrays.fill(color[i], (short)0);
                dp1 = new int[n][m];
                for (int i = 0; i < n; i++)
                        for (int j = 0; j < m; j++)
                                if (color[i][j] == 0)
                                        dfs2((short)i, (short)j);
                int max1 = 0;
                int max2 = 0;
                for (int i = 0; i < n; i++)
                        for (int j = 0; j < m; j++) {
                                int cur = dp1[i][j];
                                if (cur > max1) {
                                        max2 = max1;
                                        max1 = cur;
                                } else if (cur > max2) {
                                        max2 = cur;
                                }
                        }
                res = Math.max(res, max1 + max2);
                out.println(res);
        }

        void dfs1(short x, short y) {
                color[x][y] = 1;
                short nx = -1;
                short ny = -1;
                if (field[x].charAt(y) == '^' && GridUtils.isValid(x - 1, y, n, m)) {
                        nx = (short)(x - 1);
                        ny = y;
                }
                if (field[x].charAt(y) == 'v' && GridUtils.isValid(x + 1, y, n, m)) {
                        nx = (short)(x + 1);
                        ny = y;
                }
                if (field[x].charAt(y) == '>' && GridUtils.isValid(x, y + 1, n, m)) {
                        nx = x;
                        ny = (short)(y + 1);
                }
                if (field[x].charAt(y) == '<' && GridUtils.isValid(x, y - 1, n, m)) {
                        nx = x;
                        ny = (short)(y - 1);
                }
                if (GridUtils.isValid(nx, ny, n, m)) {
                        if (color[nx][ny] == 1)
                                cycle = true;
                        else if (color[nx][ny] == 0)
                                dfs1(nx, ny);
                }
                color[x][y] = 2;
        }

        void dfs2(short x, short y) {
                if (color[x][y] == 1)
                        return;
                color[x][y] = 1;
                for (int d = 0; d < 4; d++) {
                        short nx = (short)(x + GridUtils.dx4[d]);
                        short ny = (short)(y + GridUtils.dy4[d]);
                        if (!GridUtils.isValid(nx, ny, n, m))
                                continue;
                        if (!goesHere(nx, ny, x, y))
                                continue;
                        if (color[nx][ny] != 1)
                                dfs2(nx, ny);
                        int d1 = dp1[nx][ny] + 1;
                        if (d1 > dp1[x][y]) {
                                res = Math.max(res, d1 + dp1[x][y]);
                                dp1[x][y] = d1;
                        } else {
                                res = Math.max(res, d1 + dp1[x][y]);
                        }
                }
        }

        boolean goesHere(int x, int y, int wantX, int wantY) {
                if (field[x].charAt(y) == '^')
                        return x == wantX + 1 && y == wantY;
                if (field[x].charAt(y) == 'v')
                        return x == wantX - 1 && y == wantY;
                if (field[x].charAt(y) == '>')
                        return x == wantX && y == wantY - 1;
                return field[x].charAt(y) == '<' && x == wantX && y == wantY + 1;
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

class GridUtils {
        public final static short[] dx4 = {0, 0, -1, 1};
        public final static short[] dy4 = {-1, 1, 0, 0};

        public static boolean isValid(int row, int col, int rowCount, int colCount) {
                return 0 <= row && row < rowCount && 0 <= col && col < colCount;
        }
}