import java.io.*;
import java.util.*;

public class obsessivestring {
  private static Scanner in;
  private static PrintWriter out;
  public static int mod = 1000000007;
  
  public static int[] zAlgorithm(char[] let) {
    int N = let.length;
    int[] z = new int[N];
    int L = 0, R = 0;
    for (int i = 1; i < N; i++) {
      if (i > R) {
        L = R = i;
        while (R < N && let[R-L] == let[R]) R++;
        z[i] = R-L; R--;
      } else {
        int k = i-L;
        if (z[k] < R-i+1) z[i] = z[k];
        else {
          L = i;
          while (R < N && let[R-L] == let[R]) R++;
          z[i] = R-L; R--;
        }
      }
    }
    z[0] = N;
    return z;
  }

  public static void main(String[] args) throws IOException {
    in = new Scanner(System.in);
    out = new PrintWriter(System.out, true);
    
    String a = ("$"+in.nextLine()), b = in.nextLine();
    char[] let = (b + "#" + a).toCharArray();
    int[] ret = zAlgorithm(let);
    int N = a.length();
    int M = b.length();
    long[] dp = new long[N];
    long[] sum = new long[N];
    long[] sum2 = new long[N];
    dp[0] = 1;
    for (int i = 0; i < N; i++) {
      sum[i] = 1;
      sum2[i] = i+1;
    }
    int pr = 0;
    while (pr < N && ret[pr + M + 1] != M) pr++;
    for (int i = pr + M - 1; i < N; i++) {
      if (ret[i + 2] == M) pr = i - M + 1;
      dp[i] = sum2[pr-1];
      sum[i] = (sum[i-1] + dp[i]) % mod;
      sum2[i] = (sum2[i-1] + sum[i]) % mod;
    }
    out.println((sum[N-1]+mod-1)%mod);
    out.close();
    System.exit(0);
  }
}