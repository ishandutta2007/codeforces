import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

public class isTree {
  private static Reader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new Reader();
    out = new PrintWriter(System.out, true);
    N = in.nextInt();
    int[][] dist = new int[N][N];
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        dist[i][j] = in.nextInt();
    for (int i = 0; i < N; i++)
      if (dist[i][i] != 0) {
        out.println("NO");
        out.close();
        System.exit(0);
      }
    
    for (int i = 0; i < N; i++)
      for (int j = i + 1; j < N; j++) {
        if (dist[i][j] != dist[j][i] || dist[i][j] == 0) {
          out.println("NO");
          out.close();
          System.exit(0);
        }
      }
    
    Edge[] elist = new Edge[N * (N - 1) / 2];
    int idx = 0;
    for (int i = 0; i < N; i++)
      for (int j = i + 1; j < N; j++)
        elist[idx++] = new Edge(i, j, dist[i][j]);
    Arrays.sort(elist);
    
    par = new int[N];
    size = new int[N];
    for (int i = 0; i < N; i++) {
      par[i] = i;
      size[i] = 1;
    }
    
    eadj = new int[2 * N];
    eprev = new int[2 * N];
    ecost = new long[2 * N];
    elast = new int[N];
    eidx = 0;
    Arrays.fill(elast, -1);
    for (int i = 0; i < idx; i++) {
      int a = find(elist[i].from), b = find(elist[i].to);
      if (a == b) continue;
      join(a, b);
      addEdge(elist[i].from, elist[i].to, elist[i].cost);
    }
    
    root = 0;
    depth = new int[N];
    queue = new int[N];
    anc = new int[20][N];
    level = new long[N];
    
    init();
    
    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        if (dist[i][j] != dist(i, j)) {
          out.println("NO");
          out.close();
          System.exit(0);
        }
      }
    }
    
    out.println("YES");
    out.close();
    System.exit(0);
  }
  
  static class Edge implements Comparable<Edge> {
    public int from, to;
    public long cost;
    public Edge (int from, int to, long cost) {
      this.from = from;
      this.to = to;
      this.cost = cost;
    }
    
    public int compareTo(Edge other) {
      return (int)(Math.signum(cost - other.cost));
    }
  }
  
  public static int[] par, size;
  public static int find (int x) {
    return par[x] == x ? x : (par[x] = find(par[x]));
  }
  
  public static void join(int x, int y) {
    int a = find(x), b = find(y);
    if (size[a] < size[b]) {
      int t = a; a = b; b = t;
    }
    size[a] += size[b];
    par[b] = a;
  }
  
  public static int N;
  public static int[] eadj, eprev, elast;
  public static long[] ecost;
  public static int eidx;
  
  public static void addEdge (int a, int b, long c) {
    eadj[eidx] = b; ecost[eidx] = c; eprev[eidx] = elast[a]; elast[a] = eidx++;
    eadj[eidx] = a; ecost[eidx] = c; eprev[eidx] = elast[b]; elast[b] = eidx++;
  }
  
  private static int      root;
  private static int []   depth, queue;
  private static int [][] anc;
  private static long[] level;
  
  private static void init () {
      Arrays.fill (depth, 1 << 29);
      Arrays.fill (level, 0);
      
      int front = 0, back = 0;
      depth[root] = 0;
      level[root] = 0;
      queue[back++] = root;
      anc[0][root] = -1;
      
      while (front != back) {
          int node = queue[front++];
          for (int e = elast[node]; e != -1; e = eprev[e])
              if (depth[node] + 1 < depth[eadj[e]]) {
                  depth[eadj[e]] = depth[node] + 1;
                  level[eadj[e]] = level[node] + ecost[e];
                  anc[0][eadj[e]] = node;
                  queue[back++] = eadj[e];
              }
      }
      
      for (int k = 1; 1 << k <= N; k++)
          for (int i = 0; i < N; i++)
              anc[k][i] = anc[k - 1][i] == -1 ? -1 : anc[k - 1][anc[k - 1][i]];
  }
  
  private static int lca (int a, int b) {
      if (depth[a] < depth[b]) {
          a ^= b;
          b ^= a;
          a ^= b;
      }
      
      // make depth [a] = depth [b] with binary search
      long diff = depth[a] - depth[b];
      for (int i = 0; 1 << i <= diff; i++)
          if ((diff & (1 << i)) != 0)
              a = anc[i][a];
      
      if (a == b)
          return a;
      
      int log = 0;
      while (1 << (log + 1) <= depth[a])
          log++;
      
      // another binary search
      for (int i = log; i >= 0; i--)
          if (anc[i][a] != anc[i][b]) {
              a = anc[i][a];
              b = anc[i][b];
          }
      
      return anc[0][a];
  }
  
  private static long dist (int a, int b) {
      return level[a] + level[b] - 2 * level[lca (a, b)];
  }

  static class Reader {
    final private int BUFFER_SIZE = 1 << 16;
    private DataInputStream din;
    private byte[] buffer;
    private int bufferPointer, bytesRead;

    public Reader() {
      din = new DataInputStream(System.in);
      buffer = new byte[BUFFER_SIZE];
      bufferPointer = bytesRead = 0;
    }

    public Reader(String file_name) throws IOException {
      din = new DataInputStream(new FileInputStream(file_name));
      buffer = new byte[BUFFER_SIZE];
      bufferPointer = bytesRead = 0;
    }

    public String readLine() throws IOException {
      byte[] buf = new byte[1024];
      int cnt = 0, c;
      while ((c = read()) != -1) {
        if (c == '\n')
          break;
        buf[cnt++] = (byte) c;
      }
      return new String(buf, 0, cnt);
    }

    public int nextInt() throws IOException {
      int ret = 0;
      byte c = read();
      while (c <= ' ')
        c = read();
      boolean neg = (c == '-');
      if (neg)
        c = read();
      do {
        ret = ret * 10 + c - '0';
      } while ((c = read()) >= '0' && c <= '9');
      if (neg)
        return -ret;
      return ret;
    }

    public long nextLong() throws IOException {
      long ret = 0;
      byte c = read();
      while (c <= ' ')
        c = read();
      boolean neg = (c == '-');
      if (neg)
        c = read();
      do {
        ret = ret * 10 + c - '0';
      } while ((c = read()) >= '0' && c <= '9');
      if (neg)
        return -ret;
      return ret;
    }

    public double nextDouble() throws IOException {
      double ret = 0, div = 1;
      byte c = read();
      while (c <= ' ')
        c = read();
      boolean neg = (c == '-');
      if (neg)
        c = read();
      do {
        ret = ret * 10 + c - '0';
      } while ((c = read()) >= '0' && c <= '9');
      if (c == '.')
        while ((c = read()) >= '0' && c <= '9')
          ret += (c - '0') / (div *= 10);
      if (neg)
        return -ret;
      return ret;
    }

    private void fillBuffer() throws IOException {
      bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
      if (bytesRead == -1)
        buffer[0] = -1;
    }

    private byte read() throws IOException {
      if (bufferPointer == bytesRead)
        fillBuffer();
      return buffer[bufferPointer++];
    }

    public void close() throws IOException {
      if (din == null)
        return;
      din.close();
    }
  }

}