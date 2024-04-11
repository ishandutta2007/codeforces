import java.io.*;
import java.util.*;

public class validsets {

  private static Reader in;
  private static PrintWriter out;
  public static int D, N;
  public static int[] val;
  public static int[] eadj, eprev, elast;
  public static int eidx;
  public static int mod = 1000000007;
  
  public static void addEdge(int a, int b) {
    eadj[eidx] = b; eprev[eidx] = elast[a]; elast[a] = eidx++;
    eadj[eidx] = a; eprev[eidx] = elast[b]; elast[b] = eidx++;
  }

  public static void main(String[] args) throws IOException {
    in = new Reader();
    out = new PrintWriter(System.out, true);
    
    D = in.nextInt();
    N = in.nextInt();
    val = new int[N];
    for (int i = 0; i < N; i++) {
      val[i] = in.nextInt();
    }
    
    eadj = new int[2 * N];
    eprev = new int[2 * N];
    elast = new int[N];
    eidx = 0;
    Arrays.fill(elast, -1);
    for (int i = 0; i < N-1; i++) {
      addEdge(in.nextInt() - 1, in.nextInt() - 1);
    }
    
    long total = 0;
    for (int i = 0; i < N; i++) {
      total = (total + solve(i)) % mod;
    }
    out.println(total);
    out.close();
    System.exit(0);
  }
  
  public static int V, R;
  public static long solve (int root) {
    V = val[root];
    R = root;
    return dfs(root, -1);
  }
  
  public static long dfs(int node, int par) {
    long res = 1;
    for (int e = elast[node]; e != -1; e = eprev[e]) {
      if (eadj[e] == par) continue;
      if ((V == val[eadj[e]] && eadj[e] < R) || (val[eadj[e]] < V && V - val[eadj[e]] <= D)) {
        res = (res * (1 + dfs(eadj[e], node))) % mod;
      }
    }
    return res;
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
      byte[] buf = new byte[1 << 20];
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
      byte[] buf = new byte[1 << 20];
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