import java.io.*;
import java.util.*;

public class nysanta {
  private static Reader in;
  private static PrintWriter out;
  public static int[] from, to, weight;
  public static int[] eadj, eprev, ecost, elast;
  public static int eidx;
  
  public static void addEdge(int a, int b, int c) {
    eadj[eidx] = b; ecost[eidx] = c; eprev[eidx] = elast[a]; elast[a] = eidx++;
    eadj[eidx] = a; ecost[eidx] = c; eprev[eidx] = elast[b]; elast[b] = eidx++;
  }

  public static void main(String[] args) throws IOException {
    in = new Reader();
    out = new PrintWriter(System.out, true);
    int N = in.nextInt();
    eadj = new int[2*N];
    eprev = new int[2*N];
    ecost = new int[2*N];
    elast = new int[N];
    eidx = 0;
    Arrays.fill(elast, -1);
    
    from = new int[N];
    to = new int[N];
    weight = new int[N];
    for (int i = 0; i < N-1; i++) {
      from[i] = in.nextInt()-1;
      to[i] = in.nextInt()-1;
      weight[i] = in.nextInt();
      addEdge(from[i], to[i], weight[i]);
    }
    
    int[] queue = new int[N];
    int[] par = new int[N];
    int[] depth = new int[N];
    int[] sz = new int[N];
    int front = 0, back = 0;
    par[0] = -1;
    queue[back++] = 0;
    while (front < back) {
      int node = queue[front++];
      for (int e = elast[node]; e != -1; e = eprev[e]) {
        if (eadj[e] == par[node]) continue;
        queue[back++] = eadj[e];
        par[eadj[e]] = node;
        depth[eadj[e]] = depth[node]+1;
      }
    }
    
    for (int i = N-1; i >= 0; i--) {
      int node = queue[i];
      sz[node] = 1;
      for (int e = elast[node]; e != -1; e = eprev[e]) {
        if (eadj[e] == par[node]) continue;
        sz[node] += sz[eadj[e]];
      }
    }
    
    double cur = 0;
    for (int i = 0; i < N-1; i++) {
      if (par[to[i]] == from[i]) {
        int t = to[i]; to[i] = from[i]; from[i] = t;
      }
      
      long pairs = (long)sz[from[i]] * (long)(N - sz[from[i]]);
      cur += pairs * weight[i] / (double)N / (double)(N-1) * 2.;
    }
    
    int Q = in.nextInt();
    while (Q-- > 0) {
      int idx = in.nextInt()-1, nw = in.nextInt();

      long pairs = (long)sz[from[idx]] * (long)(N - sz[from[idx]]);
      cur += pairs * (nw - weight[idx]) / (double)N / (double)(N-1) * 2.;
      weight[idx] = nw;
      out.printf("%.15f\n", cur*3);
    }
    out.close();
    System.exit(0);
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