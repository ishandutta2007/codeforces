import java.io.*;
import java.util.*;

public class arrayandops {
  private static Reader in;
  private static PrintWriter out;
  public static int[] arr;
  public static int[][] pairs;
  public static int MAX = 1000000000;
  
  public static int[] eadj, eprev, elast;
  public static int eidx;
  public static int INF = 1 << 29;
  public static int N;
  private static int []   flow, capa, now;
  
  // notice new addEdge method
  // directed flow (even though we add two edges)
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
    in = new Reader();
    out = new PrintWriter(System.out, true);
    int N = in.nextInt(), M = in.nextInt();
    arr = new int[N];
    for (int i = 0; i < N; i++) arr[i] = in.nextInt();
    pairs = new int[M][2];
    for (int i = 0; i < M; i++) {
      pairs[i][0] = in.nextInt()-1;
      pairs[i][1] = in.nextInt()-1;
      if (pairs[i][0] % 2 == 1) {
        int t = pairs[i][0]; pairs[i][0] = pairs[i][1]; pairs[i][1] = t;
      }
    }
    
    boolean[] prime = new boolean[100000];
    Arrays.fill(prime, true);
    int ans = 0;
    for (int i = 2; i * i <= MAX; i++) {
      if (!prime[i]) continue;
      for (int j = i+i; j < prime.length; j++)
        prime[j] = false;
      ans += solve(i);
      for (int j = 0; j < N; j++) {
        while (arr[j] % i == 0) arr[j] /= i;
      }
    }
    for (int i = 0; i < N; i++) {
      if (arr[i] > 1) {
        int m = arr[i];
        ans += solve(m);
        for (int j = 0; j < N; j++)
          while (arr[j] % m == 0) arr[j] /= m;
      }
    }
    
    out.println(ans);
    out.close();
    System.exit(0);
  }
  
  public static int solve(int div) {
    int K = arr.length;
    N = K + 2;
    int E = (N + pairs.length) * 2;
    eadj = new int[E];
    elast = new int[N];
    eidx = 0;
    eprev =new int [E];
    capa = new int[E];
    flow = new int[E];
    now = new int[N];
    level = new int[N];
    Arrays.fill(elast, -1);
    
    for (int i = 0; i < K; i++) {
      int count = 0, t = arr[i];
      while (t % div == 0) {
        t /= div;
        count++;
      }
      
      if (i % 2 == 0) {
        add_edge(N-1, i, count);
      } else {
        add_edge(i, N-2, count);
      }
    }
    for (int i = 0; i < pairs.length; i++)
      add_edge(pairs[i][0], pairs[i][1], INF);
    return dinic(N-1, N-2);
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