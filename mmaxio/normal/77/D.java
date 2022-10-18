import java.io.*;
import java.util.*;

public class D {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;
    
    final int MOD = 1000000007;

    char[][] str;
    int[][] f;

    int decode(int x, int y) {
        int val = 0;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) {
                if (str[x + i][y + j] == 'O')
                    val += 1 << (i * 3 + j);
            }
        if (val == 0)
            return 0;
        else if (val == 16)
            return 1;
        else if (val == 4 + 64)
            return 2;
        else if (val == 1 + 256)
            return -2;
        else if (val == 4 + 16 + 64)
            return 3;
        else if (val == 1 + 16 + 256)
            return -3;
        else if (val == 1 + 4 + 64 + 256)
            return 4;
        else if (val == 1 + 4 + 16 + 64 + 256)
            return 5;
        else if (val == 1 + 4 + 8 + 32 + 64 + 256)
            return 6;
        else if (val == 1 + 2 + 4 + 64 + 128 + 256)
            return -6;
        else
            throw new AssertionError(val);
    }
    
    boolean isHoriz(int s) {
        return s == 0 || s == 1 || s == -2 || s == -3 || s == 4 || s == 5 || s == -6;
    }
    
    boolean isVert(int s){
        return s >= 0;
        
    }

    void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        if (n * m % 2 == 1) {
            out.print(0);
            return;
        }
        str = new char[4 * n + 1][];
        f = new int[n][m];
        for (int i = 0; i < 4 * n + 1; i++)
            str[i] = nextToken().toCharArray();

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                int x = 1 + 4 * i;
                int y = 1 + 4 * j;
                f[i][j] = decode(x, y);
            }
        
        boolean[][] hor = new boolean[n][m - 1];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m - 1; j++)
                hor[i][j] = isHoriz(f[i][j]) && isHoriz(f[i][j + 1]);
        
        boolean[][] ver = new boolean[n - 1][m];
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < m; j++)
                ver[i][j] = isVert(f[i][j]) && isVert(f[i + 1][j]);
        
//      System.err.println(Arrays.deepToString(f));
//      
//      System.err.println(Arrays.deepToString(hor));
//      System.err.println(Arrays.deepToString(ver));

        
        int[] twoCols = new int[m - 1];
        int[] oneCol = new int[m];
        
        if (n % 2 == 0) {
            for (int i = 0; i < m; i++) {
                oneCol[i] = 1;
                for (int j = 0; j < n; j += 2)
                    if (!ver[j][i]) {
                        oneCol[i] = 0;
                        break;
                    }
            }
        }
        
        for (int i = 0; i < m - 1; i++) {
            int[] ways = new int[n + 1];
            ways[0] = 1;
            for (int j = 0; j < n; j++) {
                if (hor[j][i]) {
                    ways[j + 1] += ways[j];
                    if (ways[j + 1] >= MOD)
                        ways[j + 1] -= MOD;
                }
                if (j != n - 1 && ver[j][i] && ver[j][i + 1]) {
                    ways[j + 2] += ways[j];
                    if (ways[j + 2] >= MOD)
                        ways[j + 2] -= MOD;
                }
            }
            twoCols[i] = ways[n] - oneCol[i] * oneCol[i + 1];
        }
        
        //System.err.println(Arrays.toString(twoCols));
        
        int[] ways = new int[m + 1];
        ways[0] = 1;
        for (int i = 0; i < m; i++) {
            ways[i + 1] += (long)ways[i] * oneCol[i] % MOD;
            if (ways[i + 1] >= MOD)
                ways[i + 1] -= MOD;
            if (i != m - 1) {
                ways[i + 2] += (long)ways[i] * twoCols[i] % MOD;
                if (ways[i + 2] >= MOD)
                    ways[i + 2] -= MOD;
            }
        }
        
        out.print(ways[m]);

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