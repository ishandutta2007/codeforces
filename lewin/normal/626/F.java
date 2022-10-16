import java.io.*;
import java.util.*;

public class groupprojects {
  private static InputReader in;
  private static PrintWriter out;
  public static int mod = 1000000007;
  public static int n,k;
  public static int[] a;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    
    n = in.nextInt();
    k = in.nextInt();
    a = new int[n+1];
    for (int i = 1; i <= n; i++) a[i] = in.nextInt();
    Arrays.sort(a);
    dp = new long[2][n+2][k+2];
    dp[0][0][0] = 1;
    int cur = 0;
    for (int st = 1; st <= n; st++) {
      cur = cur ^ 1;
      for (int i = 0; i <= n; i++) {
        Arrays.fill(dp[cur][i], 0);
        for (int j = 0; j <= k; j++) {
          long ret = 0;
          int nx = j-(i-1)*(a[st]-a[st-1]);
          if (i > 0 && nx >= 0) ret = (ret + dp[cur^1][i-1][nx]) % mod;
          nx = j-(i+1)*(a[st]-a[st-1]);
          if (i+1 <= n && nx >= 0) ret = (ret + dp[cur^1][i+1][nx] * (i+1)) % mod;
          nx = j-i*(a[st]-a[st-1]);
          if (nx >= 0) ret = (ret + dp[cur^1][i][nx] * (i+1)) % mod;
          dp[cur][i][j] = ret;
        }
      }
    }
    long ret = 0;
    for (int i = 0; i <= k; i++) ret = (ret + dp[cur][0][i]) % mod;
    out.println(ret);
    out.close();
    System.exit(0);
  }
  
  public static long[][][] dp;

  static class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
      reader = new BufferedReader(new InputStreamReader(stream), 32768);
      tokenizer = null;
    }

    public String next() {
      while (tokenizer == null || !tokenizer.hasMoreTokens()) {
        try {
          tokenizer = new StringTokenizer(reader.readLine());
        } catch (IOException e) {
          throw new RuntimeException(e);
        }
      }
      return tokenizer.nextToken();
    }

    public int nextInt() {
      return Integer.parseInt(next());
    }
  }


}