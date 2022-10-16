import java.io.*;
import java.util.*;

public class tworouts {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int n = in.nextInt(), m = in.nextInt();
    
    int[][] a = new int[n][n];
    int[][] b = new int[n][n];
    for (int i = 0; i < n; i++) {
      Arrays.fill(a[i], 1 << 25);
      Arrays.fill(b[i], 1 << 25);
      a[i][i] = 0;
      b[i][i] = 0;
    }
    
    for (int i = 0; i < m; i++) {
      int x = in.nextInt()-1, y = in.nextInt()-1;
      a[x][y] = a[y][x] = 1;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i != j && a[i][j] != 1)
          b[i][j] = 1;
      }
    }
    
    for (int k = 0; k < n; k++) for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
      a[i][j] = Math.min(a[i][j], a[i][k]+a[k][j]);
      b[i][j] = Math.min(b[i][j], b[i][k]+b[k][j]);
    }
    
//    int[] queue = new int[n*n];
//    int front = 0, back = 0;
//    queue[back++] = 0;
//    int[] dist = new int[n*n];
//    Arrays.fill(dist, 1 << 25);
//    int best = 1 << 25;
//    while(front < back) {
//      int cur = queue[front++];
//      int curb = cur/n, curt = cur%n;
//      if (curb == n-1) {
//        best = Math.min(best, dist[cur] + b[curt][n-1]);
//      }
//      if (curt == n-1) {
//        best = Math.min(best, dist[cur] + a[curb][n-1]);
//      }
//      
//      for (int i = 0; i < n; i++) {
//        if (a[curb][i] < 1 << 25) {
//          for (int j = 0; j < n; j++) {
//            if (b[curt][j] < 1 << 25) {
//              
//            }
//          }
//        }
//      }
//    }
    
    int max = Math.max(a[0][n-1], b[0][n-1]);
    out.println(max >= 1 << 25 ? -1 : max);
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