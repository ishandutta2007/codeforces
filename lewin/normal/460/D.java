import java.io.*;
import java.util.*;

public class Main {
  private static Reader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new Reader();
    out = new PrintWriter(System.out, true);
    L = in.nextLong();
    R = in.nextLong();
    int K = in.nextInt();
    if (K == 1) {
      out.println (L);
      out.println (1);
      out.println (L);
      out.close();
      System.exit(0);
    }
    if (K == 2) {
      if (R - L + 1 == 2) {
        if ((R ^ L) < L) {
          out.println (R ^ L);
          out.println (2);
          out.println (L + " " + R);
        } else {
          out.println (L);
          out.println (1);
          out.println (L);
        }
      } else {
        if ((L ^ (L + 1)) < ((L + 1) ^ (L + 2))) {
          out.println (L ^ (L + 1));
          out.println (2);
          out.println (L + " " + (L + 1));
        } else {
          out.println ((L + 1) ^ (L + 2));
          out.println (2);
          out.println ((L + 1) + " " + (L + 2));
        }
      }
      
      out.close();
      System.exit(0);
    }
    
    ArrayList<Long> bset = new ArrayList<Long> ();
    long bxor = R + 1;
    if (R - L + 1 >= 5 && K >= 4) {
      long x1 = 0;
      for (long i = L; i <= L + 3; i++)
        x1 ^= i;
      long x2 = 0;
      for (long i = L + 1; i <= L + 4; i++)
        x2 ^= i;
      if (x1 < x2) {
        bxor = x1;
        for (long i = L; i <= L + 3; i++) bset.add(i);
      } else {
        bxor = x2;
        for (long i = L + 1; i <= L + 4; i++) bset.add(i);
      }
    } else if (R - L + 1 <= 4) {
      int e = (int)(R - L + 1);
      for (int mask = 1; mask < 1 << e; mask++) {
        long x = 0;
        if (Integer.bitCount(mask) > K) continue;
        for (int j = 0; j < e; j++) {
          if ((mask & (1 << j)) > 0) {
            x ^= (j + L);
          }
        }
        if (x < bxor) {
          bxor = x;
          bset = new ArrayList<Long> ();
          for (int j = 0; j < e; j++) {
            if ((mask & (1 << j)) > 0) {
              bset.add(j + L);
            }
          }
        }
      }
    } else {
      // K == 3
      vis = new boolean[40][4][4][4];
      dp = new boolean[40][4][4][4];
      if (solve(39, 0, 0, 0)) {
        long a1 = 0, a2 = 0, a3 = 0;
        int m1 = 0, m2 = 0, m3 = 0;
        outer : for (int bit = 39; bit >= 0; bit--) {
          for (int i = 0; i <= 1; i++) {
            for (int j = 0; j <= 1; j++) {
              long lb = (L >> bit) & 1, rb = (R >> bit) & 1;
              if (lb == 1 && i == 0 && (m1 & 1) == 0) continue;
              if (rb == 0 && i == 1 && (m1 & 2) == 0) continue;
              if (lb == 1 && j == 0 && (m2 & 1) == 0) continue;
              if (rb == 0 && j == 1 && (m2 & 2) == 0) continue;
              if (lb == 1 && (i ^ j) == 0 && (m3 & 1) == 0) continue;
              if (rb == 0 && (i ^ j) == 1 && (m3 & 2) == 0) continue;
              int nm1 = m1;
              if (i == 1 && lb == 0) nm1 |= 1;
              if (i == 0 && rb == 1) nm1 |= 2;
              int nm2 = m2;
              if (j == 1 && lb == 0) nm2 |= 1;
              if (j == 0 && rb == 1) nm2 |= 2;
              int nm3 = m3;
              if ((i ^ j) == 1 && lb == 0) nm3 |= 1;
              if ((i ^ j) == 0 && rb == 1) nm3 |= 2;
              if (bit == 0 || dp[bit - 1][nm1][nm2][nm3]) {
                a1 |= (long)i << (long)bit;
                a2 |= (long)j << (long)bit;
                a3 |= (long)(i ^ j) << (long)bit;
                m1 = nm1;
                m2 = nm2;
                m3 = nm3;
                continue outer;
              }
            }
          }
        }
        bxor = 0;
        bset.add(a1);
        bset.add(a2);
        bset.add(a3);
      } else {
        if ((L ^ (L + 1)) < ((L + 1) ^ (L + 2))) {
          out.println (L ^ (L + 1));
          out.println (2);
          out.println (L + " " + (L + 1));
        } else {
          out.println ((L + 1) ^ (L + 2));
          out.println (2);
          out.println ((L + 1) + " " + (L + 2));
        }
        out.close();
        System.exit(0);
      }
    }
    
    out.println (bxor);
    out.println (bset.size());
    boolean first = true;
    for (long x : bset) {
      if (!first) out.print (" ");
      out.print(x);
      first = false;
    }
    out.println();
    out.close();
    System.exit(0);
    
    out.close();
    System.exit(0);
  }
  
  public static boolean[][][][] dp;
  public static boolean[][][][] vis;
  public static long L, R;
  public static boolean solve(int bit, int m1, int m2, int m3) {
    if (bit == -1) {
      return true;
    }
    if (vis[bit][m1][m2][m3]) return dp[bit][m1][m2][m3];
    vis[bit][m1][m2][m3] = true;
    boolean res = false;
    for (int i = 0; i <= 1; i++) {
      for (int j = 0; j <= 1; j++) {
        long lb = (L >> bit) & 1, rb = (R >> bit) & 1;
        if (lb == 1 && i == 0 && (m1 & 1) == 0) continue;
        if (rb == 0 && i == 1 && (m1 & 2) == 0) continue;
        if (lb == 1 && j == 0 && (m2 & 1) == 0) continue;
        if (rb == 0 && j == 1 && (m2 & 2) == 0) continue;
        if (lb == 1 && (i ^ j) == 0 && (m3 & 1) == 0) continue;
        if (rb == 0 && (i ^ j) == 1 && (m3 & 2) == 0) continue;
        int nm1 = m1;
        if (i == 1 && lb == 0) nm1 |= 1;
        if (i == 0 && rb == 1) nm1 |= 2;
        int nm2 = m2;
        if (j == 1 && lb == 0) nm2 |= 1;
        if (j == 0 && rb == 1) nm2 |= 2;
        int nm3 = m3;
        if ((i ^ j) == 1 && lb == 0) nm3 |= 1;
        if ((i ^ j) == 0 && rb == 1) nm3 |= 2;
        res |= solve(bit - 1, nm1, nm2, nm3);
      }
    }
    return dp[bit][m1][m2][m3] = res;
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