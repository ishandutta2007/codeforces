import java.io.*;
import java.util.*;

public class Main {
  private static Reader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new Reader();
    out = new PrintWriter(System.out, true);
    int N = in.nextInt(), M = in.nextInt(), W = in.nextInt();
    arr = new int[N];
    for (int i = 0; i < N; i++) {
      arr[i] = in.nextInt();
    }
    SegmentTree root = new SegmentTree(0, N - 1);
    while (M-- > 0) {
      int q = root.queryMinPos();
      int s = q, e = q + W - 1;
      if (e >= N) {
        int o = e - (N - 1);
        e -= o; s -= o;
      }
      root.update(s, e, 1);
    }
    
    out.println (root.query(root.queryMinPos()));
    out.println();
    out.close();
    System.exit(0);
  }
  
  private static int[] arr;
  static class SegmentTree {
    public SegmentTree left, right;
    public int start, end, lazy, min;
    public SegmentTree(int start, int end) {
      this.start = start;
      this.end = end;
      if (start != end) {
        int mid = (start + end) >> 1;
        left = new SegmentTree(start, mid);
        right = new SegmentTree(mid + 1, end);
        min = Math.min(left.min, right.min);
      } else {
        min = arr[start];
      }
    }
    
    public void push() {
      if (lazy != 0) {
        left.lazy += lazy;
        left.min += lazy;
        right.lazy += lazy;
        right.min += lazy;
      }
      lazy = 0;
    }
    
    public int queryMinPos() {
      if (left == null) return start;
      push();
      return left.min <= right.min ? left.queryMinPos() : right.queryMinPos();
    }
    
    public int query(int pos) {
      if (start == pos && end == pos) return min;
      push();
      int mid = (start + end) >> 1;
      if (mid >= pos) return left.query(pos);
      else return right.query(pos);
    }
    
    public void update(int s, int e, int val) {
      if (s == start && end == e) {
        lazy += val;
        min += val;
        return;
      }
      push();
      int mid = (start + end) >> 1;
      if (mid >= e) left.update(s, e, val);
      else if (mid < s) right.update(s, e, val);
      else {
        left.update(s, mid, val);
        right.update(mid + 1, e, val);
      }
      min = Math.min(left.min, right.min);
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