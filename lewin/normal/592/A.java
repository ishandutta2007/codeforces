import java.io.*;
import java.util.*;

public class pawnchess {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int n = 8;
    char[][] board = new char[n][n];
    for (int i = 0; i < n; i++) board[i] = in.next().toCharArray();
    int w = 8, b = 8;
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        if (board[i][j] == 'W') {
          boolean ok = true;
          for (int k = i-1; k >= 0; k--) {
            if (board[k][j] != '.') {
              ok = false;
              break;
            }
          }
          if (ok) w = Math.min(w, i);
        } else if (board[i][j] == 'B') {
          boolean ok = true;
          for (int k = i+1; k < 8; k++) {
            if (board[k][j] != '.') {
              ok = false;
              break;
            }
          }
          if (ok) b = Math.min(b, 8-i-1);
        }
      }
    }
    
    out.println(w <= b ? "A" : "B");
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