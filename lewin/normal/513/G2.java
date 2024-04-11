import java.io.*;
import java.util.*;

public class inversionproblem {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    
    N = in.nextInt();
    K = in.nextInt();
    int[] arr = new int[N];
    for (int i = 0; i < N; i++) arr[i] = in.nextInt();
    dp = new double[N][N][K+1];
    for (double[][] x : dp) for (double[] y : x) Arrays.fill(y, -1);
    double res = 0;
    for (int i = 0; i < N; i++) {
      for (int j = i+1; j < N; j++) {
        double q = getProb(i, j, K);
        if (arr[i] < arr[j]) res += 1 - q;
        else res += q;
      }
    }
    out.printf("%.15f\n", res);
    out.close();
    System.exit(0);
  }
  
  public static int N, K;
  public static double[][][] dp;
  public static double getProb(int i, int j, int left) {
    if (left == 0) return i < j ? 1 : 0;
    if (dp[i][j][left] != -1) return dp[i][j][left];
    double tot = N * (N - 1) / 2. + N;
    double res = 0;
    for (int l = 0; l < N; l++) {
      for (int r = l; r < N; r++) {
        int ni = i, nj = j;
        if (l <= ni && ni <= r) {
          ni = r - (ni - l);
        }
        if (l <= nj && nj <= r) {
          nj = r - (nj - l);
        }
        res += getProb(ni, nj, left-1) / tot;
      }
    }
    return dp[i][j][left] = res;
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