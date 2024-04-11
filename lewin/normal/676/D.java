import java.io.*;
import java.util.*;

public class theslab {
  private static InputReader in;
  private static PrintWriter out;
  public static int[] dx = {-1,0,1,0}, dy = {0,1,0,-1};
  public static boolean[][][] ext;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);

    int n = in.nextInt(), m = in.nextInt();
    char[][] grid = new char[n][m];
    ext = new boolean[n][m][4];
    for (int i = 0; i < n; i++) {
      grid[i] = in.next().toCharArray();
      for (int j = 0; j < m; j++) {
        int[] a = {};
        switch(grid[i][j]) {
          case '+':a = new int[]{0,1,2,3}; break;
          case '-':a = new int[]{1,3}; break;
          case '|':a = new int[]{0,2}; break;
          case '^':a = new int[]{0}; break;
          case '>':a = new int[]{1}; break;
          case '<':a = new int[]{3}; break;
          case 'v':a = new int[]{2}; break;
          case 'L':a = new int[]{0,1,2}; break;
          case 'R':a = new int[]{0,2,3}; break;
          case 'D':a = new int[]{0,1,3}; break;
          case 'U':a = new int[]{1,2,3}; break;
          case '*':a = new int[]{}; break;
        }
        for (int x : a) ext[i][j][x] = true;
      }
    }
    int x1 = in.nextInt()-1, y1 = in.nextInt()-1;
    int x2 = in.nextInt()-1, y2 = in.nextInt()-1;
    
    
    int[] queue = new int[n*m*4];
    int[] dist = new int[n*m*4];
    Arrays.fill(dist, 1 << 29);
    boolean[] vis = new boolean[n*m*4];
    int front = 0, back = 0;
    queue[back++] = x1*m+y1;
    vis[x1*m+y1] = true;
    dist[x1*m+y1] = 0;
    while (front < back) {
      int state = queue[front++];
      int crot = state/(n*m);
      int cx = (state/m)%n;
      int cy = state%m;
      
      int nst = ((crot+1)%4)*(n*m) + (cx*m) + cy;
      if (!vis[nst]) {
        vis[nst] = true;
        dist[nst] = dist[state]+1;
        queue[back++] = nst;
      }
      
      for (int i = 0; i < 4; i++) {
        int nx = dx[i]+cx, ny = dy[i]+cy;
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        int needc = (i-crot+4)%4;
        int needn = ((i^2)-crot+4)%4;
        int ns = (crot)*(n*m)+(nx*m)+ny;
        if (ext[cx][cy][needc] && ext[nx][ny][needn] && !vis[ns]) {
          vis[ns] = true;
          dist[ns] = dist[state]+1;
          queue[back++] = ns;
        }
      }
    }
    int min = 1 << 29;
    for (int i = 0; i < 4; i++) {
      min = Math.min(min, dist[i*n*m + x2*m + y2]);
    }
    if (min == 1 << 29) out.println(-1);
    else out.println(min);
    
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