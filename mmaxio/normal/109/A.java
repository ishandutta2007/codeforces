import java.io.*;
import java.util.*;

public class A {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;
    
    final int INF = Integer.MAX_VALUE / 2;

    void solve() throws IOException {
        int n = nextInt();
        
        int bestLength = INF;
        int best4 = INF;
        int best7 = INF;
        
        for (int s4 = 0; s4 * 4 <= n; s4++) {
            if ((n - s4 * 4) % 7 != 0)
                continue;
            int s7 = (n - s4 * 4) / 7;
            if (s4 + s7 < bestLength) {
                bestLength = s4 + s7;
                best4 = s4;
                best7 = s7;
            }
            
        }
        
        if (bestLength == INF)
            out.println(-1);
        else {
            for (int i = 0; i < best4; i++)
                out.print(4);
            for (int i = 0; i < best7; i++)
                out.print(7);
        }
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