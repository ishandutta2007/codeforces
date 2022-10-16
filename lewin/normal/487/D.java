import java.io.*;
import java.util.*;

public class conveyorbelt {
  private static BufferedReader in;
  private static PrintWriter out;
  public static int BLOCK_SIZE = 300;
  public static int NUM_BLOCKS;
  public static int N, M, Q;
  public static char[][] grid;
  public static int[][] tx, ty;

  public static void main(String[] args) throws IOException {
    in = new BufferedReader(new InputStreamReader(System.in));
    out = new PrintWriter(System.out, true);
    StringTokenizer st = new StringTokenizer(in.readLine());
    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());
    Q = Integer.parseInt(st.nextToken());
    grid = new char[N+1][M+2];
    for (int i = 1; i <= N; i++) {
      char[] c = in.readLine().toCharArray();
      System.arraycopy(c, 0, grid[i], 1, M);
    }
    NUM_BLOCKS = N/BLOCK_SIZE+10;
    tx = new int[NUM_BLOCKS][M+2];
    ty = new int[NUM_BLOCKS][M+2];
    vis = new boolean[N+1][M+2];
    for (int i = 0; i < NUM_BLOCKS; i++)
      fixBlock(i);
    
    while (Q-- > 0) {
      st = new StringTokenizer(in.readLine());
      char cmd = st.nextToken().charAt(0);
      if (cmd == 'A') {
        int x = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());
        int idx = x / BLOCK_SIZE;
        int[] m = getDest(x, y, idx * BLOCK_SIZE-1);
        if (m[0] == -1) {
          out.println("-1 -1");
          continue;
        }
        idx--;
        while (m[0] == -2 && idx >= 0) {
          int a = tx[idx][m[1]], b = ty[idx][m[1]];
          idx--;
          m[0] = a; m[1] = b;
        }
        out.println(m[0]+" "+m[1]);
      } else {
        int x = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());
        char c = st.nextToken().charAt(0);
        grid[x][y] = c;
        fixBlock(x / BLOCK_SIZE);
      }
    }
    out.close();
    System.exit(0);
  }
  
  public static void fixBlock(int block) {
    int start = block * BLOCK_SIZE;
    if (start > N) return;
    for (int i = 1; i <= M; i++) {
      int[] m = getDest(Math.min(N, start + BLOCK_SIZE - 1), i, start - 1);
      tx[block][i] = m[0];
      ty[block][i] = m[1];
    }
  }
  
  private static boolean[][] vis;
  public static int[] getDest(int x, int y, int lim) {
    for (int i = x; i >= 0 && i >= lim; i--) Arrays.fill(vis[i], false);
    
    int cx = x, cy = y;
    while (!vis[cx][cy]) {
      if (cx <= 0 || cy <= 0 || cy >= M+1) {
        return new int[] {cx, cy};
      }
      if (cx == lim) {
        return new int[] {-2, cy};
      }
      vis[cx][cy] = true;
      switch(grid[cx][cy]) {
        case '^':
          cx--;
          break;
        case '>':
          cy++;
          break;
        case '<':
          cy--;
          break;
      }
    }
    return new int[] {-1, -1};
  }
}