import java.io.*;
import java.util.*;

public class alternativethinking {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);

    int n = in.nextInt();
    char[] c = in.next().toCharArray();
    
    int[][] dp = new int[3][2];
    for (int i = 0; i < n; i++) {
      int k = c[i] - '0';
      int[][] next = new int[3][2];
      next[0][k] = Math.max(dp[0][k], dp[0][1-k]+1);
      next[1][k] = Math.max(dp[1][k], Math.max(dp[1][1-k]+1,dp[0][k]+1));
      next[2][k] = Math.max(dp[2][k], Math.max(dp[2][1-k]+1,dp[1][k]+1));
      dp = next;
    }
    
    int max = 0;
    for (int i = 0; i < 3; i++) max = Math.max(max, Math.max(dp[i][0],dp[i][1]));
    
    out.println(max);
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