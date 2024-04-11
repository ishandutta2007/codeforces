import java.io.*;
import java.util.*;

public class onceagain {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int n = in.nextInt(), k = in.nextInt();
    int[] arr = new int[n];
    for (int i = 0; i < n; i++) arr[i] = in.nextInt();
    
    
    int m = 301;
    int[][] mat = new int[m+1][m+1];
    for (int i = 0; i < n; i++) {
      int[][] next = new int[m+1][m+1];
      for (int j = 0; j <= m; j++) System.arraycopy(mat[j], 0, next[j], 0, m+1);
      for (int last = 0; last <= arr[i]; last++) {
        for (int first = 0; first <= last; first++) {
          next[first][arr[i]] = Math.max(next[first][arr[i]], mat[first][last] + 1);
        }
      }
      mat = next;
    }
    
    mat = mat_exp(mat, k);
    int ret = 0;
    for (int i = 0; i <= m; i++) for (int j = 0; j <= m; j++)
      ret = Math.max(ret, mat[i][j]);
    
    out.println(ret);
    out.close();
    System.exit(0);
    
  }
  
  private static int[][] mat_exp(int[][] A, int e) {
    if (e == 1)
      return A;
    else if (e % 2 == 0) {
      int[][] A1 = mat_exp(A, e / 2);
      return matrix_mult(A1, A1);
    } else
      return matrix_mult(A, mat_exp(A, e - 1));
  }

  private static int[][] matrix_mult(int[][] A, int[][] B) {
    int[][] C = new int[A.length][A.length];
    for (int i = 0; i < A.length; i++)
      for (int j = i; j < A.length; j++)
        for (int k = j; k < A.length; k++) {
          if (A[i][j] == 0 || B[j][k] == 0) continue;
          C[i][k] = Math.max(C[i][k], A[i][j] + B[j][k]);
        }
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