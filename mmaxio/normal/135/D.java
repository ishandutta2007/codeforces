import java.io.*;
import java.util.*;

public class D {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    final int INF = Integer.MAX_VALUE / 10;

    int nullAreaCnt = 0;
    int candCycleSize, otherCnt;
    int stX, stY;
    int[][] use;
    char[][] f;
    int n, m;
    boolean touchBorder;

    final int[] dx = { -1, -1, -1, 0, 0, 1, 1, 1 };
    final int[] dy = { -1, 0, 1, -1, 1, -1, 0, 1 };

    final int[] dx1 = { -1, 0, 1, 0 };
    final int[] dy1 = { 0, 1, 0, -1 };

    boolean isValid(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    void dfs(int x, int y) {
        use[x][y] = nullAreaCnt;
        if (f[x][y] == '1') {
            candCycleSize++;
            stX = x;
            stY = y;
            return;
        }

        for (int i = 0; i < 8; i++) {
            int cx = x + dx[i];
            int cy = y + dy[i];
            if (!isValid(cx, cy))
                touchBorder = true;
            if (isValid(cx, cy) && use[cx][cy] != nullAreaCnt) {
                dfs(cx, cy);
            }
        }

    }

    void dfs2(int x, int y, int prevX, int prevY) {
        if (x == stX && y == stY && otherCnt != 0)
            return;

        otherCnt++;
        int tmp = 0;
        int toX = -1, toY = -1;
        for (int i = 0; i < 4; i++) {
            int cx = x + dx1[i];
            int cy = y + dy1[i];
            if (isValid(cx, cy) && f[cx][cy] == '1'
                    && use[cx][cy] == nullAreaCnt) {
                tmp++;
                if (cx != prevX || cy != prevY) {
                    toX = cx;
                    toY = cy;
                }
            }
        }

        if (tmp != 2) {
            otherCnt = INF;
            return;
        }

        dfs2(toX, toY, x, y);

    }

    void solve() throws IOException {
        n = nextInt();
        m = nextInt();

        f = new char[n][];
        use = new int[n][m];
        for (int i = 0; i < n; i++)
            f[i] = nextToken().toCharArray();

        int ans = 0;
        
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < m - 1; j++)
                if (f[i][j] == '1' && f[i][j + 1] == '1' && f[i + 1][j] == '1' && f[i + 1][j + 1] == '1')
                    ans = 4;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (f[i][j] == '0' && use[i][j] == 0) {
                    nullAreaCnt++;
                    candCycleSize = 0;
                    touchBorder = false;
                    dfs(i, j);
                    if (touchBorder)
                        continue;
                    otherCnt = 0;
                    if (candCycleSize != 0) {
                        dfs2(stX, stY, -1, -1);
                        if (otherCnt == candCycleSize) {
                            ans = Math.max(ans, candCycleSize);
                        }
                    }
                }

        out.print(ans);

    }

    void inp() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new D().inp();
    }

    String nextToken() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (Exception e) {
                eof = true;
                return "0";
            }
        }
        return st.nextToken();
    }

    String nextString() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (Exception e) {
                eof = true;
                return "0";
            }
        }
        return st.nextToken("\n");
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