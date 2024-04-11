import java.io.*;
import java.util.*;

public class B {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    static final int M = 1_000_001;

    void solve() throws IOException {
        int n = nextInt();
        Random rng = new Random();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            int j = rng.nextInt(i + 1);
            a[i] = a[j];
            a[j] = nextInt();
        }
        Arrays.sort(a);

        int n2 = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] != a[n2 - 1]) {
                a[n2++] = a[i];
            }
        }
        a = Arrays.copyOf(a, n2);
        n = n2;
        int[] big = new int[M];
        big[0] = -1;
        for (int i = 1, j = 0; i < M; i++) {
            if (j < n && i == a[j]) {
                big[i] = i;
                j++;
            } else {
                big[i] = big[i - 1];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x = a[i];
            for (int k = 2 * x - 1; k < M; k += x) {
                int y = big[k];
                if (y > k - x) {
                    ans = Math.max(ans, y - (k - x + 1));
                }
            }
            // last
            if (big[M - 1] >= x) {
                ans = Math.max(ans, big[M - 1] % x);
            }
        }
        out.println(ans);
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