import java.io.*;
import java.util.*;

public class C {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    class Subject implements Comparable<Subject> {
        long low;
        long high;

        int diff;
        int num;

        public Subject(long low, long high, int diff, int num) {
            this.low = low;
            this.high = high;
            this.diff = diff;
            this.num = num;
        }

        @Override
        public int compareTo(Subject o) {
            return diff - o.diff;
        }
    }

    int n, m, par;
    Subject[] subj;
    long[][][] dp;

    void getAns(int i, int j, int k) {

        // System.err.println(i + " " + j + " " + k);

        if (dp[i][j][k] == -1)
            throw new AssertionError();

        if (j == 0) {
            out.println(subj[i].num + " " + (subj[i].low + k));
            return;
        }
        long realCnt = subj[i].low + k;
        for (int prev = 0; prev < i; prev++)
            if (subj[prev].diff < subj[i].diff) {
                long prevCnt = realCnt - par;
                if (subj[prev].low <= prevCnt && prevCnt <= subj[prev].high) {
                    if (dp[prev][j - 1][(int) (prevCnt - subj[prev].low)] == dp[i][j][k]
                            - realCnt) {
                        getAns(prev, j - 1, (int) (prevCnt - subj[prev].low));
                        out.println(subj[i].num + " " + (subj[i].low + k));
                        return;
                    }
                }
                if (realCnt % par == 0) {
                    prevCnt = realCnt / par;
                    if (subj[prev].low <= prevCnt && prevCnt <= subj[prev].high) {
                        if (dp[prev][j - 1][(int) (prevCnt - subj[prev].low)] == dp[i][j][k]
                                - realCnt) {
                            getAns(prev, j - 1,
                                    (int) (prevCnt - subj[prev].low));
                            out.println(subj[i].num + " " + (subj[i].low + k));
                            return;
                        }
                    }
                }
            }
    }

    void solve() throws IOException {
        n = nextInt();
        m = nextInt();
        par = nextInt();

        subj = new Subject[m];
        for (int i = 0; i < m; i++)
            subj[i] = new Subject(nextLong(), nextLong(), nextInt(), i + 1);

        Arrays.sort(subj);
        dp = new long[m][n][];
        for (int i = 0; i < m; i++) {
            int len = (int) (subj[i].high - subj[i].low);
            for (int j = 0; j < n; j++) {
                dp[i][j] = new long[len + 1];
                if (j == 0) {
                    for (int k = 0; k <= len; k++)
                        dp[i][j][k] = subj[i].low + k;
                } else {
                    for (int k = 0; k <= len; k++) {
                        // calc dp[i][j][k]
                        dp[i][j][k] = -1;
                        for (int prev = 0; prev < i; prev++) {
                            if (subj[prev].diff == subj[i].diff)
                                break;
                            long realCnt = subj[i].low + k;
                            long prevCnt = realCnt - par;
                            if (subj[prev].low <= prevCnt
                                    && prevCnt <= subj[prev].high
                                    && dp[prev][j - 1][(int) (prevCnt - subj[prev].low)] != -1)
                                dp[i][j][k] = Math
                                        .max(dp[i][j][k],
                                                realCnt
                                                        + dp[prev][j - 1][(int) (prevCnt - subj[prev].low)]);
                            if (realCnt % par == 0) {
                                prevCnt = realCnt / par;
                                if (subj[prev].low <= prevCnt
                                        && prevCnt <= subj[prev].high
                                        && dp[prev][j - 1][(int) (prevCnt - subj[prev].low)] != -1)
                                    dp[i][j][k] = Math
                                            .max(dp[i][j][k],
                                                    realCnt
                                                            + dp[prev][j - 1][(int) (prevCnt - subj[prev].low)]);
                            }
                        }
                    }
                }
            }
        }
        long best = -1;
        int bestI = -1;
        int bestK = -1;

        for (int i = 0; i < m; i++)
            for (int k = 0; k < dp[i][n - 1].length; k++)
                if (dp[i][n - 1][k] > best) {
                    //System.err.println(i + " " + k + " " + dp[i][n - 1][k]);
                    best = dp[i][n - 1][k];
                    bestI = i;
                    bestK = k;
                }

        if (best != -1) {
            out.println("YES");
            getAns(bestI, n - 1, bestK);
        } else
            out.println("NO");
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