import java.io.*;
import java.util.*;

public class C {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    int sx, sy, ex, ey, k;
    int n, m;
    boolean[] good;
    char[][] s;
    final int INF = Integer.MAX_VALUE / 3;
    final int[] dx = { 1, 0, -1, 0 };
    final int[] dy = { 0, 1, 0, -1 };

    boolean hasAnswer;
    String ans;

    boolean isValidCell(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m && good[s[x][y]];
    }

    void go(char c, int left) {
        if (left == k) {
            check();
            return;
        }
        if (c == 'z' + 1)
            return;
        good[c] = true;
        go((char) (c + 1), left + 1);
        good[c] = false;
        go((char) (c + 1), left);
    }

    void check() {
        int[][] d = new int[n][m];
        for (int i = 0; i < n; i++)
            Arrays.fill(d[i], INF);
        ArrayDeque<Integer> q = new ArrayDeque<Integer>();
        d[sx][sy] = 0;
        q.add(sx);
        q.add(sy);

        while (!q.isEmpty()) {
            int cx = q.pollFirst();
            int cy = q.pollFirst();
            if (cx == ex && cy == ey)
                break;
            for (int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if (isValidCell(nx, ny) && d[nx][ny] > d[cx][cy] + 1) {
                    d[nx][ny] = d[cx][cy] + 1;
                    q.add(nx);
                    q.add(ny);
                }
            }
        }

        if (d[ex][ey] == INF)
            return;

        int dist = d[ex][ey];

        if (hasAnswer && dist - 1 > ans.length())
            return;

        int[][] dRev = new int[n][m];
        for (int i = 0; i < n; i++)
            Arrays.fill(dRev[i], INF);
        dRev[ex][ey] = 0;
        q = new ArrayDeque<Integer>();
        q.add(ex);
        q.add(ey);

        while (!q.isEmpty()) {
            int cx = q.pollFirst();
            int cy = q.pollFirst();
            if (cx == sx && cy == sy)
                break;
            for (int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if (isValidCell(nx, ny) && dRev[nx][ny] > dRev[cx][cy] + 1) {
                    dRev[nx][ny] = dRev[cx][cy] + 1;
                    q.add(nx);
                    q.add(ny);
                }
            }
        }

        boolean[][] used = new boolean[n][m];
        ArrayList<Integer> nice = new ArrayList<Integer>();
        nice.add(sx);
        nice.add(sy);

        char[] newAns = new char[dist - 1];

        for (int i = 0; i < dist - 1; i++) {
            ArrayList<Integer> newNice = new ArrayList<Integer>();
            newAns[i] = 'z' + 1;
            for (int j1 = 0; j1 < nice.size(); j1 += 2) {
                int cx = nice.get(j1);
                int cy = nice.get(j1 + 1);
                for (int j = 0; j < 4; j++) {
                    int nx = cx + dx[j];
                    int ny = cy + dy[j];
                    if (isValidCell(nx, ny) && d[nx][ny] + dRev[nx][ny] == dist
                            && d[nx][ny] == d[cx][cy] + 1 && !used[nx][ny]) {
                        if (s[nx][ny] <= newAns[i]) {
                            if (s[nx][ny] < newAns[i]) {
                                newNice.clear();
                                newAns[i] = s[nx][ny];
                            }
                            newNice.add(nx);
                            newNice.add(ny);
                            used[nx][ny] = true;
                        }
                    }
                }
            }
            nice = newNice;
        }

        String newAnsStr = new String(newAns);

        if (!hasAnswer) {
            hasAnswer = true;
            ans = newAnsStr;
        } else {
            if (newAnsStr.length() < ans.length() || newAnsStr.compareTo(ans) < 0)
                ans = newAnsStr;
        }
    }

    void solve() throws IOException {
        n = nextInt();
        m = nextInt();
        k = nextInt();
        s = new char[n][];

        for (int i = 0; i < n; i++)
            s[i] = nextToken().toCharArray();

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (s[i][j] == 'S') {
                    sx = i;
                    sy = j;
                } else if (s[i][j] == 'T') {
                    ex = i;
                    ey = j;
                }

        good = new boolean[256];
        good['S'] = true;
        good['T'] = true;
        hasAnswer = false;
        ans = "";
        go('a', 0);

        if (!hasAnswer)
            out.print(-1);
        else
            out.print(ans);
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