import java.io.*;
import java.util.*;

public class D {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    void solve() throws IOException {
        int n = nextInt();
        int k = nextInt();
        ArrayList<Integer>[] g = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<Integer>();
        }

        for (int i = 0; i < n - 1; i++) {
            int v1 = nextInt() - 1;
            int v2 = nextInt() - 1;
            g[v1].add(v2);
            g[v2].add(v1);
        }

        int[] dp0 = new int[n];
        int[] dp1 = new int[n];
        for (int i = 0; i < n; i++) {
            dp0[i] = 1;
            dp1[i] = g[i].size();
        }

        for (int j = 2; j <= k; j++) {
            int[] dp2 = new int[n];
            for (int i = 0; i < n; i++) {
                long res = 0;
                for (int to : g[i])
                    res = res + dp1[to];
                if (j == 2)
                    res -= (long) dp0[i] * g[i].size();
                else
                    res -= (long) dp0[i] * (g[i].size() - 1);
                dp2[i] = (int) res;
            }
            dp0 = dp1;
            dp1 = dp2;
        }
        
        long ans = 0;
        for (int x : dp1)
            ans = ans + x;
        out.println(ans / 2);
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