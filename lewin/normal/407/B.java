import java.io.*;
import java.util.*;

public class longpat {
  private static InputReader in;
  private static PrintWriter out;
  public static int mod = 1000000007;

  public static int N;
  public static int[] par;
  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    N = in.nextInt();
    par = new int[N];
    for (int i = 0; i < N; i++) par[i] = in.nextInt()-1;
    
    dp = new long[N][N];
    for (long[] x : dp) Arrays.fill(x, -1);
    out.println(count(0,N-1));
    out.close();
    System.exit(0);
  }
  
  public static long[][] dp;
  public static long count (int from, int to) {
    if (from > to) return 0;
    if (dp[from][to] != -1) return dp[from][to];
    return dp[from][to] = (count(par[from], from-1) + count(from+1, to) + 2) % mod;
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