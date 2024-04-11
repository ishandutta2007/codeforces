import java.io.*;
import java.util.*;

public class nydomino {
  private static Reader in;
  private static PrintWriter out;
  public static int N;
  public static int MAXL = 20;
  public static int[] p, w;
  public static int[] last;
  public static int[][] next;
  public static long[][] cost;
  
  static class SegmentTree {
    public SegmentTree left, right;
    public int start, end;
    public int max;
    
    public SegmentTree(int start, int end) {
      this.start = start;
      this.end = end;
      if (start != end) {
        int mid = (start + end) >> 1;
        left = new SegmentTree(start, mid);
        right = new SegmentTree(mid+1, end);
        max = Math.max(left.max, right.max);
      } else {
        max = 0;
      }
    }
    public int query(int l, int r) {
      if (start == l && end == r) return max;
      int mid = (start + end) >> 1;
      if (mid >= r) return left.query(l, r);
      else if (mid < l) return right.query(l, r);
      else return Math.max(left.query(l, mid), right.query(mid+1, r));
    }
    
    public void update(int pos, int val) {
      if (start == pos && end == pos) {
        this.max = val;
        return;
      }
      int mid = (start + end) >> 1;
      if (mid >= pos) left.update(pos, val);
      else right.update(pos, val);
      this.max = Math.max(left.max, right.max);
    }
  }

  public static void main(String[] args) throws IOException {
    in = new Reader();
    out = new PrintWriter(System.out, true);
    N = in.nextInt();
    p = new int[N];
    w = new int[N];
    for (int i = 0; i < N; i++) {
      p[i] = in.nextInt();
      w[i] = in.nextInt();
    }
    SegmentTree root2 = new SegmentTree(0, N-1);
    for (int i = 0; i < N; i++) {
      root2.update(i, p[i] + w[i]);
    }
    SegmentTree root = new SegmentTree(0, N-1);
    last = new int[N];
    last[N-1] = N-1;
    root.update(N-1, N-1);
    for (int i = N-2; i >= 0; i--) {
      int lo = i, hi = N-1;
      while (lo < hi) {
        int mid = (lo + hi + 1) >> 1;
        if (p[mid] > p[i] + w[i]) hi = mid-1;
        else lo = mid;
      }
      if (lo == i) last[i] = i;
      else last[i] = root.query(i+1, lo);
      root.update(i, last[i]);
    }
    next = new int[MAXL][N];
    cost = new long[MAXL][N];
    for (int i = 0; i < N; i++) {
      next[0][i] = last[i];
      cost[0][i] = 0;
    }
    for (int k = 1; k < MAXL; k++) {
      for (int i = 0; i < N; i++) {
        if (next[k-1][i] == N-1) {
          next[k][i] = N-1;
          cost[k][i] = cost[k-1][i];
        } else {
          next[k][i] = next[k-1][next[k-1][i]+1];
          cost[k][i] = cost[k-1][i] + p[next[k-1][i]+1] - root2.query(i, next[k-1][i]) + cost[k-1][next[k-1][i]+1];
        }
      }
    }
    
    StringBuffer buff = new StringBuffer();
    int Q = in.nextInt();
    while (Q-- > 0) {
      int s = in.nextInt()-1, e = in.nextInt()-1;
      long tot = 0;
      while (last[s] < e) {
        int k = MAXL-1;
        for (; k >= 0; k--) {
          if (next[k][s] < e)
            break;
        }
        tot += cost[k][s] + p[next[k][s]+1] - root2.query(s, next[k][s]);
        s = next[k][s]+1;
      }
      buff.append(tot+"\n");
    }
    out.print(buff);
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