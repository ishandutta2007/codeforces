import java.io.*;
import java.util.*;

public class B {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    double solve2(int a, int b) {
        if (a == 0 && b == 0)
            return 1;
        else if (a == 0 && b != 0)
            return 0.5;
        else if (a != 0 && b == 0)
            return 1;
        b *= 4;
        double sq = 2.0 * a * b;
        if (a >= b) {
            return 1 - 0.5 * b * b / sq;
        } else
            return 0.5 + 0.5 * a * a / sq;
    }

    void solve() throws IOException {
        int tests = nextInt();
        for (int i = 0; i < tests; i++)
            out.printf("%.9f\n", solve2(nextInt(), nextInt()));
    }

    void inp() throws IOException {
        Locale.setDefault(Locale.US);
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