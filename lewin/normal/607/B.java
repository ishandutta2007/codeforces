import java.io.*;
import java.util.*;

public class zuma {
  private static InputReader in;
  private static PrintWriter out;
  public static int n;
  public static int[][] dp;
  public static int[] arr;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);

    n = in.nextInt();
    arr = new int[n];
    for (int i = 0; i < n; i++) arr[i] = in.nextInt();
    dp = new int[n][n];
    for (int[] x : dp) Arrays.fill(x, -1);
    out.println(1+solve(0,n-1));
    out.close();
    System.exit(0);
  }
  
  public static int solve(int l, int r) {
    if (r <= l) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    int ret = 1+solve(l+1,r);
    for (int next = l+1; next <= r; next++) {
      if (arr[l] == arr[next]) {
        int add = next+1 <= r ? 1 : 0;
        ret = Math.min(ret, solve(l+1,next-1)+solve(next+1,r)+add);
      }
    }
    return dp[l][r] = ret;
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