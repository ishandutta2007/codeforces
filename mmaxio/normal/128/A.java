import java.io.*;
import java.util.*;

public class A {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    int[][][] memo;
    char[][] f;

    final int MAX_TIME = 100;

    boolean isValid(int x, int y) {
        return x >= 0 && x < 8 && y >= 0 && y < 8;
    }

    int dfs(int x, int y, int time) {
        //System.err.println(x + " " + y + " " + time);
        if (time >= MAX_TIME - 1)
            return -1;
        if (memo[x][y][time] != 0)
            return memo[x][y][time];
        memo[x][y][time] = -1;
        if (x == 0 && y == 7)
            return memo[x][y][time] = 1;
        if (isValid(x - time, y) && f[x - time][y] == 'S')
            return -1;
        
        for (int dx = -1; dx <= 1; dx++)
            for (int dy = -1; dy <= 1; dy++) {
                int cx = x + dx;
                int cy = y + dy;
                if (isValid(cx, cy)) 
                    if (!isValid(cx - time, cy) || f[cx - time][cy] != 'S'){
                    dfs(cx, cy, time + 1);
                    if (memo[cx][cy][time + 1] == 1)
                        return memo[x][y][time] = 1; 
                }
            }
        
        return memo[x][y][time];
    }

    void solve() throws IOException {
        f = new char[8][8];
        for (int i = 0; i < 8; i++)
            f[i] = nextToken().toCharArray();
        memo = new int[8][8][MAX_TIME];
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                Arrays.fill(memo[i][j], 0);

        out.print(dfs(7, 0, 0) == 1 ? "WIN" : "LOSE");
    }

    void inp() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new A().inp();
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