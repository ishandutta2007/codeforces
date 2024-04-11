import java.io.*;
import java.util.*;

public class interestingarray {
  private static Reader in;
  private static PrintWriter out;
  
  static class SegmentTree {
    public SegmentTree left, right;
    public int val, lazy, start, end;
    
    public SegmentTree(int start, int end) {
      this.start = start;
      this.end = end;
      if (start != end) {
        int mid = (start + end) >> 1;
        left = new SegmentTree(start, mid);
        right = new SegmentTree(mid + 1, end);
        lazy = 0;
        val = 0;
      }
    }
    
    public void push() {
      if (left != null) {
        left.val |= lazy;
        right.val |= lazy;
        left.lazy |= val;
        right.lazy |= val;
      }
      lazy = 0;
    }
    
    public void join() {
      if (left != null) {
        this.val = left.val & right.val;
      }
    }
    
    public void update(int l, int r, int v) {
      if (l == start && r == end) {
        val |= v;
        lazy |= v;
        return;
      }
      push();
      int mid = (start + end) >> 1;
      if (r <= mid) left.update(l, r, v);
      else if (l > mid) right.update(l, r, v);
      else {
        left.update(l, mid, v);
        right.update(mid+1, r, v);
      }
      join();
    }
    
    public int query (int l, int r) {
      if (l == start && r == end)
        return val;
      push();
      int mid = (start + end) >> 1;
      int ret = 0;
      if (r <= mid) ret = left.query(l, r);
      else if (l > mid) ret = right.query(l, r);
      else ret = left.query(l, mid) & right.query(mid + 1, r);
      join();
      return ret;
    }
  }

  public static void main(String[] args) throws IOException {
    in = new Reader();
    out = new PrintWriter(System.out, true);
    int N = in.nextInt();
    int M = in.nextInt();
    int[][] q = new int[M][3];
    SegmentTree root = new SegmentTree(1, N);
    for (int i = 0; i < M; i++) {
      q[i][0] = in.nextInt();
      q[i][1] = in.nextInt();
      q[i][2] = in.nextInt();
      root.update(q[i][0], q[i][1], q[i][2]);
    }
    
    for (int i = 0; i < M; i++) {
      if (root.query(q[i][0], q[i][1]) != q[i][2]) {
        out.println("NO");
        out.close();
        System.exit(0);
      }
    }
    
    out.println("YES");
    out.print(root.query(1, 1));
    for (int i = 2; i <= N; i++) {
      out.print(" " + root.query(i, i));
    }
    out.println();
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