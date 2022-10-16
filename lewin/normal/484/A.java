import java.io.*;
import java.util.*;

public class bits {
  private static Reader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new Reader();
    out = new PrintWriter(System.out, true);
    int T = in.nextInt();
    while (T-- > 0) {
      L = in.nextLong();
      R = in.nextLong();
      dp = new int[63][2][2];
      dp2 = new long[63][2][2];
      for (int i = 0; i < 63; i++) {
        dp[i][0][0] = dp[i][0][1] = dp[i][1][0] = dp[i][1][1] = -1;
        dp2[i][0][0] = dp2[i][0][1] = dp2[i][1][0] = dp2[i][1][1] = -1;
      }
      out.println(makeNum(62, 0, 0));
    }
  }
  
  public static long L, R;
  public static int[][][] dp;
  public static long[][][] dp2;
  public static int maxBits(int bit, int ge, int le) {
    if (bit == -1) {
      return 0;
    }
    if (dp[bit][le][ge] != -1) return dp[bit][le][ge];
    int res = 0;
    // 0 bit
    l0: {
      if (ge == 0 && (L & (1l << bit)) != 0) break l0;
      int nle = le;
      if (le == 0 && (R & (1l << bit)) != 0) nle = 1;
      res = Math.max(res, maxBits(bit-1, ge, nle));
    }
    // 1 bit
    l1: {
      if (le == 0 && (R & (1l << bit)) == 0) break l1;
      int nge = ge;
      if (ge == 0 && (L & (1l << bit)) == 0) nge = 1;
      res = Math.max(res, 1+maxBits(bit-1, nge, le));
    }
    return dp[bit][le][ge] = res;
  }
  
  public static long makeNum(int bit, int ge, int le) {
    if (bit == -1) return 0;
    if (dp2[bit][le][ge] != -1) return dp2[bit][le][ge];
    long ret = 0;
    int curmax = 0;
    l0: {
      if (ge == 0 && (L & (1l << bit)) != 0) break l0;
      int nle = le;
      if (le == 0 && (R & (1l << bit)) != 0) nle = 1;
      ret = makeNum(bit-1, ge, nle);
      curmax = maxBits(bit-1, ge, nle);
    }
    // 1 bit
    l1: {
      if (le == 0 && (R & (1l << bit)) == 0) break l1;
      int nge = ge;
      if (ge == 0 && (L & (1l << bit)) == 0) nge = 1;
      if(1+maxBits(bit-1, nge, le) > curmax) {
        ret = makeNum(bit-1, nge, le) | (1l << bit);
      }
    }
    return dp2[bit][le][ge] = ret;
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