import java.io.*;
import java.util.*;

public class C {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();

        if (m == 1) {
            out.println(1);
            return;
        }

        double[] dp = new double[1];
        dp[0] = 1;

        int ourSum = 0;

        for (int i = 0; i < n; i++) {
            int we = nextInt() - 1;
            ourSum += we;

            double[] next = new double[dp.length + (m - 1)];
            double sumPrev = 0;
            for (int j = 0; j < next.length; j++) {
                if (j < dp.length) {
                    sumPrev += dp[j];
                }
                if (j >= m && j - m < dp.length) {
                    sumPrev -= dp[j - m];
                }
                double sum = sumPrev;
                if (j >= we && j - we < dp.length) {
                    sum -= dp[j - we];
                }
                next[j] = sum / (m - 1);
            }

            dp = next;
        }

        double ret = 0;
        for (int i = 0; i < ourSum; i++) {
            ret += dp[i];
        }

        out.println(1 + ret * (m - 1));
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