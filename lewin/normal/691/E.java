import java.io.*;
import java.util.*;

public class xorseq {
  private static InputReader in;
  private static PrintWriter out;
  public static long mod = 1000000007;

  private static long[][] mat_exp(long[][] A, long e) {
    if (e == 0) {
      long[][] ret = new long[A.length][A.length];
      for (int i = 0; i < A.length; i++) ret[i][i]++;
      return ret;
    }
    if (e == 1)
      return A;
    else if (e % 2 == 0) {
      long[][] A1 = mat_exp(A, e / 2);
      return matrix_mult(A1, A1);
    } else
      return matrix_mult(A, mat_exp(A, e - 1));
  }

  private static long[][] matrix_mult(long[][] A, long[][] B) {
    long[][] C = new long[A.length][A.length];
    for (int i = 0; i < A.length; i++)
      for (int j = 0; j < A.length; j++)
        for (int k = 0; k < A.length; k++)
          C[i][k] = (C[i][k] + A[i][j] * B[j][k]) % mod;
    return C;
  }
  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);

    int n = in.nextInt();
    long k = Long.parseLong(in.next());
    long[] arr = new long[n];
    for (int i = 0; i < n; i++) arr[i] = Long.parseLong(in.next());
    
    long[][] mat = new long[n][n];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (Long.bitCount(arr[i]^arr[j])%3 == 0)
          mat[i][j]++;
      }
    }
    
    mat = mat_exp(mat, k-1);
    long ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        ans = (ans + mat[i][j]) % mod;
      }
    }
    out.println(ans);
    
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