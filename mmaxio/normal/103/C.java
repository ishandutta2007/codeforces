import java.io.*;
import java.util.*;

public class C {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    void solve() throws IOException {
        long n = nextLong();
        long k = nextLong();
        
        long oldN = n;
        
        if (k == 0) {
            int q = nextInt();
            for (int i = 0; i < q; i++)
                out.print('.');
            return;
        }
        
        if (k == 1) {
            int q = nextInt();
            for (int i = 0; i < q; i++) {
                long x = nextLong();
                out.print(x == n ? 'X' : '.');
            }
            return;
        }
        
        n -= k;
        
        if (n <= k) {
            int q = nextInt();
            for (int i = 0; i < q; i++) {
                long x = nextLong() - 1;
                if (x < 2 * n)
                    out.print(x % 2 == 0 ? '.' : 'X');
                else
                    out.print('X');
            }
            return;
        }
        
        if ((n - k) % 2 == 0) {
            long first = n - (k - 1);
            int q = nextInt();
            for (int i = 0; i < q; i++) {
                long x = nextLong() - 1;
                if (x <= first)
                    out.print(x == first ? 'X' : '.');
                else
                    out.print((x - first + 1) % 2 == 0 ? '.' : 'X');
            }
            return;
        }
        
        long first = n - (k - 2);
        int q = nextInt();
        for (int i = 0; i < q; i++) {
            long x = nextLong() - 1;
            if (x <= first)
                out.print(x == first ? 'X' : '.');
            else if (x == oldN - 1)
                out.print('X');
            else
                out.print((x - first + 1) % 2 == 0 ? '.' : 'X');
        }
        
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