import java.io.*;
import java.util.*;

public class birthday {
  private static Reader in;
  private static PrintWriter out;
  public static long mod = 1000000007;
  public static int[] eadj, eprev, elast;
  public static long[] ecost;
  public static int eidx;
  
  public static void addEdge(int a, int b, long c) {
    eadj[eidx] = b; ecost[eidx] = c; eprev[eidx] = elast[a]; elast[a] = eidx++;
    eadj[eidx] = a; ecost[eidx] = c; eprev[eidx] = elast[b]; elast[b] = eidx++;
  }
  
  private static int      root;
  private static int []   depth, queue;
  public static long[] dist;
  private static int [][] anc;
  public static int N;
  
  private static void init () {
    depth = new int[N];
    dist = new long[N];
    queue = new int[N];
    root = 0;
    anc = new int[20][N];
      Arrays.fill (depth, 1 << 29);
      
      int front = 0, back = 0;
      depth[root] = 0;
      queue[back++] = root;
      anc[0][root] = -1;
      
      while (front != back) {
          int node = queue[front++];
          for (int e = elast[node]; e != -1; e = eprev[e])
              if (depth[node] + 1 < depth[eadj[e]]) {
                  depth[eadj[e]] = depth[node] + 1;
                  dist[eadj[e]] = (dist[node] + ecost[e]) % mod;
                  anc[0][eadj[e]] = node;
                  queue[back++] = eadj[e];
              }
      }
      
      for (int k = 1; 1 << k < N; k++)
          for (int i = 0; i < N; i++)
              anc[k][i] = anc[k - 1][i] == -1 ? -1 : anc[k - 1][anc[k - 1][i]];
  }
  
  public static int before;
  
  private static int lca (int a, int b) {
      if (depth[a] < depth[b]) {
          a ^= b;
          b ^= a;
          a ^= b;
      }
      
      int diff = depth[a] - depth[b];
      for (int i = 0; 1 << i <= diff; i++)
          if (((diff) & (1 << i)) != 0)
              a = anc[i][a];
      
      if (a == b)
          return a;
      
      int log = 0;
      while (1 << (log + 1) <= depth[a])
          log++;
      
      for (int i = log; i >= 0; i--)
          if (anc[i][a] != anc[i][b]) {
              a = anc[i][a];
              b = anc[i][b];
          }
      before = a;
      return anc[0][a];
  }
  
  private static long dist (int a, int b) {
      return (dist[a] + dist[b] - 2 * dist[lca (a, b)] + 2 * mod) % mod;
  }

  public static void main(String[] args) throws IOException {
    in = new Reader();
    out = new PrintWriter(System.out, true);
    N = in.nextInt();
    eadj = new int[2*N];
    eprev = new int[2*N];
    elast = new int[N];
    ecost = new long[2*N];
    eidx = 0;
    Arrays.fill(elast, -1);
    
    for (int i = 0; i < N-1; i++) {
      int a = in.nextInt()-1, b = in.nextInt()-1;
      long c = in.nextLong();
      addEdge(a, b, c);
    }
    
    int[] queue = new int[N];
    int[] par = new int[N];
    long[] costpar = new long[N];
    int front = 0, back = 0;
    par[0] = -1;
    queue[back++] = 0;
    while (front < back) {
      int node = queue[front++];
      for (int e = elast[node]; e != -1; e = eprev[e]) {
        if (eadj[e] == par[node]) continue;
        costpar[eadj[e]] = ecost[e];
        par[eadj[e]] = node;
        queue[back++] = eadj[e];
      }
    }
    
    init();
    
    long[] sum0 = new long[N];
    for (int i = N-1; i >= 0; i--) {
      int node = queue[i];
      sum0[node] = 1;
      for (int e = elast[node]; e != -1; e = eprev[e]) {
        if (eadj[e] == par[node]) continue;
        sum0[node] += sum0[eadj[e]];
      }
    }
    
    long[] sum1 = new long[N];
    for (int i = N-1; i >= 0; i--) {
      int node = queue[i];
      sum1[node] = 0;
      for (int e = elast[node]; e != -1; e = eprev[e]) {
        if (eadj[e] == par[node]) continue;
        sum1[node] = (sum1[node] + ecost[e] * sum0[eadj[e]] + sum1[eadj[e]]) % mod;
      }
    }
    
    long[] sum2 = new long[N];
    for (int i = N-1; i >= 0; i--) {
      int node = queue[i];
      sum2[node] = 0;
      for (int e = elast[node]; e != -1; e = eprev[e]) {
        if (eadj[e] == par[node]) continue;
        long add = ecost[e] * ecost[e] % mod * sum0[eadj[e]];
        add = (add + 2 * ecost[e] * sum1[eadj[e]]) % mod;
        add = (add + sum2[eadj[e]]) % mod;
        sum2[node] = (sum2[node] + add) % mod;
      }
    }
    
    long[] up1 = new long[N];
    for (int i = 1; i < N; i++) {
      int node = queue[i];
      int p = par[node];
      
      long above = (sum1[p] + up1[p]) % mod;
      long sub = (costpar[node] * sum0[node] + sum1[node]) % mod;
      above = (above + mod - sub) % mod;
      
      long add = costpar[node] * (N - sum0[node]) % mod;
      add = (add + above) % mod;
      up1[node] = add;
    }
    
    long[] up2 =  new long[N];
    for (int i = 1; i < N; i++) {
      int node = queue[i];
      int p = par[node];
      long above = (sum2[p] + up2[p]) % mod;
      long sub = costpar[node] * costpar[node] % mod * sum0[node] % mod;
      sub = (sub + 2 * costpar[node] * sum1[node]) % mod;
      sub = (sub + sum2[node]) % mod;
      above = (above + mod - sub) % mod;
      
      long add = costpar[node] * costpar[node] % mod * (N - sum0[node]) % mod;
      add = (add + 2 * costpar[node] * (up1[p] + sum1[p] + mod - sum1[node] + (mod - costpar[node] * sum0[node] % mod))) % mod;
      add = (add + above) % mod;
      up2[node] = add;
    }
    
    int Q = in.nextInt();
    while (Q-- > 0) {
      int u = in.nextInt()-1, v = in.nextInt()-1;
      int k = lca(u, v);
      if (k == v) {
        long s1 = sum2[u];
        long a1 = (up2[u] + sum2[u]) % mod;
        
        long d1 = dist(u, v);
        long b1 = up2[u];
        long sub = d1 * d1 % mod * (N - sum0[v]) % mod;
        sub = (sub + 2 * d1 * up1[v]) % mod;
        sub = (sub + up2[v]) % mod;
        
        b1 = (b1 + mod - sub) % mod;
        s1 = (s1 + b1) % mod;
        out.println((2 * s1 + mod - a1) % mod);
      } else {
        long d1 = dist(u, v);
        long s1 = d1 * d1 % mod * sum0[v] % mod;
        s1 = (s1 + 2 * d1 * sum1[v]) % mod;
        s1 = (s1 + sum2[v]) % mod;
        long a1 = (up2[u] + sum2[u]) % mod;
        out.println((2 * s1 + mod - a1) % mod);
      }
    }
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
      int cnt = 0;
      byte c = read();
      while (c <= ' ')
        c = read();
      do {
        buf[cnt++] = c;
      } while ((c = read()) != '\n');
      return new String(buf, 0, cnt);
    }

    public String next() throws IOException {
      byte[] buf = new byte[1024];
      int cnt = 0;
      byte c = read();
      while (c <= ' ')
        c = read();
      do {
        buf[cnt++] = c;
      } while ((c = read()) > ' ');
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