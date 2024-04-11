import java.io.*;
import java.util.*;

public class writingcode {
  private static InputReader in;
  private static PrintWriter out;
  public static int N, M, b, mod, a[];

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    
    N = in.nextInt();
    M = in.nextInt();
    b = in.nextInt();
    mod = in.nextInt();
    a = new int[N];
    for (int i = 0; i < N; i++) {
      a[i] = in.nextInt();
    }
    
    long[][] dp = new long[M+1][b+1];
    Arrays.fill(dp[0], 1);
    for (int i = N-1; i >= 0; i--) {
      long[][] next = new long[M+1][b+1];
      Arrays.fill(next[0], 1);
      for (int k = 1; k <= M; k++) {
        for (int j = 0; j <= b; j++) {
          next[k][j] = dp[k][j];
          if (a[i] <= j) next[k][j] = (next[k][j] + next[k-1][j-a[i]]) % mod;
        }
      }
      dp = next;
    }

    out.println(dp[M][b]);
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