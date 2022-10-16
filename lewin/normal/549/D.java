import java.io.*;
import java.util.*;

public class haarfeature {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int N = in.nextInt(), M = in.nextInt();
    char[][] grid = new char[N][M];
    for (int i = 0; i < N; i++) grid[i] = in.next().toCharArray();
    
    
    int[][] c = new int[N][M];
    int count = 0;
    for (int i = N-1; i >= 0; i--) {
      for (int j = M-1; j >= 0; j--) {
        int d = grid[i][j] == 'B' ? 1 : -1;
        if (c[i][j] != d) {
          int add = d - c[i][j];
          count++;
          for (int k = 0; k <= i; k++)
            for (int m = 0; m <= j; m++)
              c[k][m] += add;
        }
      }
    }
    out.println(count);
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