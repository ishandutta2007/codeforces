import java.io.*;
import java.util.*;

public class specialmatrix {
  private static Scanner in;
  private static PrintWriter out;
  public static int mod;

  public static void main(String[] args) throws IOException {
    in = new Scanner(System.in);
    out = new PrintWriter(System.out, true);
    int N = in.nextInt(), M = in.nextInt();
    mod = in.nextInt();
    int[] b = new int[N];
    for (int i = 0; i < M; i++) {
      char[] s = in.next().toCharArray();
      for (int j = 0; j < N; j++)
        if (s[j] == '1') b[j]++;
    }
    int one = 0, two = 0;
    for (int i = 0; i < N; i++) {
      if (b[i] == 1) one++;
      if (b[i] == 0) two++;
    }
    dp = new long[one+two+1][two+1];
    for (int i = 0; i <= one+two; i++) Arrays.fill(dp[i], -1);
    out.println(res(one, two));
    out.close();
    System.exit(0);
  }
  public static long[][] dp;
  public static long res(int one, int two) {
    if (one == 0 && two == 0) return 1;
    if (dp[one][two] != -1) return dp[one][two];
    long ans = 0;
    if (two >= 2)             ans = (ans + (two*(two-1)/2)%mod*res(one+2,two-2)) % mod;
    if (two >= 1 && one >= 1) ans = (ans + (two*one)%mod*res(one,two-1))%mod;
    if (one >= 2)             ans = (ans + (one*(one-1)/2)%mod*res(one-2,two)) % mod;
    return dp[one][two] = ans;
  }
}