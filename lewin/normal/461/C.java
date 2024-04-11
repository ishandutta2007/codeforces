import java.io.*;
import java.util.*;

public class Solution {
  private static Reader in;
  private static PrintWriter out;
  public static int N;
  
  static class SegmentTree {
    public SegmentTree left, right;
    public int start, end, sum;
    public SegmentTree (int start, int end) {
      this.start = start;
      this.end = end;
      if (start == end) {
        sum = 1;
      } else {
        int mid = (start + end) >> 1;
        left = new SegmentTree (start, mid);
        right = new SegmentTree (mid + 1, end);
        sum = left.sum + right.sum;
      }
    }
    
    public int query (int s, int e) {
      if (start == s && end == e) return sum;
      int mid = (start + end) >> 1;
      if (mid >= e) return left.query (s, e);
      else if (mid < s) return right.query (s, e);
      else return left.query(s, mid) + right.query(mid + 1, e);
    }
    
    public void update(int pos, int val) {
      if (start == pos && end == pos) {
        sum += val;
        return;
      }
      int mid = (start + end) >> 1;
      if (mid >= pos) left.update(pos, val);
      else right.update (pos, val);
      this.sum = left.sum + right.sum;
    }
  }

  public static void main(String[] args) throws IOException {
    in = new Reader();
    out = new PrintWriter(System.out, true);
    N = in.nextInt();
    int Q = in.nextInt();
    int start = 0, end = N - 1;
    SegmentTree root = new SegmentTree(0, N - 1);
    boolean rev = false;
    int curwidth = N;
    
    while (Q-- > 0) {
      int cmd = in.nextInt();
      if (cmd == 1) {
        int p = in.nextInt();
        if (2 * p > curwidth) {
          rev ^= true;
          p = curwidth - p;
        }
        if (!rev) {
          for (int i = p + start - 1, j = p + start; i >= start; i--, j++) {
            root.update(j, root.query(i, i));
          }
          start += p;
        } else {
          for (int i = end - p + 1, j = end - p; i <= end; i++, j--) {
            root.update(j, root.query(i, i));
          }
          end -= p;
        }
        curwidth -= p;
      } else {
        int l = in.nextInt(), r = in.nextInt();
        if (!rev) {
          l += start;
          r += start - 1;
        } else {
          int t = l; l = r; r = t;
          l = end - l + 1;
          r = end - r;
        }
        out.println (root.query(l, r));
      }
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