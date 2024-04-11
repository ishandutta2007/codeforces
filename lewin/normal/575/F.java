import java.io.*;
import java.util.*;

public class bulbo {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int n = in.nextInt();
    int x = in.nextInt();
    int[] all = new int[2*n+1];
    all[2*n] = x;
    int[] start = new int[n], end = new int[n];
    for (int i = 0; i < n; i++) {
      start[i] = in.nextInt();
      end[i] = in.nextInt();
      all[2*i] = start[i];
      all[2*i+1] = end[i];
    }
    Arrays.sort(all);
    x = Arrays.binarySearch(all, x);
    for (int i = 0; i < n; i++) {
      start[i] = Arrays.binarySearch(all, start[i]);
      end[i] = Arrays.binarySearch(all, end[i]);
    }
    
    long[][] dp = new long[2][2*n+1];
    long[] left = new long[2*n+1];
    long[] right = new long[2*n+1];
    Arrays.fill(dp[0], 1l << 60);
    dp[0][x] = 0;
    
    for (int i = 0; i < n; i++) {
      int cur = (i&1), next = 1-cur;
      left[0] = dp[cur][0];
      for (int j = 1; j <= 2*n; j++) left[j] = Math.min(dp[cur][j], all[j] - all[j-1] + left[j-1]);
      right[2*n] = dp[cur][2*n];
      for (int j = 2*n-1; j >= 0; j--) right[j] = Math.min(dp[cur][j], all[j+1] - all[j] + right[j+1]);
      
      for (int j = 0; j <= 2*n; j++) {
        dp[next][j] = Math.min(left[j], right[j]);
        if (j < start[i]) dp[next][j] += all[start[i]] - all[j];
        else if (j > end[i]) dp[next][j] += all[j] - all[end[i]];
      }
    }
    
    long best = 1l << 60;
    for (int i = 0; i <= 2*n; i++) {
      best = Math.min(best, dp[n&1][i]);
    }
    out.println(best);
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