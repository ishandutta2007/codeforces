import java.io.*;
import java.util.*;

public class signonfence {
  private static Reader in;
  private static PrintWriter out;
  
  static class SegmentTree {
    public SegmentTree left, right;
    public int start, end;
    public int l, r, max;
    
    public SegmentTree(int start, int end) {
      this.start = start;
      this.end = end;
      if (start == end) {
        l = r = max = 0;
        return;
      } else {
        int mid = (start + end) >> 1;
        left = new SegmentTree(start, mid);
        right = new SegmentTree(mid+1, end);
        l = r = max = 0;
      }
    }
    
    public SegmentTree(SegmentTree left, SegmentTree right) {
      this.start = left.start;
      this.end = right.end;
      this.left = left;
      this.right = right;
      join();
    }
    
    public void join() {
      this.l = (left.max == (left.end - left.start + 1) ? right.l + left.max : left.l);
      this.r = (right.max == (right.end - right.start + 1) ? left.r + right.max : right.r);
      this.max = Math.max(left.r + right.l, Math.max(left.max, right.max));
    }
    
    public SegmentTree update(int pos) {
      if (start == pos && end == pos) {
        SegmentTree ret = new SegmentTree(start, end);
        ret.l  = ret.r = ret.max = 1;
        return ret;
      }
      int mid = (start + end) >> 1;
      SegmentTree l1 = left;
      SegmentTree r1 = right;
      if (pos <= mid) l1 = left.update(pos);
      else r1 = right.update(pos);
      return new SegmentTree(l1, r1);
    }
    
    public int[] query (int s, int e) {
      if (start == s && end == e) return new int[] {l, r, max};
      int mid = (start + end) >> 1;
      if (e <= mid) return left.query(s, e);
      else if (mid < s) return right.query(s, e);
      else {
        int[] a1 = left.query(s, mid);
        int[] a2 = right.query(mid+1, e);
        int[] ret = new int[3];
        ret[0] = (a1[2] == (mid - s + 1) ? a2[0] + a1[2] : a1[0]);
        ret[1] = (a2[2] == (e - (mid + 1) + 1) ? a1[1] + a2[2] : a2[1]);
        ret[2] = Math.max(a1[1] + a2[0], Math.max(a1[2], a2[2]));
        return ret;
      }
    }
  }
  
  static class Pair implements Comparable<Pair> {
    public int a, b;
    public Pair (int a, int b) {
      this.a = a;
      this.b = b;
    }
    
    public int compareTo(Pair other) {
      return other.a - a;
    }
  }
  
  public static int N;
  public static Pair[] arr;

  public static void main(String[] args) throws IOException {
    in = new Reader();
    out = new PrintWriter(System.out, true);
    
    N = in.nextInt();
    
    arr = new Pair[N+1];
    for (int i = 1; i <= N; i++) {
      arr[i] = new Pair(in.nextInt(), i);
    }
    Arrays.sort(arr, 1, N+1);
    SegmentTree[] root = new SegmentTree[N+1];
    root[0] = new SegmentTree(1, N);
    for (int i = 1; i <= N; i++) {
      root[i] = root[i-1].update(arr[i].b);
    }
    
    int Q = in.nextInt();
    while (Q-- > 0) {
      int L = in.nextInt(), R = in.nextInt();
      int W = in.nextInt();
      
      int lo = 1, hi = N;
      while (lo < hi) {
        int mid = (lo + hi) >> 1;
        if (root[mid].query(L, R)[2] >= W) hi = mid;
        else lo = mid+1;
      }
      
      out.println(arr[lo].a);
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