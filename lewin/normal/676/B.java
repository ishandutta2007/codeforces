import java.io.*;
import java.util.*;

public class pouringwine {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    
    int n = in.nextInt(), t = in.nextInt();
    if (t == 0) {
      out.println(0);
      out.close();
      System.exit(0);
    }
    double[][] dp = new double[n][];
    dp[0] = new double[1];
    dp[0][0] = t;
    int count = 0;
    for (int i = 0; i < n; i++) {
      if (i+1 < n) dp[i+1] = new double[i+2];
      for (int j = 0; j <= i; j++) {
        if (dp[i][j] >= 1) {
          dp[i][j] -= 1;
          count++;
        } else {
          continue;
        }
        if (i+1 < n) {
          dp[i+1][j] += dp[i][j]/2;
          dp[i+1][j+1] += dp[i][j]/2;
        }
      }
    }
    out.println(count);
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