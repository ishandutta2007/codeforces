import java.io.*;
import java.util.*;

public class Main {
  private static Reader in;
  private static PrintWriter out;
  private static int[] eadj, eprev, elast;
  public static long[] ecost;
  private static int eidx;
  public static void addEdge (int a, int b, long c) {
    eadj[eidx] = b; ecost[eidx] = c; eprev[eidx] = elast[a]; elast[a] = eidx++;
    eadj[eidx] = a; ecost[eidx] = c; eprev[eidx] = elast[b]; elast[b] = eidx++;
  }

  public static void main(String[] args) throws IOException {
    in = new Reader();
    out = new PrintWriter(System.out, true);
    int N = in.nextInt(), M = in.nextInt(), K = in.nextInt();
    eadj = new int[2 * M];
    eprev = new int[2 * M];
    ecost = new long[2 * M];
    elast = new int[N];
    Arrays.fill (elast, -1);
    eidx = 0;
    for (int i = 0; i < M; i++) {
      addEdge (in.nextInt() - 1, in.nextInt() - 1, in.nextInt());
    }
    
    long[] dist = new long[N];
    Arrays.fill (dist, 1l << 60);
    dist[0] = 0;
    boolean[] train = new boolean[N];
    for (int i = 0; i < K; i++) {
      int s = in.nextInt() - 1;
      long x = in.nextInt();
      dist[s] = Math.min (dist[s], x);
      train[s] = true;
    }
    
    PriorityQueue<Pair> pq = new PriorityQueue<Pair> ();
    pq.add(new Pair(0, 0));
    for (int i = 0; i < N; i++) {
      if (dist[i] != 1l << 60)
        pq.add (new Pair (i, dist[i]));
    }
    
    while (pq.size() > 0) {
      Pair p = pq.poll();
      if (dist[p.to] != p.weight) continue;
      for (int e = elast[p.to]; e != -1; e = eprev[e]) {
        long ndist = dist[p.to] + ecost[e];
        if (ndist <= dist[eadj[e]]) {
          train[eadj[e]] = false;
        }
        if (ndist < dist[eadj[e]]) {
          pq.add(new Pair (eadj[e], dist[eadj[e]] = ndist));
        }
      }
    }
    
    int res = K;
    for (int i = 0; i < N; i++)
      if (train[i])
        res--;
    
    out.println(res);
    out.close();
    System.exit(0);
  }
  
  static class Pair implements Comparable<Pair> {
    public int to;
    public long weight;
    public Pair (int to, long weight) {
      this.to = to;
      this.weight = weight;
    }
    
    public int compareTo(Pair other) {
      return (int)Math.signum(weight - other.weight);
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