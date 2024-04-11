import java.io.*;
import java.util.*;

public class B {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    Set<Integer> bad = new HashSet<>();

    void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();

        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }

        for (int i = 0; i < m; i++) {
            int b = nextInt();
            bad.add(b);
        }

        int[] g = new int[n];
        g[0] = a[0];
        for (int i = 1; i < n; i++) {
            g[i] = gcd(g[i - 1], a[i]);
        }
        
        int init = 0;
        for (int i = 0; i < n; i++) {
            init += score(a[i]);
        }
        
        int alrDiv = 1;
        
        for (int i = n - 1; i >= 0; i--) {
            int val = g[i] / alrDiv;
            int sc = score(val);
            if (sc < 0) {
                init -= sc * (i + 1);
                alrDiv *= val;
            }
        }
        
        out.println(init);

    }

    int score(int x) {
        int ret = 0;
        for (int i = 2; i <= 2; i++) {
            int delta;
            if (x % i == 0) {
                delta = bad.contains(i) ? -1 : 1;
            } else {
                continue;
            }
            while (x % i == 0) {
                ret += delta;
                x /= i;
            }
        }
        for (int i = 3; i * i <= x; i += 2) {
            int delta;
            if (x % i == 0) {
                delta = bad.contains(i) ? -1 : 1;
            } else {
                continue;
            }
            while (x % i == 0) {
                ret += delta;
                x /= i;
            }
        }
        if (x != 1) {
            if (bad.contains(x)) {
                ret--;
            } else {
                ret++;
            }
        }

        return ret;
    }

    static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    B() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new B();
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