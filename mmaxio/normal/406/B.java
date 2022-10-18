import java.io.*;
import java.util.*;

public class B {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    static final int S = 1_000_000;

    void solve() throws IOException {
        int n = nextInt();
        boolean[] take = new boolean[S];

        for (int i = 0; i < n; i++) {
            int x = nextInt() - 1;
            take[x] = true;
        }

        int need = 0;
        out.println(n);
        for (int i = 0; i < S / 2; i++) {
            if (take[i] ^ take[S - 1 - i]) {
                out.print(((take[i] ? S - 1 - i : i) + 1) + " ");
            }
            if (take[i] && take[S - 1 - i]) {
                need++;
            }
        }

        for (int i = 0; i < S / 2 && need > 0; i++) {
            if (!take[i] && !take[S - 1 - i]) {
                out.print((i + 1) + " " + (S - i) + " ");
                need--;
            }
        }

        out.println();

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