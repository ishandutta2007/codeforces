import java.io.*;
import java.util.*;

public class progressmonitor {
  private static InputReader in;
  private static PrintWriter out;
  public static int mod = 1000000007;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int N = in.nextInt();
    arr = new int[N];
    for (int i = 0; i < N; i++) arr[i] = in.nextInt();
    if (arr[0] != 1) {
      out.println(0);
    } else {
      dp = new long[N+1][N+1];
      for (int i = 0; i <= N; i++) Arrays.fill(dp[i], -1);
      out.println(dfs1(1, N-1));
    }
    out.close();
    System.exit(0);
  }
  
  public static int[] arr;
  public static long[][] dp;
  public static long dfs1(int s, int e) {
    if (s > e) return 1;
    if (dp[s][e] != -1) return dp[s][e];
    long res = dfs1(s+1, e);
    for (int split = s+1; split <= e; split++) {
      if (arr[split] > arr[s]) {
        res = (res + dfs1(s+1, split-1) * dfs1(split, e)) % mod;
      }
    }
    return dp[s][e] = res;
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