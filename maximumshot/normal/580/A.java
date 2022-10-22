import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

public class Max {



    public static boolean solve() {

        Scanner in = new Scanner(System.in);

        int n = in.nextInt();

        int[] a = new int [n];

        for(int i = 0;i < n;i++) {
            a[i] = in.nextInt();
        }

        int[] dp = new int [n];

        dp[0] = 1;

        for(int i = 1;i < n;i++) {
            dp[i] = 1;
            if(a[i - 1] <= a[i]) dp[i] = dp[i - 1] + 1;
        }

        int ans = 0;

        for(int i = 0;i < n;i++) ans = Math.max(ans, dp[i]);

        System.out.println(ans);

        return true;
    }

    public static void main(String[] args) {
        //while(solve());
        solve();
    }

}