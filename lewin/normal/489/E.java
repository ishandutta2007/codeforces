import java.io.*;
import java.util.*;

public class hiking {
  private static Reader in;
  private static PrintWriter out;
  
  public static double[][] dist;

  public static void main(String[] args) throws IOException {
    in = new Reader();
    out = new PrintWriter(System.out, true);
    N = in.nextInt();
    L = in.nextInt();
    x = new int[N+1];
    b = new int[N+1];
    dist = new double[N+1][N+1];
    x[0] = 0;
    for (int i = 1; i <= N; i++) {
      x[i] = in.nextInt();
      b[i] = in.nextInt();
    }
    for (int i = 0; i <= N; i++)
      for (int j = i+1; j <= N; j++)
        dist[i][j] = Math.sqrt(Math.abs(x[j]-x[i]-L));
    
    double lo = 0, hi = 1e12;
    for (int i = 0; i < 100; i++) {
      double mid = (lo + hi) / 2.;
      if (can(mid)) hi = mid;
      else lo = mid;
    }
    
    int[] prev = new int[N+1];
    prev[0] = -1;
    double[] dp = new double[N+1];
    for (int i = 1; i <= N; i++) {
      dp[i] = dist[0][i] - lo * b[i];
      for (int j = i-1; j >= 0; j--) {
        if(dist[j][i] - lo * b[i] + dp[j] < dp[i]) {
          dp[i] = dist[j][i] - lo * b[i] + dp[j];
          prev[i] = j;
        }
      }
    }
    ArrayList<Integer> path = new ArrayList<Integer>();
    int cur = N;
    while (cur != 0) {
      path.add(cur);
      cur = prev[cur];
    }
    out.print(path.get(path.size()-1));
    for (int i = path.size()-2; i >= 0; i--)
      out.print(" "+path.get(i));
    out.println();
    out.close();
    System.exit(0);
  }
  public static int N, L;
  public static int[] x, b;
  
  private static boolean can(double ratio) {
    double[] dp = new double[N+1];
    for (int i = 1; i <= N; i++) {
      dp[i] = dist[0][i] - ratio * b[i];
      for (int j = i-1; j >= 0; j--) {
        dp[i] = Math.min(dp[i], dist[j][i] - ratio * b[i] + dp[j]);
      }
    }
    return dp[N] < 0;
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