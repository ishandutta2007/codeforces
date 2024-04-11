import java.io.*;
import java.util.*;

public class xoreq {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);

    s = Long.parseLong(in.next());
    x = Long.parseLong(in.next());
    
    dp = new long[60][2];
    for (long[] x : dp) Arrays.fill(x, -1);
    long ans = dfs(59, 0);
    if (s == x) ans -= 2;
    out.println(ans);
    
    out.close();
    System.exit(0);
  }
  
  public static long s,x;
  public static long[][] dp;
  public static long dfs(int bit, int needcarry) {
    if (bit < 0) return needcarry == 0 ? 1 : 0;
    if (dp[bit][needcarry] != -1) return dp[bit][needcarry];
    long xb = (x>>bit)&1, sb = (s>>bit)&1;
    long ret = 0;
    for (int i = 0; i <= 1; i++) {
      for (int j = 0; j <= 1; j++) {
        for (int k = 0; k <= 1; k++) {
          if ((i+j+k)%2 == sb && (i^j) == xb && (i+j+k)/2 == needcarry) {
            ret += dfs(bit-1, k);
          }
        }
      }
    }
    return dp[bit][needcarry] = ret;
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