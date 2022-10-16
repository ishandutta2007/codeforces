import java.io.*;
import java.util.*;

public class basketball {
  private static Reader in;
  private static PrintWriter out;
  
  static class Pair implements Comparable<Pair> {
    public long num;
    public int type;
    
    public Pair (int num, int type) {
      this.num = num;
      this.type = type;
    }
    
    public int compareTo(Pair other) {
      return (int)(Math.signum(num - other.num));
    }
  }

  public static void main(String[] args) throws IOException {
    in = new Reader();
    out = new PrintWriter(System.out, true);
    
    int N = in.nextInt();
    int[] a = new int[N];
    for (int i = 0; i < N; i++) a[i] = in.nextInt();
    int M = in.nextInt();
    int[] b = new int[M];
    for (int i = 0; i < M; i++) b[i] = in.nextInt();
    Pair[] q = new Pair[N+M+2];
    for (int i = 0; i < N; i++) q[i] = new Pair(a[i], 0);
    for (int i = 0; i < M; i++) q[i+N] = new Pair(b[i], 1);
    q[N+M] = new Pair(0, -1);
    q[N+M+1] = new Pair(2000000001, -2);
    Arrays.sort(q);
    
    long sa = N * 3, sb = M * 3;
    long bd = sa - sb;
    long ca = N * 3, cb = M * 3;
    for (int i = 1; i < q.length; i++) {
      if (q[i].num != q[i-1].num) {
        if (ca - cb > bd) {
          bd = ca - cb;
          sa = ca;
          sb = cb;
        }
      }
      if (q[i].type == 0) {
        ca--;
      } else if (q[i].type == 1) {
        cb--;
      }
    }
    
    out.printf("%d:%d\n", sa, sb);
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