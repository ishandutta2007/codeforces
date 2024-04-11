import java.io.*;
import java.util.*;

public class robotmove {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    
    int n = in.nextInt();
    char[] s = in.next().toCharArray();
    int[] dx = new int[n+1];
    int[] dy = new int[n+1];
    for (int i = 0; i < n; i++) {
      int ddx = (s[i] == 'U' ? 1 : (s[i] == 'D' ? -1 : 0));
      dx[i+1] = dx[i] + ddx;
      int ddy = (s[i] == 'L' ? 1 : (s[i] == 'R' ? -1 : 0));
      dy[i+1] = dy[i] + ddy;
    }
    
    int count = 0;
    for (int i = 0; i <= n; i++) {
      for (int j = i+1; j <= n; j++) {
        if (dx[i] == dx[j] && dy[i] == dy[j]) {
          count++;
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