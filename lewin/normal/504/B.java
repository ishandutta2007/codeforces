import java.io.*;
import java.util.*;

public class mishaperm {
  private static Reader in;
  private static PrintWriter out;
  
  public static int[] tree;
  
  public static int query(int pos) {
    int res = 0;
    for (int i = pos; i > 0; i -= (i & -i))
      res += tree[i];
    return res;
  }
  
  public static void update(int pos, int val) {
    for (int i = pos; i < tree.length; i += (i & -i))
      tree[i] += val;
  }

  public static void main(String[] args) throws IOException {
    in = new Reader();
    out = new PrintWriter(System.out, true);
    int N = in.nextInt();
    tree = new int[N+1];
    int[] a = new int[N];
    for (int i = 0; i < N; i++) {
      int x = in.nextInt()+1;
      a[i] = x-1 - query(x);
      update(x, 1);
    }
    tree = new int[N+1];
    int[] b = new int[N];
    for (int i = 0; i < N; i++) {
      int x = in.nextInt()+1;
      b[i] = x-1 - query(x);
      update(x, 1);
    }
    
    int[] c = new int[N];
    int carry = 0;
    for (int i = N-1; i >= 0; i--) {
      int q = a[i] + b[i] + carry;
      carry = 0;
      while (q >= N-i) {
        q -= N-i;
        carry++;
      }
      c[i] = q;
    }
    
    tree = new int[N+1];
    for (int i = 1; i <= N; i++) update(i, 1);
    
    for (int i = 0; i < N; i++) {
      int lo = 1, hi = N;
      while (lo < hi) {
        int mid = (lo + hi) >> 1;
        if (query(mid) <= c[i]) {
          lo = mid+1;
        } else {
          hi = mid;
        }
      }
      if (i != 0) out.print(" ");
      out.print(lo-1);
      update(lo, -1);
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