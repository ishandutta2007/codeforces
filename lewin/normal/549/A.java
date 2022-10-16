import java.io.*;
import java.util.*;

public class facedetecct {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int N = in.nextInt(), M = in.nextInt();
    char[][] grid = new char[N][M];
    for (int i = 0; i < N; i++) grid[i] = in.next().toCharArray();
    
    int count = 0;
    for (int i = 0; i < N-1; i++) {
      for (int j = 0; j < M-1; j++) {
        boolean[] seen = new boolean[26];
        seen[grid[i][j] - 'a'] = true;
        seen[grid[i+1][j] - 'a'] = true;
        seen[grid[i][j+1] - 'a'] = true;
        seen[grid[i+1][j+1] - 'a'] = true;
        if (seen['f'-'a'] && seen['a'-'a'] && seen['c'-'a'] && seen['e'-'a'])
          count++;
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