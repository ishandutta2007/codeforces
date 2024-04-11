import java.io.*;
import java.util.*;

public class draziltile {
  private static InputReader in;
  private static PrintWriter out;
  public static int N,M;
  public static char[][] grid;
  public static String BAD = "Not unique";
  public static int[] dx = new int[] {-1, 0, 1, 0}, dy = new int[] {0, -1, 0, 1};

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    N = in.nextInt();
    M = in.nextInt();
    grid = new char[N][M];
    for (int i = 0; i < N; i++) grid[i] = in.next().toCharArray();
    int count = 0;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) if (grid[i][j] == '.') count++;
    if (count % 2 != 0) {
      out.println(BAD);
      out.close();
      System.exit(0);
    }
    if (count == 0) {
      for (int i = 0; i < N; i++) {
        out.println(new String(grid[i]));
      }
      out.close();
      System.exit(0);
    }
    int[] qx = new int[N*M], qy = new int[N*M];
    int front = 0, back = 0;
    boolean ok = true;
    for (int i = 0; ok && i < N; i++) {
      for (int j = 0; ok && j < M; j++) {
        if (grid[i][j] == '.') {
          int c = countNeighbors(i,j);
          if (c == 0) {
            ok = false;
          }
          if (c == 1) {
            qx[back] = i;
            qy[back] = j;
            back++;
          }
        }
      }
    }
    
    if (!ok) {
      out.println(BAD);
      out.close();
      System.exit(0);
    }
    outer : while (front < back) {
      int x = qx[front], y = qy[front];
      front++;
      if (grid[x][y] != '.') continue;
      if (countNeighbors(x,y) == 0) {
        ok = false;
        break;
      }
      
      int gx = x, gy = y;
      if (x > 0) if (grid[x-1][y] == '.') {
        grid[x][y] = 'v';
        grid[x-1][y] = '^';
        gx = x-1;
      }
      if (y > 0) if (grid[x][y-1] == '.') {
        grid[x][y] = '>';
        grid[x][y-1] = '<';
        gy = y-1;
      }
      if (x+1 < N) if (grid[x+1][y] == '.') {
        grid[x][y] = '^';
        grid[x+1][y] = 'v';
        gx = x+1;
      }
      if (y+1 < M) if (grid[x][y+1] == '.') {
        grid[x][y] = '<';
        grid[x][y+1] = '>';
        gy = y+1;
      }
      
      for (int k = 0; k < 4; k++) {
        int nx = gx+dx[k], ny = gy+dy[k];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (grid[nx][ny] != '.') continue;
        int c = countNeighbors(nx,ny);
        if (c == 0) {
          ok = false;
          break outer;
        }
        if (c == 1) {
          qx[back] = nx;
          qy[back] = ny;
          back++;
        }
      }
    }
    
    for (int i = 0; ok && i < N; i++)
      for (int j = 0; ok && j < M; j++)
      if (grid[i][j] == '.') {
        ok = false;
      }
    
    if (!ok) {
      out.println(BAD);
      out.close();
      System.exit(0);
    }
    
    for (int i = 0; i < N; i++) {
      out.println(new String(grid[i]));
    }
    out.close();
    System.exit(0);
  }
  
  public static int countNeighbors(int i, int j) {
    int c = 0;
    if (i > 0) if (grid[i-1][j] == '.') c++;
    if (j > 0) if (grid[i][j-1] == '.') c++;
    if (i+1 < N) if (grid[i+1][j] == '.') c++;
    if (j+1 < M) if (grid[i][j+1] == '.') c++;
    return c;
  }
  
  public static int total;
  public static char[][] ans;
  public static int dfs(int x, int y) {
    if (x == N) {
      total++;
      for (int i = 0; i < N; i++) {
        System.arraycopy(grid[i], 0, ans[i], 0, M);
      }
      return total > 1 ? 2 : 1;
    }
    if (y == M) return dfs(x+1, 0);
    if (grid[x][y] != '.') return dfs(x,y+1);
    
    boolean f1 = false;
    if (y+1 < M && grid[x][y+1] == '.') {
      grid[x][y] = '<';
      grid[x][y+1] = '>';
      int r1 = dfs(x,y+1);
      if (r1 == 2) return 2;
      if (r1 == 1) f1 = true;
      grid[x][y] = '.';
      grid[x][y+1] = '.';
    }
    
    boolean f2 = false;
    if (x+1 < N && grid[x+1][y] == '.') {
      grid[x][y] = '^';
      grid[x+1][y] = 'v';
      int r2 = dfs(x,y+1);
      if (r2 == 2) return 2;
      if (r2 == 1) f2 = true;
      grid[x][y] = '.';
      grid[x+1][y] = '.';
    }
    
    if (f1 != f2) return 1;
    return 0;
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