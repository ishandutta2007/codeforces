import java.io.*;
import java.util.*;

public class scaygerboss {
  private static InputReader in;
  private static PrintWriter out;
  
  static class P {
    public int x,y;
    public long t;
    
    public P(int x, int y, long t) {
      this.x = x;
      this.y = y;
      this.t = t;
    }
  }
  
  public static long[][] dist;
  
  public static void initDist() {
    dist = new long[R*C][R*C];
    for (long[] x : dist) Arrays.fill(x, 1l << 60);
    for (int i = 0; i < dist.length; i++) dist[i][i] = 0;
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        if (grid[i][j] != '#') {
          int q = i*C + j;
          if (i > 0 && grid[i-1][j] != '#') dist[q][q-C] = 1;
          if (j > 0 && grid[i][j-1] != '#') dist[q][q-1] = 1;
          if (i+1 < R && grid[i+1][j] != '#') dist[q][q+C] = 1;
          if (j+1 < C && grid[i][j+1] != '#') dist[q][q+1] = 1;
        }
      }
    }
    for (int k = 0; k < dist.length; k++) for (int i = 0; i < dist.length; i++) for (int j = 0; j < dist.length; j++)
      dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
  }
  
  public static char[][] grid;
  
  public static int N, R, C, M, F;
  public static P[] mp, fp;
  public static boolean possible(long test) {
    Arrays.fill(elast, -1);
    eidx = 0;
    
    for (int i = 0; i < R; i++) for (int j = 0; j < C; j++)
      add_edge(i*C+j+M+F, i*C+j+M+F+R*C, 1);
    
    for (int i = 0; i < M; i++) {
      add_edge(N-1, i, 1);
      for (int a = 0; a < R; a++) {
        for (int b = 0; b < C; b++) {
          if (grid[a][b] == '#') continue;
          if (dist[a*C + b][mp[i].x * C + mp[i].y] > 1l << 50) continue;
          if (dist[a*C + b][mp[i].x*C + mp[i].y] * mp[i].t <= test) {
            add_edge(i, a*C+b+M+F, 1);
          }
        }
      }
    }
    for (int i = 0; i < F; i++) {
      add_edge(i+M, N-2, 1);
      for (int a = 0; a < R; a++) {
        for (int b = 0; b < C; b++) {
          if (grid[a][b] == '#') continue;
          if (dist[a*C + b][fp[i].x * C + fp[i].y] > 1l << 50) continue;
          if (dist[a*C + b][fp[i].x*C + fp[i].y] * fp[i].t <= test) {
            add_edge(a*C+b+M+F+R*C, i+M, 1);
          }
        }
      }
    }
    
    return dinic(N-1,N-2) == M;
  }
  
  private static int []   flow, capa, now, eadj, eprev, elast;
  public static int eidx;
  public static int INF = 1 << 29;
  private static void add_edge (int a, int b, int c) {
      eadj[eidx] = b; flow[eidx] = 0; capa[eidx] = c; eprev[eidx] = elast[a]; elast[a] = eidx++;
      eadj[eidx] = a; flow[eidx] = c; capa[eidx] = c; eprev[eidx] = elast[b]; elast[b] = eidx++;
  }
  
  private static int dinic (int source, int sink) {
      int res, flow = 0;
      while (bfs (source, sink)) { // see if there is an augmenting path
          System.arraycopy (elast, 0, now, 0, N);
          while ((res = dfs (source, INF, sink)) > 0) // push all possible flow through
              flow += res;
      }
      return flow;
  }
  
  private static int []   level;
  
  private static boolean bfs (int source, int sink) {
      Arrays.fill (level, -1);
      int front = 0, back = 0;
      int [] queue = new int [N];
      
      level[source] = 0;
      queue[back++] = source;
      
      while (front < back && level[sink] == -1) {
          int node = queue[front++];
          for (int e = elast[node]; e != -1; e = eprev[e]) {
              int to = eadj[e];
              if (level[to] == -1 && flow[e] < capa[e]) {
                  level[to] = level[node] + 1;
                  queue[back++] = to;
              }
          }
      }
      
      return level[sink] != -1;
  }
  
  private static int dfs (int cur, int curflow, int goal) {
      if (cur == goal)
          return curflow;
      
      for (int e = now[cur]; e != -1; now[cur] = e = eprev[e]) {
          if (level[eadj[e]] > level[cur] && flow[e] < capa[e]) {
              int res = dfs (eadj[e], Math.min (curflow, capa[e] - flow[e]), goal);
              if (res > 0) {
                  flow[e] += res;
                  flow[e ^ 1] -= res;
                  return res;
              }
          }
      }
      return 0;
  }
  
  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    R = in.nextInt(); C = in.nextInt();
    M = in.nextInt(); F = in.nextInt();
    if (Math.abs(M - F) != 1) {
      out.println("-1");
      out.close();
      System.exit(0);
    }
    grid = new char[R][C];
    for (int i = 0; i < R; i++) grid[i] = in.next().toCharArray();
    initDist();
    boolean m = M < F;
    if (m) M++; else F++;
    mp = new P[M];
    fp = new P[F];
    if (m) {
      mp[M-1] = new P(in.nextInt()-1, in.nextInt()-1, in.nextInt());
    } else {
      fp[F-1] = new P(in.nextInt()-1, in.nextInt()-1, in.nextInt());
    }
    for (int i = 0; i < (m ? M-1 : M); i++) {
      mp[i] = new P(in.nextInt()-1, in.nextInt()-1, in.nextInt());
    }
    for (int j = 0; j < (m ? F : F-1); j++) {
      fp[j] = new P(in.nextInt()-1, in.nextInt()-1, in.nextInt());
    }
    
    N = R * C * 2 + M + F + 2;
    int E = 2 * (M + F + (M + F) * (R * C) + R * C);
    eadj = new int[E];
    eprev = new int[E];
    elast = new int[N];
    now = new int[N];
    level = new int[N];
    flow = new int[E];
    capa = new int[E];
    
    long lo = 0, hi = 1l << 60;
    while (lo < hi) {
      long mid = (lo + hi) >> 1;
      if (possible(mid)) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }
    if (lo == 1l << 60) lo = -1;
    out.println(lo);
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