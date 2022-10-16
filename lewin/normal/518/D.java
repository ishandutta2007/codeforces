import java.io.*;
import java.util.*;

public class ilyaescalator {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    
    int N = in.nextInt();
    P = Double.parseDouble(in.next());
    int T = in.nextInt();
    
    dp = new double[N+1][T+1];
    for (double[] x : dp) Arrays.fill(x, -1);
    
    out.printf("%.10f\n", exp(N,T));
    out.close();
    System.exit(0);
  }
  
  public static double P;
  public static double[][] dp;
  public static double exp(int N, int T) {
    if (N == 0) return 0;
    if (T == 0) return 0;
    if (dp[N][T] != -1) return dp[N][T];
    return dp[N][T] = (1-P)*exp(N,T-1) + P*(1+exp(N-1,T-1));
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