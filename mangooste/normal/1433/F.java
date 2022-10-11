import java.util.Scanner;

public class a {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt(), k = sc.nextInt();
        int[][] a = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = sc.nextInt();
            }
        }

        int[] dp = new int[k];
        for (int i = 0; i < k; i++) {
            dp[i] = Integer.MIN_VALUE;
        }
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            int cnt = m / 2 + 1;
            int[][] curDp = new int[cnt][k];
            for (int ii = 0; ii < cnt; ii++) {
                for (int jj = 0; jj < k; jj++) {
                    curDp[ii][jj] = Integer.MIN_VALUE;
                }
            }
            curDp[0][0] = 0;

            for (int j = 0; j < m; j++) {
                for (int curCnt = Math.min(j + 1, cnt - 1); curCnt > 0; curCnt--) {
                    for (int ost = 0; ost < k; ost++) {
                        int curOst = (ost - a[i][j] % k + k) % k;
                        if (curDp[curCnt - 1][curOst] == Integer.MIN_VALUE) continue;
                        curDp[curCnt][ost] = Math.max(curDp[curCnt][ost], curDp[curCnt - 1][curOst] + a[i][j]);
                    }
                }
            }

            int[] valid = new int[k];
            for (int j = 0; j < k; j++) {
                valid[j] = Integer.MIN_VALUE;
            }
            for (int curCnt = 0; curCnt < cnt; curCnt++) {
                for (int ost = 0; ost < k; ost++) {
                    if (curDp[curCnt][ost] == Integer.MIN_VALUE) continue;
                    valid[ost] = Math.max(valid[ost], curDp[curCnt][ost]);
                }
            }

            int[] ndp = new int[k];
            for (int j = 0; j < k; j++) {
                ndp[j] = Integer.MIN_VALUE;
            }
            for (int ost = 0; ost < k; ost++) {
                if (valid[ost] == Integer.MIN_VALUE) continue;
                for (int prev = 0; prev < k; prev++) {
                    if (dp[prev] == Integer.MIN_VALUE) continue;
                    ndp[(prev + ost) % k] = Math.max(ndp[(prev + ost) % k], dp[prev] + valid[ost]);
                }
            }
            dp = ndp;
        }
        System.out.println(dp[0]);
    }
}