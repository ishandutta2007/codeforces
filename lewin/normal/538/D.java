import java.io.*;
import java.util.*;

public class weirdchess {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int N = in.nextInt();
    char[][] x = new char[N][];
    for (int i = 0; i < N; i++) {
      x[i] = in.next().toCharArray();
    }
    
    boolean[][] shift = new boolean[2*N-1][2*N-1];
    for (boolean[] b : shift) Arrays.fill(b, true);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (x[i][j] == 'o') {
          for (int k = 0; k < N; k++) {
            for (int m = 0; m < N; m++) {
              if (x[k][m] == '.') {
                shift[k - i + N - 1][m - j + N - 1] = false;
              }
            }
          }
        }
      }
    }
    
    boolean[][] covered = new boolean[N][N];
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (x[i][j] == 'o') {
          for (int k = -N+1; k <= N-1; k++) {
            for (int m = -N+1; m <= N-1; m++) {
              if (i+k >= 0 && i+k < N && j+m >= 0 && j+m < N && shift[k+N-1][m+N-1])
                covered[i+k][j+m] = true;
            }
          }
        }
      }
    }
    
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if ((x[i][j] == 'x' && !covered[i][j])) {
          out.println("NO");
          out.close();
          System.exit(0);
        }
      }
    }
    
    out.println("YES");
    for (int i = 0; i < 2*N-1; i++) {
      for (int j = 0; j < 2*N-1; j++) {
        if (i == N-1 && j == N-1) out.print('o');
        else if (shift[i][j]) out.print('x');
        else out.print('.');
      }
      out.println();
    }
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