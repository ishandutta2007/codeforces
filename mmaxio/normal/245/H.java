import java.io.*;
import java.util.*;

public class H {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    void solve() throws IOException {
        char[] s = nextToken().toCharArray();
        int n = s.length;
        int[][] a = new int[n + 1][n + 1];
        for (int i = 0; i < n; i++) {
            a[i + 1][i + 1] = 1;
        }
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1])
                a[i + 1][i + 2] = 1;
        }
        for (int len = 3; len <= n; len++)
            for (int st = 0; st <= n - len; st++) {
                int en = st + len - 1;
                if (s[st] == s[en] && a[st + 1 + 1][en - 1 + 1] == 1)
                    a[st + 1][en + 1] = 1;
            }
        
//      System.err.println();
//      for (int i = 0; i <= n; i++)
//          System.err.println(Arrays.toString(a[i]));
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                a[i + 1][j + 1] += a[i + 1][j] + a[i][j + 1] - a[i][j];
        
//      System.err.println();
//      for (int i = 0; i <= n; i++)
//          System.err.println(Arrays.toString(a[i]));
        
        int q = nextInt();
        while (q-- > 0) {
            int l = nextInt() - 1;
            int r = nextInt() - 1;
            int res = a[r + 1][r + 1] - a[r + 1][l] - a[l][r + 1] + a[l][l];
            out.println(res);
        }
    }

    H() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new H();
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