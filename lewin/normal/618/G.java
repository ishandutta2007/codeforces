import java.io.*;
import java.util.*;
public class SlimeCombiningLinear {
  private static InputReader in;
  private static PrintWriter out;
  public static double EPS = 1e-15;
  public static int maxp = 50;
  
  public static void main (String[] args) {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    
    int n = in.nextInt();
    int p = in.nextInt();
    
    double p2 = p / 1000000000., p4 = 1 - p2;
    double[][] a = new double[maxp][maxp];
    double[][] b = new double[maxp][maxp];
    for (int len = 1; len < maxp; len++) { 
      for (int pow = 1; pow < maxp; pow++) {
        if (pow == 1) a[len][pow] += p2;
        if (pow == 2) {
          a[len][pow] += p4;
          b[len][pow] += p4;
        }
        a[len][pow] += a[len-1][pow-1] * a[len][pow-1];
        b[len][pow] += a[len-1][pow-1] * b[len][pow-1];
      }
    }
    for (int len = maxp - 1; len >= 1; len--) {
      for (int pow = 1; pow < maxp; pow++) {
        a[len][pow] *= 1 - a[len-1][pow];
        b[len][pow] *= 1 - a[len-1][pow];
      }
    }
    
    // value of a slime that has been merged i times
    long[] vals = new long[maxp];
    for (int i = 0; i < maxp; i++) vals[i] = i;//1l << i;
    // manually do first few cases
    int maxn = 1000;
    double[][] dp = new double[maxn][maxp];
    double[][] sum = new double[maxn][maxp];
    for (int cur = 1; cur < maxp; cur++)
      dp[maxn-1][cur] = vals[cur];
    
    // manual dp
    for (int i = maxn-2; i >= 0; i--) {
      for (int cur = 1; cur < maxp; cur++) {
        for (int next = 1; next < maxp; next++) {
          if (cur == next) continue;
          if (cur == 1) {
            int id = Math.min(maxp-1, maxn-i-1);
            dp[i][cur] += b[id][next] * dp[i+1][next];
            sum[i][cur] += b[id][next];
          } else {
            if (cur < next) continue;
            int id = Math.min(maxp-1, maxn-i-1);
            dp[i][cur] += a[id][next] * dp[i+1][next];
            sum[i][cur] += a[id][next];
          }
        }
      }
      for (int cur = 1; cur < maxp; cur++) {
        dp[i][cur] = vals[cur] + dp[i][cur] / sum[i][cur];
      }
    }
    if (n <= maxn) {
      int k = (int)n;
      int w = Math.min(maxp-1, k);
      double exp = 0;
      for (int i = 1; i < maxp; i++) {
        exp += a[w][i] * dp[maxn-k][i];
      }
      out.printf("%.15f\n", exp);
      out.close();
      System.exit(0);
    }

    double exp1 = 0;
    double exp2 = 0;
    for (int i = 1; i < maxp; i++) {
      exp1 += a[maxp-1][i] * dp[0][i];
      exp2 += a[maxp-1][i] * dp[1][i];
    }
    out.printf("%.15f\n", exp2 + (exp1 - exp2) * (long)(n - maxn + 1));
    out.close();
    System.exit(0);
  }
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