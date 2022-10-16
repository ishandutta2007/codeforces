import java.io.*;
import java.util.*;

public class strip {
  private static Reader in;
  private static PrintWriter out;
  
  
  static class SegmentTree {
    public SegmentTree left, right;
    public int start, end, max;
    
    public SegmentTree(int start, int end) {
      this.start = start;
      this.end = end;
      max = -(1 << 29);
      if (start != end) {
        int mid = (start + end) >> 1;
        left = new SegmentTree(start,mid);
        right = new SegmentTree(mid+1, end);
      }
    }
    
    public void update(int p, int v) {
      if (start == p && end == p) {
        this.max = v;
        return;
      }
      int mid = (start + end) >> 1;
      if (mid >= p) left.update(p, v);
      else right.update(p, v);
      this.max = Math.max(left.max, right.max);
    }
    
    public int query(int s, int e) {
      if (start == s && end == e) {
        return max;
      }
      int mid = (start + end) >> 1;
      if (mid >= e) return left.query(s, e);
      else if (mid < s) return right.query(s, e);
      else {
        return Math.max(left.query(s, mid), right.query(mid+1, e));
      }
    }
  }

  public static void main(String[] args) throws IOException {
    in = new Reader();
    out = new PrintWriter(System.out, true);
    int N = in.nextInt();
    int S = in.nextInt();
    int L = in.nextInt();
    
    int[] arr = new int[N+1];
    for (int i = 1; i <= N; i++)
      arr[i] = in.nextInt();
    SegmentTree max = new SegmentTree(0, N);
    SegmentTree min = new SegmentTree(0, N);
    for (int i = 1; i <= N; i++) {
      max.update(i, arr[i]);
      min.update(i, -arr[i]);
    }
    SegmentTree res = new SegmentTree(0, N);
    res.update(0, 0);
    for (int i = 1; i <= N; i++) {
      int lo = 1, hi = i;
      while (lo < hi) {
        int mid = (lo + hi) >> 1;
        if (max.query(mid, i)+min.query(mid, i) > S) {
          lo = mid+1;
        } else {
          hi = mid;
        }
      }
      int ans = (1 << 29);
      if (lo-1 <= i-L) ans = -res.query(lo-1, i-L)+1;
      res.update(i, -ans);
    }
    int ans = -res.query(N, N);
    out.println(ans > N ? -1 : ans);
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