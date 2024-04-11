import java.io.*;
import java.util.*;

public class B {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int k = nextInt();
        int a[] = new int[m];
        int b[] = new int[m];
        int c[] = new int[m];
        
        for (int i = 0; i < m; i++) {
            a[i] = nextInt();
            b[i] = nextInt();
            c[i] = nextInt();
        }
        
        long res = 0;
        
        for (int i = 0; i < k; i++) {
            int q = nextInt();
            for (int j = 0; j < m; j++)
                if (q >= a[j] && q <= b[j]) {
                    res += c[j] + (q - a[j]);
                }
        }
        
        out.print(res);
    }

    void inp() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new B().inp();
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