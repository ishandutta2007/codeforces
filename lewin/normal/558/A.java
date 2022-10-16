import java.io.*;
import java.util.*;

public class landapple {
  private static InputReader in;
  private static PrintWriter out;
  public static int N, pos[], num[];

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    N = in.nextInt();
    pos = new int[N+1];
    num = new int[N+1];
    for (int i = 0; i < N; i++) {
      pos[i] = in.nextInt();
      num[i] = in.nextInt();
    }
    pos[N] = 0; num[N] = 0;
    vis = new boolean[N+1];
    vis[N] = true;
    int left = dfs(N, 0);
    vis = new boolean[N+1];
    vis[N] = true;
    int right = dfs(N, 1);
    out.println(Math.max(left,right));
    out.close();
    System.exit(0);
  }
  
  public static boolean[] vis;
  public static int dfs(int start, int dir) {
    if (start == -1) return 0;
    int res = num[start];
    if (dir == 0) {
      int j = -1;
      for (int i = 0; i < vis.length; i++) {
        if (vis[i]) continue;
        if (pos[i] < pos[start] && (j == -1 || pos[i] > pos[j])) j = i;
      }
      if (j != -1) {
        vis[j] = true;
        res += dfs(j, 1-dir);
      }
    } else {
      int j = -1;
      for (int i = 0; i < vis.length; i++) {
        if (vis[i]) continue;
        if (pos[i] > pos[start] && (j == -1 || pos[i] < pos[j])) j = i;
      }
      if (j != -1) {
        vis[j] = true;
        res += dfs(j, 1-dir);
      }
    }
    
    return res;
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