import java.io.*;
import java.util.*;

public class A {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    long min, max;

    void go(int a, int rest) {
        //System.err.println(a + " " + rest);
        max = Math.max(max, 3L * a * (rest + 2));
        int fr = (int) Math.sqrt(1.0 * rest);
        for (int i = fr; i >= 1; i--)
            if (rest % i == 0) {
                min = Math.min(min, (long) a * (i + 2) * (rest / i + 2));
                break;
            }
    }

    void solve() throws IOException {
        int n = nextInt();

        min = Long.MAX_VALUE;
        max = Long.MIN_VALUE;

        for (int a = 1; a * a <= n; a++)
            if (n % a == 0) {
                go(a + 1, n / a);
                go(n / a + 1, a);
            }

        out.print((min - n) + " " + (max - n));
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