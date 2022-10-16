import java.io.*;
import java.util.*;

public class darthvadertree {
  private static InputReader in;
  private static PrintWriter out;
  
  public static int mod = 1000000007;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    
    int N = in.nextInt();
    long x = in.nextInt();
    if (x == 0) {
      out.println(1);
      out.close();
      System.exit(0);
    }
    long[][] mat = new long[101][101];
    mat[0][100] = 1;
    for (int i = 0; i < N; i++) {
      int d = in.nextInt();
      mat[0][d-1]++;
    }
    for (int i = 1; i < 100; i++)
      mat[i][i-1] = 1;
    mat[100][100] = 1;
    mat = mat_exp(mat, x);
    
    long ret = (mat[0][0] + mat[0][100]) % mod;
    out.println(ret);
    out.close();
    System.exit(0);
  }
  
  private static long [][] mat_exp (long [][] A, long e) {
    if (e == 1)
        return A;
    else if (e % 2 == 0) {
      long [][] A1 = mat_exp (A, e / 2);
        return matrix_mult (A1, A1);
    } else
        return matrix_mult (A, mat_exp (A, e - 1));
  }

  private static long [][] matrix_mult (long [][] A, long [][] B) {
    long [][] C = new long [A.length] [A.length];
      for (int i = 0; i < A.length; i++)
          for (int j = 0; j < A.length; j++)
              for (int k = 0; k < A.length; k++)
                  C[i][k] = (C[i][k] + A[i][j] * B[j][k]) % mod;
      return C;
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