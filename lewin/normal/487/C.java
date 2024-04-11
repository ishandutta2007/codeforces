import java.io.*;
import java.util.*;

public class prefixproductseq {
  private static Reader in;
  private static PrintWriter out;
  
  public static int mod_exp(long b, long e, long mod) {
    long r = 1;
    while (e > 0) {
      if ((e&1) == 1) r = (r * b) % mod;
      b = (b * b) % mod;
      e >>= 1;
    }
    return (int)r;
  }

  public static void main(String[] args) throws IOException {
    in = new Reader();
    out = new PrintWriter(System.out, true);
    int N = in.nextInt();
    if (N == 4) {
      out.println("YES");
      out.println("1");
      out.println("3");
      out.println("2");
      out.println("4");
      out.close();
      System.exit(0);
    }
    for (int k = 2; k * k <= N; k++) {
      if (N % k == 0) {
        out.println("NO");
        out.close();
        System.exit(0);
      }
    }
    out.println("YES");
    if (N == 1) {
      out.println("1");
      out.close();
      System.exit(0);
    }
    if (N == 2) {
      out.println("1");
      out.println("2");
      out.close();
      System.exit(0);
    }
    long[] arr = new long[N];
    arr[0] = 1;
    arr[N-1] = N;
    long curprod = 1;
    for (int i = 1, j = N-2; i < j; i++, j--) {
      arr[i] = ((2l*i+1l)*(mod_exp(curprod, N-2, N))) % N;
      arr[j] = mod_exp(arr[i], N-2, N);
      curprod = (curprod * arr[i]) % N;
    }
    arr[N/2] = N-1;
    boolean[] seen = new boolean[N+1];
    for (int i = 0; i < N; i++) {
      out.println(arr[i]);
      if (seen[(int)arr[i]]) {
        out.println("NOOOOOOOOOOOO");
        System.exit(1);
      }
      seen[(int)arr[i]] = true;
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