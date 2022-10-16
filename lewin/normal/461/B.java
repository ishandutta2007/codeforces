import java.io.*;
import java.util.*;

public class Solution {
  private static Reader in;
  private static PrintWriter out;
  private static int[] eadj, eprev, elast, par;
  private static int eidx;
  public static int mod = 1000000007;
  
  private static void addEdge (int a, int b) {
    eadj[eidx] = b; eprev[eidx] = elast[a]; elast[a] = eidx++;
    eadj[eidx] = a; eprev[eidx] = elast[b]; elast[b] = eidx++;
  }

  public static void main(String[] args) throws IOException {
    in = new Reader();
    out = new PrintWriter(System.out, true);
    int N = in.nextInt();
    eadj = new int[2 * N];
    eprev = new int[2 * N];
    elast = new int[N];
    par = new int[N];
    eidx = 0;
    Arrays.fill (elast, -1);
    for (int i = 1; i < N; i++) {
      addEdge(i, in.nextInt());
    }
    
    int[] col = new int[N];
    for (int i = 0; i < N; i++) col[i] = in.nextInt();
    
    int[] queue = new int[N];
    int front = 0, back = 0;
    boolean[] vis = new boolean[N];
    queue[back++] = 0;
    vis[0] = true;
    par[0] = -1;
    while (front < back) {
      int node = queue[front++];
      for (int e = elast[node]; e != -1; e = eprev[e]) {
        if (vis[eadj[e]]) continue;
        par[eadj[e]] = node;
        vis[eadj[e]] = true;
        queue[back++] = eadj[e];
      }
    }
    long[][] dp = new long[2][N];
    for (int i = N - 1; i >= 0; i--) {
      int node = queue[i];
      if (col[node] == 0) {
        long m = 1;
        for (int e = elast[node]; e != -1; e = eprev[e]) {
          if (eadj[e] == par[node]) continue;
          m = (m * (dp[0][eadj[e]] + dp[1][eadj[e]])) % mod;
        }
        dp[0][node] = m;
      } else {
        dp[0][node] = 0;
      }
      
      if (col[node] == 1) {
        long m = 1;
        for (int e = elast[node]; e != -1; e = eprev[e]) {
          if (eadj[e] == par[node]) continue;
          m = (m * (dp[0][eadj[e]] + dp[1][eadj[e]])) % mod;
        }
        dp[1][node] = m;
      } else {
        long prodall = 1;
        int idx = -1;
        boolean two = false;
        for (int e = elast[node]; e != -1; e = eprev[e]) {
          if (eadj[e] == par[node]) continue;
          if ((dp[0][eadj[e]] + dp[1][eadj[e]]) % mod == 0) {
            if (idx == -1) {
              idx = eadj[e];
            } else {
              two = true;
            }
          } else {
            prodall = (prodall * (dp[0][eadj[e]] + dp[1][eadj[e]])) % mod;
          }
        }
        long m = 0;
        if (!two) {
          if (idx == -1) {
            for (int e = elast[node]; e != -1; e = eprev[e]) {
              if (eadj[e] == par[node]) continue;
              long a = prodall * inv(dp[0][eadj[e]] + dp[1][eadj[e]], mod) % mod;
              a = a * dp[1][eadj[e]] % mod;
              m = (m + a) % mod;
            }
          } else {
            m = prodall * dp[1][idx] % mod;
          }
        }
        dp[1][node] = m;
      }
    }
    
    out.println (dp[1][0]);
    out.close();
    System.exit(0);
  }
  
  public static long inv (long N, long M) {
    long x = 0, lastx = 1, y = 1, lasty = 0, q, t, a = N, b = M;
    while (b != 0) {
        q = a / b; t = a % b; a = b; b = t;
        t = x; x = lastx - q * x; lastx = t;
        t = y; y = lasty - q * y; lasty = t;
    }
    return (lastx + M) % M;
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