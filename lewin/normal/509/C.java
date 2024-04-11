import java.io.*;
import java.util.*;

public class sumdig {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int N = in.nextInt();
    int prev = in.nextInt();
    int maxlen = 400;
    c = new char[maxlen];
    Arrays.fill(c, '0');
    int m = prev;
    int idx = maxlen-1;
    while (m > 0) {
      c[idx] = (char)(Math.min(m,9)+'0');
      idx--;
      m -= Math.min(m, 9);
    }
    out.println(new String(c, idx+1, (maxlen-idx-1)));
    
    for (int i = 1; i < N; i++) {
      int K = in.nextInt();
      vis = new boolean[2][maxlen+1][K+1];
      for (int r = idx+1; r >= 0; r--) {
        if (dfs(r, K, 0)) {
          idx = r-1;
          break;
        }
      }
      out.println(new String(c, idx+1, (maxlen-idx-1)));
    }
    out.close();
    System.exit(0);
  }
  
  public static boolean[][][] vis;
  public static char[] c;
  public static boolean dfs(int offset, int left, int greater) {
    if (offset == c.length) return left == 0 && greater == 1;
    if (vis[greater][offset][left]) return false;
    vis[greater][offset][left] = true;
    if ((c.length-offset) * 9 < left) return false;
    
    if (greater == 1) {
      for (int i = 0; i <= 9; i++) {
        if (i > left) break;
        if (dfs(offset+1, left-i, greater)) {
          c[offset] = (char)(i+'0');
          return true;
        }
      }
      return false;
    } else {
      int at = c[offset]-'0';
      if (at > left) return false;
      if (dfs(offset+1, left-at, greater)) {
        c[offset] = (char)(at+'0');
        return true;
      }
      for (int i = at+1; i <= 9; i++) {
        if (i > left) break;
        if (dfs(offset+1, left-i, 1)) {
          c[offset] = (char)(i+'0');
          return true;
        }
      }
      return false;
    }
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