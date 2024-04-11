import java.io.*;
import java.util.*;

public class C {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    void solve() throws IOException {
        int n = nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }
        
        int init = 0;
        
        int[][] inv = new int[n][n + 1];
        for (int i = 0; i < n; i++) {
            int[] cache = inv[i];
            for (int j = 0; j < n; j++) {
                if ((j > i) ^ (a[j] > a[i])) {
                    init++;
                    cache[j + 1] = cache[j] + 1;
                } else {
                    cache[j + 1] = cache[j];
                }
            }
        }
        
        init /= 2;
        
        int best = 0;
        int bestCnt = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int cur = (a[i] > a[j] ? 1 : -1);
                int val = inv[i][j] - inv[i][i + 1];
                cur += 2 * val - (j - i - 1);
                
                
                
                val = inv[j][j] - inv[j][i + 1];
                cur += 2 * val - (j - i - 1);
                if (cur > best) {
                    best = cur;
                    bestCnt = 1;
                } else if (cur == best) {
                    bestCnt++;
                }
            }
        }
        
        out.println(init - best + " " + bestCnt);
    }

    C() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new C();
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